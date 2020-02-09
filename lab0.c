
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
    char string1[200];
    char *file=malloc(100*sizeof(char));
    if (argc >= 2 ){
	    if(!strcmp(argv[1],"-")){

	        file = argv[1];

            int fd = open(file, O_RDONLY);
            if(fd==-1){
                printf("FILE NOT FOUND");
                exit(1);
            }
            char buf[1];
            int x=1;
            int i=0;
            while(x){
                x = read(fd,buf,1);
                string1[i] = buf[0];
            }
	    close(fd);
        }
    }
    else{

        fgets(string1,200, stdin); //string is being stored into file
    }

    int i;
    int numofOnes;
    int dec;
    char ascii;
    char* par;

    printf("Original ASCII    Decimal  Parity\n-------- -------- -------- --------\n");
    int x =1;
    int k=7;
    int offset =0;
    while(x){
        dec=0;
        numofOnes=0;
        while(k>=0 && x!= 0){
            if(string1[offset]=='\0'){
                x=0;
        
                for(i=k;i>=0;i--){
                    printf("0");
		            k--;
                }
                break;
            }else if(string1[offset]==' '|| string1[offset]=='\n'|| string1[offset]=='\t'){
                continue;
                
            }else{
                printf("%c",string1[offset]);
                dec += ((int)(string1[offset])-48)*pow(2,k);
                numofOnes += ((int)(string1[offset])-48);
                k--;
            } 
            offset++;
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
    /*while(x){
	    i=7;
	    dec=0;
	    numofOnes =0;
        while (i>=0){
            buf[0]=string1[i];
            if(buf[0]=='\0'){
            x=0;
            }
            if(x==0){
                int j;
                for(j=i; j>=0; j--){
                    printf("0");
			        i--;
                    offset++;
                }
	       break;

        }
	if(buf[0] ==' ' || buf[0] =='\0'||buf[0] =='\n' ||buf[0]=='\t'){
        offset++;
		continue;
        }

           printf("%c",buf[0]);
            dec += ((int)(buf[0])-48)*pow(2,i);
            numofOnes += ((int)(buf[0])-48);
		i--;
        offset++;
        }
    if(numofOnes%2==0){
        par = "EVEN";

    }
    else{
        par = "ODD";
    }
    ascii = (char)(dec);
    printf("%8c %8d %8s\n", ascii,dec,par);

    }*/
return(0);

	

}

