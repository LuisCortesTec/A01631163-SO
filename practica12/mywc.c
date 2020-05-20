#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argn, char **argv){
    char *fileName = argv[1];
    char buffer;
    char flag_spacio = 0;
    int linea = 0;
    int caracter = 0;
    int word = 0;
    int fd = open(fileName, O_RDONLY);
    if (fd < 0){
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd,&buffer,1)){
        //printf("%c", buffer);
        if(buffer == '\n'){
            linea++;
        }
        if((buffer == ' ' || buffer == '\n' || buffer == EOF)&& flag_spacio == 0){
            word++;
            flag_spacio = 1;
        }else if (buffer != ' ' && buffer != '\n' && buffer != EOF) {
            flag_spacio = 0;
        }
        caracter++;
    }
    printf("lineas: %d \n",linea);
    printf("caracteres: %d \n", caracter);
    printf("word: %d \n", word);
    close(fd);
    exit(0);
}