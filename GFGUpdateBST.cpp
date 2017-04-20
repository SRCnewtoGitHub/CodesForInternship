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
	struct node* node=(struct node*)(malloc(sizeof(struct node)));
	node->data=d;
	node->left=NULL;
	node->right=NULL;
}
void update(struct node* root,int*);
void in(struct node* root);
int main(){
	struct node *root = newNode(5);
  root->left        = newNode(2);
  root->right       = newNode(7);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  root->right->left=newNode(6);
  root->right->right=newNode(8);
  in(root);
  int s=0;
  update(root,&s);
  cout<<endl;
  in(root);
 	return 0;
}
void update(struct node* root,int* s){			//reverse inorder.
	if(root==NULL)
		return;
	update(root->right,s);
	
	*s=*s+root->data;
	root->data=*s;
	update(root->left,s);
}
void in(struct node* root){
	if(root==NULL)
		return;
	in(root->left);
	cout<<root->data<<" ";
	in(root->right);
}





