#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    pid_t child1; //launches two child processes therefore need to check for status of 2 children
    int status1;
    pid_t child2;
    int status2;

    char* newargv1[argc];
    char* newargv2[argc];

    
    //The array pipefd is used to return two file descriptors referring to the ends of the pipe
    int pipefd[2]; 

     if(argc<=1){
        fprintf(stderr,"Error:Not enough arguements.\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], ","))
        {
            break;
        }
        newargv1[i-1]=argv[i];
    }
    newargv1[i] = (char*)0;
    if(i+1 >= argc)
    {
        fprintf(stderr,"Error:Not enough arguements.\n");
        exit(EXIT_FAILURE);
    }
    int j;
    for(j=1; j+i < argc; j++)
    {
        newargv2[j-1]=argv[i+j];
    }
    newargv1[i] = (char*)0;

    //allocates a pipe
    if (pipe(pipefd) == -1){
        fprintf(stderr,"Error:Pipe Failed\n");
        exit(EXIT_FAILURE);
    }

    //forks once
    child1 = fork();
    //child2 = fork();

    if (child1>0){
        //In parent
        child2 = fork();

        if(child2<0)
        {
            fprintf(stderr,"Error:Fork Failed\n");
            exit(EXIT_FAILURE); 
        }
        else if(child2>0)
        {
            //in parent
            fprintf(stderr, "child 1 %s: $$ = %d\n", newargv1[0], getpid());
		    fprintf(stderr, "child 2 %s: $$ = %d\n", newargv2[0], getpid());

            close(pipefd[0]);

		    waitpid(child1, &status1, WUNTRACED);
		    fprintf(stderr, "child 1 %s: $? = %d\n", newargv1[0], status1);

		    waitpid(child2, &status2, WUNTRACED);
		    fprintf(stderr, "child 2 %s: $? = %d\n", newargv2[2], status2);

		    close(pipefd[1]);
        }
        else
        {
            //in child2
            dup2(pipefd[1],1);

            execve(argv[2], newargv2, NULL);
        }
    }
    else if(child1<0){
        fprintf(stderr,"Error:Fork Failed\n");
        exit(EXIT_FAILURE);   
    }
    else{
        //in child1
        //duplicate file descriptor
        dup2(pipefd[1],1);

        execve(argv[1], newargv1, NULL);
    }
    return 0;
}
