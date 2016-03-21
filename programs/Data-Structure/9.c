#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *left,*right;
};

struct node *a[20];
struct node *root=NULL;

void create()
{
int n=0,ele;
struct node *newn,*temp;
printf("Enter the element\n");
scanf("%d",&ele);
do
{
newn=(struct node*)malloc(sizeof(struct node));
newn->info=ele;
newn->left=NULL;
newn->right=NULL;
n++;
a[n]=newn;
if(root==NULL)
root=newn;
else
{
if(n%2==0)
{
temp=a[n/2];
temp->left=newn;
}
else
{
temp=a[n/2];
temp->right=newn;
}
}
printf("Enter zero to terminate\n");
scanf("%d",&ele);
}while(ele!=0);
}

void inorder(struct node *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
printf("%4d",temp->info);
inorder(temp->right);
}
//printf("\n");
}

void preorder(struct node *temp)
{
if(temp!=NULL)
{
printf("%4d",temp->info);
preorder(temp->left);
preorder(temp->right);
}
}

void postorder(struct node *temp)
{
if(temp!=NULL)
{
postorder(temp->left);
postorder(temp->right);
printf("%4d",temp->info);
}
}

void main()
{
create();
printf("Inorder\n");
inorder(root);
printf("\nPreorder:\n");
preorder(root);
printf("\nPostorder\n");
postorder(root);
printf("\n");
}


