#pragma once

#include "common.h"

#define PROCS_MAX 8
#define PROC_UNUSED 0
#define PROC_RUNNABLE 1

struct process {
    int pid;
    int state;
    vaddr_t sp;
    uint8_t stack[8192];
};