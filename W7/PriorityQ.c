#include <stdio.h>
#include <stdlib.h>
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
void pqmindelete(Q *q)
{
	
	int i,j;
	int min,minpos;
	if(q->f==-1&&q->r==-1)
	{
		printf("Underflow\n");
		return;
	}
	min=q->x[q->f];
	minpos=q->f;
	for(i=q->f;i<=q->r;i++)
	{
		if(q->x[i]<min)
		{
				min=q->x[i];
				minpos=i;
		}
	}
	printf("Element deletd:%d\n",q->x[minpos]);
	for(j=minpos;j>q->f;j--)
	{
		q->x[j]=q->x[j-1];
	}
	if(q->f==q->r)
	{
		q->f=-1;
		q->r=-1;
	}
	else
	q->f++;
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
			case 2:pqmindelete(&q);
			break;
			case 3:display(q);
			break;
			case 4:break;
			default:printf("Invalid\n");
		}
	}while(ch!=4);
}