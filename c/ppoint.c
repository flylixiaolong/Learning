#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node *next;
	int num;
};

static struct Node *list;

static struct Node **find(int index)
{
	struct Node **p;
    for(p=&list;*p;p=&(*p)->next)
	{
//		printf("%d ",(*p)->num);
		if((*p)->num==index)
			break;
	}
//	printf("\n");
	return p;
}

static void destory()
{
	struct Node *p=list;
	printf("%d ",list->num);
	while(list&&(p=list->next))
	{
		printf("%d ",p->num);
		list->next=p->next;
		free(p);
	}
	printf("\n");
	free(list);
	list=NULL;
}
int main()
{
	struct Node **p;
	int i=0;
	for(i=0;i<100;i++)
	{
		p=find(i);
		if(!(*p))
		{
			(*p)=malloc(sizeof(struct Node));
			(*p)->next=NULL;
			(*p)->num=i;
		}
	}
	destory();
	return 0;
}


