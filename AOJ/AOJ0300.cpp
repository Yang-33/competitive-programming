#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
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

/* -----  2018/07/23  Problem: AOJ 0300 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0300  ----- */
/* ------問題------

フロッピーキューブをプログラミングで解いてみましょう。フロッピーキューブは図のように表面に色のついた９個の立方体から構成されている立体パズルで、キューブの列を回転させることによって、６つの各面の色をそろえます。
フロッピーキューブに対しては下図のような４種類の操作を行うことができ、一回の操作で、端にある３つの隣接したキューブを１８０度回転することができます。わかりやすいように、図では、上面に＋(赤色)、下面に＊(緑色)、右前面に□(黄色)、左前面に●(青色)、右奥面に○(水色)、左奥面に■紫色) の記号が付いている状態を初期状態としています。
フロッピーキューブの初期状態が与えられるので、パズルを解くために必要な最小の操作回数を求めるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

最悪っぽいけど全探索で間に合う。
枝刈りは必要ない。
swapが本質とかいうアレ。

----解説ここまで---- */

using LL = long long; template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;

// 8回で解けるので枝刈り全探索で良い
// 見えない面は意識する必要がない
// 30面を動かせるようにすれば良い
// 1index
bool check(const V<int>&a) {
	int a1 = a[1];
	int a16 = a[16];
	int a21 = a[21];
	int a10 = a[10];
	int a15 = a[15];
	int a28 = a[28];
	set<int>se({ a1,a16,a21,a10,a15,a28 });
	if (SZ(se) != 6)return false;
	FOR(i, 1, 9 + 1) { //a1
		if (a[i] != a1)return false;
	}
	FOR(i, 16, 18 + 1) {
		if (a[i] != a16)return false;
	}
	FOR(i, 19, 21 + 1) {
		if (a[i] != a21)return false;
	}
	FOR(i, 13, 15 + 1) {
		if (a[i] != a15)return false;
	}
	FOR(i, 10, 12 + 1) {
		if (a[i] != a10)return false;
	}
	FOR(i, 22, 30 + 1) {
		if (a[i] != a28)return false;
	}
	return true;
}
//3つだけ
void SWAPTO(V<int>&a, int mode) {
	if (mode == 0) {//7-9
		swap(a[7], a[22]); // 7
		swap(a[9], a[24]); // 9

		swap(a[10], a[12]); // front
		swap(a[18], a[13]); // side

		swap(a[8], a[23]);//cent
	}
	else if (mode == 1) {// 1-7
		swap(a[1], a[24]); // 1
		swap(a[7], a[30]); // 7

		swap(a[16], a[18]); // front
		swap(a[10], a[21]); // side

		swap(a[4], a[27]);//cent

	}
	else if (mode == 2) { // 3-9
		swap(a[3], a[22]); // 3
		swap(a[9], a[28]); // 9

		swap(a[13], a[15]); // front
		swap(a[12], a[19]); // side

		swap(a[6], a[25]);//cent

	}
	else if (mode == 3) { // 1-3
		swap(a[1], a[28]); // 1
		swap(a[3], a[30]); // 3

		swap(a[21], a[19]); // front
		swap(a[15], a[16]); // side

		swap(a[2], a[29]);//cent

	}
}

int ans;
void f(int tr, const V<int>&a) {
	if (tr == 8) {
		if (check(a)) {
			ans = min(ans, 8);
		}
		return;
	}
	if (check(a)) {
		ans = min(ans, tr);
		return;
	}

	FOR(k, 0, 4) { // 1
		if (ans < tr + 1)return;
		V<int> b = a;
		SWAPTO(b, k);
		f(tr + 1, b);
	}

	return;
}


void solve() {
	int N = 30;
	V<int>a(N + 1);
	FOR(i, 0, N) {
		cin >> a[i + 1];
	}
	ans = 10;
	f(0, a);
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	FOR(i, 0, N)solve();

	return 0;
}