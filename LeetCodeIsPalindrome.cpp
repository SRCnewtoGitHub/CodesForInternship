#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct ListNode{
	int data;
	struct ListNode* next;
};
bool isPalindrome(struct ListNode*);
void printList(ListNode*);
void push(struct ListNode** head, int d){
	ListNode* node=(struct ListNode*)(malloc(sizeof(struct ListNode)));
	node->data=d;
	node->next=*head;
	*head=node;
}
int main(){
	struct ListNode* head=NULL;
	//push(&head,1);
	/*push(&head,1);
	push(&head,2);
	push(&head,2);
	push(&head,1);*/

		printList(head);
		cout<<endl;
		if(isPalindrome(head))
			cout<<"Yo Palindrome !!!!";
		else cout<<"NOOOOO :(";

return 0;
}

bool isPalindrome(struct ListNode* head) {
    stack<int> S;
    int flag=0;
    struct ListNode* temp=head;
    struct ListNode* start=head;
    while(temp!=NULL){
    	S.push(temp->data);
    	temp=temp->next;
	}
	while(!S.empty() && start!=NULL){
		if(S.top()!=start->data){
			flag=1;
			break;
		}
		start=start->next;
		S.pop();
	}
	if(flag==1)
		return false;
	else return true;
}
void printList(ListNode* head){
	ListNode* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
