#include "functions.h"


void isNull(char *key){
	if(!key){
		printf("Si e' verificato un errore - errno: %d\n", errno);
		perror("Allocation was not succesful...\n");
		exit(EXIT_FAILURE);
	}
	
}



int function(){
	time_t start, finish;
	struct tm *timeinfo;
	double run_time = 0;
	double i = 0;

	time(&start);
	timeinfo = localtime(&start);
	printf("Current local time and date: %s", asctime (timeinfo));

	char *key = malloc(sizeof(char *)*BUF_SIZE);
	printf("FUNZIONA\n");
	
	// check if key is null
	isNull(key);

	memset(key, 0, sizeof(char *)*BUF_SIZE);

	while(1){

		signal(SIGALRM, SIG_IGN);
		alarm(1);

		time(&finish);
		timeinfo = localtime(&finish);
		run_time = difftime(finish, start);
		
		*key = getchar();		
		i++;

		if(*key=='\n'){
			
			printf("Finora sono stati digitati %.0lf caratteri in %.0lf secondi\n", i, run_time);
		}
		
		/**
		 * getchar() in a loop
		 * avoid printing everytime I get a character
		 * **/
		 
		 /** La seguente condizione di uscita 
		  *  sara' poi da togliere 
		  *  per fare girare il programma in background 
		  * **/
		if(*key==27){
			printf("Finora sono stati digitati %.0lf caratteri in %.0lf secondi\n", i, run_time);
			printf("La media e' di %.2lf caratteri al secondo", (double)(i/run_time));
			break;
		}
	}
	
	exit(EXIT_SUCCESS);
}


