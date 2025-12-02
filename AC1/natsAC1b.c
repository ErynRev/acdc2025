// this dont work either

#include <stdio.h>

int main(void) {
    FILE *f;
    int state = 50;
    int line_change;
    char direction;
    int count = 0;

    f=fopen("./AC1/d1", "r");

    while (fscanf(f, "%c%d\n", &direction, &line_change) == 2) {

        if (direction == 76) { /* L */
            state -= line_change;
        }
        else if (direction == 82) { /* R */
            state += line_change;
        }

        while (state > 99) {
            state -= 100;
            count += 1;
        
        }


        while (state < 0) {
            state += 100;
            count += 1;
        
        }

         /*if (state == 0) {
            count += 1;
            }*/

        printf("%c\t%d\t%d\t%d\n", direction, line_change, count, state);
    }

    printf("%d \n", count);

    return 0;

}