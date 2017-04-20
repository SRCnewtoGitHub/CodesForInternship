#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
}; 
int detectCycle(struct node*);
void printList(struct node*);
void removeDetectedCycle(struct node*);
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
	struct node* head=NULL;
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	head->next->next->next->next=head;
	int d=detectCycle(head);
	cout<<endl;
	removeDetectedCycle(head);
	cout<<"After removing cycle : ";
	printList(head);
	return 0;
}
void removeDetectedCycle(struct node* head){
	struct node* slow,*fast;
	slow=head;
	fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		/*if(slow==fast){
			break;
		}*/
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
		slow=head;
		while(slow!=fast->next){
			slow=slow->next;
			fast=fast->next;
		}
		
		fast->next=NULL;  // removing cycle.
		}
	}
}
int detectCycle(struct node* head){
	struct node* slow,*fast;
	slow=fast=head;
	while(slow!=NULL && fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			cout<<"Cycle found !";
			return 1;
		}
	}
	cout<<"No cycle found !";
	return 0;
}
void printList(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}	
	
	

