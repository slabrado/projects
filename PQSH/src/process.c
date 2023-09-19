/* process.c: PQSH Process */

#include "pqsh/macros.h"
#include "pqsh/process.h"
#include "pqsh/timestamp.h"

#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

/**
 * Create new process structure given command.
 * @param   command     String with command to execute.
 * @return  Pointer to new process structure
 **/
Process *process_create(const char *command) {
<<<<<<< HEAD
    
    //allocate space for new process
    Process *new = malloc(sizeof(Process));
=======
    /* TODO: Implement */
    //allocate space for new process
    Process *new = malloc(sizeof(Process));
    if (new == NULL) {
        free(new);
        return NULL;
    }
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    //copy command
    strcpy(new->command, command);
    //new process always enters waiting queue
    new->arrival_time = timestamp();
    //set start and end to 0
    new->start_time = 0;
    new->end_time = 0;
    //set PID (process hasn't been called yet)
    new->pid = 0;
    //set next process
    new->next = NULL;

    //return pointer
    return new;
}

/**
 * Start process by forking and executing the command.
 * @param   p           Pointer to Process structure.
 * @return  Whether or not starting the process was successful
 **/
bool process_start(Process *p) {
<<<<<<< HEAD

    //fork process
    pid_t pid = fork();
    p->pid = pid;
    
=======
    /* TODO: Implement */
    //fork process
    pid_t pid = fork();
    p->pid = pid;

>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    //fork fails
    if (p->pid < 0) {
        exit(1);
        return false;
    }
<<<<<<< HEAD
    
=======

>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    //child
    if (p->pid == 0){
        //parse command
        char *argv[MAX_ARGUMENTS] = {0};
        int i = 0;
        for (char *token = strtok(p->command, " "); token; token = strtok(NULL, " ")) {
            argv[i++] = token;
        }
        //execute new command
        execvp(argv[0], argv);
        //exit if execvp fails
        exit(1);
    //parent
    } else {
        p->start_time = timestamp();
        //int status;
        //pid_t pid;
        //while((pid = (waitpid(p->pid, &status, WNOHANG)) < 0));
        return true;
    }

    return false;
}

/**
 * Pause process by sending it the appropriate signal.
 * @param   p           Pointer to Process structure.
 * @return  Whether or not sending the signal was successful.
 **/
bool process_pause(Process *p) {
    if (kill(p->pid, SIGSTOP) < 0){
        return false;
    } 
    return true;
}

/**
 * Resume process by sending it the appropriate signal.
 * @param   p           Pointer to Process structure.
 * @return  Whether or not sending the signal was successful.
 **/
bool process_resume(Process *p) {
<<<<<<< HEAD
=======
    /* TODO: Implement */
>>>>>>> de2f42d28b07e3f07ccdc4099e9b19e215d6b95d
    if (kill(p->pid, SIGCONT) < 0){
        return false;
    }
    return true;
}

/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */
