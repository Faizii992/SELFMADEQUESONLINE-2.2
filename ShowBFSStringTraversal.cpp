
#include<bits/stdc++.h>
#define true 1
#define false 0
using namespace std;
int visited[10];
vector < int > adj[10];
queue < int > q;
map<  int, string> mp;
map < string, int > maprev;
void BFS(int s)
{
    visited[s]=true;
q.push(s);
cout<<mp[s]<< " "<<endl;

while(!q.empty())
{
int u=q.front();
q.pop();
for(int i=0;i<adj[u].size();i++)
{

    if(visited[adj[u][i]]==false)
    {
        visited[adj[u][i]]=true;
        q.push(adj[u][i]);
        cout<<mp[adj[u][i]]<<" ";
    }
}
}

}
int main()
{

    int node,edge;
    cin>>node>>edge;

cout<<"Enter two connected :"<<endl;
for(int i=0;i<edge;i++)
{
    adj[i].clear();
    visited[i]=false;
}
for(int i=0;i<node;i++)
{
    string a;
    cin>>a;
    mp[i]=a;
    maprev[a]=i;
}
for(int i=0;i<edge;i++)

{

    string a,b;
    cin>>a>>b;
    for(int i=0;i<edge;i++)
    {
        adj[maprev[a]].push_back(maprev[b]);
         adj[maprev[b]].push_back(maprev[a]);

    }

}

string s;
cout<<"Enter starting node: "<<endl;
cin>>s;
BFS(maprev[s]);

}



