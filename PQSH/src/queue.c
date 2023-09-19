/* queue.c: PQSH Queue */

#include "pqsh/macros.h"
#include "pqsh/queue.h"

#include <assert.h>

/**
 * Push process to back of queue.
 * @param q     Pointer to Queue structure.
 **/
void        queue_push(Queue *q, Process *p) {
<<<<<<< HEAD
    
=======
    /* TODO: Implement */
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    //if queue is empty
    if (q->head == NULL) {
        q->head = p;
        q->tail = p;
        q->size = 1;
        return;
    }
    
    //if queue not empty
    q->tail->next = p;
    q->tail = q->tail->next;
    q->size++;
    return;
}

/**
 * Pop process from front of queue.
 * @param q     Pointer to Queue structure.
 * @return  Process from front of queue.
 **/
Process *   queue_pop(Queue *q) {
<<<<<<< HEAD
    
=======
    /* TODO: Implement */
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    //if queue empty
    if (q->size == 0){
        return NULL;
    }

    //if queue not empty
    Process *p = q->head;
    q->head = q->head->next;
    q->size--;
<<<<<<< HEAD
=======
    p->next = NULL;
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    return p;
}

/**
 * Remove and return process with specified pid.
 * @param q     Pointer to Queue structure.
 * @param pid   Pid of process to return.
 * @return  Process from Queue with specified pid.
 **/
Process *   queue_remove(Queue *q, pid_t pid) {
<<<<<<< HEAD

=======
    /* TODO: Implement */
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    //check if head exists
    if (!q->head){
        return NULL;
    }
    
    //check head
    if (q->head->pid == pid){
        return queue_pop(q);
    }

    //prepare for loop
    Process *curr = q->head;
    Process *prev = curr;
    curr = curr->next;
    
    //loop through queue until pid is found
    while (curr){
        if (curr->pid == pid){
            prev->next = curr->next;
            curr->next = NULL;
            q->size--;
            return curr;
        }
        prev = curr;
        curr = curr->next;
    }
    
    //return NULL if pid is not found
    return NULL;
}

/**
 * Dump the contents of the Queue to the specified stream.
 * @param q     Queue structure.
 * @param fs    Output file stream.
 **/
void        queue_dump(Queue *q, FILE *fs) {
<<<<<<< HEAD
    
    //print header
    fprintf(fs, "%6s %-30s %-13s %-13s %-13s\n", 
                "PID", "COMMAND", "ARRIVAL", "START", "END");

=======
    fprintf(fs, " %6s %-30s %-13s %-13s %-13s\n", 
                "PID", "COMMAND", "ARRIVAL", "START", "END");
    /* TODO: Display information for each item in Queue. */
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    //check if head exists
    if (!q->head){
        return;
    }
    
    //prepare for loop
    Process *curr = q->head;
<<<<<<< HEAD
    curr = curr->next;
    
    //loop through queue until pid is found
    while (curr){
        fprintf(fs, "%6d %-30s %-13f %-13f %-13f\n", 
=======
    //curr = curr->next;
    
    //loop through queue until pid is found
    while (curr){
        fprintf(fs, "%6d %-30s %-13.2f %-13.2f %-13.2f\n", 
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
                curr->pid, curr->command, curr->arrival_time, curr->start_time, curr->end_time);
        curr = curr->next;
    }
}

/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */
