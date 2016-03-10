#include<stdio.h>
struct Dog{
    int a;
    int b;
};
int main(){
    struct Dog d={1,2};
    printf("%d,%d\n",d.a,d.b);
    return 0;
}
