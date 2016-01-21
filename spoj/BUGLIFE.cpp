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
int color[2005];
 
bool isbipartite(vector<vector<int> > & adj, int src){
    int i;
    queue<int> my;
    my.push(src);
    color[src] = 1;
    while(!my.empty()){
        int tp = my.front();
        my.pop();
        int m = adj[tp].size();
 
        lp(i,0,m){
            if(color[adj[tp][i]]==-1){
                color[adj[tp][i]] = 1 - color[tp];
                my.push(adj[tp][i]);
            }else if(color[adj[tp][i]]==color[tp]){
                return false;
            }
        }
    }
    return true;
}
 
int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t,m=0;
    cin >> t;
    while(t--){
        m++;
        int x;
        cin >> n >> x;
        vector<vector<int > > adj(n);
        int u,v;
        mem(color,-1);
 
        lp(i,0,x){
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cout << "Scenario #" << m << ":\n";
 
        int f=0;
        lp(i,0,n){
            if(color[i]==-1 && !isbipartite(adj,i)){
                f=1;
                break;
            }
        }
 
        if(f==0){
            cout << "No suspicious bugs found!\n";
        }else{
            cout << "Suspicious bugs found!\n";
        }
    }
 
    return 0;
} 