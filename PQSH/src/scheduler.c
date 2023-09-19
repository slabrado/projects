/* scheduler.c: PQSH Scheduler */



#include "pqsh/macros.h"

#include "pqsh/scheduler.h"

#include "pqsh/timestamp.h"



#include <errno.h>

#include <sys/wait.h>



/**

 * Add new command to waiting queue.

 * @param   s	    Pointer to Scheduler structure.

 * @param   fs      File stream to write to.

 * @param   command Command string for new Process.

 **/

void scheduler_add(Scheduler *s, FILE *fs, const char *command) {

    /* TODO: Implement */
<<<<<<< HEAD

    Process *new;

    // Create new process

    new = process_create(command);

    // Add process to the waiting queue

    queue_push(&s->waiting, new);

    // Display confirmation to the file stream

    fprintf(fs, "Added process \"%s\" to waiting queue", command); 

=======
    Process *new;
    // Create new process
    new = process_create(command);
    // Add process to the waiting queue
    queue_push(&s->waiting, new);
    // Display confirmation to the file stream
    fprintf(fs, "Added process \"%s\" to waiting queue", command); 
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
}



/**

 * Display status of queues in Scheduler.

 * @param   s	    Pointer to Scheduler structure.

 * @param   fs      File stream to write to.

 * @param   queue   Bitmask specifying which queues to display.

 **/

void scheduler_status(Scheduler *s, FILE *fs, int queue) {
<<<<<<< HEAD

    fprintf(fs, "Running = %4lu, Waiting = %4lu, Finished = %4lu, Turnaround = %05.2lf, Response = %05.2lf\n", s->running.size, s->waiting.size, s->finished.size, s->total_turnaround_time, s->total_response_time );

    /* TODO: Complete implementation. */

    if (queue == RUNNING) {

        fprintf(fs, "Running Queue: \n");

        queue_dump(&s->running, fs);

    } else if (queue == WAITING) {

        fprintf(fs, "Waiting Queue: \n");

        queue_dump(&s->waiting, fs);

    } else {

        fprintf(fs, "Finished Queue: \n");

        queue_dump(&s->finished, fs);

    }

   

=======
    fprintf(fs, "Running = %4lu, Waiting = %4lu, Finished = %4lu, Turnaround = %05.2lf, Response = %05.2lf\n\n", s->running.size, s->waiting.size, s->finished.size, s->total_turnaround_time / s->finished.size, s->total_response_time / s->finished.size);
    // Display Running queue metrics
    if ((queue == RUNNING) && (s->running.size != 0)) {
        fprintf(fs, "Running Queue: \n");
        queue_dump(&s->running, fs);
    // Display Waiting queue metrics
    } else if ((queue == WAITING) && (s->waiting.size != 0)) {
        fprintf(fs, "Waiting Queue: \n");
        queue_dump(&s->waiting, fs);
    // Display Finished queue metrics 
    } else if ((queue == FINISHED) && (s->finished.size != 0)){
        fprintf(fs, "Finished Queue: \n");
        queue_dump(&s->finished, fs);
    // Dsiplay metrics for occupied queues
    } else if (queue == 0) {
        if (s->running.size > 0) {
            fprintf(fs, "Running Queue: \n");
            queue_dump(&s->running, fs);
        } else if (s->waiting.size > 0) {
            fprintf(fs, "Waiting Queue: \n");
            queue_dump(&s->waiting, fs);
        } else if (s->finished.size > 0) {
            fprintf(fs, "Finished Queue: \n");
            queue_dump(&s->finished, fs);
        }
    }
   
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
}



/**

 * Schedule next process using appropriate policy.

 * @param   s	    Pointer to Scheduler structure.

 **/

void scheduler_next(Scheduler *s) {
<<<<<<< HEAD

    /* TODO: Dispatch to appropriate scheduler function. */

    if (s->policy == FIFO_POLICY) {

        scheduler_fifo(s);

    } else if (s->policy == RDRN_POLICY) {

        scheduler_rdrn(s);

    }

=======
    // Schedule next process with FIFO policy if indicated by the user
    if (s->policy == FIFO_POLICY) {
        scheduler_fifo(s);
    // Schedule next process with Round Robin if indicated by the user
    } else if (s->policy == RDRN_POLICY) {
        scheduler_rdrn(s);
    }
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
}



/**

 * Wait for any children and remove from queues and update metrics.

 * @param   s	    Pointer to Scheduler structure.

 **/

void scheduler_wait(Scheduler *s) {
<<<<<<< HEAD

    /* TODO: Wait for any children without blocking:

     *

     *  - Remove process from queues.

     *  - Update Process metrics.

     *  - Update Scheduler metrics.

     **/

    pid_t pid;

   // Determines if a process has terminated

    double end;

    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0) {

        // Removes the terminated process from the running queue

        Process *found = queue_remove(&s->running, pid);

        // Update Process metrics 

        end  = timestamp();

        found->end_time = end;

        // Update Scheduler metrics

        s->total_turnaround_time = found->end_time - found->arrival_time;

        s->total_response_time = found->start_time - found->arrival_time;

        // Move the process to the finished queue

        queue_push(&s->finished, found);

    }

=======
    pid_t pid;
   // Determines if a process has terminated
    double end;
    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0) {
        // Removes the terminated process from the running queue
        Process *found = queue_remove(&s->running, pid);
        // Update Process metrics 
        end  = timestamp();
        found->end_time = end;
        // Update Scheduler metrics
        s->total_turnaround_time += found->end_time - found->arrival_time;
        s->total_response_time += found->start_time - found->arrival_time;
        // Move the process to the finished queue
        queue_push(&s->finished, found);
    }
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
}



/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */
