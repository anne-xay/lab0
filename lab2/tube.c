#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv){

    pid_t child1; //launches two child processes therefor need to check for status of 2 children
    int status1;
    pid_t child2;
    int status2;

    //The array pipefd is used to return two file descriptors referring to the ends of the pipe
    int pipefd[2]; 

     if(argc<=1){
        fprintf(stderr,"Error:Not enough arguements.\n");
        exit(EXIT_FAILURE);
    }

    //allocates a pipe
    if (pipe(pipefd) == -1){
        fprintf(stderr,"Error:Pipe Failed\n");
        exit(EXIT_FAILURE);
    }

    //forks two children
    child1 = fork();
    child2 = fork();

    if(child1<0){
        fprintf(stderr,"Error:Fork Failed\n");
        exit(EXIT_FAILURE);   
    }
    else if(child1==0 && child2>0){
        //duplicate file descriptor
        dup2(pipefd[1],1);
    }
    else{
        if (child2<0){
            fprintf(stderr,"Error:Fork Failed\n");
            exit(EXIT_FAILURE);
        }
        else if (child2==0 && child1>0){
            dup2(pipefd[1],1);
        }
        else{
            //print
             fprintf(stderr,"Parent: child1 pid:%d, child2 ppid:%d \n", child1, child2);
        }
    }

}
