
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node * rlink,*llink;
}NODE;
void displaynos(NODE *num)
{
	NODE* cur=num->rlink;
	do
	{
		printf("%d",cur->data);
		cur=cur->rlink;
	}while(cur!=num->rlink);
	
}
void displaysum(NODE *sum)
{
	NODE* cur=sum;
	do
	{
		printf("%d",cur->data);
		cur=cur->rlink;
	}while(cur!=sum);
}
NODE* insertRear(int n, NODE* num)
{
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	temp->data=n;
	if(num==NULL)
	{
		temp->rlink=temp;
		temp->llink=temp;
		return temp;
	}
	temp->llink=num;
	temp->rlink=num->rlink;
	num->rlink->llink=temp;
	num->rlink=temp;
	return temp;

}
NODE* insertFront(int n, NODE *sum)
{
	NODE* temp=(NODE *)malloc(sizeof(NODE));
	temp->data=n;
	if(sum==NULL)
	{
		temp->rlink=temp;
		temp->llink=temp;
		return temp;
	}
	temp->rlink=sum;
	temp->llink=sum->llink;
	sum->llink->rlink=temp;
	sum->llink=temp;
	
	return temp;
}
void main()
{
	NODE *num1=NULL, *num2=NULL, *sum=NULL;
	int add=0;
	int n1,n2;
	int carry=0;
	int i;
	printf("Enter number and -1 to stop\n");
	for(i=0;i<50;i++)
	{
		scanf("%d",&n1);
		if(n1==-1)
			break;
		
		num1=insertRear(n1,num1);
		
	}
	printf("Enter number and -1 to stop\n");
	for(i=0;i<50;i++)
	{
		scanf("%d",&n2);
		if(n2==-1)
			break;
		
		num2=insertRear(n2,num2);
		
	}
	NODE *cur1=num1,*cur2=num2;
	do
	{
		add=cur1->data+cur2->data+carry;
		sum=insertFront(add%10,sum);
		carry=add/10;
		cur1=cur1->llink;
		cur2=cur2->llink;
	}while(cur1!=num1 && cur2!=num2);
	while(cur1!=num1)
	{
		add=carry+cur1->data;
		cur1=cur1->llink;
		sum=insertFront(add%10,sum);
		carry=add/10;
	}
	while(cur2!=num2)
	{
		add=carry+cur2->data;
		cur2=cur2->llink;
		sum=insertFront(add%10,sum);
		carry=add/10;
	}
	if(carry==1)
		sum=insertFront(carry,sum);
	displaynos(num1);
	printf("\n");
	displaynos(num2);
	printf("\n");
	displaysum(sum);


}