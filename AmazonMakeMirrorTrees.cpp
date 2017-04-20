#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
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
bool isSubtree(struct node* , struct node*);
bool isequal(struct node* , struct node* );
void PrintInOrder(struct node* );
void Mirror(struct node*);
int main(){
	struct node* root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->left=Newnode(6);
	root->left->right=Newnode(5);
	PrintInOrder(root);
	cout<<endl;
	Mirror(root);
	PrintInOrder(root);
	return 0;
}
void Mirror(struct node* root){
	if(root==NULL)
		return;
	struct node* a,*b,*temp;
	
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	Mirror(root->left);
	Mirror(root->right);
}
void PrintInOrder(struct node* root){
	if(root==NULL)
		return;
	PrintInOrder(root->left);
	cout<<root->data<<" ";
	PrintInOrder(root->right);
}
