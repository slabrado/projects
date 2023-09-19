/* thor.c */

#include "hammer.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Functions */

void usage(const char *progname, int status) {
    fprintf(stderr, "Usage: %s [options] URL\n", progname);
    fprintf(stderr, "    -n HAMMERS How many times to hammer the URL\n");
    exit(status);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    /* TODO: Parse command line arguments */
    int N = 1;
    char *url = "";
    if (argc == 1){
        usage(argv[0], 1);
    }
    for (int i = 1; i < argc; i++){
        if (streq(argv[i], "-h")) {
            usage(argv[0], 0);
        } else if (streq(argv[i], "-n")) {
            N = atoi(argv[i+1]);
            url = argv[i+2];
            break;
        } else if (argv[i][0] == '-') {
            usage(argv[0], 1);
        } else {
            url = argv[i];
            break;
        }
    }
    /* TODO: Throw Hammers */
    if (throw(url, N, stdout)){
        return EXIT_SUCCESS;
    } 
    return EXIT_FAILURE;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
