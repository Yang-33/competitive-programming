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

/* -----  2018/10/02  Problem: yukicoder 322  / Link: http://yukicoder.me/problems/no/322  ----- */
/* ------問題------

Geometry Dash は N 個の難所からなるステージをクリアするゲームです． このゲームの製作者であるあなたは，必要なクリア時間が最大になるように N 個の難所の順番を決めることにしました． このゲームのクリア時間は以下のように計算されます．
N 個の難所には，それぞれ通過に必要な時間 Ti と難易度 Di ( i=1,2,…,N ) が決まっています．また，N 個の難所はあらかじめ決められた順番通りに辿る必要があります． i 番目の難所は， 到達する直前の到達回数が Di 回以上のときに通過することができます．ただし，到達回数はそれぞれの難所について独立に数えるものとします． 到達回数が Di 回未満のときは，到達してから Ti/2 時間経過した後に，開始地点に戻され，ふたたび 1 つ目の難所から辿りはじめます． クリア時間は，N 個の難所を決められた順番ですべて辿るために必要な時間の合計です．ただし，難所の間を移動する時間や開始地点に戻る時間は無視してください．
例えば， 3 個の難所が前から順番に T={2,6,4}, D={1,2,1} となるように並べられていた場合， クリア時間は 33 であり，以下の図のように計算されます． 
クリア時間を最大化するような N 個の難所の順番を計算して出力してください．複数の候補がある場合はどれでも出力してかまいません．

-----問題ここまで----- */
/* -----解説等-----

サンプルが親切すぎるだろ
エスパーすれば良い
実際、2個の比較をすると、その式がちゃんと出てくるので嬉しい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	struct box {
		LL a, b;
		int id;
		box(LL a,LL b, int id):a(a),b(b),id(id){}
		bool operator < (const box& r)const {
			return r.a*b < r.b*a;
		}
	};
	VI t(N), d(N);
	FOR(i, 0, N) {
		cin >> t[i];
	}
	FOR(i, 0, N) {
		cin >> d[i];
	}
	vector<box> boxes;
	FOR(i, 0, N) {
		boxes.push_back(box(t[i], d[i], i + 1));
	}
	SORT(boxes);
	for (auto it : boxes) {
		cout << it.id << " ";
	}cout << endl;

	return 0;
}
