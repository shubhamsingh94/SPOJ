/*
    Author : SHUBHAM SINGH
*/

#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll; 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef unsigned long long llu;
 
#define lp(i,a,b) for(i=a;i<b;i++)
#define iter(j,a) for(vector<int>::iterator j = a.begin();j!=a.end();j++)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define gc getchar
#define mem(a,b) memset(a,b,sizeof(a));
 
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
 
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define __int64 9223372036854775807
#define unsigned__int64 18446744073709551615
 
#define mod 1000000007
 
int n;
int dist[50005],ans;
bool visit[50005];


// USING BFS. 
int bfs(vector<vector<pair<int,int> > > & adj, int src){
    int i;
    queue<int> my;
    mem(visit,false);
    visit[src] = true;
    my.push(src);
    mem(dist,0);
 
    while(!my.empty()){
        int tp = my.front();
        my.pop();
        lp(i,0,adj[tp].size()){
            if(!visit[adj[tp][i].f]){
                visit[adj[tp][i].f]=true;
                dist[adj[tp][i].f] = max(dist[adj[tp][i].f],dist[tp]+adj[tp][i].s);
                my.push(adj[tp][i].f);
            }
        }
    }
 
    int pos=0;
    ans = dist[0];
    lp(i,1,n){
        if(ans<dist[i]){
            ans = dist[i];
            pos=i;
        }
    }
    return pos;
}




// Using DFS
void dfs(vector<vector<pair<int,int> > > & adj, int src){
    int i;
    visit[src] = true;
    int n = adj[src].size();
    lp(i,0,n){
        if(!visit[adj[src][i].f]){
            dist[adj[src][i].f] = dist[src]+adj[src][i].s;
            dfs(adj,adj[src][i].f);   
        }
    }
}

int dfs_node(vector<vector<pair<int,int> > > & adj, int src){
    int i;
    dist[src] = 0;
    lp(i,0,adj.size())
        visit[i] = false;
    dfs(adj,src);

    int pos;
    ans=0;
    lp(i,0,n){
        if(ans < dist[i]){
            ans = dist[i];
            pos = i;
        }
    }
    return pos;
}





 
int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
 
    while(t--){
        cin >> n;
        vector<vector<pair<int,int> > > adj(n);
        int u,v,d;
        lp(i,0,n-1){
            cin >> u >> v >> d;
            u--;
            v--;
            adj[u].pb(mp(v,d));
            adj[v].pb(mp(u,d));
        }
        int start,end;

        // Using DFS
        start = dfs_node(adj,0);
        end = dfs_node(adj,start);

        // Using BFS
        // start = bfs(adj,0);
        // end = bfs(adj,start);
        cout << ans << "\n";
    }
 
    return 0;
}
