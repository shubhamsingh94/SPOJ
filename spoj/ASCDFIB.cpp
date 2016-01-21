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

long long fib[1100005];
int value[100005];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    fib[1] = 0;
    fib[2] = 1;

    lp(i,3,1100005){
        fib[i] = (fib[i-1]+fib[i-2])%mod;
    }

    int t;
    cin >> t;

    int m=1;
    while(t--){
        cout << "Case " << m << ": ";
        m++;
        mem(value,0);

        int a,b;
        cin >> a >> b;

        i=0;
        while(i!=b+1){
            value[fib[i+a]]++;
            i++;
        }

        int ans=0;
        lp(i,0,100002){
            while(value[i]--){
                cout << i << " ";
                ans++;
                if(ans==100)
                    break;
            }
            if(ans==100)
                break;
        }

        cout << "\n";

    }

    return 0;
}