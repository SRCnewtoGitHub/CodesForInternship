#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* down;
	struct node* right;
}; 
struct node* flatten(struct node*);
	struct node* merge(struct node*, struct node*);
	void printList(struct node*);
void push(struct node** head,int d){
	struct node* newnode=(struct node*)(malloc(sizeof(struct node)));//that should be "sizeof(struct node)" not "node*"
	//newnode->next=NULL;
	newnode->right=NULL;
	newnode->data=d;
	newnode->down=*head;			//data tai fill korisni vai -_-
	*head=newnode;
}

int main(){
	
	struct node* head=NULL;
	push(&head,5);
	push(&head,4);
	push(&head,2);
	push(&head->right,6);
	push(&head->right,5);
	push(&head->right,3);
	push(&head->right->right,9);
	push(&head->right->right,7);
	
	struct node* res=flatten(head);
	printList(res);
	
	return 0;
}
struct node* flatten(struct node* a){
	if(a==NULL || a->right==NULL)
		return a;
	return merge(a,flatten(a->right));
}
struct node* merge(struct node* a, struct node* b){
	struct node* res;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
		
	if(a->data > b->data){
		res=b;
		res->down=merge(a,b->down);
	}
	else{
		res=a;
		res->down=merge(a->down,b);
	}
	return res;
}
void printList(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->down;
	}
	cout<<endl;
}
