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

void RecurArrayPath(struct node*,int *arr,int idx,int* no,int* i);
int sumNumbers(struct node* root);
int findNo(int a[],int l);
int main(){
	struct node* root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->left=Newnode(6);
	//root->left->left->left=Newnode(9);
	root->left->right=Newnode(5);
	root->right->left=Newnode(7);
	root->right->right=Newnode(8);
	int s=sumNumbers(root);
	cout<<s;
	return 0;
}
void RecurArrayPath(struct node* root,int* arr,int idx,int* no,int* i){
	if(root==NULL)
		return;
	arr[idx]=root->data;
	(idx)++;
	if(root->left==NULL && root->right==NULL){
		no[*i]=findNo(arr,idx);
		(*i)++;
	}
	RecurArrayPath(root->left,arr,idx,no,i);
	RecurArrayPath(root->right,arr,idx,no,i);
	
}
int sumNumbers(struct node* root){
	//vector<int> V;
	int sum=0;
	int* arr=new int[100];
	int* no=new int[100];
	int idx=0;
	int i=0;
	RecurArrayPath(root,arr,idx,no,&i);
	//vector<int>::iterator it;
	for(int c=0;c<i;c++)
		sum=sum+no[c];
	return sum;
}
int findNo(int a[],int l){
	int i,s;
	int r=1;
	s=0;
	for(i=l-1;i>=0;i--){
		s=s+r*a[i];
		r=r*10;
	}
 	return s;
}
	
	
	
	
	


