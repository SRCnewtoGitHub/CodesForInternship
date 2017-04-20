#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
}; 

void push(struct node** head,int d){
	struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
	newnode->data=d;
	//newnode->next=NULL;
	newnode->next=*head;
	*head=newnode;
}
int main(){
	void rotate(struct node**,int k);
	void printList(struct node*);
	struct node* head=NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,2);
	push(&head,1);
	rotate(&head,3);
	printList(head);
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
void rotate(struct node** head,int k){
	struct node* temp=*head;
	struct node* tk1,*tk2;
	int c=1;
	while(c<k){
		temp=temp->next;
		c++;
	}
	//temp is the k-1 th node.
	tk1=temp->next;  // tk1 is the (k) th node.
	tk2=tk1;
	while(tk2->next!=NULL){
		tk2=tk2->next;
	}                              //tk2 is the last node.
	tk2->next=*head;
	*head=tk1;
	temp->next=NULL;
	
}
