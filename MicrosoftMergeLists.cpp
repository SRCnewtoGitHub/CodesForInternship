#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
}; 

void push(struct node** head,int d){
	struct node* newnode=(struct node*)(malloc(sizeof(struct node*)));
	newnode->data=d;
	//newnode->next=NULL;
	newnode->next=*head;
	*head=newnode;
}
int main(){
	struct node* merge(struct node*, struct node*);
	void printList(struct node*);
	struct node* a,*b;
	a=b=NULL;
	push(&a,5);
	push(&a,3);
	push(&a,1);
	push(&b,6);
	push(&b,4);
	push(&b,2);
	
	struct node* res=merge(a,b);
	printList(res);
	
	return 0;
}
struct node* merge(struct node* a, struct node* b){
	struct node* res;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
		
	if(a->data > b->data){
		res=b;
		res->next=merge(a,b->next);
	}
	else{
		res=a;
		res->next=merge(a->next,b);
	}
	return res;
}
void printList(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
