#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;


void bfs(map< int, set<int> > graph, int primaryNode, int level[1005]){
    int visited[1005]={0};
    queue<int> q;
    q.push(primaryNode);
    level[primaryNode]=0;
    while(!q.empty()){
         int primaryNode = q.front();
         q.pop();
           for(std::set<int>::iterator it = graph[primaryNode].begin(); it!=graph[primaryNode].end(); it++){
                  if(visited[*it]==0){
                             q.push(*it);
                             level[*it]=depth;
    			     visited[*it]=1;                        
     			 }
                  }
            visited[primaryNode]=1;
         }
    
}

int main(){
 int t,n,m; cin>>t;

 while(t--){
   int level[1005];
   map <int, set<int> > graph;
   int node1, node2, primaryNode;

   cin>>n>>m;
   for(int i=0; i<m; i++){
     cin>>node1>>node2;
     graph[node1].insert(node2);
     graph[node2].insert(node1);
   }

   cin>>primaryNode;
   bfs(graph,primaryNode,level);

   for(int i=1;i<=n;i++)
      if(i!=primaryNode){
        if(level[i]==0)cout<<-1<<" ";
        else
          cout<<level[i]*6<<" ";
      }
      cout<<"\n";
 }

}
