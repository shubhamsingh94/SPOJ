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
 
 
int w,h;
bool visit[55][55];
char adj[55][55];
int ans;
 
bool valid(int x, int y){
	if(x>=0 && x<h && y>=0 && y<w)
		return true;
	return false;
}
 
int a[8]={0,0,1,-1,1,-1,1,-1};
int b[8]={1,-1,0,0,-1,1,1,-1};
 
 
int dfs(int x, int y, char ch){
	visit[x][y] = true;
	int value=0;
	int i;
	lp(i,0,8){
		if(valid(a[i]+x, b[i]+y) && !visit[a[i]+x][b[i]+y] && adj[a[i]+x][b[i]+y]==ch){
			value = max(dfs(a[i]+x,b[i]+y,ch+1),value);
		}
	}
	return value+1;
}
 
int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int k,l,m=1,value;
    while(1){
    	cin >> h >> w;
    	if(h==0 && w==0)
    		break;
 
    	ans = 0;
 
    	lp(i,0,h){
    		lp(j,0,w){
    			cin >> adj[i][j];
                visit[i][j] = false;
    		}
    	}
 
    	lp(i,0,h){
    		lp(j,0,w){
    			if(adj[i][j]=='A'){
    				value = dfs(i,j,'B');
    				ans = max(ans,value);
    			}
    		}
    	}
 
    	cout << "Case " << m << ": " << 	ans << "\n";
    	m++;
    }
 
    return 0;
} 