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
int main(){
	bool checkMirror(struct node*,struct node*);
	struct node* root1=(struct node*)(malloc(sizeof(struct node*)));
	struct node* root2=(struct node*)(malloc(sizeof(struct node*)));
	bool c;
	/*r1=Newnode(1);
	r2=Newnode(1);
	r1->left=Newnode(2);
	r1->right=Newnode(3);
	r1->left->left=Newnode(4);
	r1->left->right=Newnode(5);
	r1->right->right=Newnode(7);
	
	r2->right=Newnode(2);
	r2->left=Newnode(3);
	r2->right->right=Newnode(4);
	r2->right->left=Newnode(5);
	r2->left->left=Newnode(7);*/
		root1 = Newnode(1);
		root1->left = Newnode(2);
		root1->left->right = Newnode(3);
		root1->right = Newnode(4);

		root2 = Newnode(1);
		root2->right = Newnode(2);
		root2->right->left = Newnode(3);
		root2->left = Newnode(4);
	
	c=checkMirror(root1,root2);
	if (c)
		cout<<"Yo Mirror image ! ";
	else cout<<"Soory bro no mirror image :(";
	
	return 0;
}
bool checkMirror(struct node* root1,struct node* root2){
	if(root1==NULL && root2==NULL){
		return true;
	}
	
	if ((root1 == NULL && root2 != NULL)
				|| (root1 != NULL && root2 == NULL)){
				
		return false;
	}
	
	return root1->data==root2->data && checkMirror(root1->left,root2->right) && checkMirror(root1->right,root2->left);
}
