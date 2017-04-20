#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void DFS(int maze[][100],int R,int C,int x,int y,bool vis[][100],int &maxi);
bool vis[100][100];
int main() {
    int maze[100][100],n,m,t,count,i,j,tempmax,maximum;
    scanf("%d",&t);
    while(t--){
        maximum=0;
        tempmax=0;
        count=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                    scanf("%d",&maze[i][j]);
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                vis[i][j]=false;
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(maze[i][j]==1 && vis[i][j]==false){
                    DFS(maze,n,m,i,j,vis,tempmax);
                    count++;
                }
                maximum=max(tempmax,maximum);
                tempmax=0;
            }
        }
        printf("%d %d\n",count,maximum);
    }
       
    return 0;
}
void DFS(int maze[][100],int R,int C,int x,int y,bool vis[][100],int &maxi){
    maxi++;
    vis[x][y]=true;
    if(x+1<R && maze[x+1][y]==1 && vis[x+1][y]==false)
        DFS(maze,R,C,x+1,y,vis,maxi);
    if(y+1<C && vis[x][y+1]==false && maze[x][y+1]==1)
            DFS(maze,R,C,x,y+1,vis,maxi);
    if(x-1>=0 && vis[x-1][y]==false && maze[x-1][y]==1)
        DFS(maze,R,C,x-1,y,vis,maxi);
    if(y-1>=0 && vis[x][y-1]==false && maze[x][y-1]==1)
            DFS(maze,R,C,x,y-1,vis,maxi);
    
}


