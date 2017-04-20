#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int len,j,c,n,diff,a[100],it,i;
	vector<int> seq;
	cin>>n;
	for(it=0;it<n;it++){
		cin>>a[it];
		seq.push_back(a[it]);
	}
	n=seq.size();
	
	diff=seq[1]-seq[0];
	for(i=2;i<seq.size();i++){
		if(seq[i]-seq[i-1]>0 && diff>0){
			if(max(seq[i],seq[i-1])==seq[i]){
				seq.erase(seq.begin()+i-1);
				diff=seq[i]-seq[i-1];
			}
			else{
				seq.erase(seq.begin()+i);
				diff=seq[i-1]-seq[i-2];
			}
			
		}
		else if(seq[i]-seq[i-1]<0 && diff<0){
			if(min(seq[i],seq[i-1])==seq[i]){
				seq.erase(seq.begin()+i-1);
				diff=seq[i]-seq[i-1];
				
			}
			else{
				
				seq.erase(seq.begin()+i);
				diff=seq[i-1]-seq[i-2];
			}
		}
		else diff=seq[i]-seq[i-1];
	}
	cout<<seq.size();
	cout<<endl;
	for(i=0;i<seq.size();i++)
		cout<<seq[i]<<" ";
	return 0;
}
