#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sighandler(int sig) {
    FILE *file = fopen("flag.txt", "r");
    char buf[32];

    fgets(buf, 32, file);
    printf("Good job, here is you flag %s\n", buf);
    exit(0);
}

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

int main() {

    init();
    
    signal(SIGSEGV, sighandler);

    char buf[128];
    printf("Enter your name : ");
    gets(buf);
    printf("Your name is: %s\n", buf);

    return 0;
}