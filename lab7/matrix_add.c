#include <stdio.h>
#include <stdlib.h>

/*general program layout
matrix_add: block, size, scalar

for i = 1 .. size 
    for j = 1 .. size 
               block[i][j] += scalar;
     end for
end for
*/

void matrix_add(int block, int size, int scalar){
    int i;
    for(i=1; i<size ;i++){
        for(j=1; j<size; j++){

        }
    }
}

/*main: size, blocks
for x = 1 .. blocks
   for y = 1 .. blocks
       async read request matrix[x, y]
       block = async read return matrix[x, y]
       matrix_add(block, block_size, scaler)
       async write request block
       async write return block
   end for
end for

	end_time = get the current time
emit end_time - start_time
*/

int main(int argc, char** argv) {
    struct status s;
    int x;
    int y;

    
    /*start_time  = get current time;
    scalar        = random number;
    block_size = size / blocks;*/

    //how to get current time
    s.seconds = time(NULL);

    s.scalar = rand();

    s.block_size = s.size/s.blocks;

    for(x=1; x < s.blocks; x++){
        for(y=1; i < s.blocks; y++){
            /*async read request matrix[x, y]
            block = async read return matrix[x, y]
            matrix_add(block, block_size, scaler)
            async write request block
            async write return block*/

        }
    }






}

