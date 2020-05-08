5/04/20
    Started with part 2 of lab6 first.

    Created a skeleton to correspond to what you are looking for in Lab6. Daemon will spawn and terminate a child process upon receiving a signal therefore I created an if and else statement to see what happens when you recieve the signal SIGTERM, SIG_USR1, and SIG_USR2. 

    If SIGTERM ---> kill all child processes(mole1&mole2) and shutdown daemon 
    If SIG_USR1 ---> kill mole1 and create a new mole (Don't know how I'll create a new mole but will do research)
        Joking, I do know that inorder to create anything new, you have to fork a new child like what we have done in the past labs. 
    If SIG_USR2 ---> kill mole2 and create new mole.

*side note to myself, if I am going to create a new mole for both SIG_USR1 and SIGUSR2, I should probably call in a function that does that. 

5/06/20
    Still working on part 2 of lab6.
    Goal is to create a function that will create a new mole.
        Steps are as follows :
                1. fork a new child (fork())
                2. randomly determine if you are creating mole1 or mole2 (rand())
                3. set arg[0] to either mole1 or mole2 (execv())





