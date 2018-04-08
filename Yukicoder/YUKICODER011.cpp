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

/* -----  2018/04/08  Problem: yukicoder 011  / Link: http://yukicoder.me/problems/no/011  ----- */
/* ------問題------

JenはW×H枚のカードでトランプゲームをしている。
Jenは(表面を見ることができる)手札にあるいずれかのカードと、手札以外にあるカードのマッチするカードの枚数を知りたくなった。

このトランプは、マークがW種類あり、数字は1からHで構成されており、組み合わせの重複はないとする。
ここでマッチするとは、マークまたは数字のどちらかが一致するカードのことである。

今、手札にはN枚のカードがあり、「手札のカード以外」のマッチするカードの枚数を求めてください。

W×H が 23^2 以上となる場合があります。

-----問題ここまで----- */
/* -----解説等-----

H*Wの領域にカードを置くとすると、その垂直、水平方向にカードをマッチさせることができる。
したがってこれでできる格子点を数えれば良い。
これは簡単にできて、あるマーク、ある数字のユニークな出現回数を覚えておけば計算できる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL W, H, N;
	cin >> W >> H >> N;
	vector<PLL>sk(N);
	FOR(i, 0, N) {
		cin >> sk[i].first >> sk[i].second;
	}

	map<LL, int>mark;
	map<LL, int>num;
	int markcnt = 0;
	int numcnt = 0;
	FOR(i, 0, N) {
		if(mark[sk[i].first] == 0)mark[sk[i].first] = 1 , markcnt++;
		if(num[sk[i].second]==0)num[sk[i].second] = 1 , numcnt++;
	}
	LL ans = markcnt * H + numcnt * W - numcnt*markcnt - N;
	cout << ans << "\n";

	return 0;
}
