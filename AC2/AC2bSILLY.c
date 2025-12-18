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


    LETS DO THIS THE SILLY WAY (CREDITS TO JESS)

    but how?
    -- divisible by all the 1 digit * 11, 101, 10101, 1010101, 101010101, 10101010101, 10101010101  etc
    (anything that can divide by 1010, is also divisible by 11 so dont have to check)
    (if divisible by 11 that means )
    how can i make this easier? do i just write it like this?



*/

#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void) {
    FILE *fptr;
    int digits;
    int digitpal;
    long start;
    long end;
    long bwah;
    long bwah2;
    long palcheck;
    long i;
    long j;
    long k = 0;
    long z;
    char pls[10]; 
    long palindromearray[1000] = {0, 0};
    long count = 0;
    int n; //num of digits

    
    fptr = fopen("AC2Nums", "r");
    if (!fptr) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fptr, "%ld-%ld\n", &start, &end) == 2) {
        for(i = start; i <= end; i ++) {
            
            /* if digits 2 and divisible by 11 then invalid, 
            if digits 3 and div by 111 then invalid,
            if digits 4 and div by 101 and 1111 then invalid,
            if digits 5 and div by 11111
            if digits 6 and div by 1001, 10101, and 111111 then invalid,
            @Therefore if ever odd digits only one divisible route - a number only consisting of 1s for amount of digits
            , but for even then divisible by that and the number of 10s for the digits/2
            same for 100 and so on (if possible)
            
            well this could be infered by number of digits/2 - 1 for the power to ten then times by 10 and add 1,
            this (in 6 digits case) would give 1001
            plus what about 10101? this would be from 10 to power .. digits/2..  + digits/2 - 2.. until you get to 1 or 10^0
            for 111111, this would be 10^digits (0,-1,-2,-3,-4,-5,-6)
            how would one do this? make the freaking numbers


            only want to check the "half points" or quarter points if they have it
            always the digits of 2s, so hoW?

            */

            sprintf(pls, "%ld", i);
            digits = (long) ((strlen(pls)));

            printf("num = %ld\t -- digits are %d \n", i, digits);

            
            
            for (j = 1; j <= (digits/ 2); j ++) {
                palcheck = 0;             
                for (bwah = 0; bwah < (digits); bwah += j) {
                    palcheck += (long) pow(10, bwah);
                    
                }

                printf("%ld\n", palcheck);


                if ( j == 1) {
                    if (i % palcheck == 0) { // checks if i is divisible by the pal
                        z = (long) i / palcheck;                 

                        sprintf(pls, "%ld", z);
                        digitpal = (long) ((strlen(pls)));
                        
                        if (((double) (digits - digitpal) /digitpal > 1)) {
                            count += (long) i; 
                            printf("pal = %d\t and count = %ld\n", palcheck, count);
                            printf("Repeated digit is = %ld\t, Palindrome diviser is %ld\t \n", z, palcheck);
                            
                        }
                    }
                }
                
                else {
                    if (!(palcheck % 10 == 0)) { // is it divisible by 10? theres no point checking these bc if theyre right they could just return a decimal which were not looking for 
                        if (i % palcheck == 0) { // checks if i is divisible by the pal
                            z = (long) i / palcheck;                 

                            sprintf(pls, "%ld", z);
                            digitpal = (long) ((strlen(pls)));
                            if (!(z == 1)) {
                                if (((double) (digits - digitpal) /digitpal > 1)) {
                                    count += (long) i; 
                                    printf("pal = %d\t and count = %ld\n", palcheck, count);
                                    printf("Repeated digit is = %ld\t, Palindrome diviser is %ld\t \n", z, palcheck);
                                    break;
                                }
                            }

                            
                        }
                    }
                }
                
                
            
            }
            

            
       
               
            
        }
    
        printf("%ld\t and %ld\t ,, count is %ld\t \n", start, end, count);
        
    }



return 0;

}
