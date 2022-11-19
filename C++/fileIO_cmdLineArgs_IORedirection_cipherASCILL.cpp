#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


//remember part 3 supports part 2
//while (getline(cin, variable for the line))
//cat in.txt | ./a.out -e 3 > out.txt //writes it to the file
//cat in.txt | ./a.out -e 3 >> out.txt //appends to the file(adds)
using namespace std;

void encrypt(char c[], int a);
void decrypt(char c[], int a);


int main(int argc, char** argv) {
   std::string filein;
   std::string fileout;
   std::string shift;
   std::string option;
   if (argc==5) { // fileIO
     option = string(argv[1]);
     int shift = atoi(argv[2]);
     if (shift>26 || shift<-26) {
       cout << "Invalid input.\nProgram Terminated..."<< endl;
       return 0;
     }
     if (option == ("-e")) {
       filein = string(argv[3]);
       fileout = string(argv[4]);
       ifstream cin(filein);
       ofstream cout(fileout);
       string s;
       if (cin.is_open()) {
         while (!cin.eof()) {
           getline(cin, s);
           int n = s.length();
           char char_array[n+1];
           strcpy(char_array, s.c_str());
           encrypt(char_array, shift);
           if (cout.is_open()) {
             cout << char_array;
           }
           cout << endl;
         }
       }
       cout.close();
       cin.close();
     }
     else if (option == ("-d")) {
       filein = string(argv[3]);
       fileout = string(argv[4]);

       ifstream cin(filein);
       ofstream cout(fileout);
       string s;
       if (cin.is_open()) {
         while (!cin.eof()) {
           getline(cin, s);
           int n = s.length();
           char char_array[n+1];
           strcpy(char_array, s.c_str());
           decrypt(char_array, shift);
           if (cout.is_open()) {
             cout << char_array;
           }
           cout << endl;
         }
       }
       cout.close();
       cin.close();
     }
     else {
       cerr << "Usage: " << argv[0] << " <encrypt/decrypt> <shift> <filein> <fileout>" << endl;
       return 0;
     }
   }
   else if (argc==3) {// io redirection 
     option = string(argv[1]);
     int shift = atoi(argv[2]);
     if (shift>26 || shift<-26) {
       cout << "Invalid input.\nProgram Terminated..."<< endl;
       return 0;
     }
     if (option == ("-e")) {
        string s;
        for (int i=0;i<6;i++) {
         getline(cin, s);
         int n = s.length();
         char char_array[n+1];
         strcpy(char_array, s.c_str());
         encrypt(char_array, shift);
         for (int i=0;i<=strlen(char_array);i++) {
           cout << char_array[i];
         }
		     cout << endl;
       }
     }
	   else if (option == ("-d")) {
		     string s;
         for (int i=0;i<6;i++) {
         getline(cin, s);
         int n = s.length();
         char char_array[n+1];
         strcpy(char_array, s.c_str());
         decrypt(char_array, shift);
         for (int i=0;i<=strlen(char_array);i++) {
           cout << char_array[i];
         }
		     cout << endl;
       }
	    }

   }
   else {
     cerr << "Usage: " << argv[0] << " <encrypt/decrypt> <shift> <filein> <fileout>" << endl;
     return 0;
   }
}

void encrypt(char c[], int a) {
  int temp;
  for (int i=0; i<strlen(c); i++) {
    temp = static_cast<int>(c[i])+a;
    if (static_cast<int>(c[i])==32 || static_cast<int>(c[i])==32) {
      temp=32;
    }
    else if (static_cast<int>(c[i])>47 && static_cast<int>(c[i])<58) {
      temp=static_cast<int>(c[i]);
    }
    else if (temp<65) {
      temp=static_cast<int>(c[i])+a+26;
    }
    else if (temp>90) {
      temp=static_cast<int>(c[i])+a-26;
    }
    if (temp==42) {
      temp = 32;
    }
    c[i]=temp;
  }
}
void decrypt(char c[], int a) {
 int temp;
  for (int i=0; i<strlen(c); i++) {
    temp = static_cast<int>(c[i])-a;
    if (static_cast<int>(c[i])==32 || static_cast<int>(c[i])==32) {
      temp=32;
    }
    else if (static_cast<int>(c[i])>47 && static_cast<int>(c[i])<58) {
      temp=static_cast<int>(c[i]);
    }
    else if (temp<65) {
      temp=static_cast<int>(c[i])-a+26;
    }
    else if (temp>90) {
      temp=static_cast<int>(c[i])-a-26;
    }
    c[i]=temp;
  }
}
