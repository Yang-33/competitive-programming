#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <climits> //INT_MIN/MAX
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/04/11  Problem: NagoyaU contest 4 A / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2699  ----- */
/* ------問題------

|x|+|y|=D となるような点のうち、|(x^2+y^2)^(1/2) - E|の最小値を求める

-----問題ここまで----- */
/* -----解説等-----

全探索＆算数

----解説ここまで---- */



int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int D,E;
  for(;;){
    double  ans =1e10;

    cin>>D>>E;
    if(D==0&&E==0)break;
    double d=D;
    double e=E;
    FOR(i,0,D){
      ans=min(ans,abs(sqrt(2*i*i-2*i*d+d*d)-e));
    }
    printf("%.5f\n",ans); 
    }
  return 0;
}
