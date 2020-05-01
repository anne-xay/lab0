#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int page_num;
    int offset;
    //converts string to integer
    int user_input = atoi(argv[1]);

    page_num = user_input/4096;
    offset = user_input%4096;

    if(argc <2){
        fprintf(stderr, "INVALID ARGUEMENTS\n");
        exit(EXIT_FAILURE);
    }

    printf("The address %d contains:\n", user_input);
    printf("page number = %d\n", page_num);
    printf("offset = %d\n", offset);


}
