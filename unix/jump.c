#include<stdio.h>
#include<setjmp.h>
#include<signal.h>

jmp_buf env;

void show(){
	printf("show longjmp\n");
	longjmp(env, 1);
}

int main(int argc, char* argv[]) { 
	if(setjmp(env) == 0) {
		printf("setjmp before\n");
		show();
	}else{
		printf("setjmp after\n");
	}
	return 0;
}
