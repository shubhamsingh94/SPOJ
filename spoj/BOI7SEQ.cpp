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


int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int x,y;
    stack<int> st;
    while(n--){
        cin >> x;
        st.push(x);
    }
    int ans=0,f=0;
    while(1){
        x = st.top();
        st.pop();
        y = st.top();
        st.pop();

        if(st.empty()){
            ans += max(x,y);
            break;
        }

        if(x<=y){
            st.push(y);
            ans += y;
        }else{
            if(x>=st.top()){
                ans += max(y,st.top());
            }else{
                ans += x;
            }
            st.push(x);
        }
    }
    cout << ans << "\n";

    return 0;
}