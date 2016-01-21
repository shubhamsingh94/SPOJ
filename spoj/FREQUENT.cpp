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
#define mod 100000

struct data{
    int left,right,f0,f1,f2;
};

int a[100005];
vector<data> M(1000020);

data combine(data & a, data & b){
    data z;
    z.left = a.left;
    z.right = b.right;
    z.f1 = a.f1;
    z.f2 = b.f2;  
    z.f0 = max(a.f0,b.f0);
    if(a.left==b.left)
        z.f1 = a.f1+b.f1;
    if(a.right==b.right)
        z.f2 = a.f2+b.f2;
    if(a.right==b.left)
        z.f0 = max(z.f0,a.f2+b.f1);
    
    return z;
}

void build(int n, int l, int r){
    if(l==r){
        M[n].left = M[n].right = a[l];
        M[n].f0 = M[n].f1 = M[n].f2 = 1;
    }else{
        build(2*n,l,(l+r)/2);
        build(2*n+1,(l+r)/2+1,r);
        M[n] = combine(M[2*n],M[2*n+1]);
    }
}

data query(int n, int l, int r, int x, int y){
    if(l>=x && r<=y)
        return M[n];
    int mid = (l+r)/2;
    if(y<=mid)
        return query(2*n,l,mid,x,y);
    else if(x>mid)
        return query(2*n+1,mid+1,r,x,y);
    else{
        data a,b;
        a = query(2*n,l,mid,x,y);
        b = query(2*n+1,mid+1,r,x,y);
        return combine(a,b);
    }
}

int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        int n,q;
        cin >> n;
        if(n==0)
            break;
        cin >> q;

        lp(i,0,n)
            cin >> a[i];

        int x,y;
        build(1,0,n-1);

        while(q--){
            cin >> x >> y;
            x--,y--;
            cout << query(1,0,n-1,x,y).f0 << "\n";
        }
    }

    return 0;
}