#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int* arr=(int*)(malloc(sizeof(int)));
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
	int i;
	int* BSTarray(struct node*);
	int* a;
	struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
	a=BSTarray(root);
	int k1=sizeof(a)/sizeof(a[0]);
	for(i=0;i<k1;i++)
		cout<<a[i]<<" ";
	
	return 0;
}
int* BSTarray(struct node* root){
	static int k=0;
	if(root==NULL)
		return arr;
	BSTarray(root->left);
	arr[k++]=root->data;
	BSTarray(root->right);
}
