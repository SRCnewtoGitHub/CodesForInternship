#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
}; struct node* start=NULL;

void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    *head_ref->next=new_node;
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
int main(){
	
	
	
	
	return 0;
}

