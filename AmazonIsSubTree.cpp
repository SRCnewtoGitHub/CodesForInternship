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
	struct node* node=(struct node*)(malloc(sizeof(struct node*)));
	node->data=d;
	node->left=NULL;
	node->right=NULL;
}
bool isSubtree(struct node* , struct node*);
bool isequal(struct node* , struct node* );
int main(){
	struct node* root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->left=Newnode(4);
	root->left->right=Newnode(5);
	
	struct node* sub=Newnode(2);
	sub->left=Newnode(4);
	sub->right=Newnode(5);
	bool c=isSubtree(root,sub);
	if(c)
		cout<<"Yo Its SUBTREE !";
	else cout<<"NOOOOOO :(";
	return 0;
}
bool isSubtree(struct node* root, struct node* sroot){
	if(sroot==NULL)
		return true;
	if(root==NULL)
		return false;
	if(isequal(root,sroot))
		return true;
	return isSubtree(root->left,sroot) || isSubtree(root->right,sroot);
}
bool isequal(struct node* S, struct node* T){
	if(S==NULL && T==NULL)
		return true;
	if(S==NULL || T==NULL)
		return false;
	
	return (S->data==T->data && isequal(S->left,T->left) && isequal(S->right,T->right));
}
