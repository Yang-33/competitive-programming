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

/* -----  2018/05/05  Problem: yukicoder 151  / Link: http://yukicoder.me/problems/no/151  ----- */
/* ------問題------

長さ N の区間 [0,N) の釣り堀で魚釣りをします。

全ての魚は以下の規則に従って動きます。
時刻 t で左向きで位置 x にいる魚は時刻 t+1 で、位置 x−1 に向きを変えずに移動する。
ただし、x=0 の魚(位置 x−1 に移動出来ない魚)は、そのままの位置で右向きに向きを変える。
同様に、時刻 t で右向きで位置 x にいる魚は時刻 t+1 で、位置 x+1 に向きを変えずに移動する。
ただし、x=N−1 の魚(位置 x+1 に移動出来ない魚)は、そのままの位置で左向きに向きを変える。
(つまり、魚から見て正面に移動できれば 1 進み、移動できなければそのまま反転する。)

はじめ t=0 では、釣り堀に魚は存在しません。
各時刻 t (1≤t≤Q) において、以下の 3 種類のいずれかのクエリが与えられるので Q コのクエリを順番に処理してください。
t 番目のクエリ(1-indexed)は、時刻 t で実行されます。
'L y z' ー 位置 y に z 匹の魚が左向きに放たれる。( z 匹の魚は全て左を向く)
'R y z' ー 位置 y に z 匹の魚が右向きに放たれる。( z 匹の魚は全て右を向く)
'C y z' ー 時刻 t で区間 [y,z) 内にいる魚の総数を出力する。

-----問題ここまで----- */
/* -----解説等-----

魚が移動するのは相対的に見れば、区間が移動するように見える。
右へ移動する魚を管理する区間と、左へ移動する魚を管理する区間を準備する。
右へ移動する魚では区間を左に、左へ移動する魚では区間を右に移動させれば良い。
反射するときは、区間から外れるときなので反対の管理側へ移動させればよい。

----解説ここまで---- */

template<typename type>
struct BIT0 { // 0-index
	int N;
	vector<type> data;
	BIT0(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
	}
	void add(int i, type w) { // a[i] += w
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [0,i)
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r)
	type sum(int l, int r) {
		return sum(r) - sum(l);
	}
	type point(int p) {
		return sum(p, p + 1);
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q; cin >> N >> Q;

	BIT0<LL> bitR(N + Q + 10);
	BIT0<LL> bitL(N + Q + 10);

	int Lpoint = 0, Rpoint = Q;
	LL ans;

	FOR(i, 0, Q) {
		char x; LL y, z;
		cin >> x >> y >> z;

		Lpoint++, Rpoint--;
		{
			LL LEnd = bitL.point(Lpoint - 1);
			bitR.add(Rpoint, LEnd);
		}
		{
			LL REnd = bitR.point(Rpoint + N);
			bitL.add(Lpoint + N - 1, REnd);
		}
		if (x == 'R') {
			bitR.add(Rpoint + y, z);
		}
		else if (x == 'L') {
			bitL.add(Lpoint + y, z);
		}
		else if (x == 'C') {
			ans = bitL.sum(Lpoint + y, Lpoint + z) + bitR.sum(Rpoint + y, Rpoint + z);
			cout << ans << "\n";
		}
	}

	return 0;
}
