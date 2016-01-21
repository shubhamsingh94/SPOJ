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
#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)
// c is container
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

int a[1005][1005];
ll h[1005];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
    	int m,n;
    	cin >> m >> n;

    	char x;
    	lp(i,1,m+1){
    		lp(j,1,n+1){
    			cin >> x;
    			if(x=='R')
    				a[i][j] = 0;
    			else
    				a[i][j] = 1;
    		}
    	}

    	lp(i,2,m+1){
    		lp(j,1,n+1){
    			if(a[i][j]==1)
    				a[i][j] = a[i-1][j] + a[i][j];
    			else
    				a[i][j] = 0;
    		}
    	}

    	ll value=0,ans;
    	lp(j,1,m+1){

	    	lp(i,1,n+1){
	    		h[i] = a[j][i];	
	    	}

	    	stack<long int> st;

	    	ll y,l,r;
	    	ans=0;

	    	lp(i,1,n+1){
	    		if(st.empty() || h[i]>=h[st.top()]){
	    			st.push(i);
	    		}else{
	    			while(!st.empty() && h[i]<h[st.top()]){
	    				l = st.top();
	    				st.pop();
	    				y = h[l] * (st.empty() ? i-1 : i-st.top()-1);
	    	//			cout << l << ":" << y << "\n";
	    				if(ans < y){
	    					ans  = y;
	    				}
	    			}
	    			st.push(i);
	    		}
	    	}

	    	while(!st.empty()){
	    		l = st.top();
	    		st.pop();
	    		y = h[l] * (st.empty() ? i-1 : i-st.top()-1);
	    		if(ans<y)
	    			ans = y;
	    	}

	    	if(value<ans)
    			value = ans;
    	}
    	cout << value*3 << "\n";
    }

    return 0;
}