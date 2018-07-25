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

/* -----  2018/07/26  Problem: AOJ 0258 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0258  ----- */
/* ------問題------

家庭菜園に野菜を植えることにしました。n 粒の種があったので1日に1粒ずつ、n 日かけて n 粒の種をまきました。どの種からも芽が出て、すくすくと育っています。収穫の時期が待ち遠しいものです。
ある日、いつものように苗に水やりをしていると、おかしなことに気づきました。n 本の野菜の苗があるはずなのに、1本多いのです。雑草が生えてきてしまいました。直ちに引っこ抜きたいのですが、困ったことにどの苗もよく似ていて、野菜と雑草の見分けがつきません。
手がかりになるのは、野菜の成長速度です。この野菜は、種をまいてからずっと、1日に決まった長さだけ伸び続けるのです。しかし、この「決まった長さ」というのが何センチメートルなのかはわかりません。また、最初の種を何日前にまいたのかも忘れてしまいました。苗は一列に並んでいますが、唯一覚えているのは、種をまくとき毎日一粒ずつ右から順にまいていったことだけです。
n＋１本の苗の長さを入力し、雑草の長さを出力するプログラムを作成して下さい。

-----問題ここまで----- */
/* -----解説等-----

一個抜いて全探索をする。
なんかO(N)でもできる気がするけどダメだった。

----解説ここまで---- */

template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		V<int>h(N + 1);
		FOR(i, 0, N + 1) {
			cin >> h[i];
		}

		FOR(k, 0, N + 1) {
			V<int> v;
			FOR(i, 0, N + 1) {
				if (i == k) continue;
				v.push_back(h[i]);
			}
			auto isValid = [&](const V<int>&v) {
				int d = v[1] - v[0];
				FOR(i, 0, SZ(v) - 1) {
					if (v[i + 1] - v[i] != d) return false;
				}
				return true;
			};

			if (isValid(v)) {
				cout << h[k] << endl;
				break;
			}
		}
	}
}