#include <stdio.h>

void printc(const char* str) {
	char *p = (char *)str;
	while(*p){
		printf("%c,", *p);
		p++;
	}
	printf("\n");
}

int main() {
	char *p[] = {"abc", "def", "ghi", NULL};
	printf("%p\n", p);
	printf("%p\n", p[0]);
	printf("%p\n", p[1]);
	printf("%p\n", p[2]);
	printf("%p\n", p[3]);
	for(int i=0; p[i]!=NULL; i++) {
		printf("%p=>%s\n",p[i], p[i]);
		printc(p[i]);
	}

	while(p!=NULL) {
		printf("%s", *p);
		p++;
	}
}


