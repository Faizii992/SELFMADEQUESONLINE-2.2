

#include<bits/stdc++.h>
#define V 10
#define white 1
#define grey 2
#define black 3
#define false 0
#define true 1

using namespace std;
stack<int > stck;
stack<int > stck1;
int node,edge;
int flag=0;
vector< int > adj[V];
vector <int > vec;
vector< int > visited;
int mark=0;
vector < int > reversedadj[V];
map < string , int > mp1;
map < int, string > mp2;
int color[V];
void creategraph(int edge)
{
    string a,b;

    for(int i=0;i<edge;i++)
    { cin>>a>>b;
        adj[mp1[a]].push_back(mp1[b]);
        reversedadj[mp1[b]].push_back(mp1[a]);
    }
}
void DFS(int source)
{
    color[source]=grey;
    for(int i=0;i<adj[source].size();i++)
    {
        if(color[adj[source][i]]==white)
        {
            DFS(adj[source][i]);
        }
    }
    stck.push(source);
    stck1.push(source);
    color[source]=black;

}
void DFS2visit(int source)
{
  visited[source]=true;
  cout<<mp2[source]<<" "<<endl;

    for(int i=0;i<reversedadj[source].size();i++)
    {
        if(visited[reversedadj[source][i]]==false)
        {//cout<<source<<" "<<endl;
            DFS2visit(reversedadj[source][i]);
        }
    }




}
int main()
{

    cout<<"Enter node and edges: "<<endl;
    cin>>node>>edge;
    puts("");
cout<<"Enter the strings: "<<endl;
for(int i=0;i<node;i++)
{
    string a,b;
    cin>>a;
    mp1[a]=i;
    mp2[i]=a;
}
    for(int i=0;i<node;i++)
    {
        adj[i].clear();
        reversedadj[i].clear();
        color[i]=white;
    }

visited.assign(node,false);

    cout<<"Enter two vertexes: "<<endl;
    puts("");
    creategraph(edge);


for(int i=0;i<node;i++)
{
    if(color[i]==white)
    {
        DFS(i);

    }

}

cout<<"The Topological sorted result: "<<endl;
puts("");
int flag=0;
while(!stck1.empty())
{
    int v=stck1.top();
    stck1.pop();
    cout<<mp2[v]<<endl;
}

while(!stck.empty())
{
    int u=stck.top();
    stck.pop();
   // cout<<u<<endl;


if(visited[u]==false)
{
    mark++;
    cout<<"Component number :"<<mark<<" has the following elements: "<<endl;
    DFS2visit(u);
}

}
cout<<"Total number of connected components :"<<mark;
//DFS(start);


}
