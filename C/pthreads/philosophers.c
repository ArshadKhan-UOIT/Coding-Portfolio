#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>
#include <stdbool.h>


#define N 5
#define LEFT (i+N-1) % N
#define RIGHT (i+1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

long state[N];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t s[N];

void test(long i) {

  if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT]!=EATING) {
    state[i] = EATING;
    printf("%ld eating \n", i);

    pthread_mutex_unlock(&(s[i]));
  }
}

void take_forks(long i) {
  pthread_mutex_lock(&mutex);
  printf("%ld hungry \n", i);
  state[i] = HUNGRY;
  test(i);
  pthread_mutex_unlock(&mutex);
  pthread_mutex_lock(&(s[i]));

  // pthread_exit(NULL);
}

void put_forks(long i) {
  pthread_mutex_lock(&mutex);
  state[i] = THINKING;
  printf("%ld thinking \n", i);
  test(LEFT);
  test(RIGHT);
  pthread_mutex_unlock(&mutex);

  // pthread_exit(NULL);
}

void *philosopher(void *threadId) {

  long tid;
  tid = (long) threadId;

  while(true) {

    sleep(1);
    take_forks(tid);
    // printf("%ld start \n", tid);
    sleep(1);
    // printf("%ld finish \n", tid);
    put_forks(tid);
  }


}



int main(int argc, char *argv[]) {
  for(int i = 0; i<N; i++) {
      pthread_mutex_init(&s[i], NULL);
      state[i] = THINKING;
  }

  pthread_t phils[N];

  long id;
  int rc;



  for(id=0; id<N; id++) {
  	rc = pthread_create(&phils[id], NULL, philosopher, (void*) id);
		if(rc) {
			printf("Error, reader failed to start: %d\n",rc);
			exit(-1);
		}
	}


  pthread_exit(NULL);
}
