/*

hellooo AGAIN
its the fucken second day
and i promised id do tem all to learn C

What do i need to do?

the file gives ranges of IDs,, but in these ranges if there are any repeating IDs, they are notorised as invalid
THIS TIME SPLIT THEM NOT JUST UP IN HALF BUT ALL THE WAY UP TO N TIMES

i.e,
in the range 252220-252525, there is two invalid IDs in 252252 as it splits into 252,252 (i.e., 2 lots of 252)
and also 25,25,25 (i.e. 3 lots of 25)

SOOOO i need to search the ranges given, (only EVEN amount of digits)

therefore im gonna have to:
-- Go up range 1 by 1 -- For loop
-- Check each number to see if it is even number of digits -- 
-- AND THEN Split the number down into .n. number of digits
-- THEN CHECK If the numbers in each are equal

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
    long n; //num of digits
    char new_str[n] = {'0', '\0'};
    
    
    fptr = fopen("./AC2/test", "r");
    if (!fptr) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fptr, "%ld-%ld\n", &start, &end) == 2) {
        for(i = start; i <= end; i ++) {
            
            sprintf(pls, "%ld", i);
            digits = (int) ((strlen(pls)));

            printf("num = %ld\t -- digits are %d \n", i, digits);
            
            for (n = 2; n <= digits; n++) {
                                // now i need to have the split n times, which is annoying
                for (split = 2; split <= n; split++) {
                    new_str[n] = '0' + (i%((int) (pow(10, digits/split))));
                                                        

                }
                printf("%s\n", new_str);

            }
                
            
        }
    
        printf("%ld\t and %ld\t ,, count is %ld\t \n", start, end, count);
    }


return 0;

}

