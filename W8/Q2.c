#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	char ch;
	struct node *link;

}NODE;
NODE* NewList(NODE *head1,NODE* head2)
{
	NODE *cur1=head1->link;
	NODE *cur2=head2->link;
	NODE *head=(NODE*)malloc(sizeof(NODE));
	head->ch='0';
	head->link=head;
	NODE *cur;
	cur=head;
	int n;
	while(cur1!=head1 && cur2!=head2)
	{
		if(cur1->ch <= cur2->ch)
		{
			cur->link=cur1;
			cur1=cur1->link;
		}
		else
		{
			cur->link=cur2;
			cur2=cur2->link;
		}
		n=(int)head->ch;
		n+=1;
		head->ch=(char)n;
		cur=cur->link;
	}
	while(cur1!=head1)
	{
		cur->link=cur1;
		cur1=cur1->link;
		n=(int)head->ch;
		n+=1;
		head->ch=(char)n;
		cur=cur->link;

	}
	while(cur2!=head2)
	{
		cur->link=cur2;
		cur2=cur2->link;
		n=(int)head->ch;
		n+=1;
		head->ch=(char)n;
		cur=cur->link;

	}
	return head;
}
void display(NODE *head)
{
	int i;
	NODE *cur=head->link;
	if(head->ch-'0'==0)
	{
		printf("EMPTY LIST!\n");
		return;
	}
	for(i=1;i<=(int)head->ch-'0';i++)
	{
		printf("%c\t",cur->ch);
		cur=cur->link;
	}
	printf("\n");
}
NODE * insertRear(char ele,NODE *head)
{
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	temp->ch=ele;
	temp->link=head;
	NODE *cur;
	cur=head;
	int n;
	if(head->ch=='0')
		head->link=temp;
	else
	{
		while(cur->link!=head)
			cur=cur->link;
		cur->link=temp;
	}
	n=(int)head->ch;
	n+=1;
	head->ch=(char)n;
	return head;
}
void main()
{
	NODE *head1,*head2,*head;
	head1=(NODE*)malloc(sizeof(NODE));
	head2=(NODE*)malloc(sizeof(NODE));
	head1->ch='0';
	head2->ch='0';
	head1->link=head1;
	head2->link=head2;
	int n,i;
	char ele;
	printf("Enter size of first list:\n");
	scanf("%d",&n);
	scanf("%c",&ele);
	printf("Enter character list 1:\n");
	for(i=0;i<n;i++)
	{
		scanf("%c",&ele);
		head1=insertRear(ele,head1);
		scanf("%c",&ele);

	}
	printf("Enter size of second list:\n");
	scanf("%d",&n);
	scanf("%c",&ele);
	printf("Enter character list 2:\n");
	for(i=0;i<n;i++)
	{
		scanf("%c",&ele);
		head2=insertRear(ele,head2);
		scanf("%c",&ele);

	}
	printf("list 1\n");
	display(head1);
	printf("list 2\n");
	display(head2);
	printf("After merging\n");
	head=NewList(head1,head2);
	display(head);



}