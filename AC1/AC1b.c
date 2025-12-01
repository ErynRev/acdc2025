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
    int count = -1;
    int start = 50; // Defining the starting positon as 50
    int newpos; //defining position end
    int oldpos; //def position old start
    int deltnum; // Define change in num (deltnum)
    char direction; // Define direction positive or negative

    fptr=fopen("./AC1/AC1aNums.txt", "r");  // fptr then opens the AC1aNums.txt file as "r"ead only

    while (fscanf(fptr, "%c%d\n", &direction, &deltnum) == 2) { // %c refers to the character and will go to direction character 
        oldpos = start;
        
        // %d gives number change
        if (direction == 76) { // dec code for L = Left
            newpos = oldpos - deltnum; // subtract change from position
            
        }

        else {  // else Right
            newpos = oldpos + deltnum; // add change
        
        }

        while (newpos > 99) {
            newpos -= 100; // take away 100
            count ++; // also add to count
        
        }
        
        while (newpos < 0) {
            newpos += 100; // add 100
            count ++; // also add to count
            if (oldpos == 0) {
                count -=2;
            }
        
        }


        printf("%c\t%d\t%d\t%d\n", direction, deltnum, newpos, count);

        oldpos = newpos;
    
    }
    

    printf("%d\t%d \n", oldpos, count);

return 0;
}
