#ifndef INTERFACES_H
#define INTERFACES_H

#include "functions.h"

/** SETTING UP AN INTERFACE ENVIRONMENT 
 *  USING GTK v3.0
 *  
 * **/

extern int key_counter;
extern GTimer *gtimer;
extern glong microsec;

void set_up();

int main_gtk(int argc, char **argv);

gboolean my_keypress_function (GtkWidget *widget, GdkEventKey *event, gpointer data);

#endif /* INTERFACES_H */
