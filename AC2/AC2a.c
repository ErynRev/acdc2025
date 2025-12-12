/*

hellooo AGAIN
its the fucken second day
and i promised 

What do i need to do?

the file gives ranges of IDs,, but in these ranges if there are any repeating IDs, they are notorised as invalid

i.e,
in the range 222220-222225, there is one invalid ID in 222222 as it splits into 222,222 (i.e., 2 lots of 222)

SOOOO i need to search the ranges given, (only EVEN amount of digits)

therefore im gonna have to:
-- Go up range 1 by 1 -- For loop
-- Check each number to see if it is even number of digits -- 
-- AND THEN Split the number down the middle
-- THEN CHECK If the numbers on each side equal

while scanning
    scan for start int and end int;



*/

#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void) {
    FILE *fptr;
    int digits;
    long start;
    long end;
    long split;
    long split2;
    long i;
    char pls[10]; 
    long count;
    
    
    fptr = fopen("AC2Nums", "r");
    if (!fptr) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fptr, "%ld-%ld\n", &start, &end) == 2) {
        for(i = start; i <= end; i ++) {
            
            sprintf(pls, "%ld", i);
            digits = (int) ((strlen(pls)));

            printf("num = %ld\t -- digits are %d \n", i, digits);
            
            if (digits%2 == 0) {
                split = i%((int) (pow(10, digits/2)));
                                
                split2 = i/((int) (pow(10, digits/2)));
                printf("split %ld and split2 %ld\n", split, split2);

                if (split == split2) {
                    count += i;
                }
            
            }
        }
    
        printf("%ld\t and %ld\t ,, count is %ld\t \n", start, end, count);
    }


return 0;

}

