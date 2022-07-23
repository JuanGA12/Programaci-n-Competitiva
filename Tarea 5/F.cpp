#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int n, m, visit[N], low[N], pre[N], arts[N];
vector<int> adj[N];
vector<pair<int,int>> puentes;

void read(){
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m;++i){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int i, int p){
    visit[i] = true;
    pre[i] = i;
    low[i] = pre[i];
    int n_hijos = 0;
    for(auto u : adj[i]){
        if(visit[u]){
            if(u!=p) low[i] = min(low[i], pre[u]);
        }else{
            dfs(u, i);
            n_hijos++;
            low[i] = min(low[i], low[u]);
            if (low[u] == pre[u]) puentes.push_back({u, i});
            if (u!=p and low[u]>=pre[i]) arts[i] = 1;
        }
    }
    if(i == p and n_hijos>1) arts[i] = 1;
}
int main()
{
    read();
    dfs(1, 1);
    int test_cases,type,a,b,c,x,y;
    cin >> test_cases;
    while(test_cases--){
        cin >> type;
        if (type == 1)
        {
            cin >> a >> b >> x >> y;
        }
        else
        {
            cin >> a >> b >> c;
            arts[c] ? cout << "no" : cout << "yes";
            cout << endl;
        }

    }
    return 0;
}