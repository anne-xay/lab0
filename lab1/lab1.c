#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/times.h>

void PRINTPROCESS(int child, int wait_child, int status){
    if (child<0){
       printf("FORKING FAILED\n");
       
    }
    else if(child==0){
        //getppid()- gets process identification for PPID
        //getpid()- gets process identification for PID
        printf("PPID: %d, PID: %d\n", getppid(),getpid());
        
    }
    else{
        //use waitpid()- wait for process to change state
        //OPTIONS:WCONTINUED, WNOHANG, WUNTRACED
        printf("PPID: %d, PID: %d, CPID: %d, RETVAL: %d\n", getppid(), getpid(), wait_child ,status);
    }
    
}

int main(){
    
    time_t START;
    time_t STOP;
    pid_t wait_child;
    pid_t child;

    clock_t BUF;
    //for times()
    struct tms Process_time;

    //time()- get time in seconds
    time(&START);

    printf("START: %ld\n", START);
    
    //fork()- create a child process
    child = fork();

    if (child<0){
       //printf("FORKING FAILED\n");
       //exit()- cause normal process termination
       PRINTPROCESS(child,0,0);
       exit(EXIT_FAILURE);
    }
    else if(child==0){
        //getppid()- gets process identification for PPID
        //getpid()- gets process identification for PID
        //printf("PPID: %ld, PID: %ld\n", getppid(),getpid());
        PRINTPROCESS(child,0,0);
        exit(EXIT_SUCCESS);
    }
    else{
        //use waitpid()- wait for process to change state
        //OPTIONS:WCONTINUED, WNOHANG, WUNTRACED
        int status;
        wait_child = waitpid(child, &status,WUNTRACED);
        PRINTPROCESS(child,wait_child,status);
        //printf("PPID: %ld, PID: %ld, CPID: %ld, RETVAL: %d\n", getppid(), getpid(), wait_child ,status);
    }
    BUF = times(&Process_time);
printf("USER: %ld, SYS: %ld\n", Process_time.tms_utime ,Process_time.tms_stime);
printf("CUSER: %ld, CSYS: %ld\n", Process_time.tms_cutime,Process_time.tms_cstime);
STOP=time(NULL);
printf("STOP: %ld", STOP);
exit(EXIT_SUCCESS);

    
}