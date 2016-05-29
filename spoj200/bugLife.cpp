#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int sex[2005];
int visited[2005];
int suspicious;

vector< vector<int> > graph;

void exploreAndMark(int bug)
{
    queue <int> q;
    q.push(bug);
    sex[bug] = 0;
    visited[bug] = 1;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for(int i = 0; i < graph[current].size(); i++)
        {
            if(visited[graph[current][i]]==0)
            {
                q.push(graph[current][i]);
                visited[graph[current][i]] = 1;
                sex[graph[current][i]] = 1 - sex[current];
            }
            else if ( sex[current] == sex[graph[current][i]])
            {
                suspicious = 1;
                return;
            }
        }
    }
}

int main()
{   ios_base::sync_with_stdio(false);
    int t; cin>>t;
    for(int testCase = 1; testCase <= t; testCase++)
    {
        int numBugs; int interactions;
        cin>>numBugs>>interactions;
        
        graph.clear();
        graph.resize(numBugs+1);

        suspicious = 0;

        while(interactions--)
        {
            int a,b;  cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        memset(visited, 0, sizeof(visited));
        memset(sex, 0, sizeof(sex));

        for(int bug = 1; bug<=numBugs; bug++)
        {
            if(visited[bug]==0)
            {
                exploreAndMark(bug);
                if(suspicious)
                    break;
            }
        }
        cout<<"Scenario #"<<testCase<<":"<<endl;

        if(suspicious)
            cout<<"Suspicious bugs found!"<<endl;
        else
            cout<<"No suspicious bugs found!"<<endl;
    }

    return 0;
}
