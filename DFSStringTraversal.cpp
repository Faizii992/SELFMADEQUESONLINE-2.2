#include<bits/stdc++.h>
#define grey 1
#define white 0
#define black 2
using namespace std;


 vector<int> visited;
 queue<int> q;
 int node,edge;

map < string, int> mp1;
map < int ,string> mp2;
 int color[100];
  vector <int> adj[10];


void creategraph(int edge)
{ string a,b;


    for(int i=0;i<edge;i++)
    {
         cin>>a;
    cin>>b;
        adj[mp1[a]].push_back(mp1[b]);
        adj[mp1[b]].push_back(mp1[a]);
    }

}

void DFS(int source)
{  color[source]=grey;
cout<<mp2[source]<<endl;
for(int i=0;i<adj[source].size();i++)
{
    if(color[adj[source][i]]==white)
    {
    DFS(adj[source][i]);
    }
color[source]=black;



}
}

 int main()
 { string startingnode;
     printf("Enter node and edge:");
     cin>>node>>edge;
for(int i=0;i<node;i++)
{
    adj[i].clear();
}
//color.assign(node,white);


for(int i=0;i<node;i++)
{
    string a,b;
    cin>>a;

    mp1[a]=i;
    mp2[i]=a;
}
cout<<"Enter the adjacent nodes:"<<endl;
     creategraph(edge);


 printf("Enter starting node:");
     cin>>startingnode;

     printf("The path of traversal is:");
     DFS(mp1[startingnode]);

 }

