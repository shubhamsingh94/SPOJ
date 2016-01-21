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

int a[10005];
int b[10005];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);

    while(1){
        int m,n;
        cin >> m;
        if(m==0)
            break;

        lp(i,0,m)
            cin >> a[i];

        cin >> n;
        lp(i,0,n)
            cin >> b[i];

        i=0,j=0;
        int sum1=0,sum2=0,ans=0;

        while(i<m && j<n){
            if(a[i]>b[j]){
                sum2 += b[j];
                j++;
            }else if(a[i]<b[j]){
                sum1 += a[i];
                i++;
            }else{
                ans += max(sum1,sum2);
                ans += a[i];
                sum1=0;
                sum2=0;
                i++;
                j++;
            }
        }

        if(i==m){
            while(j<n){
                sum2 += b[j];
                j++;
            }
        }else{
            while(i<m){
                sum1 += a[i];
                i++;
            }
        }
        ans += max(sum1,sum2);
        cout << ans << "\n";
    }

    return 0;
}