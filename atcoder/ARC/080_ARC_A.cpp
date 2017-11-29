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

/* -----  2017/11/29  Problem: 080_arc_a / Link: https://arc080.contest.atcoder.jp/tasks/arc080_a  ----- */
/* ------問題------

長さ N の数列 a=(a1,a2,…,aN) があります。 各 ai は正の整数です。
すぬけ君の目標は、a の要素を自由に並べ替え、次の条件が成り立つようにすることです。
各 1≤i≤N−1 について、ai と ai+1 の積は 4 の倍数である。
すぬけ君が目標を達成できるか判定してください。

-----問題ここまで----- */
/* -----解説等-----

4 だけならその個数をfour とすれば　2*four + 1だけの範囲をカバーしている。
2 だけなら全ての値が 2 の倍数でなければならない。
両方を考えるとき、fourのみでカバーできないときは左から詰めると考えたとき、
最後の 4 の隣は2の倍数でなければならない。
従って成立しないとき、 2* four + 1 < N  and 2*four + two < N

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int four = 0, two = 0;
	cin >> N;
	FOR(i, 0, N) {
		int a; cin >> a;
		if (a % 4 == 0)four++;
		else if (a % 2 == 0)two++;
	}
	int ok = 1;

	if (N > 2 * four + 1 && N > 2 * four + two)ok = 0;
	cout << (ok ? "Yes" : "No") << "\n";

	return 0;
}
