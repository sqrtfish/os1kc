#include "user.h"

// extern char _binary_shell_bin_start[];
// extern char _binary_shell_bin_size[];

void main(void) {
    // *((volatile int *) 0x80200000) = 0x1234;
    while (1) {
prompt:
        printf("> ");
        char cmdline[128];
        for (int i = 0;; i++) {
            char ch = getchar();
            putchar(ch);
            if (i == sizeof(cmdline) - 1) {
                printf("command line too long\n");
                goto prompt;
            } else if (ch == '\r') {
                // one the debug console the newline character is '\r'
                printf("\n");
                cmdline[i] = '\0';
                break;
            } else {
                cmdline[i] = ch;
            }
        }

        if (strcmp(cmdline, "hello") == 0) {
            printf("hello world from shell\n");
        } else if (strcmp(cmdline, "exit") == 0) {
            exit();
        } else if (strcmp(cmdline, "readfile") == 0) {
            char buf[128];
            int len = readfile("hello.txt", buf, sizeof(buf));
            buf[len] = '\0';
            printf("%s\n", buf);
        } else if (strcmp(cmdline, "writefile") == 0) {
            writefile("hello.txt", "Hello from shell!\n", 19);
        } else {
            printf("unknown command: %s\n", cmdline);
        }
    }
    // printf("Hello World from shell!\n");
    // for (;;);
    // uint8_t *shell_bin = (uint8_t *) _binary_shell_bin_start;
    // printf("shell_bin size = %d\n", (int) _binary_shell_bin_size);
    // printf("shell_bin[0] = %x (%d bytes)\n", shell_bin[0]);
}