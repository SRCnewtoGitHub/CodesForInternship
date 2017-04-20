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
bool sumPath(struct node*,int);
int main(){
	struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left=newNode(6);
  bool c=sumPath(root,9);
  if(c)
  	cout<<"Yo exists path !!!";
else cout<<"NOOOO :(";
  return 0;
}
bool sumPath(struct node* root,int sum){
	if(root==NULL)
		return (sum==0);
	else{
	
	bool ans=false;
	int subsum=sum-root->data;
	if(subsum==0 && root->left==NULL && root->right==NULL){
		return true;
	}
	if(root->left)
	ans=ans || sumPath(root->left,subsum);
	if(root->right)
	ans= ans || sumPath(root->right,subsum);
	
	return ans;
	}	
}

