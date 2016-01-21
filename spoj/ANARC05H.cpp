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

char str[30];
int array[30][300];		//returns the number of possibilities (array states->(position,previousSum))
int len;
int
cal (int pos, int pre)
{
  if (pos == len)
    return 1;
  if (array[pos][pre] != -1)
    return array[pos][pre];
  array[pos][pre] = 0;
  int c = 0;
  int sum = 0;
//this is the very important part of the solution.Here you are keeping on adding digits.if the sum(till ith digit)>=pre
//you call the subproblem cal(i+1,sum) .this process will be recursively going till the pos==length of input string
  	int i;
  lp (i, pos, len)
  {

    sum += str[i] - '0';
    if (sum >= pre)
      c += cal (i + 1, sum);
  }
  return (array[pos][pre] = c);
}

int
main ()
{
int i,j;
  int t = 1;
  while (1)
    {
      scanf ("%s", str);
      len = strlen (str);
      if (!(str[0] >= '0' && str[0] <= '9'))
	break;
      lp (i, 0,30) memset (array[i], -1, sizeof array[i]);
      printf ("%d. %d\n", t++, cal (0, 0));
    }
}
