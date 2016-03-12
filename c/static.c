#include <stdio.h>
#include "static.h"

void set(int i)
{
    s=i;
}
int get()
{
    return s;
}
void show()
{
    printf("%d\n",s);
}
