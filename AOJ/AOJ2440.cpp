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

/* -----  2018/06/24  Problem: AOJ 2440 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2440  ----- */
/* ------問題------

ある部屋ではICカードを用いて鍵を開け閉めする電子錠システムを用いている。 このシステムは以下のように動作する。
各ユーザーが持つICカードを扉にかざすと、そのICカードのIDがシステムに渡される。 システムはIDが登録されている時、施錠されいるなら開錠し、そうでないのなら施錠し、それぞれメッセージが出力される。 IDが登録されていない場合は、登録されていないというメッセージを出力し、開錠及び施錠はおこなわれない。
さて、現在システムにはN個のID(U1, U2, ……, UN)が登録されており、施錠されている。 M回ICカードが扉にかざされ、そのIDはそれぞれ順番にT1, T2, ……, TMであるとする。 この時のシステムがどのようなメッセージを出力するか求めよ。

-----問題ここまで----- */
/* -----解説等-----

愚直にシュミレーションすればよい。

----解説ここまで---- */

void solve() {
	int N, M;
	cin >> N;
	set<string> se;
	FOR(i, 0, N) {
		string s;
		cin >> s;
		se.insert(s);
	}
	cin >> M;
	int state = 0;
	FOR(i, 0, M) {
		string s;
		cin >> s;
		if (se.count(s)) {
			if (state == 0) {
				cout << "Opened by " << s << endl;
			}
			else {
				cout << "Closed by " << s << endl;
			}
			state ^= 1;
		}
		else {
			cout << "Unknown " << s << endl;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}