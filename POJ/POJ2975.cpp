#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;
typedef vector<int> VI;
typedef long long LL;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/03  Problem: POJ 2975 / Link: http://poj.org/problem?id=2975  ----- */
/* ------問題------

NIMをする。
先手が必勝盤面にするための手数は何通りあるか。

-----問題ここまで----- */
/* -----解説等-----

最初ダメだったので式変形をしたのですが、
M個とるときに
(a[i]-M)^(ret^a[i])==0であるかを1<=M<=a[i] についてみればよいのでこれを式変形すると、
if ((a[i]-(ret^a[i])>=1)&&((ret^a[i])>=0))ans++;
となる。
これでいいのだが、
FOR(i,0,N)if(ret<=a[i])ans++;
if(ret==0)ans=0
がダメな理由が分からない。
-> 分かった。
削減したときに上位の桁の数字が変わりうるので普通にだめ

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> N,N) {
		vector<LL> a(N);
		FOR(i, 0, N) {
			cin >> a[i];
		}
		LL ret = 0;
		FOR(i, 0, N) {
			ret ^= a[i];
		}
		ans = 0;
		
		FOR(i, 0, N) {
			if ((a[i]-(ret^a[i])>=1)&&((ret^a[i])>=0))ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}
