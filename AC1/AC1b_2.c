/*
I am C code Dumbie so please freakin
bear
wif
 

What do i need to do?

This time screw that method, yea? we gonna fuck shit up by adding one per bc why not


THIS WORKS
*/

#include <stdio.h>

int main(void) {
    FILE *fptr; // This tells the FILE variable to point to fptr defined below
    int i;
    int count = 0;
    int start = 50; // Defining the starting positon as 50
    int deltnum; // Define change in num (deltnum)
    char direction; // Define direction positive or negative

    fptr=fopen("./AC1/AC1aNums.txt", "r");  // fptr then opens the AC1aNums.txt file as "r"ead only

    while (fscanf(fptr, "%c%d\n", &direction, &deltnum) == 2) { // %c refers to the character and will go to direction character 

        
        // %d gives number change
        if (direction == 'L') { // dec code for L = Left

            for (i = 0; i < deltnum; i++) {
                start --;
                if (start == 0) {
                    count ++;
                }

                if (start < 0) {
                    start += 100;
                }
            }


        }

        else if (direction == 'R') {  // else Right
            for (i = 0; i < deltnum; i++) {
                start ++;
                
                if (start > 99) {
                    start -= 100;
                }
                if (start == 0) {
                    count ++;
                }
            }
        }
     
        

        printf("%c\t%d\t%d\t%d\n", direction, deltnum, start, count);

    
    
    }
    

    printf("%d\t%d \n", start, count);

return 0;
}
