#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n,a[100],m,l,f,pos,i;
	cout<<"Enter the no of elements : ";
	cin>>n;
	cout<<"Enter the elements of sequence : ";
	for(i=0;i<n;i++)
		cin>>a[i];
	f=0;
	l=n-1;
	while(f<=l){
		m=(l+f)/2;
		if(a[m]>a[m+1]){
			pos=m;
			break;
		}
		else if(a[m-1]>a[m]){
			pos=m-1;
			break;
		}
		else if(a[f]>=a[m]){
			l=m;
		}
		else if(a[f]<a[m]){
			f=m-1;	
		}
	}
	cout<<"Pivot position : "<<m<<endl;
	cout<<"Pivot element : "<<a[m]<<endl;
	
	return 0;
	
}
