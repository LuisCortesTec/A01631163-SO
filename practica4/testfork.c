#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>                               

int main(){
    int pid = fork();
    if(pid==0){
        printf("Hijo\n");
    }else {
        printf("Padre\n");
    }
    return 0;
}