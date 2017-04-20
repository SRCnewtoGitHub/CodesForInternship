#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int maxi=-1000;
struct node{
	int data;
	struct node* left,*right;
};
struct node* newNode(int d){
	struct node* node = (struct node*)(malloc(sizeof(struct node)));
	node->data=d;
	node->left=NULL;
	node->right=NULL;
	return node;
}
int main(){
	int maxwt(struct node*);
	struct node* root=newNode(-10);
	root->left        = newNode(-1);
    root->right       = newNode(7);
    root->left->left  = newNode(8);
    root->left->right = newNode(-4);
    root->right->left  = newNode(5);
    root->right->right = newNode(2);
    cout<<"Max weight binary tree : "<<maxwt(root)<<endl;
	
	return 0;
}
int maxwt(struct node* root){
	
	if(root==NULL)
		return 0;
	//maxi=root->data+root->right->data+root->left->data;
	maxi=root->data+maxwt(root->right)+maxwt(root->left);
	
	return maxi;
	//max(maxi,root->data+root->right->data+root->left->data);
}
