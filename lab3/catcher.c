#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int total = 29 ;
static char* sigs[] = {"HUP","INT","QUIT","ILL","TRAP","ABRT","BUS","FPE","KILL","USR1","SEGV","USR2","PIPE","ALRM","TERM","STKFLT","CHLD","CONT","STOP","TSTP","TTIN","TTOU","URG","XCPU","XFSZ","VTALRM","PROF","WINCH","IO"};
int sig_termcount =0;
int signalcount=0;

//The handler registers itself again	
void sig_handler(int sig){
    if(sig == SIGTERM){
        sig_termcount++;
    }
    else
    {
        sig_termcount = 0;
    }

    signalcount++;

    //The handler emits a line to stdout that indicates 
    //the signal caught, 
    //and the time it was caught 
    printf("SIG%s caught at %ld\n", sigs[sig-1], time(NULL));

    //The handler registers itself again
    signal(sig, sig_handler);
    
}


int main(int argc, char** argv){

    if(argc <2){
        fprintf(stderr, "INVALID ARGUEMENTS\n");
    }

//The program processes the command line arguments
    //The arguments indicate which signals to catch


    //signals are 1+, which is when you want to start checking
    for(int i=1; i<argc; i++){
        for(int j = 0; j<total; j++){
            if(strcmp(sigs[j], argv[i])==0){
                //The program registers a handler for each argument
                signal(j+1,sig_handler);
                break;

            }

        }

    }


//The program emits a status line that includes its PID to stder
    fprintf(stderr, "catcher: $$ = %d\n", getpid());
		
//The program gracefully terminates after
    //receiving three successive SIGTERM signals	
//The program pauses itself continually
    do
    {
        pause();
    }
    while(!(sig_termcount > 3));

    //The program emits a final status message to stderr that indicates
    //the number of signals caught
    fprintf(stderr, "catcher: Total signals count = %d\n", signalcount);


}


