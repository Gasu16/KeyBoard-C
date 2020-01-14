#include "interfaces.h"

/*** 
 * TO FIX: 
 * g_timer_destroy: assertion 'timer != NULL' failed
 * timer always remains 0, it doesn't start
 *  ***/


void set_up(){
	gtk_init(NULL, NULL);
	printf("L'ambiente GTK e' stato settato\n");
}

int key_counter = 0;
GTimer *gtimer;
glong microsec;

gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer data){
    key_counter++;
    if (event->keyval == GDK_KEY_Escape){
        g_printerr("ESC KEY PRESSED!\n");
        g_timer_stop(gtimer);
        g_timer_destroy(gtimer);
        gtk_main_quit();
        return TRUE;
    }
	gdouble sec = g_timer_elapsed(gtimer, &microsec);
    g_printerr("%s - %d volte\n", gdk_keyval_name(event->keyval), key_counter);
    g_printerr("Sono passati %lf secondi e %ld microsecondi\n", sec, microsec);
    return FALSE;
}


int main_gtk(int argc, char **argv){
	g_timer_new();
	//g_timer_start(gtimer);
	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window, "key_release_event", G_CALLBACK (my_keypress_function), NULL);
	
	//g_timeout_add_seconds(1, my_keypress_function, window);
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
