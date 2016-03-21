#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
struct AVLNode
{
	int data;
	int balfact;
	struct AVLNode *left;
	struct AVLNode *right;
};

/*Insert an element into tree*/
struct AVLNode *buildtree(struct AVLNode *root,int data,int *h)
	{
	struct AVLNode *node1,*node2;
	if(!root)
		{
		root=(struct AVLNode *)malloc(sizeof(struct AVLNode));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		root->balfact=0;	
		*h=TRUE;
		return(root);
		}
	if(data<root->data)
		{
		root->left=buildtree(root->left,data,h);
		/*if left subtree is higher*/
		if(*h)
			{
			switch(root->balfact)
				{
				case 1:
					node1=root->left;
					if(node1->balfact==1)
						{
						printf("\nRight rotation along %d\n",root->data);
						root->left=node1->right;
						node1->right=root;
						root->balfact=0;
						root=node1;
						}
					else
						{
						printf("\nDouble rotation left along%d\n",node1->data);
						node2=node1->right;
						node1->right=node2->left;
						printf("then right along%d\n",root->data);
						node2->left=node1;
						root->left=node2->right;
						node2->right=root;
						if(node2->balfact==1)
							root->balfact=-1;
						else
							root->balfact=0;
						if(node2->balfact==-1)
							node1->balfact=1;
						else
							node1->balfact=0;
						root=node2;
						}
					root->balfact=0;
					*h=FALSE;
					break;
				case 0:
					root->balfact=1;
					break;
				case -1:
					root->balfact=0;
					*h=FALSE;
				}
			}
		}
	if(data>root->data)
		{
		root->right=buildtree(root->right,data,h);
		/*if the right subtree is higher*/
		if(*h)
			{
			switch(root->balfact)
				{
				case 1:
					root->balfact=0;
					*h=FALSE;
					break;
				case 0:
					root->balfact=-1;
					break;
				case -1:
					node1=root->right;
					if(node1->balfact==-1)
						{
						printf("\nLeft rotation along%d\n",root->data);
						root->right=node1->left;
						node1->left=root;
						root->balfact=0;
						root=node1;
						}
					else
						{
						printf("\nDouble rotation,right along %d\n",node1->data);
						node2=node1->left;
						node1->left=node2->right;
						node2->right=node1;
						printf("then left along %d\n",root->data);
						root->right=node2->left;
						node2->left=root;
						if(node2->balfact==-1)
							root->balfact=1;
						else
							root->balfact=0;
						if(node2->balfact==1)
							node1->balfact=-1;
						else
							node1->balfact=0;
						root=node2;
						}
					root->balfact=0;
					*h=FALSE;
				}
			}
		}
	return(root);
	}
/*balances the tree,if right sub-tree is higher*/
struct AVLNode *balright(struct AVLNode *root,int *h)
	{
	struct AVLNode *node1,*node2;
	switch(root->balfact)
		{
		case 1:
			root->balfact=0;
			break;
		case 0:
			root->balfact=-1;
			*h=FALSE;
			break;
		case -1:
			node1=root->right;
			if(node1->balfact<=0)
				{
				printf("\nLeft rotation along %d\n",root->data);
				root->right=node1->left;
				node1->left=root;
				if(node1->balfact==0)
					{
					root->balfact=-1;
					node1->balfact=1;
					*h=FALSE;
					}
				else
					root->balfact=node1->balfact=0;
				root=node1;
				}
			else
				{
				printf("\nDouble rotation,right along %d\n",node1->data);
				node2=node1->left;
				node1->left=node2->right;
				node2->right=node1;
				printf("then left along %d\n",root->data);
				root->right=node2->left;
				node2->left=root;
				if(node2->balfact==-1)
					root->balfact=1;
				else
					root->balfact=0;
				if(node2->balfact==1)
					node1->balfact=-1;
				else
					node1->balfact=0;
				root=node2;
				node2->balfact=0;
				}
		}
	return(root);	
	}
/*balances the tree,if left sub-tree is higher*/
struct AVLNode *balleft(struct AVLNode *root,int *h)
	{
	struct AVLNode *node1,*node2;
	switch(root->balfact)
		{
		case -1:
			root->balfact=0;
			break;
		case 0:
			root->balfact=1;
			*h=FALSE;
			break;
		case 1:
			node1=root->left;
			if(node1->balfact>=0)
				{
				printf("\nRight rotation along %d\n",root->data);
				root->left=node1->right;
				node1->right=root;
				if(node1->balfact==0)
					{
					root->balfact=1;
					node1->balfact=-1;
					*h=FALSE;
					}
				else
					{
					root->balfact=node1->balfact=0;
					}
				root=node1;
				}
			else
				{
				printf("\nDouble rotation,left along %d\n",node1->data);
				node2=node1->right;
				node1->right=node2->left;
				node2->left=node1;
				printf("then right along %d\n",root->data);
				root->left=node2->right;
				node2->right=root;
				if(node2->balfact==1)
					root->balfact=-1;
				else
					root->balfact=0;
				if(node2->balfact==-1)
					node1->balfact=1;
				else
					node1->balfact=0;
				root=node2;
				node2->balfact=0;
				}
		}
	return(root);
	}
/*Display the tree in-order*/
void display(struct AVLNode *root)
	{
	if(root!=NULL)
		{
		display(root->left);
		printf("%d\t",root->data);
		display(root->right);
		}
	}
/*returns height of AVL tree*/
int height(struct AVLNode *root)
	{
	int rheight,lheight;
	if(root==NULL)
		return -1;
	else
		{
		rheight=height(root->right);
		lheight=height(root->left);
		if(rheight>lheight)
			return rheight+1;
		else
			return lheight+1;
		}
	}
int main()
	{
	struct AVLNode *avl=NULL;
	int h;
	int i,count,temp;
	printf("Enter the number of nodes:");
	scanf("%d",&count);
	for(i=0;i<count;i++)
		{
		printf("\nEnter value for node # %d:",(i+1));
		scanf("%d",&temp);
		avl=buildtree(avl,temp,&h);
		}
	printf("\n\nAVL tree:\n");
	display(avl);
	printf("\n\nAVL height:%d\n\n",height(avl));
	return 0;
	} 	

