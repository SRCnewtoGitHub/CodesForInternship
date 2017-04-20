#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
}; 

struct node* revRange(struct node*,int,int);
void printList(struct node*);

void push(struct node** head,int d){
	struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
	//newnode->next=NULL;
	newnode->next=*head;
	newnode->data=d;			
	*head=newnode;
}
struct node *newNode(int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
struct node* revRange(struct node* head,int m,int n){
	struct node* prev;
	struct node* current,*next;
	struct node* temp;
	temp=head;
	int c=0;
	while(temp!=NULL && c<m-1){
		temp=temp->next;
		prev=temp->next;
		c++;
	}
	c=0;
	current=temp;
	while(current!=NULL && c<n-m){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		c++;
	}
	
	return prev;
}
int main(){
	struct node *root=NULL;
	//push(&root,9);
	push(&root,8);
	push(&root,7);
	push(&root,6);
	push(&root,5);
	push(&root,4);
	push(&root,3);
	push(&root,2);
	push(&root,1);
	printList(root);
	struct node* res=revRange(root,3,7);
	printList(res);
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
