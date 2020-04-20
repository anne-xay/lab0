#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h>
#include <signal.h>


/*According to man manual - rand(3)
static unsigned long next = 1;

//RAND_MAX assumed to be 32767 
int myrand(void) {
    next = next * 1103515245 + 12345;
    return((unsigned)(next/65536) % 32768);
}

void mysrand(unsigned int seed) {
     next = seed;
 }*/


void eat(int seat){
    //consume a random amount of real-time (usleep(3),rand(3))
        //Philosopher #n is eating
        printf("Philosopher #%d is eating/n", seat);
        usleep(rand());

}

void think(int seat){
    //consume a random amount of real-time (usleep(3),rand(3))
        //Philosopher #n is thinking
        printf("Philosopher #%d is thinking/n", seat);
        usleep(rand());

}

int cycles(sem_t chopstick[],int i){
    //to keep a count of the number of full eat-think cycles
    int EatThink_cycles = 0;

    do{
        wait(chopstick[i]);
        wait(chopstick[(i+1)]);

        /*eat for  awhile*/

        signal(chopstick[i]);
        signal(chopstick[(i+1)]);

        /*think for awhile*/

    }while(true);



}

void remove(){
/*When your program receives this signal, it needs to 

    //return success from the process
*/

    /*effectively remove the philosopher from the eat-think cycle
        release any system resources*/
    sem_close();
    sem_unlink();
    sem_destroy();

     /*Philosopher #n completed m cycles onto stderr*/
    //fprintf(stderr,"Philosopher #%d completed %d cycles/n, seat, completed )";


}


int main(int argc, char** argv){

}



