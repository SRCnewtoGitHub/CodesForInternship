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
void LOT(struct node* root){
	struct node* temp;
	vector<int> V;
	vector<vector <int> > F;
	queue<struct node*> Q;
	Q.push(root);
	while(!Q.empty()){
		int n=Q.size(), i=0;
		while(i<n){
			temp=Q.front();
			Q.pop();
			//vector<int> V;
			//if(i==0)		//for LEFT view, no if condition for level order traversal.
			//if(i==n-1)	//for RIGHT view
				//cout<<temp->data<<" ";
				V.push_back(temp->data);
			if(temp->left)
				Q.push(temp->left);

			if(temp->right)
				Q.push(temp->right);

			i++;
		}
		vector<vector<int> >::iterator it;
		it=F.begin();
		F.insert(it,V);
		V.clear();
	}
	//cout<<endl;
}






