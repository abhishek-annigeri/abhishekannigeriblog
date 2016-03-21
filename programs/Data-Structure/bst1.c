#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *right,*left;
}*root,*p,*q;

struct node *make(int y)
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=y;
newnode->right=newnode->left=NULL;
return(newnode);
}

void left(struct node *r,int x)
{
if(r->left!=NULL)
printf("Invalid\n");
else
r->left=make(x);
}

void right(struct node *r,int x)
{
if(r->right!=NULL)
printf("Invalid\n");
else
r->right=make(x);
}

void inorder(struct node *r)
{
if(r!=NULL)
{
inorder(r->left);
printf("%d\t",r->data);
inorder(r->right);
}
}

void preorder(struct node *r)
{
if(r!=NULL)
{
printf("%d\t",r->data);
preorder(r->left);
preorder(r->right);
}
}

void postorder(struct node *r)
{
if(r!=NULL)
{
postorder(r->left);
postorder(r->right);
printf("%d\t",r->data);
}
}


void main(){
int no,ch;
printf("Enter root\n");
scanf("%d",&no);
root=make(no);
p=root;
while(1){
printf("\nEnter another no\n");
printf("\nEnter 0 to terminate\n");
scanf("%d",&no);
if(no==0)
break;
p=root;
q=root;
while(no!=p->data && q!=NULL){
p=q;
if(no< p->data)
q=p->left;
else
q=p->right;}
if(no < p->data){
printf("Left branch of %d is %d",p->data,no);
left(p,no);}
else{
right(p,no);
printf("Right branch of %d is %d",p->data,no);
}}
while(1)
{
printf("\n1:Inorder\n2:Preorder\n3:Postorder\n");
printf("Enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: inorder(root);
	break;
case 2: preorder(root);
	break;
case 3: postorder(root);
	break;
case 4: exit(0);
default : printf("Invalid choice\n");
	 break;

}}}
