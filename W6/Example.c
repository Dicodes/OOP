#include <stdio.h>
#define MAX 50
typedef struct
{
	int x[MAX];
	int f,r;
}Q;
void insertq(int x,Q *q)
{
	if(q->r==MAX-1)
		printf("OVERFLOW\n");
	else
	{
		q->x[++q->r]=x;
		if(q->f==-1)
			q->f=0;
	}
}
int deleteq(Q *q)
{
	int x;
	if(q->f==-1)
	{
		printf("UNDERFLOW\n");
		return -999;
	}
	else if(q->f==q->r)
	{
		x=q->x[q->f];
		q->f=-1;
		q->r=-1;
	}
	else
	{
		x=q->x[q->f++];
	}
	return x;
}
void display(Q q)
{
	int i;
	if(q.f==-1&&q.r==-1)
		printf("EMPTY QUEUE\n");
	else
	{
		for(i=q.f;i<=q.r;i++)
			printf("%d\t",q.x[i]);
	}
	printf("\n");
}
void main()
{
	Q q;
	q.f=-1;
	q.r=-1;
	int ch,ele;
	do
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to insert:\n");
			scanf("%d",&ele);
			insertq(ele,&q);
			break;
			case 2:ele=deleteq(&q);
			if(ele!=-999)
				printf("Element deleted:%d\n",ele);
			else
				printf("Empty Queue");
			break;
			case 3:display(q);
			break;
			case 4:break;
			default:printf("Invalid\n");
		}
	}while(ch!=4);
}