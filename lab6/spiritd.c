#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

pid_t daemon;
pid_t mole1;
pid_t mole2;
pid_t new_mole;
char* rand_mole;

void dev_mole(){
    char* CP[3];

    new_mole = fork();

    //set arg[0] to either mole1 or mole2 (execv(2))
    if(new_mole == 0){
        CP[0] = 'mole.c';
        CP[1] = rand_mole;
        CP[2] = NULL;

        execve(CP[0], CP);

    }

}

void create_mole(){
    int rand;
    //randomly determine the child process number (between 1 or 2)
    rand = ((random()%2-1+1)+1); 

    if(rand == 1){
        rand_mole ="mole1";
        dev_mole();
    }
    else
    {
        rand_mole ="mole2";
        dev_mole();        
    }
    
}

//for daemon to handle the 3 signals 
void sig_handler(sig){
    //see signal(2)
    signal(sig,sig_handler);

    if(sig == SIGTERM){
        //see kill(2)
        kill(mole1, SIGKILL);
        kill(mole2, SIGKILL);
        kill(daemon, SIGKILL);
        
    }
    else if(sig == SIGUSR1){
        kill(mole1, SIGKILL);

        //need to create a new mole here
        create_mole();

    }
    else if(sig == SIGUSR2){
        kill(mole2, SIGKILL);

        ///need to create a new mole here
        create_mole();

    }

}

int main(int argc, char** argv){
    
}
