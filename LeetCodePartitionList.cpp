#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
}; 

struct node* Partition(struct node*,int);
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
	push(&root,7);
	push(&root,3);
	push(&root,6);
	push(&root,1);
	push(&root,5);
	push(&root,1);
	printList(root);
	res1=Partition(root,4);
	printList(res1);
	return 0;
}
struct node* Partition(struct node* head,int val){
	struct node* a,*b,*temp1,*temp2;
	struct node* res1,*res2,*prev1,*prev2;
	res1=res2=NULL;
	a=head;
	b=head;
	while(a!=NULL){
		if(a->data<val){
			temp1=newNode(a->data);
			if(res1==NULL)
				res1=temp1;
			else prev1->next=temp1;
			prev1=temp1;
		}
	}
	return res1;
	/*while(b!=NULL){
		if(b->data>=val){
			temp2=newNode(b->data);
			if(res2==NULL)
				res2=temp2;
			else prev2->next=temp2;
			prev2=temp2;
		}
	}
	struct node* i=res1;
	while(i!=NULL){
		i=i->next;
	}
	i->next=res2;
	return res1;*/
}
void printList(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}	
	
	
	
	

