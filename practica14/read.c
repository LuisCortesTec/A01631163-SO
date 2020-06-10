#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s{
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main(){
    int src;

    Student *myStudent1;
    myStudent1 = (Student *)malloc(sizeof(Student));
    myStudent1 -> id = 20;
    myStudent1 -> semester = 2;
    sprintf(myStudent1 -> firstName, "%s", "Miguel");

    src = open("class.bin", O_RDWR);
    read(src, myStudent1, sizeof(Student));
    printf("My student is: %d, %d, %s, %s", myStudent1->id,
     myStudent1->semester, 
     myStudent1->firstName, 
     myStudent1->lastName );
     sprintf(myStudent1->lastName, "%s>%d","perez",2);
     lseek(src,-1*sizeof(Student), SEEK_CUR);
     write(src, myStudent1, sizeof(Student));
     close(src);

    free(myStudent1);
    return 0;

}