#include <stdio.h>

#include "outpost.h"
#include "procs.h"

#define MAX_PROCS 1024

int main() {
    proc_t *procs[MAX_PROCS];
    int i;
    
    if(get_procs(procs, MAX_PROCS) == -1) {
        return 1;
    }

    for(i = 0; i < MAX_PROCS; i++) {
        if(procs[i] == NULL) {
            break;
        }

        printf("Running process: %s\n", procs[i]->name);
    }

    return 0;
}