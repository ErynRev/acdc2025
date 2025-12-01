/*
I am C code Dumbie so please freakin
bear
wif

BLEH!!! (code just disappeared on me trynna member)

What do i need to do?

FILE command with pointer to fopen file to read
Create int starting count at 0
Create int defining  start
Create int defining  the change in number,, deltnum
Create char defining direction

fscanf to scan for L and R assigning each negative and positive respectfully
then subtract/add digits after that in same row to previous position
loop of when going below 0 or above 99, it returns back down; ---- you can tell im dumb bc i forgot that 0-99 is 100 digits
i.e., above 99 subtract 100, below 0 add 100

Count how many times 0 comes up in sequence

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
    if (!fptr) {
        printf("Error opening file.\n");
        return 1;
    }

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
        }
        
        while (start < 0) {
            start += 100;
        }

        if (start == 0) {
            count += 1;
        }

 

        printf("%c\t%d\t%d\t%d\n", direction, deltnum, start, count);

    }

    printf("%d\n", count);

return 0;
}
