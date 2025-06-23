#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int secret(void) {
    char *args[] = {"cat", "flag.txt", NULL};
    printf("Congragts!\n");
    printf("You found the secret!\n");
    execvp("cat", args);
}

void segfault_handler() {
    write(0,"Aww! Dang it! You were so close!", strlen("Aww! Dang it! You were so close!"));
    exit(0);
}

int main(void) {
    char buff[32];
    signal(SIGSEGV, segfault_handler);
    printf("There is a secret in this system. Can you find it out??\n");
    sleep(2);
    read(0, buff, 60);
    return(0);
}