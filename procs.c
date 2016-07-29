#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "outpost.h"

#define BUFFER_SIZE 512

int get_procs(proc_t *procs[], size_t max) {
    char *cmd = "ps -e -o command";
    char buffer[BUFFER_SIZE];
    int i = 0, len = 0, first = 1;
    FILE *fp;

    if((fp = popen(cmd, "r")) == NULL) {
        printf("error: could not open ps\n");
        return -1;
    }

    while(fgets(buffer, BUFFER_SIZE, fp) != NULL && i < max) {
        if(first == 1) {
            // skip first line, contains column name ('command')
            first = 0;
            continue;
        }

        len = strlen(buffer);
        procs[i] = malloc(sizeof(proc_t));
        procs[i]->name = malloc(sizeof(char) * len);         
        strncpy(procs[i]->name, buffer, len - 1);

        i++;
    }
}