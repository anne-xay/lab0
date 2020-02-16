
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


char ascii[34][6] = {"NULL", "SOH", "STX", "ETX",  
                    "EOT", "ENQ", "ACK", "BEL", "BS", 
                    "TAB", "LF", "VT", "FF", "CR", "SO", 
                    "SI", "DLE", "DC1", "DC2", "DC3", "DC4",
                    "NAK", "SYN", "ETB", "CAN", "EM", "SUB",
                    "ESC", "FS", "GS", "RS", "US", "Space", "DEL"};
char binary[200][9];
int sizeOFbinary = 0;

void BUFFER(){
    int i;
    int j;
    for(i=0;i<=7;i++){
        for(j=0;j<=7;j++){
            if (binary[i][j]!='1' && binary[i][j]!='0'){
                int k = j;
                while(k<=7){
                    binary[i][k]='0';
                    k++;
                }
            }

        }
        binary[i][8]= '\0';
    }

}

int Decimal(char* bin){
    //dec += ((int)(binary[offset])-48)*pow(2,k);
    int i;
    int dec =0;
    for(i=1;i<=7;i++){

        dec+=((int)(bin[i])-48)*pow(2,7-i);

        printf("%d %c\n", dec, bin[i]);
        
        
    }

    return dec;

}

char* Ascii(int dec, char* c){
    if(dec<=32){
        c = ascii[dec];
    } 
    else if(dec==127){
        c = ascii[33];
    }
    else{
        c[0] = (char)(dec);
        c[1] = '\n';
    }
}

char* Parity(char* bin){
    //numofOnes += ((int)(binary[offset])-48);
    int numOFones =0;
    int i;
    for(i=0;i<=7;i++){
        numOFones += ((int)(bin[i]-48)*pow(2,7-i));
        
    }
    if(numOFones%2==0){
            return "EVEN";

        }
        else{
            return "ODD";
        }

}

void PRINT(char* bin){
    int dec;
    char* parity;
    char ascii[6];
    dec = Decimal(bin);
    parity =Parity(bin);
    Ascii(dec, ascii);
    printf("%8s %8c %8d %s\n", bin, ascii[0], dec, parity);
}

 void readFile(int fd){
    char buf;
    int x=1;
    int i=0;
    int j=0;
    while(x){
         x = read(fd,&buf,1);
         if(buf==' '){
            i++;
            sizeOFbinary++;
         } else if(x==0){
             continue;
         }else{
         binary[i][j] = buf;
            j++;
         }
        }
        sizeOFbinary+=1;
	    close(fd);
}

int main(int argc, char** argv)
{
    int i;
    if (argc<=1){
        printf("Error: File Not Found.");
        exit(1);
    }
     else if (argv[1][0]=='-'){
         for (i=2; i<argc; i++){
            strcpy(binary[i-2], argv[i]);
         }
         sizeOFbinary =argc-2;
    }
    else if (argv[1][0]=='1'||argv[1][0]=='0'){
        for (i=1; i<argc;i++){
            strcpy(binary[i-1], argv[i]);
        }
        sizeOFbinary= argc -1;
    }
    else{
        
        int fd = open(argv[1], O_RDONLY);
        if(fd==-1){
            printf("Error: File Not Found");
            exit(1);
        }
        readFile(fd);

    }
    printf("Original ASCII    Decimal  Parity\n-------- -------- -------- --------\n");
    BUFFER();
    for(i=0;i<sizeOFbinary;i++){
        printf("%s\n", binary[i]);
        PRINT(binary[i]);

    }
    /*char string1[200];
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
                i++;
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
        k=7;
        while(k>=0 && x!=0){
            if(string1[offset]=='\0'){
                x=0;
        
                for(i=k;i>=0;i--){
                    printf("0");
		            k--;
                }
                break;
            }else if(string1[offset]==' '|| string1[offset]=='\n'|| string1[offset]=='\t'){
                if(string1[offset]=='\0'){
                    break;
                }
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
    while(x){
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

