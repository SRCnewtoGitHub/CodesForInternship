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
	bool isBST(struct node*);
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
bool isBST(struct node* root){
	static struct node* prev=NULL;
	if(root!=NULL){
		if(isBST(root->left)==NULL)
			return false;
		if(prev!=NULL && root->data<=prev->data)
			return false;
		prev=root;
		
		return isBST(root->right);
	}
	return true;
}
