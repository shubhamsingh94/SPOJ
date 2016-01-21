// #include<bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<vi> vvi;
// typedef vector<vl> vvl;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;
// typedef vector<pii> vpii;
// typedef vector<pll> vpll;
// typedef vector<vpii> vvpii;
// typedef vector<string> vs;
// typedef vector<char> vc;
// typedef vector<bool> vb;
// typedef unsigned long long llu;

// #define lp(i,a,b) for(i=a;i<b;i++)
// #define iter(j,a) for(vector<int>::iterator j = a.begin();j!=a.end();j++)
// #define f first
// #define s second
// #define mp make_pair
// #define pb push_back
// #define gc getchar
// #define mem(a,b) memset(a,b,sizeof(a));

// #define sz(a) int((a).size())
// #define pb push_back
// #define all(c) (c).begin(),(c).end() 
// #define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)
// // c is container
// #define present(c,x) ((c).find(x) != (c).end()) 
// #define cpresent(c,x) (find(all(c),x) != (c).end())



// ll dp[605][605][205];
// ll w[205];
// ll h[205];

// int main(){
//     ll i,j;
//     ios_base :: sync_with_stdio(0);
//     cin.tie(NULL);
//     cout.tie(NULL);


//     int t;
//     cin >> t;
//     while(t--){
//         int wd,ht;
//         cin >> wd >> ht;
//         int n;
//         cin >> n;

//         lp(i,1,n+1){
//             cin >> w[i] >> h[i];
//         }
        
//         int k;

//         lp(i,1,wd+1){
//             lp(j,1,ht+1){
//                 lp(k,1,n+1){
//                     dp[i][j][k] = dp[i][j][k-1];
//                     if(i>=w[k] && j>=h[k]){
//                         dp[i][j][k] = max(dp[i][j][k],dp[i-w[k]][j][k] + dp[w[k]][j-h[k]][k] + w[k]*h[k]);
//                         dp[i][j][k] = max(dp[i][j][k],dp[i][j-h[k]][k] + dp[i-w[k]][h[k]][k] + w[k]*h[k]);
//                     }
//                     if(i==11 && j==11)
//                         cout << dp[i][j][k] << ":";
//                 }
//                 if(i==11 && j==11)
//                     cout << "\n";
//             }
//         }

//         lp(i,1,wd+1){
//             lp(j,1,ht+1){
//                 cout << dp[i][j][n] << " ";
//             }
//             cout << "\n";
//         }

//         ll ans;
//         ans = wd*ht-dp[wd][ht][n];
//         cout << ans << "\n";
//     }


//     return 0;
// }

#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
short t, n, wi, he, i, j, k;
int **w;
scanf("%hd", &t);
while (t--) {
scanf("%hd%hd%hd", &wi, &he, &n);
w = new int*[wi + 1];
for (i = 0; i <= wi; ++i) {
w[i] = new int[he + 1];
for (j = 0; j <= he; ++j) {
w[i][j] = i * j;
}
}
for (i = 0; i < n; ++i) {
scanf("%hd%hd", &j, &k);
w[j][k] = 0;
}
for (i = 0; i <= wi; ++i) {
for (j = 0; j <= he; ++j) {
for (k = 0; k <= i; ++k) {
w[i][j] = min(w[i][j], w[k][j] + w[i - k][j]);
}
for (k = 0; k <= j; ++k) {
w[i][j] = min(w[i][j], w[i][k] + w[i][j - k]);
}
}
}

for(i=1;i<=wi;i++){
    for(j=1;j<=he;j++){
        printf("%d ", i*j-w[i][j]);        
    }
    printf("\n");
}

printf("%d\n", w[wi][he]);
for (i = 0; i <= wi; ++i) {
delete[] w[i];
}
delete[] w;
}
return 0;
}