#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
	int data;
	struct node *link;

}NODE;
NODE* insertRear(int ele,NODE *head)
{
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	NODE *cur;
	cur=head;
	temp->data=ele;
	temp->link=NULL;
	int i;
	if(head->data==0)
		head->link=temp;
	else
	{
		for(i=1;i<=head->data;i++)
			cur=cur->link;
		cur->link=temp;
	}
	head->data+=1;
	return head;
}
NODE * deleteFront(NODE *head)
{
	if(head->data!=0)
	{
		printf("Deleted element is: %d\n",head->link->data);
		head->link=head->link->link;
	}
	else
	{
		printf("Empty queue\n");
		return head;
	}
	head->data-=1;
	return head;
}
void display(NODE *head)
{
	int i;
	if(head->data==0)
	{
		printf("EMPTY LIST!\n");
		return;
	}
	NODE *cur=head;
	for(i=1;i<=head->data;i++)
	{
		cur=cur->link;
		printf("%d\t",cur->data);
	}
	printf("\n");
}
void main()
{
	NODE *head;
	head->data=0;
	head->link=NULL;
	int n,ele;
	do
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("Enter element to be inserted:\n");
			scanf("%d",&ele);
			head=insertRear(ele,head);
			break;
			case 2:deleteFront(head);
			break;
			case 3:display(head);
			break;
			case 4:break;
		}
	}while(n!=4);

}