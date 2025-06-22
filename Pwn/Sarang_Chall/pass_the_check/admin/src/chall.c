#include <stdio.h>

void flag() {
    FILE *file = fopen("flag.txt", "r");
    char buf[32];

    fgets(buf, 32, file);
    printf("Here you go: %s\n", buf);
}

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

int main() {

    init();

    char buf[32];
    int val = 0xDEADC0DE;

    printf("Can you pass the check: ");
    gets(buf);

    if (val == 0xCAFED00D) {
        flag();
    } else {
        printf("No flag for you\n");
    }
    return 0;
}