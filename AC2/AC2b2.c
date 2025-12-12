
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void) {
    
    int digits = 10;
    int digitpal;
    long start;
    long end;
    long bwah;
    long double bwah2;
    long palcheck;
    long i;
    long j;
    char pls[10]; 
    long double count;
    int n; //num of digits
    
    
                for (j = 1; j < ((digits)/2); j += 1) {
                    palcheck = 0;             
                    for (bwah = 0; bwah < (digits); bwah += j) {
                        palcheck += pow(10, bwah);
                         
                        
                    }
                    printf("%ld\n", palcheck);

                    
                }
    
return 0;

}           
