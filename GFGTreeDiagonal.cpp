#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

struct node{
	int data;
	struct node* left,*right;
};
struct node* newNode(int d){
	struct node* node=(struct node*)(malloc(sizeof(struct node)));
	node->data=d;
	node->left=NULL;
	node->right=NULL;
}
void pre(struct node*);
void storeDiag(struct node* root,int curdiag,map<int,vector<int> >&M);
void PrintDiag(struct node* root);
int main(){
	struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left=newNode(6);
  root->right->right=newNode(7);
  //pre(root);
  PrintDiag(root);
  
  return 0;
}
void storeDiag(struct node* root,int curdiag,map<int,vector<int> >&M){
	if(root==NULL)
		return;
	storeDiag(root->left,curdiag+1,M);
	M[curdiag].push_back(root->data);
	storeDiag(root->right,curdiag,M);
}
void PrintDiag(struct node* root){
	map<int,vector<int> > M;
	int n;
	int c=0;
	storeDiag(root,c,M);
	map<int,vector<int> >::iterator i;
	for(i=M.begin();i!=M.end();i++){
		for(int j=0;j<i->second.size();j++)
			cout<<i->second[j]<<" ";
		cout<<endl;
	}
}






