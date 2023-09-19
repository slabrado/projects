/* scheduler_fifo.c: PQSH FIFO Scheduler */



#include "pqsh/macros.h"

#include "pqsh/scheduler.h"



#include <assert.h>



/**

 * Schedule next process using fifo policy:

 *

 *  As long as we have less running processes than our number of CPUS and

 *  there are waiting processes, then we should move a process from the

 *  waiting queue to the running queue.

 *

 * @param   s	    Scheduler structure

 */

void scheduler_fifo(Scheduler *s) {
<<<<<<< HEAD

    /* TODO: Implement FIFO Policy */

    /* ERROR CHECKING?*/

    //const char *command;

    Process *pro;

    //pro = process_create(s->);

    while ((s->running.size < s->cores) && (s->waiting.size > 0)) {

        pro = queue_pop(&s->waiting);

        process_start(pro);

       // scheduler_next(process);

        queue_push(&s->running, pro);

    }



=======
    Process *pro;
    while ((s->running.size < s->cores) && (s->waiting.size > 0)) {
        pro = queue_pop(&s->waiting);
        if (process_start(pro) == false) {
            break;
        }
        queue_push(&s->running, pro);
    }

>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
}



/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */
