#ifndef _STATIC_H
#define _STATIC_H

#include <stdio.h>

static int s=0;
void set(int i);
int get();
void show();
void inset(int i){s=i;}
int inget(){return s;}
void inshow(){printf("%d\n",s);}

#endif

