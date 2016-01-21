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



ll dp[55][55];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,x;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k;
        cin >> k;
        int a[2*(n+3)];

        mem(a,0);
        mem(dp,0);

        lp(i,1,k+1){
            cin >> x;
            a[x]=1;
        }

        dp[1][1]=1;
        dp[1][0]=0;

        lp(i,2,2*n+1){
            lp(j,0,i+1){
                if(j==0){
                    if(a[i]==1){
                        dp[i][0]=0;
                    }else{
                        dp[i][0] = dp[i-1][1];
                    }
                }else{
                    if(a[i]==1){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1];
                    }
                }
            }
        }

        cout << dp[2*n][0] << "\n";
    }

    return 0;
}