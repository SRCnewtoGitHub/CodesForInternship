#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next,*prev;
};
struct node* start=NULL;

int main(){
	int k;
	struct node* ans;
	void create(void);
	void printList(struct node*);
	struct node* reverse(struct node*,int);
	create();
	printList(start);
	cout<<endl;
	cout<<"Enter the reversing interval : ";
	cin>>k;
	ans=reverse(start,k);
	printList(ans);
	return 0;
}
void create(){
	int n,i;
	cout<<"Enter the number of elements in linked list : ";
	cin>>n;
	struct node* current=NULL;
	//struct node* start=NULL;
	
	for(i=0;i<n;i++){
		struct node* newnode=(struct node*)(malloc(sizeof(struct node*)));
		cout<<"Enter elements : ";
		cin>>newnode->data;
		newnode->next=NULL;
		if(start==NULL){
			start=newnode;
			current=newnode;
		}
		else{
			current->next=newnode;
			current=newnode;
		}
	}
}
struct node* reverse(struct node* start,int k){
	struct node* nextnode=NULL;
	struct node* prevnode=NULL;
	struct node* current=start;
	int c=0;
	while(c<k && current!=NULL){
		nextnode=current->next;
		current->next=prevnode;
		prevnode=current;
		current=nextnode;
		c++;
	}
	if(nextnode!=NULL)
		start->next=reverse(nextnode,k);
	return prevnode;
}
void printList(struct node* start){
	cout<<"The linked list is : "<<endl;
	struct node* temp=start;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}
