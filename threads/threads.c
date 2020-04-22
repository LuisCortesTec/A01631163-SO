#include <stdio.h>
#include <pthread.h>

#define NUMTHREADS 10

int val = 5;
pthread_mutex_t mutex;

void * hello(void *id){
    pthread_mutex_lock(&mutex);
    printf("hello world %ld, %d\n", (long)id, val);
    val += val;
    pthread_mutex_unlock(&mutex);
};

int main(){
    pthread_t hilos[NUMTHREADS];
    for (long i=0; i<NUMTHREADS; i++){
        pthread_create(&hilos[i],NULL,hello,(void *)i);
    }
    pthread_exit(NULL); //bloquear proceso padre hasta que los hilos terminen

    return 0;
}