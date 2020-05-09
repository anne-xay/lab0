#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE* file;
    file = fopen("~/lab6.log", "w+") ;

    if (strcmp("mole1",argv[1]) == 0){
        fprintf(file, "Pop %s\n", argv[1]);
    }
    else if(strcmp("mole2",argv[1]) == 0){
        fprintf(file, "Pop %s\n", argv[1]);
    }

    fclose(file);
    return 0;

}

