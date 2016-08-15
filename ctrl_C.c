#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

volatile sig_atomic_t eflag = 1;

void handler(int signum){
	printf("\nreceived ctrl+c\n");
	printf("call exit()\n");
	eflag = 0;
	exit(EXIT_SUCCESS);
	// EXIT_suCCESS -> $B@.8y=*N;(B
	// EXIT_FAILURE -> $B<:GT=*N;(B
}


int main(){
	if(signal(SIGINT, handler) == SIG_ERR){
		printf("call signal() error!\n");
	}

	while(eflag){
		printf("waiting...\n");
		sleep(1);
	}

		printf("-end main-\n");

return 0;
}
