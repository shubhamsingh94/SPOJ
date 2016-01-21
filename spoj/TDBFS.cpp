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

#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)
// c is container
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007

bool visit[1005];

void iterative_dfs(vector<vi > & adj, int start){
	stack<int> st;
	mem(visit,false);

	int top,sz,i;
	st.push(start);
	while(st.empty()==false){
		top = st.top();
		st.pop();

		if(!visit[top]){
			visit[top] = true;
			cout << top << " ";
			sz = adj[top].size();
			lp(i,0,sz){
				if(!visit[adj[top][i]])
					st.push(adj[top][i]);
			}
		}
	}
	cout << "\n";
}


void recursive_dfs(vector<vi > & adj, int start){
	visit[start] = true;
	cout << start << " ";
	int i;
	lp(i,0,adj[start].size()){
		if(!visit[adj[start][i]]){
			recursive_dfs(adj,adj[start][i]);
		}
	}
}


void bfs(vector<vi > & adj, int start){
	queue<int> qu;
	mem(visit,false);

	int sz,top,i;
	qu.push(start);
	visit[start] = true;
	cout << start << " ";

	while(qu.empty() == false){
		top = qu.front();
		qu.pop();

		sz = adj[top].size();
		lp(i,0,sz){
			if(!visit[adj[top][i]]){
				visit[adj[top][i]] = true;
				cout << adj[top][i] << " ";
				qu.push(adj[top][i]);
			}
		}
	}
	cout << "\n";
}


int main(){
	ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

	int t,m=1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vi > adj(n+1);
		int x,y,v;
		lp(i,1,n+1){
			cin >> x >> y;
			lp(j,0,y){
				cin >> v;
				adj[x].push_back(v);
			}
		}

		cout << "graph " << m << "\n";
		m++;

		while(1){
			cin >> x >> y;
			if(x==0 && y==0)
				break;

			if(y==0){
				mem(visit,false);
				recursive_dfs(adj,x);
				cout << "\n";
			}else{
				bfs(adj,x);
			}
		}

	}

	return 0;
}