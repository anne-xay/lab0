#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

int main(int argc, char** argv[])
{

    char *file = malloc(100*sizeof(char));
    if (argc >= 2 || argv[1]!="-"){
        file = argv[1];
    }
    
    else{
        scanf("%s", file); //string is being stored into file
    }


    int fd = open(file, O_RDONLY);
    if(fd==-1){
        printf("FILE NOT FOUND");
        exit(1);
    }
    char *buf;
    

    int i;
    char bit;
    int numofOnes;
    int dec;
    char ascii;
    char* par;

    printf("Original ASCII    Decimal  Parity\n-------- -------- -------- --------\n");
    int x=1;
    while(x){
        for (i=0; i<7; i++){
            x = read(fd,buf,1);
            if(x=0){
                int j;
                for(j=i; j<8; j++){
                    printf('0');
                }
                break;
            }
            printf(buf);
            dec += ((int)(bit)-48)*pow(2,i);

            numofOnes += ((int)(bit)-48);
            
        }
    if(numofOnes%2==0){
        par = "EVEN";

    }
    else{
        par = "ODD";
    }
    ascii = (char)(dec);
    printf("%8c %8d %8s", ascii,dec,par);
    }
   

return(0);



}

