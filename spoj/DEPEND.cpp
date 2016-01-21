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

map<string,int> my;
int adj[9005][9005];
bool visit[9005];
vector<bool> v(9005);
int num=0;


int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string ch,x;
    int y,z;
    num=1;

    while(!cin.eof()){
        cin >> ch;
        if(my[ch]==0){
            my[ch] = num;
         //   v[num] = ch;
            y = num;
            num++;
        }else{
            y = my[ch];
        }
        v[y]=true;

        while(1){
            cin >> x;
            if(x=="0")
                break;
            if(my[x]==0){
                my[x] = num;
               // v[num] = x;
                adj[y][num] = 1;
                adj[y][0]++;
                num++;
            }else{
                z = my[x];
                if(adj[y][z]==0){
                    adj[y][0]++;
                    adj[y][z]=1;
                }
            }
        }
    }

    // lp(i,1,num){
    //     lp(j,0,num){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int ans=0,f;
    while(1){
        f=1;
        lp(i,1,num){
            if(!v[i])
                continue;
            if(adj[i][0]==0){
                ans++;
                f=0;
                adj[i][0] = -1;
                lp(j,1,num){
                    if(adj[j][i]==1){
                        adj[j][i] = 0;
                        adj[j][0]--;
                    }
                }
            }
        }
        if(f)
            break;
    }

    // lp(i,1,num){
    //     lp(j,0,num){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans << "\n";

    return 0;
}