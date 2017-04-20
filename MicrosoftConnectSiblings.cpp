#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int data;
	struct node* left,*right;
	struct node* nextRight;
};
struct node* Newnode(int d){
	struct node* node=(struct node*)(malloc(sizeof(struct node)));
	node->data=d;
	node->left=NULL;
	node->right=NULL;
}

void PrintInOrder(struct node* );
void connect(struct node*);
int main(){
	struct node* root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->left=Newnode(6);
	root->left->left->left=Newnode(9);
	root->left->right=Newnode(5);
	root->right->left=Newnode(7);
	root->right->right=Newnode(8);
	connect(root);
	cout<<endl;
	if(root->left->left->nextRight==NULL)   //for testing.
		cout<<"NO value for NULL";
	else cout<<root->left->left->nextRight->data;
	return 0;
}
void connect(struct node* root){
	struct node* temp;
	struct node* prev=NULL;
	queue<struct node*> Q;
	Q.push(root);
	root->nextRight=NULL;
	while(!Q.empty()){
		int n=Q.size(), i=0;
		while(i<n){
			temp=Q.front();
			Q.pop();
			if(i) prev->nextRight=temp;
			prev=temp;
			
			cout<<temp->data<<" ";

			if(temp->left)
				Q.push(temp->left);

			if(temp->right)
				Q.push(temp->right);

			i++;
		}
		prev->nextRight=NULL;
	}
	cout<<endl;
}






