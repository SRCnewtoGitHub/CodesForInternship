#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
struct time{
	int start;
	int end;
};
stack<time> S;
bool comparator(time t1,time t2){
	return (t1.start < t2.start);
}
int main(){
	time arr[100];    //contains the intervals.
	int i,j,n;
	time t,k;
	
	cout<<"Enter the no of intervals to be merged : ";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i].start>>arr[i].end;
	sort(arr,arr+n,comparator);
	S.push(arr[0]);
	for(i=1;i<n;i++){
		t=S.top();
		if(t.end>=arr[i].start){
			S.pop();
			t.end=arr[i].end;
			S.push(t);
		}
		else if(t.end<arr[i].start){
			S.push(arr[i]);
		}
	}
	while(!S.empty()){
		k=S.top();
		cout<<"["<<k.start<<" "<<k.end<<"]";
		cout<<" ";
		S.pop();
	}
	return 0;
}
	
	

