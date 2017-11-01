#include "bits/stdc++.h"
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

/* -----  2017/09/23  Problem: 016_agc_b  / Link: http://agc016.contest.atcoder.jp/tasks/agc016_b  ----- */
/* ------問題------

 N 匹の猫がいます。 猫には 1 から N まで番号が振られています。

各猫はある色の帽子を被っています。 猫 i は「自分を除く N−1 匹の猫が被っている帽子の色の種類数はちょうど ai である」と言っています。

すべての猫の発言と矛盾しないような帽子の色の組合せが存在するか判定してください。

-----問題ここまで----- */
/* -----解説等-----

パズル。
自分がuniqueな色を持っている人とそうでない人は区別がつく。
割り当てを考えるときに、発言した数字が2以上離れたものがあればこれはうそになる。
また数字の小さい方はほかの人が同色であることを示している。
あとはなんか考えるとできる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	FOR(i, 0, N)cin >> a[i];
	SORT(a);
	int same = 1;
	int p = a[0];
	int diff = 0;
	FOR(i, 1, N) {
		if (p != a[i]) {
			same = 0;
		}
		if (p + 2 <= a[i]) {
			diff = 1;
		}
	}
	if (same&&N-1==p) {
		cout << "Yes" << endl;
		return 0;
	}
	else if (same) {
		int pp = a[0];
		if (N >= 2 * pp) {
			cout << "Yes" << endl;
			return 0;
		}
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	else if (diff == 1) {
		cout << "No" << endl;
		return 0;
	}

	int unique_num = 0;
	FOR(i, 0, N) {
		if (a[i] == p) {
			unique_num++;
		}
	}
	FOR(i, 0, N) {
		if (a[i] == p) {
			if (a[i] < unique_num) {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			/*if (a[i] >= N - unique_num - 1) {
				;
			}
			else {
				cout << "No" << endl;
				return 0;
			}*/
		}
	}
	int Nuni = a[N-1]- unique_num;//これだけの色がある
	int sz = 0;
	FOR(i, 0, N) {
		if (a[i] == p)continue;
		else {
			sz = N - i; break;
		}
	}
	if (sz < 2*Nuni) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}