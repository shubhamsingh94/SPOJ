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
        vpii v;
        int x;

        lp(i,0,m-1){
            cin >> x;
            v.pb(mp(x,1));
        }

        lp(i,0,n-1){
            cin >> x;
            v.pb(mp(x,0));
        }

        sort(allr(v));

        int y=1,ans=0;
        x=1;
        lp(i,0,m+n-2){
            if(v[i].s==1){
                ans += v[i].f * y;
                x++;
            }else{
                ans += v[i].f * x;
                y++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
} 