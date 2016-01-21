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

int dp[1005][1005];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        string a,b;
        cin >> a >> b;

        if(a[0]=='*' && b[0]=='*')
            break;

        int m,n;
        m = a.size();
        n = b.size();

       // cout << a << ":" << b << "\n";

        int c[26];
        mem(c,-1);

        lp(i,0,m){
            if(c[a[i]-'a']==-1){
                c[a[i]-'a'] = i;
            }
        }
        
        lp(i,0,m+1){
            lp(j,0,n+1){
                if(i==0 || j==0){
                    dp[i][j] = max(i,j);
                }else if(a[i-1]==b[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    if(i>1 && j>1 && a[i-1]==b[j-2] && a[i-2]==b[j-1]){
                        dp[i][j] = 1 + dp[i-2][j-2];
                    }else if(i>1 && j>1 && a[i-1]==b[j-1] && a[i-2]==b[j-1]){
                        dp[i][j] = 1 + dp[i-2][j-2];
                    }else if(i>1 && j>1 && a[i-1]==b[j-2] && a[i-2]==b[j-1]){
                        dp[i][j] = 1 + dp[i-2][j-2];
                    }else
                        dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }

        lp(i,1,m+1){
            lp(j,1,n+1){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }

        cout << dp[m][n] << "\n";

    }

    return 0;
}