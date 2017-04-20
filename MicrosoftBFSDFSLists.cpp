#include<cstdio>
#include<iostream>
#include<list>
#include<stack>
#include<queue>
using namespace std;
class graph{
		int V;
		list<int> *adj;
	public:
		void DFS(int v);
		void BFS(int v);
		
		graph(int V){                                  //Constructor
			this->V=V;
			adj=new list<int>[V+1];
		}
		void addEdge(int v,int w){							//We are assuming the vertex to start from 1, not zero.
			adj[v].push_back(w);
			adj[w].push_back(v);
		}	
};
void graph::DFS(int v){
	int it,p;
	bool *vis=new bool[V+1];
	for(it=1;it<=V;it++)
		vis[it]=false;
	vis[v]=true;
	stack<int> S;
	S.push(v);
	list<int>::iterator i;
	while(!S.empty()){
		cout<<S.top()<<" ";
		p=S.top();
		S.pop();
		for(i=adj[p].begin();i!=adj[p].end();i++){
			if(vis[*i]==false){
				vis[*i]=true;
				S.push(*i);
			}
		}
	}
}
void graph::BFS(int v){
	int p;
	bool *vis=new bool[V+1];
	for(int it=1;it<=V;it++)
		vis[it]=false;
	vis[v]=true;
	queue<int> S;
	S.push(v);
	list<int>::iterator i;
	while(!S.empty()){
		cout<<S.front()<<" ";
		p=S.front();
		S.pop();
		for(i=adj[p].begin();i!=adj[p].end();i++){
			if(vis[*i]==false){
				vis[*i]=true;
				S.push(*i);
			}
		}
	}
}
int main(){
	int V,E,i,u,w,a;
	cout<<"Enter the number of vertices : ";
	cin>>V;
	graph g(V);
	cout<<"Enter the number of edges : ";
	cin>>E;
	for(i=1;i<=E;i++){
		cout<<"Enter "<<i<<"th edge :";
		cin>>u>>w;
		g.addEdge(u,w);
	}
	cout<<"Enter starting of traversals : ";
	cin>>a;
	cout<<"BFS of graph is : ";
	g.BFS(a);
	cout<<endl<<endl;
	cout<<"DFS of graph is : ";
	g.DFS(a);
	return 0;
}

