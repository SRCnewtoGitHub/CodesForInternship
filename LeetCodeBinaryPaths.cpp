#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
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

void RecurArrayPath(struct node*,int *arr,int idx);
void printArray(int*,int);
void PrintPath(struct node*);
int main(){
	struct node* root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->left=Newnode(6);
	root->left->left->left=Newnode(9);
	root->left->right=Newnode(5);
	root->right->left=Newnode(7);
	root->right->right=Newnode(8);
	PrintPath(root);
	return 0;
}
void RecurArrayPath(struct node* root,int* arr,int idx){
	if(root==NULL)
		return;
		
	arr[idx]=root->data;
	(idx)++;
	if(root->left==NULL && root->right==NULL){
		printArray(arr,idx);
	}
	
	
	RecurArrayPath(root->left,arr,idx);
	
	RecurArrayPath(root->right,arr,idx);
	
}
void PrintPath(struct node* root){
	int* arr=new int[10];
	int idx=0;
	RecurArrayPath(root,arr,idx);
}
void printArray(int a[],int l){
	int i;
	for(i=0;i<l;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
	
	
	
	
	


