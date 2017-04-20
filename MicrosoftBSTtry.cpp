#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
	int data;
	struct node* left,*right;
};
struct node* newNode(int d){
	struct node* node=(struct node*)(malloc(sizeof(struct node*)));
	node->data=d;
	node->left=NULL;
	node->right=NULL;
}
int main(){
	int* isBST(struct node*);
	struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
	bool ans;
	if(isBST(root))
	cout<<"Yes BST !";
	else cout<<"No";
	
	return 0;
}
int* isBST(struct node* root){
	int a[100],k,i,flag;
	k=0;
	flag=0;
	if(root==NULL)
		return 0;
	isBST(root->left);
	a[k++]=root->data;
	isBST(root->right);
	
	return a;
}
