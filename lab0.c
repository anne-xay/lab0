
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{

    char *file=malloc(100*sizeof(char));
    if (argc >= 2 ){
	if(!strcmp(argv[1],"-")){

	    file = argv[1];

    }
    else{

        fgets(file,100, stdin); //string is being stored into file
    }
	printf("%s", file);


    int fd = open(file, O_RDONLY);
    if(fd==-1){
        printf("FILE NOT FOUND");
        exit(1);
    }
    char buf[0];


    int i;
    int numofOnes;
    int dec;
    char ascii;
    char* par;

    printf("Original ASCII    Decimal  Parity\n-------- -------- -------- --------\n");
    int x=1;
    while(x){
	i=7;
	dec=0;
	numofOnes =0;
        while (i>=0){
            x = read(fd,buf,1);

            if(x==0){
                int j;
                for(j=i; j>=0; j--){
                    printf("0");
			i--;
                }
	       break;

            }
	if(buf[0] ==' ' || buf[0] =='\0'||buf[0] =='\n' ||buf[0]=='\t'){
		continue;
        }

           printf("%c",buf[0]);
            dec += ((int)(buf[0])-48)*pow(2,i);
            numofOnes += ((int)(buf[0])-48);
		i--;
        }
    if(numofOnes%2==0){
        par = "EVEN";

    }
    else{
        par = "ODD";
    }
    ascii = (char)(dec);
    printf("%8c %8d %8s\n", ascii,dec,par);

    }
close(fd);
return(0);



}

