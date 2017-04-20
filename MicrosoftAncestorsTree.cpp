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
bool ancestor(struct node*,int);

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
	bool b=ancestor(root,99);
	if(b)
		cout<<"Yo target found !!";
		else cout<<"NOOOOO :(";
	return 0;
}
bool ancestor(struct node* root,int key){
	if(root==NULL)
		return false;
	if(root->data==key)
		return true;
	if(ancestor(root->left,key)){
		cout<<root->data<<" ";
		return true;
	}
	if(ancestor(root->right,key)){
		cout<<root->data<<" ";
		return true;
	}
	return false;
}







