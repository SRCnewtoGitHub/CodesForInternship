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
void storeIO(struct node*,int*,int*);
void arraytoBST(struct node*,int*,int*);
void inorder(struct node*);
void CorrectBST(struct node*);
int countNodes (struct node*);
int main(){
	struct node* root=Newnode(1);
	root->left=Newnode(2);
	root->left->left=Newnode(3);
	root->right=Newnode(5);
	root->right->left=Newnode(4);
	inorder(root);
	CorrectBST(root);
	cout<<"\nCorrected tree :\n";
	inorder(root);
	return 0;
}
void storeIO(struct node* root,int in[],int* idx){
	if(root==NULL)
		return;
	storeIO(root->left,in,idx);
	in[*idx]=root->data;
	(*idx)++;
	storeIO(root->right,in,idx);
}
void arraytoBST(struct node* root,int* a,int* idx){
	if(root==NULL)
		return;
	arraytoBST(root->left,a,idx);
	root->data=a[*idx];
	(*idx)++;
	arraytoBST(root->right,a,idx);
}
void CorrectBST(struct node* root){
	if(root==NULL)
		return;
	int i=0;
	int n=countNodes(root);
	int* arr=new int[n+1];
	storeIO(root,arr,&i);
	sort(arr,arr+n);
	i=0;
	arraytoBST(root,arr,&i);
	delete[] arr;
}
void inorder(struct node* root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int countNodes (struct node* root)
{
    if (root == NULL)
     return 0;
    return countNodes (root->left) +
           countNodes (root->right) + 1;
}
