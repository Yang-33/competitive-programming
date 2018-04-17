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

/* -----  2018/04/17  Problem: yukicoder 088  / Link: http://yukicoder.me/problems/no/088  ----- */
/* ------問題------

リバーシ(orしろくろ、オセロ)と呼ばれる、８×８マスの盤と表裏が白黒になっている６４枚の石を使うボードゲームがあります。
今、織田くんとユキコちゃんはこのリバーシで遊んでいます。
しかし、少し疲れたのでゲームの途中ですが休憩することにしました。
休憩を終えてゲームを再開しようとしましたが、二人はなんと次がどちらの手番だったか忘れてしまったのです。
先手(黒番)がどちらだったか、そしてお互いに一回もパスをしなかったことだけは覚えています。
現在の盤の状態から次どちらが石を置けばいいのか二人に教えてあげてください。
なお、次の手番のプレイヤーがパスをすることはないとします。

-----問題ここまで----- */
/* -----解説等-----

盤面にある個数の偶奇から次の番がわかる。  こういうのはxorで一行に収められる。  

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string y = "yukiko";
	string o = "oda";
	vector<string>m(8);
	int cnt = 0;
	FOR(i, 0, 8) {
		cin >> m[i];
		FOR(j, 0, 8)if (m[i][j] == '.') {
			cnt++;
		}
	}
	cout << ((s != o) ^ (cnt % 2) ? y : o) << endl;

	return 0;
}
