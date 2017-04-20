#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
#include<vector>
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
void getVerticalDist(struct node* root, int hd,map<int,vector<int> >& m){
	if(root==NULL)
		return ;
	m[hd].push_back(root->data);
	getVerticalDist(root->left,hd-1,m);
	getVerticalDist(root->right,hd+1,m);
}
void printVO(struct node* root){
	int j;
	int hd=0;                          //root has dist 0.
	map<int,vector<int> >m;
	getVerticalDist(root,hd,m);
	map<int,vector<int> >::iterator i;
	for(i=m.begin();i!=m.end();i++){
		for(j=0;j<i->second.size();j++)	
			cout<<i->second[j]<<" ";
			cout<<endl;
	}
}
int main(){
	struct node* root=Newnode(3);
	root->left=Newnode(1);
	root->left->left=Newnode(2);
	root->right=Newnode(5);
	root->right->left=Newnode(4);
	printVO(root);
	return 0;
}
