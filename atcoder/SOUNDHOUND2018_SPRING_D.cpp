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

/* -----  2018/01/27  Problem: soundhound2018_spring D / Link: https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_d  ----- */
/* ------問題------

kenkooooさんはSoundHound社で働いています。建物は H 階建てで、1 つのフロアは W 個の東西に直線上につながった部屋からなります。上から i 番目の階の、西から j 番目の部屋を部屋 (i,j) と呼ぶことにします。
いま、kenkooooさんは部屋 (1,1) にいます。kenkooooさんは以下の動作を繰り返すことで、地上階(上から H 番目の階)の部屋から建物を出ることにしました:
部屋 (i,j) にいるとき、存在するなら部屋 (i,j−1)に移動する。
部屋 (i,j) にいるとき、存在するなら部屋 (i,j+1)に移動する。
部屋 (i,j) にいるとき、存在するなら部屋 (i+1,j)に移動する。
ただし、地上階にたどり着いてからも移動をしてもかまいません。
さらに、部屋 (i,j) には Pi,j 円が落ちており、その部屋に初めて入るときkenkooooさんはこれを拾います。
一方で、部屋 (i,j) に入るたびに、入室料として Fi,j 円を払う必要があります。
kenkooooさんはすでに十分大きい金額を今持っているため、途中で手持ちのお金がなくなってしまうことはありません。部屋 (H,j) から建物を出るとき、この建物で最大いくら得ることができるかをすべての 1≦j≦W について求めてください。

-----問題ここまで----- */
/* -----解説等-----

二往復以内で最適な値が出る。
前計算で[,]を計算して端から,->,<-をもてばよい。　←かわいい
ここまでわかったのにコンテスト中に解けないのは流石にダメそう
L(i):=i番目の手前に入って手前に帰ってくる値 ([の形になるやつ、矢印の関係に注意)
R(i):=右に行って返ってくるやつ

ここまで準備できれば右方向と左方向に向かってやれば良い。

----解説ここまで---- */

LL H, W;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	VVL gain(H, VL(W));
	VVL cost(H, VL(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> gain[i][j];
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> cost[i][j];
		}
	}

	VL dp(W, -LINF);
	dp[0] = 0;
	FOR(i, 0, H) {
		VL nxt(W, -LINF);
		VL L(W, 0);
		LL val = 0;
		FOR(j, 0, W) { // [
			L[j] = max(L[j], val);
			val += gain[i][j] - cost[i][j] - cost[i][j];
			val = max(val, gain[i][j] - cost[i][j]);
		}
		VL R(W, 0);
		val = 0;
		FORR(j, W - 1, 0 - 1) { // ]
			R[j] = max(R[j], val);
			val += gain[i][j] - cost[i][j] - cost[i][j];
			val = max(val, gain[i][j] - cost[i][j]);
		}
		LL good = -LINF;
		FOR(j, 0, W) { // ->
			good = max(good, dp[j]);
			good = max(good, dp[j] + L[j] - cost[i][j]);
			good += gain[i][j] - cost[i][j];
			nxt[j] = max(nxt[j], good);
			nxt[j] = max(nxt[j], good + R[j] - cost[i][j]);
		}
		good = -LINF;
		FORR(j, W - 1, 0 - 1) { // <-
			good = max(good, dp[j]);
			good = max(good, dp[j] + R[j] - cost[i][j]);
			good += gain[i][j] - cost[i][j];
			nxt[j] = max(nxt[j], good);
			nxt[j] = max(nxt[j], good + L[j] - cost[i][j]);
		}

		dp.swap(nxt);
	}



	FOR(i, 0, W) {
		cout << dp[i] << endl;
	}

	return 0;
}
