all: 
	gcc -lpthread `pkg-config --cflags gtk+-3.0` -o keyboardcounterC keyboardcounterC.c functions.c interfaces.c `pkg-config --libs gtk+-3.0`



