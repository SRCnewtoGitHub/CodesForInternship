#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int no[100],next[100],temp,i,j,flag,pos,smallest;
	char s[100];
	cin>>s;
	int n=strlen(s);
	for(i=0;i<n;i++)
		no[i]=(int)(s[i]-'0');
	flag=0;
	for(i=n-1;i>0;i--){
		if(no[i]>no[i-1])
			break;
	}
	if(i==0){
		cout<<"Not possibe !";
		exit(0);
	}
	smallest=i;
	for(j=i+1;j<n;j++){
		if(no[j]>no[i-1] && no[j]<no[smallest])
			smallest=j;
	}
	swap(no[smallest],no[i-1]);
	sort(no+i,no+n);
	for(i=0;i<n;i++)
		cout<<no[i];
		
	return 0;
}
