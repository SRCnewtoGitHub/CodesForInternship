#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};struct node* start=NULL;

int main(){
	int n;
	struct node* create(int);
	void printList(struct node*);
	cout<<"Enter the number of digits : ";
	cin>>n;
	struct node* node1=(struct node*)(malloc(sizeof(struct node*)));
	struct node* node2=(struct node*)(malloc(sizeof(struct node*)));
	node1=create(n);
	printList(node1);
	cout<<endl;
	start=NULL;
	node2=create(n);
	printList(node2);
	

	printList(start);
	return 0;
}
struct node* create(int n){
	int a;
	int i;
	struct node* temp;
	for(i=0;i<n;i++){
		struct node* cur;
		temp=start;
		struct node* newnode;
		newnode=(struct node*)(malloc(sizeof(struct node*)));
		cout<<"Enter the digits : ";
		cin>>newnode->data;
		newnode->next=NULL;
		if(temp==NULL){
			temp=newnode;
			cur=newnode;
		}
		else{
			cur->next-newnode;
			cur=newnode;
		}
		
	}
	return temp;
	
}
void printList(struct node* root){
	struct node* temp=root;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}
struct node* add(struct node* n1,struct node* n2){
	
}
