#include <stdio.h>

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

int main() {

    init();

    char buf[128];

    printf("Enter your shellcode: ");
    
    fgets(buf, 128, stdin);

    void (*exe)(void) = buf;
    exe();

    return 0;
}