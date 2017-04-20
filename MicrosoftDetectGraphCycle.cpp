#include<cstdio>
#include<iostream>
#include<list>
using namespace std;
class graphCycle{
		int V;
		list<int> *adj;
	public:
		bool CyclicHelp(int v,bool vis[],int parent);
		bool isCyclic();
		
		graphCycle(int V){                                  //Constructor
			this->V=V;
			adj=new list<int>[V+1];
		}
		void addEdge(int v,int w){							//We are assuming the vertex to start from 1, not zero.
			adj[v].push_back(w);
			adj[w].push_back(v);
		}
		
};
bool graphCycle::CyclicHelp(int v,bool vis[],int parent){
	vis[v]=true;
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++){
		if(vis[*i]==false){
			CyclicHelp(*i,vis,v);
		}
		else if(*i!=parent)
			return true;
	}
	return false;
}
bool graphCycle::isCyclic(){
	bool *vis=new bool[V];
	int i,u;
	for(i=1;i<=V;i++)
		vis[i]=false;
	for(u=1;u<=V;u++){
		if(vis[u]==false){
			if(CyclicHelp(u,vis,-1))
				return true;
		}
	}
	return false;
}
int main(){
	int V,E,i,u,w;
	cout<<"Enter the number of vertices : ";
	cin>>V;
	graphCycle g(V);
	cout<<"Enter the number of edges : ";
	cin>>E;
	for(i=1;i<=E;i++){
		cout<<"Enter "<<i<<"th edge :";
		cin>>u>>w;
		g.addEdge(u,w);
	}
	bool c=g.isCyclic();
	if(c)
		cout<<"Yo EXISTS cycle !!";
	else cout<<"NOOOOO FUCKING CYCLE !!!";
	
	return 0;
}
