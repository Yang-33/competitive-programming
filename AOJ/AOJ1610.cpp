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

/* -----  2018/06/10  Problem: AOJ 1610 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1610  ----- */
/* ------問題------

竹の寿命は数十年あり，一生の最後に花を咲かせて種をつくる． 筑波を旅行していた生物学者の ACM 博士は偶然見かけた竹の花の美しさに魅了され， 竹の花を毎年見られる庭を作りたいと思った． ACM 博士は，竹の品種改良をはじめて，ついに竹の寿命を操作した品種を作る方法を確立した． この方法を使えば，任意の年数で花を咲かせる竹の品種を作ることができる．

種をまいてから k 年で花を咲かせる竹を k 年竹と呼ぶことにしよう． k 年竹は種をまいてから k 年で種を作って枯れる． したがって，さらに k 年後には次の世代が花を咲かせる． このように，k 年竹の種をまくと，k 年周期で花が見られる． 例えば， 15 年竹の種をまくと， 15 年後，30 年後，45 年後というように 15 年ごとに花が見られる．

あなたは，ACM 博士に庭の設計を依頼された．庭はいくつかの区画に区切られている． 1 つの区画では同じ品種の竹しか育てることができない． ACM 博士の依頼は，できるだけ多くの年にどこかの区画で竹の花を見るには， 各区画にどの品種の竹の種をまけばよいかを決めて欲しいというものである．

あなたは，すぐに全ての区画に1年竹の種をまくことを提案した． しかし，ACM 博士によれば寿命の短い竹の品種は作るのが難しいので， 寿命が長い竹だけしか使わない庭を設計して欲しいそうだ． 最初の竹が咲くまで待つのはかまわないが， その後は毎年花が見られるようにして欲しいということだ． 今度は，例えば 10 年竹を使って，今年はある区画に，来年は別区画にというように， 10 年間異なる区画にまき続けることを提案した．そうすれば， 10 年後以降毎年どこかの区画で花が見られる．しかし ACM 博士は， もう全区画に今年種をまくと決めたのだ，と反対した．

-----問題ここまで----- */
/* -----解説等-----

篩っぽくやればよい。

vectorでTLEしたので嫌な気持ちになった

----解説ここまで---- */


int era[7400000];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;

	while (cin >> M >> N, N || M) {
		fill(era, era + 7400000, 0);
		int ans = 0;
		for (int i = M; i < 7400000; i++) {
			if (era[i])continue;
			else {
				if (N > 0) {
					N--;
					era[i] = 1;
					for (int j = 2 * i; j < 7400000; j += i) {
						era[j] = 1;
					}
				}
				else {
					ans = i;
					goto X;
				}
			}
		}
	X:;
		cout << ans << endl;
	}


	return 0;
}