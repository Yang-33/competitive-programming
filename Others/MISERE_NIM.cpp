#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9;

/* -----  2017/09/14  Problem: __CONTEST_NAME__  / Link: http://www.spoj.com/problems/MMMGAME/en/  ----- */
/* ------問題------

Misere Nim

-----問題ここまで----- */
/* -----解説等-----

Nimの逆形。
ゲームの末尾の状態について考えれば、1がたくさんあるときに、これが奇数なら負け、偶数なら勝利である。
一方で山に1以外のものが存在していれば、これを操作して1である山の数の偶奇を調整できるため、これらはすべて勝ちの盤面になる。(1.1.1.1.11)の前の手(相手)の前の手(自分の手)をみればよい
したがってこの状態に移動することが可能かどうかが分かればよい。
この盤面のgrundy数は明らかに0ではないので、途中までは通常のNim戦略(0をわたす)で戦い、この状態になったときに適切な戦法を考えれば勝ちになる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string First = "John";
	string Second = "Brother";

	int T;  cin >> T;
	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		vector<int> g(N, 0);
		int grundy = 0;
		int Mx = -INF;
		for (int i = 0; i < N; i++) {
			cin >> g[i];
			grundy ^= g[i];
			Mx = max(Mx, g[i]);
		}
		if (Mx == 1) {
			cout << ((N % 2 == 1) ? Second : First) << "\n";
		}
		else {
			cout << ((grundy != 0) ? First : Second) << "\n";
		}
	}

	return 0;
}
