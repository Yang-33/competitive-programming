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

/* -----  2018/08/27  Problem: yukicoder 259  / Link: http://yukicoder.me/problems/no/259  ----- */
/* ------問題------

長さ N の区間 [0,N) の釣り堀で魚釣りをします。

全ての魚は以下の規則に従って動きます。
時刻 t で左向きで位置 x にいる魚は時刻 t+1 で、位置 x−1 に向きを変えずに移動する。
ただし、x=0 の魚(位置 x−1 に移動出来ない魚)は、そのままの位置で右向きに向きを変える。
同様に、時刻 t で右向きで位置 x にいる魚は時刻 t+1 で、位置 x+1 に向きを変えずに移動する。
ただし、x=N−1 の魚(位置 x+1 に移動出来ない魚)は、そのままの位置で左向きに向きを変える。
(つまり、魚から見て正面に移動できれば 1 進み、移動できなければそのまま反転する。)

はじめ t=0 では、釣り堀に魚は存在しません。
以下の 3 種類のクエリが Q コ与えられるので順番に処理してください。
'L t y z' ー 時刻 t で位置 y に z 匹の魚が左向きに放たれる。( z 匹の魚は全て左を向く)
'R t y z' ー 時刻 t で位置 y に z 匹の魚が右向きに放たれる。( z 匹の魚は全て右を向く)
'C t y z' ー 時刻 t で区間 [y,z) 内にいる魚の総数を出力する。

-----問題ここまで----- */
/* -----解説等-----

前回の自分の解法では解けないので位置についてもう少し考える。
最初左向きにいる魚に関して、pos[i]-tにいることになる。
反転して循環することを考えると、円環を移動していることになる。
このことから、クエリを回転させたほうが良いことになる。
回転は実際にシュミレーションをしてみるとわかる。右向きに移動するものは左向きにクエリを、
逆も同様に処理すれば良い。
shift segtree便利そう…

----解説ここまで---- */

template<typename type>
struct BIT0 { // 0-index
	int N;
	int nn;
	vector<type> data;
	BIT0(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
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
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, Q; cin >> N >> Q;
	int M = 2 * N;
	BIT0<LL>bit(M);
	auto decodeIndex = [&M, &N](LL x) {
		x %= M;
		return (x + M) % M;
	};

	FOR(i, 0, Q) {
		char c; int t, y, z; cin >> c >> t >> y >> z;
		if (c == 'R') {
			int idx = decodeIndex(y - t);
			bit.add(idx, z);
		}
		else if (c == 'L') {
			int idx = decodeIndex(M - y - t - 1);
			bit.add(idx, z);
		}
		else {
			LL ans = 0;
			{ // L 
				int lidx = decodeIndex(y - t);
				int ridx = decodeIndex(z - t);
				if (lidx < ridx) {
					ans += bit.sum(lidx, ridx);
				}
				else {
					ans += bit.sum(0, M) - bit.sum(0, lidx) + bit.sum(0, ridx);
				}
			}

			{ // R
				int lidx = decodeIndex(M - z - t);
				int ridx = decodeIndex(M - y - t);
				if (lidx < ridx) {
					ans += bit.sum(lidx, ridx);
				}
				else {
					ans += bit.sum(0, M) - bit.sum(0, lidx) + bit.sum(0, ridx);
				}
			}



			cout << ans << "\n";
		}

	}

	return 0;
}
