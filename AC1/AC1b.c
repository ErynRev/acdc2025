/*
I am C code Dumbie so please freakin
bear
wif
 

What do i need to do?

This is exact same but this time count each time it goes past 0 even if its not landing on 0
baso just add to count each time pos (start) goes >99 or <0

wish me luck
*/

#include <stdio.h>

int main(void) {
    FILE *fptr; // This tells the FILE variable to point to fptr defined below
    int count = 0;
    int start = 50; // Defining the starting positon as 50
    int deltnum; // Define change in num (deltnum)
    char direction; // Define direction positive or negative

    fptr=fopen("./AC1/AC1aNums.txt", "r");  // fptr then opens the AC1aNums.txt file as "r"ead only

    while (fscanf(fptr, "%c%d\n", &direction, &deltnum) == 2) { // %c refers to the character and will go to direction character 
        // %d gives number change
        if (direction == 76) { // dec code for L = Left
            start -= deltnum; // subtract change from position
        }

        else {  // else Right
            start += deltnum; // add change
        }

        while (start > 99) {
            start -= 100; // take away 100
            count += 1; // also add to count
        }
        
        while (start < 0) {
            start += 100; // add 100
            count += 1; // also add to count
        }

        /* if (start == 0) {
            count += 1;
        }
        */

        printf("%c\t%d\t%d\t%d\n", direction, deltnum, start, count);

    }

    printf("%d \n", count);

return 0;
}
