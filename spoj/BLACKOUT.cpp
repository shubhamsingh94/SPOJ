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
#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)
// c is container
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define mod 100000

ll a[2005][2005];
ll dp[2005][2005];

ll wt[1005];
ll p[1005];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,q,k;
    cin >> n >> m >> q >> k;

    lp(i,1,n+1){
        lp(j,1,m+1){
            cin >> a[i][j];
        }
    }

    lp(i,1,n+1){
        lp(j,1,m+1){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + a[i][j] - dp[i-1][j-1];
        }
    }

    int x1,x2,y1,y2,num;
    lp(i,1,q+1){
        cin >> x1 >> y1 >> x2 >> y2;
        wt[i] = dp[x2][y2] + dp[x1-1][y1-1] - dp[x1-1][y2] - dp[x2][y1-1];
        p[i] = (x2-x1+1)*(y2-y1+1);
    }

    lp(i,1,q+1){
        lp(j,0,k+1){
            dp[i][j] = dp[i-1][j];
            if(wt[i]<=j){
                dp[i][j] = max(dp[i-1][j-wt[i]] + p[i],dp[i][j]);
            }
        }
    }
    cout << dp[q][k] << "\n";

    return 0;
}