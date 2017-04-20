#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
}; 

struct node* addZero(struct node*);
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
	push(&root,0);
	push(&root,9);
	push(&root,6);
	push(&root,0);
	push(&root,5);
	push(&root,4);
	push(&root,0);
	push(&root,1);
	push(&root,2);
	printList(root);
	res1=addZero(root);
	printList(res1);
	return 0;
}

struct node* addZero(struct node* head){
	struct node* head2=NULL;
	struct node* res=NULL;
	struct node* prev=NULL;
	struct node* temp=NULL;
	
	//you dont need the temp variable, only head node is enough
	//you need to preserve the head of resulting list and iterate a different node
	//iterating head of resulting list will give you a single node not the entire list
	while(head){
		int s=0;
		// prev=head;
		while(head!=NULL && head->data!=0){	//the NULL condition should be tested before any other condition
			s=s+head->data;
			head=head->next;
		}
		temp=newNode(s);
		if(!head2)
			head2=temp;
		else
			res->next=temp;
	
		res=temp;
		//res=prev;
		// if(head->next!=NULL)
		// head=head->next;
		if(head)
			head=head->next;
	}
	return head2;
}

void printList(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
