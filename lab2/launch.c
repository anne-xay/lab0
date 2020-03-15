#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void PRINTPROCESS(){
    
    
}

int main(int argc, char** argv){

    if(argc<=1){
        fprintf(stderr,"Error:Not enough arguements.\n");
        exit(EXIT_FAILURE);
    }

    pid_t child;
    child = fork();

    if (child<0){
       fprintf(stderr,"FORK FAILED\n");
       
       //exit()- cause normal process termination
       exit(EXIT_FAILURE);
    }
    else if(child==0){
        char *newargv[argc-1];
        int i;
        for(i=1; i < argc; i++){

           newargv[i-1] = argv[i];
           printf("%s\n", newargv[i]);
        
        }
 
        //execve - execute program
        execve(argv[1], newargv, NULL);
        perror("execve");   /* execve() returns only on error */
        exit(EXIT_FAILURE);   
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
