#include <stdio.h>
#include "static.h"

int main()
{
    s=10;
    printf("%d\n",s);
    show();
    set(10);
    show();
    printf("%d\n",get());
    set(11);
    show();
    printf("%d\n",get());
    
    return 0;
}

