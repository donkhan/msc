#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int data;
	struct node *left;
	struct node *right;
};
 
struct node *create();
void insert(struct node *,struct node *);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
 
int main(){
	struct node *root=NULL;
	root=create(20);
	insert(root,create(12));
	insert(root,create(6));
	insert(root,create(25));		
	printf("\nPreorder Traversal: ");
	preorder(root);
	printf("\nPost Order Traversal : ");
	postorder(root);
	printf("\nIn Order Traversal : ");
	inorder(root);
	printf("\n");
	return 0;
}

 
struct node *create(int n){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->left=temp->right=NULL;
	return temp;
}
 
void insert(struct node *root,struct node *temp){
	if(temp->data<root->data){
		if(root->left!=NULL){
			insert(root->left,temp);
		}
		else{
			root->left=temp;
		}
	}
	
	if(temp->data>root->data){
		if(root->right!=NULL){
			insert(root->right,temp);
		}
		else{
			root->right=temp;
		}
	}
}
 
void preorder(struct node *root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void postorder(struct node *root){
	if(root != NULL){
		postorder(root->left);
		printf("%d ",root->data);
		postorder(root->right);
	}
}


void inorder(struct node *root){
	if(root != NULL){
		inorder(root->left);
		inorder(root->right);
		printf("%d ",root->data);
	}
}


