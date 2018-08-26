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

/* -----  2018/08/26  Problem: yukicoder 253  / Link: http://yukicoder.me/problems/no/253  ----- */
/* ------問題------

ユキコちゃんとあなたはロウソクを使ったゲームをします。

ロウソクは最初 X cmあります。X は 10 以上 109 以下のある整数です。
ゲーム中ユキコちゃんはロウソクを見ることができますが、あなたは見ることはできずロウソクの最初の長さも知りません。
ゲームは次の様に進行します。

ユキコちゃんがロウソクに火をつけます。
あなたはユキコちゃんにある非負整数 Y について「現在のロウソクの長さは Y cmですか？」と質問できます。
ユキコちゃんは現在のロウソクの長さが Y cmより「短い」か「長い」か「等しい」かをあなたに答えます。
ロウソクが1cm短くなります。ただしすでに燃え尽きている場合、つまり0cmの場合は0cmのままです。
あなたがまだ質問したい場合は2.に戻る。そうでないなら終了。
100回までの質問でロウソクの最初の長さ X を当ててください。

-----問題ここまで----- */
/* -----解説等-----

質問するときに、経過時間も引いてしまえば良い。

----解説ここまで---- */

int ask(int x) {
	cout << "? " << x << endl;
	int res; cin >> res;
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int L = 10; int R = 1e9 + 1;
	int cnt = 1;
	int firstResponse = ask(90);
	if (firstResponse != 1) {
		FOR(i, 0, 99) {
			if (ask(0) == 0) {
				L = cnt;
				break;
			}
			cnt++;
		}
	}
	else {
		FOR(i, 0, 100 - 1) {
			int mid = (L + R) / 2;
			int response = ask(mid-cnt);
			if (response == 0) {
				L = mid;
				break;
			}
			else if (response == -1) {
				R = mid;
			}
			else {
				L = mid;
			}
			cnt++;
		}
	}


	int ans = L;

	cout << "! " << ans << "\n";

	return 0;
}
