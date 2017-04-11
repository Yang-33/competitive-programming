#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <climits> //INT_MIN/MAX
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/04/11  Problem: NagoyaU contest 4 B / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2700  ----- */
/* ------問題------

JAG王国では国内の空港にそれぞれ空港コードを割り当てて識別をしている．

空港コードは，小文字の英語アルファベットで表記した空港の名前をもとに以下の規則で割り当てられる:

名前の最初の文字と，母音 (a,i,u,e,o) の直後の文字を順に取り出す．
取り出した文字列が k 文字未満ならそれを空港コードとし， k 文字以上なら，その取り出した文字列の先頭 k 文字を空港コードとして使う．
例えば k = 3 のとき，haneda には hnd ， oookayama には ooo ， tsu には t というコードが割り当てられる．

しかしこのコードの割り当て方では，違う名前の空港でも同じコードが割り当てられることがあり，混乱を招いてしまう．
空港の名前の一覧が与えられるので，すべての空港のコードが異なるようにできるか判定して，
可能な場合はすべての空港コードが異なるようにできる最小の k を求め，不可能な場合はその旨を伝えるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

条件を満たす部分文字列を文字列の配列に入れていく。その後もし生成した部分文字列が一致すれば-1,
そうでなければ一致しなくなるような長さを各文字列に対してとり、これの最大値を求めればよい。

----解説ここまで---- */

ll N;
string m = "aiueo";

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	for (;;) {
		cin >> N;
		if (N == 0)break;

		vector<string> S(N);
		FOR(i, 0, N) {
			string s;
			cin >> s;
			S[i] += s[0];
			FOR(j, 0, s.size()) {
				FOR(k, 0, 5) {
					if (s[j] == m[k]) {
						S[i] += s[j + 1];
					}
				}
			}
		}
		int ans = 0;
		FOR(i, 0, N) {
			FOR(j, i + 1, N) {
				if (S[i] == S[j]) {
					ans = INF;
				}
				else {
					int x = 0;
					while (x < S[i].size() && x < S[j].size() && S[i][x] == S[j][x])
						x++;
					ans = max(ans, x + 1);
				}
			}
		}
		if (ans == INF)cout << -1 << endl;
		else cout << ans << endl;


	}


	//cout << ans << endl;
	return 0;
}
