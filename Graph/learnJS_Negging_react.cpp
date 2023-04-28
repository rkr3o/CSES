//learn js
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
int start, endpt;
vector<int> tr;

void addnode(int u, int v){
    adj[u].push_back(v);
}

void traverse(int start){
    for(int i=0;i<adj[start].size();i++){
        if(adj[start][i]==endpt){
            return;
        }
        if(adj[start].empty()){
            return;
        }
        else{
            tr.push_back(adj[start][i]);
            traverse(adj[start][i]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        mp[x]=0;
    }

    int e;
    cin>>e;

    for(int i=0;i<e;++i){
        int x,y;
        cin>>x>>y;
        addnode(x,y);
    }
    
    cin>>start>>endpt;
    tr.push_back(start);
    traverse(start);
    tr.push_back(endpt);
    
    sort(tr.begin(), tr.end());
    for(int i=0;i<tr.size();i++){
        cout<<tr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

///////////////////////////////////////// negging react
#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
vector<pair<int,int>>adj[N];
int dist[N];

int main(){
    int n;
    cin >> n;
    unordered_set<int> nodes;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        nodes.insert(x);
    }
    int e;
    cin >> e;
    for(int i=0;i<e;++i){
        int x, y, d;
        cin >> x >> y >> d;
        adj[x].push_back({y,d});
    }
    int src, dest;
    cin >> src >> dest;

    memset(dist, -1, sizeof(dist));
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto i=adj[u].begin();i!=adj[u].end();++i){
            int v = (*i).first;
            int weight = (*i).second;
            if(nodes.find(v) != nodes.end() && (dist[v] == -1 || dist[v] > dist[u]+weight)){
                dist[v] = dist[u]+weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[dest] << endl;
    return 0;
}
