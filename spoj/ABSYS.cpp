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
 
int convert(string s){
	int n=sz(s);
	int i;
	int ans=0;
	lp(i,0,n){
		if(!isdigit(s[i]))
			return -1;
		else
			ans = ans*10+(s[i]-'0');
	}
	return ans;
}
 
int main(){
    ll i,j;
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t,x;
    cin >> t;
    cin.ignore();
    while(t--){
    	string s1,s2,s3,s4,s5;
		cin >> s1 >> s2 >> s3 >> s4 >> s5;
		int v1,v2,v3;
		v1 = convert(s1);
		v2 = convert(s3);
		v3 = convert(s5);
		if(v1<0)
			v1 = v3-v2;
		else if(v2<0)
			v2 = v3-v1;
		else
			v3 = v1+v2;
 
		cout << v1 << " + " << v2 << " = " << v3 << "\n";
    }
 
    return 0;
} 