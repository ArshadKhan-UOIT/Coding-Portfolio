#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5
#define LEFT (i+N-1) % N
#define RIGHT (i+1) %N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
// typedef int semaphore;
// int state[N];
long state[N];
// semaphore mutex = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// semaphore s[N];
pthread_mutex_t s[N];
//up with unlock
// down with lock
void test(long i) {
	if(state[i]==HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		state[i] = EATING;
        printf("%ld Started Eating\n", i);  
		// up(&s[i]);
        pthread_mutex_unlock(&(s[i]));

	}
}
//up with unlock
// down with lock
void take_forks(long i) {
	// down(&mutex);

    pthread_mutex_lock(&mutex);
	state[i] = HUNGRY;
	test(i);
	// up(&mutex);
    pthread_mutex_unlock(&mutex);
	// down(&s[i]);
    pthread_mutex_lock(&(s[i]));

}

void put_forks(long i) {
	// down(&mutex);
    pthread_mutex_lock(&mutex);
	state[i] = THINKING;

	printf("%ld Finished Eating\n", i);
	test(LEFT);		// see if the left neighbour can now eat
	test(RIGHT);	// see if the right neighbour can now eat
	// up(&mutex);
    pthread_mutex_unlock(&mutex);
}

//1 means true
void *philosopher(void *threadID) {
    long tid;
	tid = (long) threadID;
	while(1) {
		// think();
        sleep(1);
		take_forks(tid);
		// eat();
        sleep(1);
        // printf("%ld Finished Eating\n", tid);
		put_forks(tid);
	}
}


int main(int argc, char *argv[]) {
    pthread_t pil_threads[N];
    int rc;
    long t;

    for (int i=0;i<N;i++) {
        state[i] = THINKING;    //iniitializing all states to thinking 
        pthread_mutex_init(&s[i], NULL);    //initializing the mutex entries in the s array
    }

    for (t=0;t<N;t++) {
        printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&pil_threads[t], NULL, philosopher, (void*) t);
		if(rc) {    //if rc false (0)
			printf("Error in pthread_create: %d\n",rc);
			exit(-1);
		}
    }
    pthread_exit(NULL);
}


