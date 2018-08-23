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

/* -----  2018/08/23  Problem: yukicoder 216  / Link: http://yukicoder.me/problems/no/216  ----- */
/* ------問題------

K君はプログラミングコンテストに参加するのが大好きです。
今日もFAC(First Accept Contest)に参加します。
FACは変わったコンテストで、各問題一番最初に解いた人にしかスコアが加算されません。
最終的にスコアが一番高かった人が1位になります。

K君はコンテストに少し遅れて参加することになってしまいました。
既にいくつかの問題は解かれてしまっています。
K君はプロなので全ての問題を一瞬で解くことができます。

遅れて参加したK君が1位になれるなら"YES"、できないなら"NO"を出力してください。
1位の人と同じスコアだった場合も1位とみなします。
コンテストにはK君以外に100人参加しています。

-----問題ここまで----- */
/* -----解説等-----

実際に点数を見てあげれば良い

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI score(N); FOR(i, 0, N)cin >> score[i];
	VI who(N); FOR(i, 0, N) cin >> who[i];
	VI personsPoint(101, 0);
	FOR(i, 0, N) {
		personsPoint[who[i]] += score[i];
	}
	int Ksan = personsPoint[0];
	cout << (Ksan==*max_element(ALL(personsPoint))?"YES":"NO") << "\n";

	return 0;
}
