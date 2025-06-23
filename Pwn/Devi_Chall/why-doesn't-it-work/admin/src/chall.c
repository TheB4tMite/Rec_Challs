#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <seccomp.h>
    


int main(void) {

    scmp_filter_ctx ctx;
    int rc = -1;
    ctx = seccomp_init(SCMP_ACT_KILL);
    if (ctx==NULL) {
        perror("seccomp initialization failed");
    seccomp_release(ctx);
    return -1;
    }

    
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0);
    if (rc<0) {
        perror("syscall failed to add");
        seccomp_release(ctx);
        return -1;
    }
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0); //
    if (rc<0) {
        perror("syscall failed to add");
        seccomp_release(ctx);
        return -1;
    }
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0); //
    if (rc<0) {
        perror("syscall failed to add");
        seccomp_release(ctx);
        return -1;
    }
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(close), 0);
    if (rc<0) {
        perror("syscall failed to add");
        seccomp_release(ctx);
        return -1;
    }
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
    if (rc<0) {
        perror("syscall failed to add");
        seccomp_release(ctx);
        return -1;
    }
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0);
    if (rc<0) {
        perror("syscall failed to add");
        seccomp_release(ctx);
        return -1;
    }
    rc = seccomp_load(ctx);
    if (rc<0) {
        perror("syscall failed to add");
        seccomp_release(ctx);
        return -1;
    }
    
    
    char code[0x100];
    const char* buff = ">>";
    write(1, buff, sizeof(buff)); 
    read(0, code, 0x1000);
    void (*shell)() = code;
    shell();
    return 0;
}