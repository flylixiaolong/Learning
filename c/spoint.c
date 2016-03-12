#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node *next;
	int num;
};

static struct Node *list;

static struct Node **find(int num)
{
	struct Node **p;
	for(p=&list;*p;*p=(*p)->next)
	{
		if((*p)->num==num)
		{
			break;
		}
	}
	return p;
}

static void destory()
{
	struct Node *p;
	while(list&&(p=list->next))
	{
		list=p;
		free(p);
	}
	free(list);
	list=NULL;
}
int main()
{
	int i=0;
	struct Node **p,*e;
    for(i=0;i<100;i++)
	{
		p=find(i);
		if(!(*p))
		{
			*p=malloc(sizeof(struct Node));
			(*p)->next=NULL;
			(*p)->num=i;
			printf("%d\n",i);
		}
	}
	destory();
	return 0;
}
