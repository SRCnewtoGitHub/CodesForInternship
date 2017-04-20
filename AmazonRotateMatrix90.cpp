#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int m,n,r,c,i,j,a[10][10],b[10][10];
	cin>>m>>n;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	}
	r=1;
	for(i=1;i<=n;i++){
		c=1;
	for(j=m;j>=1;j--){
		b[r][c++]=a[j][i];
	}
	r++;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
		return 0;
}
