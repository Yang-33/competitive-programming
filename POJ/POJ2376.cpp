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

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;

#define ALL(a)  a.begin(),a.end()
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

/* -----  2017/12/11  Problem: POJ 2376 / Link: http://poj.org/problem?id=2376  ----- */
/* ------問題------

N(<25000)個の区間が与えられ、1からT(<10^6)を被覆するのに必要な最小の個数を求める問題。

-----問題ここまで----- */
/* -----解説等-----

値が閉区間[L,R]で与えられるので、現在の区間を大きく被覆するようなものを前から構成していけば良い。
たぶんO(N).

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL T;  cin >> N >> T;
	vector<PII>a(N);

	int ok = 1;
	FOR(i, 0, N) {
		cin >> a[i].first >> a[i].second;
	}
	SORT(a);
	// 伸ばせるだけのばす
	LL now = 0;
	for (int i = 0; i < N; i++) {
		if (now >= T)break;
		if (a[i].first <= now + 1) {
			int id; int Max = 0;
			for (int j = i; j < N; j++) {
				if (a[j].first <= now + 1) {
					if (Max < a[j].second) {
						Max = a[j].second;
						id = j;
					}
				}
				else break;
			}
			if (now < Max) {
				now = Max ;
				i = id;
				ans++;
			}
		}
		else {
			ok = 0;
			break;
		}
	}


	if (!ok||now<T)ans = -1;

	cout << ans << "\n";

	return 0;
}