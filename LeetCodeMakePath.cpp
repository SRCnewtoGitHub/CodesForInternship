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

void PrintInOrder(struct node* );
void LOT(struct node*);
int main(){
	struct node* root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->left=Newnode(6);
	root->left->left->left=Newnode(9);
	root->left->right=Newnode(5);
	root->right->left=Newnode(7);
	root->right->right=Newnode(8);
	LOT(root);

	return 0;
}
bool isMirror(struct node* t1,struct node* t2){
	if(t1==NULL && t2==NULL)
		return true;
	if(t1==NULL || t2==NULL)
		return true;
	return t1->data==t2->data && isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left);
}
bool isS
