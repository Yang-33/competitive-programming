#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

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

/* -----  2018/02/23  Problem: 017_agc_b / Link: https://agc017.contest.atcoder.jp/tasks/agc017_b?lang=en  ----- */
/* ------問題------

N 個のマスが一列に並んでいます． 一番左のマスには整数 A が，一番右のマスには整数 B が書かれており，他のマスには何も書かれていません．
青橋君は，何も書かれていないマスに整数を書き込み，次の条件を満たすようにしたいです：
どの隣接する 2 マスについても，書かれている整数の差は C 以上 D 以下である．
青橋君は，この条件を満たす限り，いくらでも大きい整数や小さい整数を書き込むことができます． 青橋君が条件を満たすように整数を書き込むことができるかを判定してください．

-----問題ここまで----- */
/* -----解説等-----

つくれる値は連続しているので、その上限と下限だけを実際に確認してこれがBを含んでいるかを確認すればよい。

----解説ここまで---- */

LL N, A, B, C, D;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> A >> B >> C >> D;
	if (A > B)swap(A, B);
	if (C > D)swap(C, D);
	FOR(i, 0, N - 1) {
		{
			LL up = i*D - (N - i - 1)*C + A;
			LL down = i*C - (N - i - 1)*D + A;
			if (down <= B&&B <= up)ans = 1;
		}
		{
			LL up = -(i*D - (N - i - 1)*C) + A;
			LL down = -(i*C - (N - i - 1)*D) + A;
			if (down <= B&&B <= up)ans = 1;
		}
	}

	cout <<(ans?"YES":"NO") << "\n";

	return 0;
}
