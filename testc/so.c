#include<stdio.h>
int *func1(){
    static int a[4]={1,2,3,4};
    int i=0;
    for(i=0;i<4;i++){
        printf("a[%d]=%d\n",i,a[i]);
        a[i]++;
    }
    return a;
};
int main(){
    int *(*fun1)()=&func1;
    //printf("%u",&fun1()[0]);
    int *a=(*fun1)();
    printf("%d,%d,%d,%d\n",a[0],a[1],a[2],a[3]);
    return 0;
}

