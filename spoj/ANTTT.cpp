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

int pnt[1005];

int find(int x){
    if(pnt[x]!=x){
        pnt[x] = find(pnt[x]);
    }
    return pnt[x];
}

void un(int x, int y){
    pnt[x] = y;
}

int x[1005][2];
int y[1005][2];

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,f;
    cin >> t;

    while(t--){
        int n,m,r1,r2,a,b;
        cin >> n >> m;

        lp(i,1,n+1)
            pnt[i] = i;

        lp(i,0,n){
            cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
        }

        int num1,num2,den1,den2,gcd;
        double x1,y1,x2,y2,x3,y3,x4,y4;
        double px;

        lp(i,0,n){
            lp(j,i+1,n){
                f=0;

                x1 = x[i][0];
                y1 = y[i][0];

                x2 = x[i][1];
                y2 = y[i][1];

                x3 = x[j][0];
                y3 = y[j][0];

                x4 = x[j][1];
                y4 = y[j][1];

                r1 = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
                if(r1 == 0){
                    num1 = y1*x2 - x1*y2;
                    den1 = x2-x1;
                    r1 = __gcd(num1,den1);
                    num1 = num1/r1;
                    den1 = den1/r1;

                    num2 = y3*x4 - x3*y4;
                    den2 = x4-x3;
                    r1 = __gcd(num2,den2);
                    num2 = num2/r1;
                    den2 = den2/r1;
//                    cout << i << ":" << j<< ":" << num1 << ":" << num2 << ":" << den1 << ":" << den2 << "\n";
                    if(num1 == num2 && den1==den2){
                        if(x3>=x1 && x3<=x2 || x3>=x2 && x3<=x1 || x4>=x1 && x4<=x2 || x4>=x2 && x4<=x1)
                            f=1;
                    }
                }else{
                    px = (x1*y2-y1*x2)*(x3-x4) - (x1-x2)*(x3*y4-y3*x4);
                    px = px/r1;

                    if(px>=x1 && px<=x2 || px>=x2 && px<=x1){
                        if(px>=x3 && px<=x4 || px>=x4 && px<=x3){
                            f=1;
                        }
                    }
                }
                

                if(f==1){
              //      cout << i << ":" << j << "\n";
                    r1 = find(i+1);
                    r2 = find(j+1);
                    if(r1!=r2){
                        un(r1,r2);
                    }
                }
            }
        }

        // lp(i,1,n+1)
        //     cout << pnt[i] << ":";
        // cout << "\n";

        lp(i,0,m){
            cin >> a >> b;
            r1 = find(a);
            r2 = find(b);
            if(r1==r2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}