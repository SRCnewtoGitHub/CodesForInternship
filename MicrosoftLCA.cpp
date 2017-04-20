#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* left,*right;
};
struct node* newNode(int data){
	struct node* node=(struct node*)(malloc(sizeof(struct node*)));
	node->data=data;
	node->right=NULL;
	node->left=NULL;
}
int main(){
	struct node* LCA(struct node*,int,int);
	struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    struct node *t = LCA(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = LCA(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = LCA(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	
	
	return 0;
}
struct node* LCA(struct node* root,int n1,int n2){
	if(root==NULL)
		return 0;
	if(root->data>n1 && root->data>n2)
		return LCA((root->left),n1,n2);
	if(root->data<n1 && root->data<n2)
		return LCA(root->right,n1,n2);
		
	return root;
}
