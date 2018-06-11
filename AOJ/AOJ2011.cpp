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

/* -----  2018/06/10  Problem: AOJ 2011 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2011  ----- */
/* ------問題------

はるか昔、八尾氏が残したとされる伝説の秘宝が八王子のどこかに眠っているという。 その在処を示すとされる宝の地図は、いくつかの断片に分割された状態で、八尾氏の n 人の子孫達によって受け継がれている。
今、八尾氏の子孫達は協力してその秘宝を手に入れようとしていた。 ところが、秘宝の在処を指し示す宝の地図の一部分だけでは秘宝を見つけることができない。 そこで、八尾氏の子孫達は全員で集まって地図を 1 ヶ所に集めようとした。 ところが、いざ実行に移そうとしてもなかなか予定が合わずに集まることができない。 しかしこの秘宝に関する情報は、一族において秘密裏に伝えられてきた貴重な情報である。 漏洩の危険性を考慮すると、公共の通信手段を用いて地図をやりとりすることなど問題外である。
そこで、子孫同士が直接会って地図を手渡すということを繰り返すことで、ある 1 人の子孫のところに地図を集めることにした。 なお、1 人が 1 日に会える人数に制限はないが、互いにスケジュールが空いていることが必要である。
あなたの仕事は、それぞれの子孫に対するスケジュールの空いている日のリストから、地図を集めるには最低で何日必要かを求めるプログラムを書くことである。
ちなみに、八尾氏一族の結束は非常に固い。 最終的に地図全体を手にした子孫が、他の子孫を裏切って秘宝を持ち逃げすれば、一族から制裁を受けることになる。その制裁はきわめて恐ろしいものであるため、実際にその子孫が秘宝を持ち逃げすることは事実上不可能である。

-----問題ここまで----- */
/* -----解説等-----

UFを使うと死ぬ。
というのはただの枝分かれではmapの全回収ができないため
実際にシュミレーションします

----解説ここまで---- */

template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;
// やっていけばよい(とは…) 

void solve() {
	int N;
	while (cin >> N, N) {

		VV<int> info(N, V<int>(33, 0));
		FOR(i, 0, N) {
			int k; cin >> k;
			FOR(j, 0, k) {
				int a; cin >> a;
				info[i][a] = 1;
			}
		}
		int ans = -1;
		V<LL> have(N, 0);
		FOR(i, 0, N) {
			have[i] = 1LL << i;
		}
		LL comp = (1LL << (N)) - 1;
		FOR(day, 1, 33) {
			// i さんがjさんと会ってmapを受け渡した
			FOR(i, 0, N) {
				FOR(j, 0, N) {
					if (info[i][day] && info[j][day]) {
						LL bit = have[i] | have[j];
						have[i] = have[j] = bit;
					}
				}
			}
			FOR(i, 0, N) {
				if (have[i] == comp && ans == -1) {
					ans = day;
				}
			}
		}

		cout << ans << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}