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

struct data{
    int sum,best,pref,suff;
};

struct data combine(struct data a, struct data b){
    struct data z;
    z.best = max(a.best,max(b.best,a.suff+b.pref));
    z.pref = max(a.pref,a.sum+b.pref);
    z.suff = max(b.suff,a.suff+b.sum);
    z.sum = a.sum + b.sum;
    return z;
}

void build(int n, int l, int r, vi & A, vector<struct data> & M){
    if(l==r){
        M[n].sum = M[n].best = M[n].pref = M[n].suff = A[l];
    }else{
        build(2*n,l,(l+r)/2,A,M);
        build(2*n+1,(l+r)/2+1,r,A,M);
        M[n] = combine(M[2*n],M[2*n+1]);
    }
}

void modify(int n, int l, int r, vi & A, vector<struct data> & M, int pos, int v){
    if(l==r){
        M[n].sum = M[n].best = M[n].pref = M[n].suff = v;
    }else{
        int mid = (l+r)/2;
        if(pos<=mid)
            modify(2*n,l,(l+r)/2,A,M,pos,v);
        else
            modify(2*n+1,(l+r)/2+1,r,A,M,pos,v);
        M[n] = combine(M[2*n],M[2*n+1]);
    }
}

struct data query(int n, int l, int r, vi & A, vector<struct data> & M, int x, int y){
    if(l>=x && r<=y){
        return M[n];
    }else{
        int mid = (l+r)/2;
        if(y<=mid)
            return query(2*n,l,(l+r)/2,A,M,x,y);
        else if(x>mid)
            return query(2*n+1,(l+r)/2+1,r,A,M,x,y);
        else
            return combine( query(2*n,l,(l+r)/2,A,M,x,y), query(2*n+1,(l+r)/2+1,r,A,M,x,y));
    }
}

vector<struct data> M(200005);
vector<int> a(50005);

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n;

    lp(i,0,n)
        cin >> a[i];

    build(1,0,n-1,a,M);

    cin >> m;

    int x,y,p;
    struct data z;
    lp(i,0,m){
        cin >> p >> x >> y;
        if(p==1){
            x--;
            y--;
            z = query(1,0,n-1,a,M,x,y);
            cout << z.best << "\n";
        }else{
            x--;
            modify(1,0,n-1,a,M,x,y);
        }
    }

    return 0;
}