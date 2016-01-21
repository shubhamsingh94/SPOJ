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


ll nCR(ll n, ll k){
    ll r=1,ans=1;

    if(k>n-k)
        k = n-k;

    while(r!=k+1){
        ans = (ans*n)/r;
        r++;
        n--;
    }

    return ans;
}

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    while(getline(cin,a)){
     //   cout << a << "\n";

        ll b[26];
        mem(b,0);
        ll n = a.size(); 
        ll len=0;
        lp(i,0,n){
            if(a[i]>='a' && a[i]<='z'){
                b[a[i]-'a']++;
                len++;
            }else if(a[i]>='A' && a[i]<='Z'){
                b[a[i]-'A']++;
                len++;
            }
        }

        // lp(i,0,26)
        //     cout << b[i] << " ";
        // cout << "\n";

        ll x=0,y=0;
        lp(i,0,26){
            if(b[i]>0)
                x++;
            if(b[i]%2==1)
                y++;
        }

        if(x==0){
            cout << "1\n";
            continue;
        }

        if(len%2==1){
            if(y>1){
                cout << "0\n";
                continue;
            }

            ll ans=1;
            i=0;
            x = (len-1)/2;
            while(i!=26){
                if(b[i]>0){
                    y = b[i]/2;
                    ans = ans*nCR(x,y);
                    x = x-y;
                }
                i++;
            }
            cout << ans << "\n";
        }else{
            if(y>0){
                cout << "0\n";
                continue;
            }

            ll ans=1;
            i=0;
            x = len/2;
            while(i!=26){
                if(b[i]>0){
                    y = b[i]/2;
                    ans = ans*nCR(x,y);
                    x = x-y;
                }
                i++;
            }
            cout << ans << "\n";
        }

    }

    return 0;
}