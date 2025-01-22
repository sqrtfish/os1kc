#include "process.h"

struct process procs[PROCS_MAX];

struct process *create_process(uint32_t pc) {
    // find an unused process control structure.
    struct process *proc = NULL;
    int i;
    for(i = 0; i < PROCS_MAX; i++) {
        if(procs[i].state == PROC_UNUSED) {
            proc = &proc[i];
            break;
        }
    }

    if(!proc) PANIC("no free process slots");
}