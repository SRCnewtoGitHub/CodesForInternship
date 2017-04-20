#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
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
int diameter(struct node*);
int height(struct node*);

int main(){
	struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left=newNode(6);
  root->right->left->left=newNode(7);
  printf("Diameter of the given binary tree is %d\n", diameter(root));
 
}
int diameter(struct node* root){
	if(root==NULL)
		return 0;
	int lh=height(root->left);
	int rh=height(root->right);
	
	int ld=diameter(root->left);
	int rd=diameter(root->right);
	
	return max(lh+rh+1,max(ld,rd));
}
int height(struct node* root){
	if(root==NULL)
		return 0;
	return 1 + max(height(root->left),height(root->right));
}
