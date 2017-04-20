#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};
//struct node* start=NULL;
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
int main(){
	//input of binary tree.
	//cout<<"Enter number of elements of binary tree : "<<n;
	void zigzag(struct node*);
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout << "Zigzag traversal of binary tree is \n";
    zigzag(root);

	return 0;
}
void zigzag(struct node* root){
	stack<struct node*> slr;
	stack<struct node*> srl;
	srl.push(root);
	while(!(slr.empty()) || !(srl.empty())){
	
		while(!(srl.empty())){
			struct node* link=srl.top();
			cout<<link->data;
			srl.pop();
			if(link->right){
				slr.push(link->right);
			}
			if(link->left){
				slr.push(link->left);
			}
		}
		while(!(slr.empty())){
			struct node* link=slr.top();
			cout<<link->data;
			slr.pop();
			if(link->left){
				srl.push(link->left);
			}
			if(link->right){
				srl.push(link->right);
			}
		}
		
	}
}
