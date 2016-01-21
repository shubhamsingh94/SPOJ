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
 
char a[105][105];
bool visited[105][105];
 
int x[8] = {0,0,1,-1,1,1,-1,-1};
int y[8] = {1,-1,0,0,1,-1,1,-1};
 
string s = "ALLIZZWELL";
int row,col;
 
bool valid(int b, int c){
    if(b>=0 && b<=row && c>=0 && c<=col)
        return true;
    return false;
}
 
bool dfs(char a[105][105], int p,int q, int index){
    if(index==10)
        return true;
    
    visited[p][q] = true;
    int b,c,i;
    lp(i,0,8){
        b = p+x[i];
        c = q+y[i];
        if(valid(b,c)){
            if(a[b][c]==s[index] && !visited[b][c] && dfs(a,b,c,index+1)){
                return true;
            }
        }
    }
    visited[p][q] = false;
    return false;
}
 
int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
 
    while(t--){
        mem(visited,false);
        int flag=0;
        cin >> row >> col;
        lp(i,0,row)
            lp(j,0,col)
                cin >> a[i][j];
 
        lp(i,0,row){
            lp(j,0,col){
                if(a[i][j]=='A' && dfs(a,i,j,1)){
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
 
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
 
    }
 
 
    return 0;
} 