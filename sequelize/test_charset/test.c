#include <stdlib.h>
#include <stdio.h>

void mycat(char* a, const char* b) {
    while(*(++a));
    // while(*++a=*++b);
}

int main() {
    char *array[2] = {"abc", "def"};
    char * path = getenv("PATH");
    printf("%s\n", "abc");
    printf("%s\n", path);
    char * s = "abc";
    char * p = s;
    while(*p) {
        printf("%s\n", p);
        p++;
    }
    char *d = "abcdefg";
    while(*(++d));
    char a[100]="abcd";
    char b[10]="def";
    mycat(a,b);
    printf("%s\n", a);
    int i=0,j=0;
    while((i=j)==0){
        printf("yes\n");
    }
    return 0;
}

