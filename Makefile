CC=gcc
CFLAGS=-I.

outpostagent:
	$(CC) -o outpostagent main.c outpost.h procs.h procs.c -I.
