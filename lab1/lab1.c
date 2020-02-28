#include <stdio.c>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(){
    
    time_t START;
    time_t STOP;
    pid_t wait_child;
    pid_t child;
    int status;

    //time()- get time in seconds
    time(&START);
    
    printf("START: %ld/n", START);
    
    child = fork();

    if (child == 0){
        //getppid()- gets process identification for PPID
        printf("PPID: %ld,", getppid());

        //getpid()- gets process identification for PID
        printf("PID: %ld/n", getpid());
    }


    
}