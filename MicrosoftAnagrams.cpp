#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char str[100];char w[10];
	int countw[26],counts[26],c,i,j,d,ch,anag,flag,l,ls;
	anag=0;
	cin>>str;
	cin>>w;
	ls=strlen(str);
	l=strlen(w);
	for(i=0;i<26;i++){
		counts[i]=0;
		countw[i]=0;
	}
	
	for(i=0;i<l;i++){
		d=(int)(w[i])-97;
		countw[d]++;
	}
	c=0;
	while(c+l-1<ls){
		for(i=0;i<26;i++){
			counts[i]=0;
		}
		flag=0;
		for(j=c;j<c+l;j++){
			ch=(int)(str[j])-97;
			counts[ch]++;
		}
		for(i=0;i<26;i++){
			if(counts[i]!=countw[i]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			anag=anag+1;
			c=c+l;
		}
		else c++;
		
	}
	cout<<"No of anagrams : "<<anag;
}
