#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dijkstra(const vector<vector<pair<int,int>>> &graph, int start, int end)
{
    priority_queue<pair<int,int>> priQueue;
    vector<int> minLength(graph.size(),-1);
    priQueue.push(make_pair(0,start));
    minLength[start]=0;
    while(!priQueue.empty())
    {
        int vertex=priQueue.top().second;
        int length=priQueue.top().first;
        priQueue.pop();
        for(auto p : graph[vertex])
        {
            if(minLength[p.first]==-1 || length+p.second<minLength[p.first])
            {
                minLength[p.first]=length+p.second;
                priQueue.push(make_pair(minLength[p.first],p.first));
            }
        }
    }
    return minLength[end];


}
int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int,int>>> graph(n+1);
    while(m--)
    {
        int u, v, length;
        cin>>u>>v>>length;
        graph[u].push_back(make_pair(v,length));
        graph[v].push_back(make_pair(u,length));
    }
    cout<<dijkstra(graph,s,t)<<endl;
    return 0;
}
