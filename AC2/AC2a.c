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
#include <stdlib.h>

int main(void) {
    FILE *fptr;
    size_t digits;
    int start;
    int end;
    int i;
    char* pls; 
    int count;
    
    fptr = fopen("./AC2/AC2Nums", "r");
    if (!fptr) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fptr, "%d-%d\n", &start, &end) == 2) {
        for(i = start; i <= end; i ++) {
            printf("%d\t \n", i);
            itoa(i, pls, 10);
            digits = strlen(pls);
        }
    
        printf("%d\t and %d\t \n", start, end);
    }


return 0;

}

