#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};struct node* head=NULL;

struct node* newnode(int d){
	struct node* n=(struct node*)(malloc(sizeof(struct node)));
	n->data=d;
	n->next=NULL;
}
void push(struct node** head,int newd){
	struct node* new_node=newnode(newd);
	new_node->next=*head;
	*head=new_node;
}
struct node* addList(struct node* n1,struct node* n2){
	struct node* prev=NULL;
	struct node* res=NULL;
	struct node* temp=NULL;
	int sum,carry=0;
	while(n1!=NULL || n2!=NULL){
		sum=carry+(n1?n1->data:0)+(n2?n2->data:0);
		if(sum>=10)
			carry=1;
		else carry=0;
		sum=sum%10;
		temp=newnode(sum);
		if(res==NULL)
			res=temp;
		else prev->next=temp;
		
		prev=temp;
		if(n1!=NULL)
			n1=n1->next;
		if(n2!=NULL)
			n2=n2->next;
	}
	
	if(carry>0){
		temp->next=newnode(carry);
	}
	return res;
	
}
void printList(struct node *node)
{
    	if(node==NULL)
    		return;
        //printf("%d ", node->data);
        printList(node->next);
    	cout<<node->data<<" ";
    
    
    
}
 
/* Driver program to test above function */
int main(void)
{
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 5);
    push(&first, 0);
    push(&first, 0);
    //push(&first, 5);
    //push(&first, 7);
    printf("First List is ");
    printList(first);
    cout<<endl;
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);
 	cout<<endl;
    // Add the two lists and see result
    res = addList(first, second);
    printf("Resultant list is ");
    printList(res);
 
   return 0;
}

