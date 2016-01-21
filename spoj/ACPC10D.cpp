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

ll a[100005][3];
ll dp[100005][3];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int m=0;
    while(1){
      m++;
      ll n;
      cin >> n;

      if(n==0)
        break;

      lp(i,0,n)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

      lp(i,0,n)
        lp(j,0,3)
          dp[i][j] = 1000000000;

      dp[0][0] = 0;
      dp[0][1] = 0;

      lp(i,0,n){
        lp(j,0,3){
          if(i==0 && j==0)
            continue;
          if(j==0){
            dp[i][1] = min(dp[i][1],dp[i][0]+a[i][0]);
            dp[i+1][1] = min(dp[i+1][1],dp[i][0]+a[i][0]);
          }else if(j==1){
            dp[i][2] = min(dp[i][2],dp[i][1]+a[i][1]);
            dp[i+1][0] = min(dp[i+1][0],dp[i][1]+a[i][1]);
            dp[i+1][2] = min(dp[i+1][2],dp[i][1]+a[i][1]);
          }else{
            dp[i+1][1] = min(dp[i+1][1],dp[i][2]+a[i][2]);
          }
          dp[i+1][j] = min(dp[i+1][j],dp[i][j]+a[i][j]);
        }
      }
      
      cout << m << ". " << dp[n-1][1]+a[n-1][1] << "\n";
    }

    return 0;
}