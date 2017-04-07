#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl

/* -----  2017/04/08  Problem: Google Code Jam 2017 qual Round A  / Link: https://code.google.com/codejam/contest/3264486/dashboard#s=p0  ----- */
/* ------問題------

一列に並んだ盤面が与えられる。
裏表がそれぞれバラバラに並べられているのでこれをすべて(+)にしたい。
ただし裏返すことができるのは連続したK個だけである。
もしすべて表にすることができればその最小回数を、不可能であればIMPOSSIBLEと出力。

-----問題ここまで----- */
/* -----解説等-----

蟻本で見た…
裏返す回数は各要素に対して二回以上になることはないので端から順番にひっくり返していってすべて表になるかどうか確認すればよい。
正当性を確認するのがなかなか難しいと思う。

----解説ここまで---- */

ll N;


void solve(int x) {
	string S; int K; string ans = "IMPOSSIBLE";
	int cnt = 0;
	cin >> S >> K;
	FOR(i, 0, S.size() - K + 1) {
		if (S[i] == '-') {
			cnt++;
			FOR(j, 0, K) {
				if (S[i + j] == '-')S[i + j] = '+';
				else S[i + j] = '-';
			}
		}
		//debug(S);
	}
	bool flag = true;
	FOR(i, 0, S.size()) {
		if (S[i] == '-')flag = false;
	}
	if (flag)
		cout << "Case #" << x + 1 << ": " << cnt << endl;
	else
		cout << "Case #" << x + 1 << ": " << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		solve(i);
	}

	return 0;
}
