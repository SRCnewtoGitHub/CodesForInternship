#include<cstdio>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

struct node{
	int data;
	struct node* left,*right;
};
struct node* Newnode(int d){
	struct node* n=(struct node*)(malloc(sizeof(struct node*)));
	n->data=d;
	n->right=NULL;
	n->left=NULL;
}
int main(){
	void leftview(struct node*);
	struct node* root;
	root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->right=Newnode(4);
	root->right->right=Newnode(5);
	leftview(root);
	return 0;
}
void leftview(struct node* root){
	if(root==NULL){
		cout<<"Empty tree !";
		return;
	}
	deque<struct node*> s1;
	deque<struct node*> s2;
	s1.push_back(root);
	while(!(s1.empty()) || !(s1.empty())){
		cout<<s1.back()->data<<" ";
		while(!(s1.empty())){
			struct node* temp;
			temp=s1.front();
			s1.pop_front();
			if(temp->left)
				s2.push_back(temp->left);
			if(temp->right)
				s2.push_back(temp->right);
		}
		cout<<s2.back()->data<<" ";
		while(!(s2.empty())){
			struct node* temp1;
			temp1=s2.front();
			s2.pop_front();
			if(temp1->left)
				s1.push_back(temp1->left);
			if(temp1->right)
				s1.push_back(temp1->right);
		}
		
	}
	
	
}
