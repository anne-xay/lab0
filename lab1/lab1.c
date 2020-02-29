#include <stdio.h>
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

    struct tms STime;
    struct tms ETime;

    //time()- get time in seconds
    time(&START);
    times(&STime);

    printf("START: %ld\n", START);
    
    //fork()- create a child process
    child = fork();

    if (child<0){
       printf("FORKING FAILED\n");
       //exit()- cause normal process termination
       exit(EXIT_FAILURE);
    }
    else if(child==0){
        //getppid()- gets process identification for PPID
        //getpid()- gets process identification for PID
        printf("PPID: %ld, PID: %ld\n", getppid(),getpid());
        exit(EXIT_SUCCESS);
    }
    else{
        //use waitpid()- wait for process to change state
        //OPTIONS:WCONTINUED, WNOHANG, WUNTRACED
        int status;
        wait_child = (child, &status,__W_CONTINUED);
        printf("PPID: %ld, PID: %ld, CPID: %ld, RETVAL: %d\n", getppid(), getpid(), wait_child ,status);
    }
printf("USER: %ld, SYS: %ld\n",   , );
printf("CUSER: %ld, CSYS: %ld\n",  , );
printf("STOP: %ld", );

times(&ETime);
printf("STOP: ")
    
}