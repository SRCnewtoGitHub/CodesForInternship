#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int Island(int maze[][100],int r,int c);
void DFS(int maze[][100],int r,int c,bool vis[][100]);

int main(){
	int maze[100][100],m,n,i,j;
	cout<<"Enter row and col : ";
	cin>>m>>n;
	cout<<"Input maze matrix : ";
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			cin>>maze[i][j];
	}
	cout<<"No of Islands : "<<Island(maze,m,n);
	return 0;
}
int Island(int maze[][100],int r,int c){
	int i,j,cnt;
	cnt=0;
	bool vis[100][100];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(vis[i][j]==false && maze[i][j]==1){
				DFS(maze,i,j,vis);
				cnt++;
			}
		}
	}
	return cnt;	
}
void DFS(int maze[][100],int r,int c,bool vis[][100]){
	vis[r][c]=true;
	if(maze[r][c+1]==1)
		DFS(maze,r,c+1,vis);
	if(maze[r+1][c]==1)
		DFS(maze,r+1,c,vis);
}
	
	
	

