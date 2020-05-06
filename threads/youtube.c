
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

sem_t buffer_mutex;
char buffer[N];

sem_t empty;
sem_t full;

void * producer(void * th){
    for(int i=0; i<5*N; i++){
        sem_wait(&empty);
        sem_wait(&buffer_mutex);
        buffer[(i++)%N] = 'a';
        sem_post(&buffer_mutex);
        sem_post(&full);
    }
}

void *consumer(void * th){
    for(int i=0; i<5*N; i++){
        sem_wait(&full);
        sem_wait(&buffer_mutex);
        printf("%C ",buffer[(i)%N]);
        buffer[(i)%N] = '-';
        sem_post(&buffer_mutex);
        sem_post(&empty);
    }
}

int main(){
    pthread_t tp, tc;
    sem_init(&buffer_mutex, 0, 1);
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
    pthread_create(&tc, NULL, consumer, NULL);
    pthread_exit(NULL);
}