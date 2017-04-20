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
void pre(struct node*);
int toSumTree(struct node*);
int main(){
	struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left=newNode(6);
  root->right->right=newNode(7);
  pre(root);
  cout<<endl;
  toSumTree(root);
  pre(root);
  return 0;
}
int toSumTree(struct node *node)
{
	int s;
    if(node==NULL)
        return 0;
    s=node->data;
    node->data=toSumTree(node->left)+toSumTree(node->right);
    
    
    //else s=node->data;
    return node->data+s;
    
}
void pre(struct node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	pre(root->left);
	pre(root->right);
}
