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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/10  Problem: ARC 024 C / Link: http://arc024.contest.atcoder.jp/tasks/arc024_c  ----- */
/* ------問題------

Takahashi 市の住人はダジャレが大好きであり、Takahashi 市で上手に渡り歩くためには高度なダジャレ能力が要求される。
Takahashi 市の住人の間では、引っ越してきた相手に様々なダジャレを浴びせることが習慣となっている。最近の Takahashi 市では「アナグラムダジャレ」というものが流行っている。「アナグラムダジャレ」とは、文章の中に、互いに共通部分を持たない、2 つの同じ長さの文字列に関して、一方に出てくる文字列を並べ替えると他方の文字列になるというものである。その文字列の長さが m であるとき、この文章は長さ m の「アナグラムダジャレ」を含むと呼ぶことにする。
例えば、「だじゃれをいったのはだれじゃ」という文章を考えると、先頭 4 文字からなる文字列「だじゃれ」と末尾 4 文字からなる文字列「だれじゃ」は互いに共通部分を持たず、かつ「だじゃれ」を並べ替えると「だれじゃ」になるため、この文章は長さ 4 の「アナグラムダジャレ」を含むということになる。
Takahashi 市に引っ越したばかりの青木君は、Takahashi 市で上手に渡り歩くために、「アナグラムダジャレ」検知能力を身につけたいと考えている。青木君は長さ K の「アナグラムダジャレ」を発見するのが苦手なので、文章生成ソフトを用いて特訓することにした。
ところが文章生成ソフトには長さ K の「アナグラムダジャレ」が含まれているか判定する機能がついていない。
あなたは青木君のために長さ K の「アナグラムダジャレ」が含まれているかを判定するプログラムを作らなければならない。

-----問題ここまで----- */
/* -----解説等-----

可換なhashを作るだけ。交わらないようにずらして計算すればよい。
AOJでこういうのを何度もやった。そもそも問題がつまらない系

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	string s; cin >> s;
	using T = array<int, 26>;
	map<T, int>Map;
	vector<T>arrset(N);
	// K個以上になったらinsert,
	queue<int>q;
	T sub;
	FOR(i, 0, 26) {
		sub[i] = 0;
	}
	FOR(i, 0, N) {
		s[i] -= 'a';
	}
	FOR(i, 0, N) {
		sub[s[i]]++;
		q.push(s[i]);
		if (i >= K - 1) {
			if (i >= K) {
				sub[q.front()]--;
				q.pop();
			}
			arrset[i] = sub;
		}
	}
	// arrset[i]:= 0index, (i-K,i]の状態値になっている
	// なんか遅れて見れれば良い
	// 各要素に対してK個手前分をfindする
	FOR(i, K - 1, N) {
		// arrset[i]をみて、なければi-K+1を入れる
		if (Map.find(arrset[i]) != Map.end()) {
			ans = 1;
		}
		if (i - K + 1 >= K - 1)Map[arrset[i - K + 1]] = 1;
	}

	cout << (ans ? "YES" : "NO") << "\n";

	return 0;
}