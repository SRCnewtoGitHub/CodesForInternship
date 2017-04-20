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
	struct node* mth=NULL;
	struct node* nth=NULL;
	struct node* prev=NULL;
	struct node* current,*next;
	struct node* temp;
	struct node* mmth=NULL;
	//struct node* dummy=newNode(-1);
	//dummy->next=head;
	temp=head;
	int c=0;
	while(temp!=NULL && c<m-2){
      //temp is the (m-1)th node.
		c++;
		temp=temp->next;
	}
	if(temp!=NULL && m!=1)
		mmth=temp;
	if(m!=1){
		if(temp->next)
		mth=temp->next;
	}
	else{
		mth=temp;
	}
	while(temp!=NULL && c<n-1){          //going to the nth node.
		temp=temp->next;
		c++;
	}
	nth=temp;
	current=mth;
	//mth->next=nth->next;
	struct node* s=nth->next;
	c=m;
	while(current!=NULL && c<n+1){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		c++;
	}
	if(m!=1){
	
	if(mmth->next)
		mmth->next=prev;
	}
	struct node* p;
	p=prev;
	while(p->next!=NULL)
		p=p->next;
	p->next=s;
	if(m==1)
		head=prev;
	return head;
}
int main(){
	struct node *root=NULL;
	//push(&root,9);
	/*push(&root,8);
	push(&root,7);
	push(&root,6);
	push(&root,5);
	push(&root,4);
	push(&root,3);*/
	push(&root,2);
	push(&root,1);
	printList(root);
	struct node* res=revRange(root,1,2);
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
