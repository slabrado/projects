/* timestamp.c: PQSH Timestamp */

#include "pqsh/timestamp.h"

#include <time.h>
#include <sys/time.h>

/**
 * Return current timestamp as a double.
 *
 * Utilizes gettimeofday for precision (accounting for seconds and
 * microseconds) and falls back to time (only account for seconds) if that
 * fails.
 *
 * @return  Double representing the current time.
 **/
double timestamp() {
<<<<<<< HEAD
=======
    /* TODO: Implement */
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    struct timeval current;
    
    if (gettimeofday(&current, NULL) < 0){
        return time(NULL);
    }

    return current.tv_sec + (current.tv_usec/1000000.0);
}

/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */
