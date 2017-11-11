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

/* -----  2017/11/11  Problem: POJ 2718 / Link: http://poj.org/problem?id=2718  ----- */
/* ------問題------

増加列な数列a[i]が来る。
このとき列の数字をすべて使って作られる数字二つについて、その最小の差は。

-----問題ここまで----- */
/* -----解説等-----

全探索をすればよいが、next_permutationでやるとうれしい。
変数をLLにすると謎TLEになる。ウケ

----解説ここまで---- */

LL absLL(LL a) {
	return (a >= 0 ? a : -a);
}
int ren(VI &a, int s, int t) {
	int ret = 0;
	if (a[s] == 0&& s + 1 < t)return -1;
	FOR(i, s, t) {
		ret = 10*ret+a[i];
	}

	return ret;
}

int d[2];
void solve(VI &a) {
	int ans = INF;
	int n = SZ(a);
	d[0] = n / 2;
	d[1] = (n + 1) / 2;
	int x, y;
	do {
		for (int i = 0; i < 2; ++i) {
			if (i == 1 && d[1] == d[0]) {
				continue;
			}
			x =ren(a,0, d[i]);
			y = ren(a,d[i], n);
			if (x != -1 && y != -1) {
				ans = min(ans, abs(x - y));
			}
		}
	} while (next_permutation(ALL(a)));
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int id = 0;
		VI a(10);
		while (ss >> a[id]) { id++; }
		a.resize(id);
		solve(a);
	}

	return 0;
	return 0;
}