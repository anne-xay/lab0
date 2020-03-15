#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void C_PROCESS(int argc, char** argv){
    char *newargv[argc];
        int i;
        for(i=1; i < argc; i++){

           newargv[i-1] = argv[i];
        
        }
        newargv[argc-1] = (char*)0;
 
        //execve - execute program
        execve(argv[1], newargv, NULL);
        perror("execve");   /* execve() returns only on error */
        exit(EXIT_FAILURE);    
}

int main(int argc, char** argv){

    if(argc<=1){
        fprintf(stderr,"Error:Not enough arguements.\n");
        exit(EXIT_FAILURE);
    }

    pid_t child = fork();

    if (child<0){
       fprintf(stderr,"FORK FAILED\n");
       
       //exit()- cause normal process termination
       exit(EXIT_FAILURE);
    }
    else if(child==0){
       C_PROCESS(argc, argv);   
    }

    else{
        //use waitpid()- wait for process to change state
        //OPTIONS:WCONTINUED, WNOHANG, WUNTRACED
        int status;
        fprintf(stderr, "%s: $$ = %d\n", argv[1], child);
        waitpid(child, &status,WUNTRACED);
        fprintf(stderr, "%s: $? = %d\n", argv[1], status);
    }
    exit(EXIT_FAILURE);

}
