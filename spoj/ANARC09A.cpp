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

ll dp[2005][2005];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m=0;
    while(1){
        m++;
        string a;
        cin >> a;
        if(a[0]=='-')
            break;

    //  cout << a << "\n";

        int n = a.size();

        lp(i,0,n+1){
            lp(j,0,n+1){
                dp[i][j] = INT_MAX;
            }
        }
        
        if(a[0]=='{')
            dp[1][1] = 0;
        else
            dp[1][1] = 1;
        
        dp[1][0] = INT_MAX;
        
        lp(i,2,n+1){
            lp(j,0,i+1){
                if(j==0){
                    if(a[i-1]=='{')
                        dp[i][j]=dp[i-1][j+1]+1;
                    else
                        dp[i][j]=dp[i-1][j+1];
                }
                else{
                    if(a[i-1]=='{')
                        dp[i][j] = min(dp[i-1][j-1], 1+dp[i-1][j+1]);
                    else                        
                        dp[i][j] = min(dp[i-1][j-1]+1, dp[i-1][j+1]);
                }
            }
        }

        cout << m << ". " << dp[n][0] << "\n";
    }
}