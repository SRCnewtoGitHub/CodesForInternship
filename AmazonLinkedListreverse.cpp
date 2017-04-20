#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
	int data;
	struct node* next,*prev;
};
struct node* start=NULL;

struct node* newNode(int d){
	//struct node* node;
	struct node* node = (struct node*)(malloc(sizeof(struct node)));
	node->data=d;
	node->next=NULL;
	node->prev=NULL;
}
int main(){
	struct node* reverse(struct node*,int);
	void printList(struct node*);
	int c,k;
	c=2;
	cout<<"Enter the rev-interval : ";
	cin>>k;
	struct node* head=newNode(1);
	while(c<=10){
		head=head->next;
		head=newNode(c);
		c++;
		
	}
	struct node* ans=(struct node*)(malloc(sizeof(struct node*)));
	ans=reverse(head,k);
	printList(ans);
	return 0;
}
struct node *reverse (struct node *head, int k)
{
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->next = reverse(next,k); 
 
    /* prev is new head of the input list */
    return prev;
}
void printList(struct node* head){
	struct node* temp;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}
