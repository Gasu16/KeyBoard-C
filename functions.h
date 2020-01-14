#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <limits.h>
#include <sys/types.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <signal.h>



#define BUF_SIZE 100000000
#define CURRENT_SIZE(x) (sizeof(x) / sizeof(x[0]))

extern char *key;
extern time_t start, finish;
extern struct tm *timeinfo;
extern double run_time;
extern double i;

void isNull(char *key);
int function();

#endif /* FUNCTIONS_H */
