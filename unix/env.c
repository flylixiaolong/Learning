#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[]) {
	int i = 0;
	for(i=0; argv[i]!=NULL; i++) {
		printf("%s\n", argv[i]);
	}

	for(i=0; environ[i]!=NULL; i++) {
		printf("%s\n", environ[i]);
	}
}
