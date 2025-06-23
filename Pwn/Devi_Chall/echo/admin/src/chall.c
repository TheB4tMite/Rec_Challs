#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void) {
    char flag[50];
    char whatever[8];
    FILE* file = fopen("flag.txt", "r");
    if (file == NULL) {printf("File not found. Report error.");}
    fgets(flag, 43, file);
    if (flag == NULL) {printf("Flag not found. Report error.");}
    while (true) {
        printf("Enter whatever you like and i will echo it back to you.\n");
        printf("Say something: ");
        if (fgets(whatever, 8, stdin)){
            printf(whatever);
        } else {
            printf("Bye!");
        }
    }
    exit(0);
    return 0;
}
