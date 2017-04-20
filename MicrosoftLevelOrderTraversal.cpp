#include<cstdio>
#include<iostream>
#include<stack>
#include<list>
using namespace std;
int main(){
	void DFS(int[][100],int,int);
	void BFS(int[][100],int,int);
	int t,i,j,s,ch;
	int gr[100][100];
	//gr=new int[100][100];
	//gr=new int*[100];
	//gr=new int[100][100];
	int a,b,n,m;
	scanf("%d",&t);
	while(t--){
		cout<<"Enter the no of vertices and edges : ";
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				gr[i][j]=0;
		 }
		
		for(i=1;i<=m;i++){
			cout<<"Enter the "<<i<<"th edge : ";
			cin>>a>>b;
			gr[a][b]=6;
			gr[b][a]=6;
		}
		cout<<"Enter the starting point : ";
		cin>>s;
		/*for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				cout<<gr[i][j]<<" ";
			cout<<endl;
		}*/
		cout<<"Enter 1 for BFS, 2 for DFS : ";
		cin>>ch;
		if(ch==1)
			BFS(gr,n,s);
		if(ch==2)
			DFS(gr,n,s);
		cout<<endl;
	}
	return 0;
}
void DFS(int m[][100],int n,int s){
	int t,i,p,c,k;
	c=0;
	bool vis[100];
	for(i=1;i<=n;i++)
		vis[i]=false;
	stack<int> st;
	st.push(s);
	vis[s]=true;
	k=s;
	while(!(st.empty())){
		p=st.top();
	/*	s=p;
		for(i=1;i<=n;i++){
			if(m[s][i]==6 && vis[i]==false)
				cout<<k<<" to "<<i<<"-"<<(c+6)<<endl;
		}
		//cout<<p<<" ";
		queue.pop_front();
		//c=c+6;*/
		cout<<p<<"-->";
		st.pop();
		for(i=1;i<=n;i++){
			if(m[p][i]==6){
				
				if(vis[i]==false){
					vis[i]=true;
					st.push(i);
			    }
			}
		}
		//c=c+6;
	}
}
void BFS(int m[][100],int n,int s){
	int t,i,p,c,k;
	c=0;
	bool vis[100];
	for(i=1;i<=n;i++)
		vis[i]=false;
	list<int> queue;
	queue.push_back(s);
	vis[s]=true;
	k=s;
	while(!(queue.empty())){
		p=queue.front();
	/*	s=p;
		for(i=1;i<=n;i++){
			if(m[s][i]==6 && vis[i]==false)
				cout<<k<<" to "<<i<<"-"<<(c+6)<<endl;
		}
		//cout<<p<<" ";
		queue.pop_front();
		//c=c+6;*/
		cout<<p<<"-->";
		queue.pop_front();
		for(i=1;i<=n;i++){
			if(m[p][i]==6){
				
				if(vis[i]==false){
					vis[i]=true;
					queue.push_back(i);
			    }
			}
		}
		//c=c+6;
	}
}
