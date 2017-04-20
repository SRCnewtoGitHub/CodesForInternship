#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
}; 

struct node* removeDup(struct node*);
void printList(struct node*);

void push(struct node** head,int d){
	struct node* newnode=(struct node*)(malloc(sizeof(struct node)));//that should be "sizeof(struct node)" not "node*"
	//newnode->next=NULL;
	newnode->next=*head;
	newnode->data=d;			//data tai fill korisni vai -_-
	*head=newnode;
}
struct node *newNode(int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
int main(){
	struct node *root=NULL, *res1;
	//push(&root,0);
	//push(&root,9);
	//push(&root,5);
	//push(&root,4);
	push(&root,4);
	push(&root,3);
	push(&root,1);
	push(&root,1);
	push(&root,1);
	printList(root);
	res1=removeDup(root);
	printList(res1);
	return 0;
}
struct node* removeDup(struct node* head){
	struct node* dummy=newNode(-1);
	struct node *temp,*start,*prev;
	dummy->next=head;
	prev=dummy;
	temp=head;
	while(temp->next!=NULL){
		if(temp->data==temp->next->data){
			start=temp;
			while(start->next!=NULL && start->data==start->next->data){
				start=start->next;
				temp=temp->next;
			}
			if(start->next)	
				prev->next=start->next;
			else prev->next=NULL;
			
			if(temp->next)
			temp=temp->next;
		}
		else{
			prev=temp;
		 	temp=temp->next;
		}
	}
	return dummy->next;
}
void printList(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
	
	
	
	
	
	
