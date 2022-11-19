/*********************************************
 *
 *               Lab10
 *
 *  This is an example of packet sniffing using
 *  the libpcap library.  For packet structures
 *  this program uses the definitions found in
 *  the /usr/include/netinet directory
 *
 *  Without parameters this program will use
 *  the first network interface.  The program
 *  will only work correctly if this is an
 *  ethernet interface.  It won't work for
 *  WiFi.  If there is a parameter it is the name
 *  of a PCAP file that is used for the
 *  packets instead of the network interface.
 *******************************************/
#include <stdio.h>
#include <time.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <stdlib.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>


void packetCallback(u_char *args, const struct pcap_pkthdr *header,
		const u_char *packet);

int main(int argc, char **argv) {
	char *device;
	char error_buffer[PCAP_ERRBUF_SIZE];
	pcap_t *handle;
	int packet_count = 0;
	int packet_timeout = 10000;

	/*
	 *  determine where the packets are coming from
	 */
	if(argc == 2) {
		handle = pcap_open_offline(argv[1], error_buffer);
		if(handle == NULL) {
			printf("error opening file: %s\n",error_buffer);
			exit(1);
		}
	} else {
		device = pcap_lookupdev(error_buffer);
		if(device == NULL) {
			printf("Can't find device: %s\n", error_buffer);
			exit(1);
		}
		handle = pcap_open_live(device, BUFSIZ, 0, packet_timeout,
				error_buffer);
		if(handle == NULL) {
			printf("can't open device: %s\n", error_buffer);
			exit(1);
		}
	}

	/*
	 *  start the capture loop
	 */
	pcap_loop(handle, packet_count, packetCallback, NULL);

	/*
	 *  close the handle and exit
	 */
	pcap_close(handle);
}


/*
 *  This procedure processes a single IP packet.
 *  It does the basic work that you will expand upon.
 *  For the assignment it will call procedures for
 *  handling TCP and UDP packets.
 */
void processIP(const u_char *packet) {
	struct iphdr *ip;
	u_char *payload;
	char *addr;
	unsigned int len;
	struct tcphdr *tcp;
	struct udphdr *udp;
	struct servent *service;
	uint16_t sport, dport;

	/*
	 *  cast the bytes to an IP packet header
	 */
	ip = (struct iphdr*) packet;
	/*
	 *  check that we have an IPv4 packet
	 */
	if(ip->version != 4) {
		printf("not version 4\n");
		return;
	}
	/*
	 *  compute the header length and the location
	 *  of the TCP or UDP packet
	 */
	len = ip->ihl*4;
	printf("header length: %d\n", len);
	payload = (unsigned char*)packet+len;

	if(ip->protocol == IPPROTO_TCP) {
		printf("TCP packet\n");
		// call the TCP procedure here
		// tcp = (struct tcphdr*) packet;
		tcp = (struct tcphdr*) payload;
		sport = ntohs(tcp->th_sport);
		printf("  source port: %d\n",sport);
		if (sport < 1024) {
			service = getservbyport(htons(sport), NULL);	//changed it to null so any protocall is matched
			if (service != NULL) {
				printf("  source service: %s\n",service->s_name);
			}
		}
		// printf("	source port 2: %d\n",tcp->source);
		dport = ntohs(tcp->th_dport);
		printf("  destination port: %d\n",dport);
		if (dport < 1024) {
			service = getservbyport(htons(dport), NULL);
			if (service != NULL) {
				printf("  destination service: %s\n",service->s_name);
			}
		}
		// printf("	destination port 2: %d\n",tcp->dest);
		// printf("  sequence number: %d\n",tcp->th_seq);
		printf("  sequence number: %u\n",ntohl(tcp->th_seq));	//formatting the seq numbers properly	
		// printf("	sequence number 2: %d\n",tcp->seq);
		// printf("  acknowledgement number: %d\n",tcp->th_ack);
		printf("  acknowledgement number: %u\n",ntohl(tcp->th_ack));	//formatting the ack numbers properly
		// printf("	acknowledgement number 2: %d\n",tcp->ack_seq);
		int ACK = (tcp->th_flags & TH_ACK);
		int SYN = (tcp->th_flags & TH_SYN);
		int FIN = (tcp->th_flags & TH_FIN);
		int RST = (tcp->th_flags & TH_RST);
		if ( ACK != 0 || SYN != 0 || FIN != 0 || RST != 0 ) {
			printf("  Flags:\n");
			if (ACK != 0) {
				// printf("    ACK: %d\n",ACK);
				printf("    ACK\n");
			}
			if (SYN != 0) {
				// printf("    SYN: %d\n",SYN);
				printf("    SYN\n");
			}
			if (FIN != 0) {
				// printf("    FIN: %d\n",FIN);
				printf("    FIN\n");
			}
			if (RST != 0) {
				// printf("    RST: %d\n",RST);
				printf("    RST\n");
			}
		}
		// if ( tcp->ack != 0 || tcp->syn != 0 || tcp->fin != 0 || tcp->rst !=  0 ) {
		// 	if (tcp->ack != 0) {
		// 		printf("    ACK\n");
		// 	}
		// 	if (tcp->syn != 0) {
		// 		printf("    SYN\n");
		// 	}
		// 	if (tcp->fin != 0) {
		// 		printf("    FIN\n");
		// 	}
		// 	if (tcp->rst != 0) {
		// 		printf("    RES\n");
		// 	}
		// } 

	}
	if(ip->protocol == IPPROTO_UDP) {
		printf("UDP packet\n");
		// call the UDP procedure here
		// udp = (struct udphdr*) packet;
		udp = (struct udphdr*) payload;
		sport = ntohs(udp->uh_sport);
		printf("  source port: %d\n",sport);
		if (sport < 1024) {
			service = getservbyport(htons(sport), NULL);
			if (service != NULL) {
				printf("  source service: %s\n",service->s_name);
			}
		}
		// printf("	source port 2: %d\n",udp->source);
		dport = ntohs(udp->uh_dport);
		printf("  destination port: %d\n",dport);
		if (dport < 1024) {
			service = getservbyport(htons(dport), NULL);
			if (service != NULL) {
				printf("  destination service: %s\n",service->s_name);
			}
		}
		// printf("	destination port 2: %d\n",udp->dest);
		printf("  packet length: %d\n",ntohs(udp->uh_ulen));
		// printf("	packet length 2: %d\n",udp->len);

	}
	/*
	 *  print the source and destination addresses
	 */
	addr = (char*) &(ip->saddr);
	printf("  source address: %hhu.%hhu.%hhu.%hhu\n",addr[0], addr[1],addr[2], addr[3]);
	addr = (char*) &(ip->daddr);
	printf("  destination address: %hhu.%hhu.%hhu.%hhu\n",addr[0], addr[1],addr[2], addr[3]);

}


/*
 *  This is the callback procedure that processes the
 *  ethernet packets.  If the payload is an IP packet
 *  processIP() is called to process it.
 */
void packetCallback(u_char *args, const struct pcap_pkthdr *header,
		const u_char *packet) {
	struct ether_header *eptr;
	short type;

	printf("time: %s", ctime((const time_t*) &header->ts.tv_sec));
	eptr = (struct ether_header *) packet;
	type = ntohs(eptr->ether_type);
	if(type == ETHERTYPE_IP) {
		printf("IP packet\n");
		processIP(packet+14);
	}
	if(type == ETHERTYPE_ARP) {
		printf("arp packet\n");
	}
	printf("\n");
}
