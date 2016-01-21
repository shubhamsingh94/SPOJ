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

ll h[100005];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
    	int n;
    	cin >> n;
    	if(n==0)
    		break;

    	lp(i,1,n+1){
    		cin >> h[i];
    	}

    	stack<long int> st;

    	ll ans = 0,y,l,r;

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
    	//	cout << l << ":" << y << "\n";
    		if(ans<y)
    			ans = y;
    	}

    	cout << ans << "\n";
    }
}