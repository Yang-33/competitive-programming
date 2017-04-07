#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)

/* -----  2017/04/08  Problem: Google Code Jam 2017 qual Round B / Link: https://code.google.com/codejam/contest/3264486/dashboard#s=p1  ----- */
/* ------問題------

Tidy Numbersを、左の桁から非減少の講義単調増加列と定義する。
当たられた数以下のTidy Numbersを出力せよ。

-----問題ここまで----- */
/* -----解説等-----

右の桁からその左の桁を比較していった際に、右の桁が大きいようにすればよい。
もしそうでなければ左の桁を-1、右の桁を９、以降の桁も９に書き換えればよい。
左が０になっても整数の桁は減少するだけで問題はない。

またこの問題は1111111....(S.size()),....,11111,1111,111,11,1を貪欲に９個選んだものがTidy Numbersになることから
数値比較をしてもよい。S.size()≦１９より簡単に求められる。

----解説ここまで---- */

ll N;


void solve(int x) {
	string s; ll ans;
	cin >> s;
	s = '0' + s;
	FORR(i, s.size() - 1, 0) {
		if (s[i - 1] > s[i]) {
			int a = s[i - 1] - '0';
			FOR(j, i, s.size())s[j] = '9';
		 s[i - 1] = a - 1 + '0';
		}
	}
	ans = stoll(s);

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
