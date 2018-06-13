#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	int data;
	struct node *rlink,*llink;
}NODE;
NODE* insert(int item,NODE *root)
{
	char direction[10];
	int i;
	NODE *temp,*cur,*prev;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=item;
	temp->llink=temp->rlink=NULL;
	if(root==NULL)
		return temp;
	printf("Give insertion directions:\n");
	scanf("%s",direction);
	//strupper(direction);
	prev=NULL;
	cur=root;
	for(i=0;i<strlen(direction) && cur!=NULL;i++)
	{
		prev=cur;
		if(direction[i]=='L'||direction[i]=='l')
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(cur!=NULL || i!=strlen(direction))
	{
		printf("CANNOT INSERT\n");
		free(temp);
		temp=NULL;
		return root;
	}
	if(direction[i-1]=='L'||direction[i-1]=='l')
		prev->llink=temp;
	else
		prev->rlink=temp;
	return root;
}
