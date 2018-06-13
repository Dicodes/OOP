#include <stdio.h>
#include <string.h>
#define MAX 5
typedef struct 
{
	char str[MAX][50];
	int f,r;
}Q;
void insertF(char s[],Q *pq)
{
	if(pq->f==0)
	{
		printf("OVERFLOW\n");
		return;
	}
	else
	{
		if(pq->f==-1)
		{
			pq->f=0;
			pq->r=0;
			strcpy(pq->str[pq->f],s);
		}	
		else
		{
			pq->f-=1;
			strcpy(pq->str[pq->f],s);
		}
	}

}
void insertR(char s[],Q *pq)
{
	if(pq->r==MAX-1)
	{
		printf("OVERFLOW\n");
		return;
	}
	else
	{
		if(pq->r==-1)
		{
			pq->f=0;
			pq->r=0;
			strcpy(pq->str[pq->r],s);
		}
		else
		{
			pq->r+=1;
			strcpy(pq->str[pq->r],s);
		}
	}
}
/*void deleteR(Q *pq)
{
	if(pq->f==-1&&pq->r==-1)
	{
		printf("UNDERFLOW\n");
		return;
	}
	char s[50];
	strcpy(s,pq->str[pq->r]);
	if(pq->r==pq->f)
	{
		pq->r=-1;pq->f=-1;
	}
	else
	{
		pq->r-=1;
	}
	printf("Deleted element: %s\n",s);
}*/
void deleteF(Q *pq)
{
	if(pq->f==-1&&pq->r==-1)
	{
		printf("UNDERFLOW\n");
		return;
	}
	char s[50];
	strcpy(s,pq->str[pq->f]);
	if(pq->r==pq->f)
	{
		pq->r=-1;pq->f=-1;
	}
	else
	{
		pq->f+=1;
	}
	printf("Deleted element: %s\n",s);

}
void display(Q q)
{
	int i;
	if(q.f==-1&&q.r==-1)
		printf("EMPTY QUEUE");
	for(i=q.f;i<=q.r;i++)
		printf("%s\t",q.str[i]);
	printf("\n");
}
void main()
{
	int choice;
	char s[50];
	Q q;
	q.f=-1;
	q.r=-1;
	do
	{
		printf("1.InsertF\t2.InsertR\n3.DeleteF\t4.Display\t5.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter element: ");
			scanf("%s",s);
			insertF(s,&q);
			break;
			case 2:printf("Enter element: ");
			scanf("%s",s);
			insertR(s,&q);
			break;
			case 3:deleteF(&q);
			break;
			case 4:display(q);
			break;
			case 5:break;
		}
	}while(choice!=5


		);
}