#include "wq.h"

int isp(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

int count(char *s) {
    int c = 0;
    unsigned char x = 0;
    while (*s) {
        if (!isp(*s) && !x) {
            c++;
            x = 1;
        } else if (isp(*s)) {
            x = 0;
        }
        s++;
    }
    return c;
}

int run(int argc, char **args) {
    if (isatty(0)) {
        int c = 0;
        for (int i = 1; i < argc; i++) {
            c += count(args[i]);
        }
        printf("Total word count is: %d\n", c);
    } else {
        char buffer[MAX];
        ssize_t b_r = read(0, buffer, MAX);
        buffer[b_r] = '\0';
        printf("Total word count is: %d\n", count(buffer));
    } 
    return 0;
}
