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

/* -----  2018/05/05  Problem: yukicoder 159  / Link: http://yukicoder.me/problems/no/159  ----- */
/* ------問題------

USB(コネクタ)について、「2回ひっくり返すと刺さる」と言われることがあります。
太郎君は、USBを刺す時次のような手順に従います。

始め、USBは確率pで表向きで確率(1−p)で裏向きである。
USBを刺すことを試みる。USBが表向きの時確率qでUSBが刺さり、確率(1−q)で刺さらない。USBが裏向きのときUSBは刺さらない。
USBが刺さらなかった場合、USBが表なら裏に、裏なら表にひっくり返し、2に戻る。USBが刺さった場合手順を終える。
USBを刺す各試行は独立と考えてよい。

この手順においてUSBをちょうどi回ひっくり返して終わる確率をPiと表すことにします。太郎君は、P1<P2となるのがどのような場合か気にしています。
p,qが与えられるので、P1<P2ならばYES、そうでない時NOを出力するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

状態は3つしか無いので、手で計算する。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double p, q;
	cin >> p >> q;
	cout << ((1 - p)*q < p*(1 - q)*q ? "YES" : "NO") << endl;
	return 0;
}
