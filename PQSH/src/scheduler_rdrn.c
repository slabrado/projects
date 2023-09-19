/* scheduler_rdrn.c: PQSH Round Robin Scheduler */



#include "pqsh/macros.h"

#include "pqsh/scheduler.h"



#include <assert.h>



/**

 * Schedule next process using round robin policy:

 *

 *  1. If there no waiting processes, then do nothing.

 *

 *  2. Move one process from front of running queue and place in back of

 *  waiting queue.

 *

 *  3. Move one process from front of waiting queue and place in back of

 *  running queue.

 *

 * @param   s	    Scheduler structure

 **/

void scheduler_rdrn(Scheduler *s) {
<<<<<<< HEAD

    /* TODO: Implement Round Robin Policy */

    /* ERROR CHECKING?*/

    Process *pro;

    if (s->running.size == s->cores) {

        pro = queue_pop(&s->running);

        process_pause(pro);

        queue_push(&s->waiting, pro);

    }



    while ((s->running.size < s->cores) && (s->waiting.size > 0)) {

        pro = queue_pop(&s->waiting);

        if (pro->pid == 0) {

            process_start(pro);

        } else {

            process_resume(pro);

        }



        queue_push(&s->running, pro);

    }

}





=======
    // Initialize a process pro
    Process *pro;
    // Moving process from front of running queue to back of waiting queue
    if (s->running.size == s->cores) {
        pro = queue_pop(&s->running);
        if (process_pause(pro) == false) {
            return;
        }
        queue_push(&s->waiting, pro);
    }
    // Moving process from front of waiting queue to back of running queue
    while ((s->running.size < s->cores) && (s->waiting.size > 0)) {
        pro = queue_pop(&s->waiting);
        if (pro->pid == 0) {
            if (process_start(pro) == false) {
                break;
            }
        } else {
            if (process_resume(pro) == false) {
                break;
            }
        }
        queue_push(&s->running, pro);
    }
}


>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */


