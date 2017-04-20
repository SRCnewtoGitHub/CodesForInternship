#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
}; 

struct node* removeDup(struct node*,int);
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
	//push(&root,6);
	push(&root,6);
	push(&root,4);
	push(&root,6);
	push(&root,1);
	push(&root,1);
	push(&root,1);
	printList(root);
	res1=removeDup(root,1);
	printList(res1);
	return 0;
}
struct node* removeDup(struct node* head,int val){
	struct node* dummy=newNode(-1);
	struct node* s;
	dummy->next=head;
	if(head==NULL)
		return NULL;
	struct node* prev,*temp;
	temp=dummy;
	prev=NULL;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
		if(temp->data==val){
			s=temp;
			while(s!=NULL && s->data==val)
				s=s->next;
			if(s)
				prev->next=s;
			else prev->next=NULL;
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
