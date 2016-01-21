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


char b[55][55];
ll a[2510][2510];

bool inset[2510];
ll dist[2510];

int m,n;

int caldist(int x1,int y1,int x2,int y2){
    // if(x1<0 || y1<0 || x2<0 || y2<0)
    //     return INT_MAX;
    // else if(x1>=m || x2>=m || y1>=n || y2>=n)
    //     return INT_MAX;

    if(abs(x1-x2)==1 && abs(y1-y2)==0 || abs(x1-x2)==0 && abs(y1-y2)==1){
        if(b[x1][y1]=='$' || b[x2][y2]=='$')
            return 2;
        else if(b[x1][y1]=='X' || b[x2][y2]=='X')
            return 2;
        else{
            if(abs(b[x1][y1] - b[x2][y2])==0)
                return 1;
            else if(abs(b[x1][y1] - b[x2][y2])==1)
                return 3;
            else
                return -1;
        }
    }else{
        return -1;
    }
}

int find_min_dist(int n){
    int x=0,i;
    ll mn = INT_MAX;
    lp(i,0,n){
        if(!inset[i] && mn>=dist[i]){
            mn = dist[i];
            x = i;
        }
    }

    return x;
}

void update(int src,int n){
    int i;
    lp(i,0,n){
        if(a[src][i]!=-1 && dist[i]>dist[src]+a[src][i]){
            dist[i] = dist[src]+a[src][i];
        }
    }
}

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;

        int src;
        char ch;
        lp(i,0,m){
            lp(j,0,n){
                cin >> b[i][j];
                if(b[i][j]=='X'){
                    src = i*n+j;
                }
            }
        }

        for(i=0;i<m;){
            a[(n+1)*i][(n+1)*i] = 0;
            i++;
        }

        lp(i,0,m*n){
            lp(j,i+1,m*n){
                
                a[i][j] = caldist(i/n,i%n,j/n,j%n);
                a[j][i] = a[i][j];
            }
        }

        lp(i,0,m*n){
            lp(j,0,m*n){    
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\n\n";

        n = m*n;

        lp(i,0,n)
            inset[i] = false;

        lp(i,0,n){
            dist[i] = INT_MAX;
        }

        dist[src] = 0;
        inset[src] = true;

        int x=0,y=src;
        lp(j,0,n){
            update(y,n);
            x = find_min_dist(n);
            inset[x] = true;
            y = x;
        }

        cout << "Source:" << src << " distance\n";
        lp(i,0,n){
            cout << i << " " << dist[i] << "\n";
        }

        n = n/m;

        vl v;
        lp(i,0,m){
            lp(j,0,n){
                if(b[i][j]=='$')
                    v.push_back(i*n+j);
            }
        }

        int flag=0;
        lp(i,0,v.size()){
         //   cout << v[i] << "#";
            if(dist[v[i]]==INT_MAX){
                flag=1;
            }
        }

        if(flag==1)
            cout << "-1\n";
        else{
            cout << "OK";
        }

    }

}