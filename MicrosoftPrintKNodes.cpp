#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int data;
	struct node* left,*right;
};
struct node* Newnode(int d){
	struct node* node=(struct node*)(malloc(sizeof(struct node)));
	node->data=d;
	node->left=NULL;
	node->right=NULL;
}
void printK(struct node*,int);
int height(struct node*);
int main(){
	int k;
	struct node* root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->left=Newnode(6);
	root->left->left->left=Newnode(9);
	root->left->right=Newnode(5);
	root->right->left=Newnode(7);
	root->right->right=Newnode(8);
	cout<<"Enter distance from root : ";
	cin>>k;
	printK(root,k);
	
	return 0;
}
void printK(struct node* root,int k){
	if(root==NULL)
		return;
	if(k==0)
		cout<<root->data<<" ";
		printK(root->right,k-1);
		printK(root->left,k-1);
}
int height(struct node* root){
	if(root==NULL)
		return 0;
	else return 1+max(height(root->left),height(root->right));
}
