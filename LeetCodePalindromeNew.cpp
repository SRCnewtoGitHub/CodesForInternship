#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct ListNode{
	int data;
	struct ListNode* next;
};
ListNode* isPalindrome(struct ListNode*);
void printList(ListNode*);
void push(struct ListNode** head, int d){
	struct ListNode* node=(struct ListNode*)(malloc(sizeof(struct ListNode)));
	node->data=d;
	node->next=*head;
	*head=node;
}
int main(){
	ListNode* head=NULL;
	//push(&head,1);
	push(&head,1);
	push(&head,2);
	push(&head,1);
	push(&head,1);

	
		printList(head);
		cout<<endl;
		struct ListNode* rev=isPalindrome(head);
		printList(rev);
		

return 0;
}

struct ListNode* isPalindrome(struct ListNode* head) {
	ListNode* start=head;
    ListNode* current=head;
    ListNode* prev=NULL;
    ListNode* next;
    int flag=0;
    while(current!=NULL){
    	next=current->next;
    	current->next=prev;
    	prev=current;
    	current=next;
	}
	return head;
}
	/*while(head!=NULL && prev!=NULL){
		if(head->data!=prev->data){
			flag=1;
			break;
		}
		head=head->next;
		prev=prev->next;
	}
	if(flag==0)
		return true;
	else return false;
}*/
void printList(struct ListNode* head){
	struct ListNode* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
