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

int a[100005];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;

        lp(i,0,n)
            cin >> a[i];
        a[n] = mod;

        ll l=0,r=0,sum=a[0],ans=0,value=0;
        while(l<n){
            if(sum<=m){
                if(ans<(r-l+1) || ans==(r-l+1) && value>sum){
                    ans = r-l+1;
                    value = sum;
                }
                r++;
                sum += a[r];
            }else{
                sum -= a[l];
                l++;
            }
        }
        cout << value << " " << ans << "\n";
    }

    return 0;
}