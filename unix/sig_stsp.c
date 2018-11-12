#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_stsp(int sino) {
	sigset_t sig_old, sig_set;
	sigprocmask(0, NULL, &sig_old);
	printf("%u\n", sig_old);
}

int main() {
	signal(SIGTSTP, sig_stsp);
	while(1){
		sleep(1);
		printf("live\n");
	}
	return 0;
}
