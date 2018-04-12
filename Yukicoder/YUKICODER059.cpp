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

/* -----  2018/04/12  Problem: yukicoder 059  / Link: http://yukicoder.me/problems/no/059  ----- */
/* ------問題------

列車が出発駅から終点駅まで向かう。
その間に中間駅がN個ある。
列車は必ずすべての中間駅に停車する。
列車は出発駅では荷物を1つも積んでいない。
各中間駅では荷物を１つ積むか降ろすことが決まっている。
荷物には重さWが設定されている。
各中間駅では積むか降ろす荷物の重さが指定される。
・Wが正の数の場合は、重さ|W|の荷物を詰む。
・Wが負の数の場合は、重さ|W|の荷物を降ろす。

ここでひとつ変わったルールがある。

・荷物を積むまえにすでにその荷物の重さ以上の荷物がK個以上列車に積まれている場合にはその荷物を積めない。

この変わったルールのために荷物を積めない場合がある。
ルールに反しなければ必ず荷物を積む。

また、荷物を降ろす場合に指定した重さの荷物が積まれていない場合も考えられる。
この場合は指定された荷物が無いのだから荷物を降ろす必要は無い。
もし指定された重さの荷物があれば必ず1つ降ろす。
最終的に何個の荷物を最終駅まで運ぶことになるだろうか？

-----問題ここまで----- */
/* -----解説等-----

BITを高機能なsetっぽく使うあれ。
値i以上の個数を高速にcountできればよい。
値が非常に大きいときはBITの内部をmapにするか、さきに座標圧縮してからやると解ける。

----解説ここまで---- */
template<typename type>
struct BIT0 { 
	int N;
	int nn;
	vector<type> data;
	BIT0(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [0,i)
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r)
	type sum(int l, int r) {
		return sum(r) - sum(l);
	}
};
LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	VI W(N);
	for (int &w : W) {
		cin >> w;
	}

	BIT0<int> bit(1e6 +6);
	for (int w : W) {
		if (w < 0) {
			if(bit.sum(-w,-w+1))bit.add(-w,-1);
		}
		else {
			if (bit.sum(w,1e6+6)<K) {
				bit.add(w, 1);
			}
		}
	}
	ans = bit.sum(1e6+6);
	cout << ans << "\n";

	return 0;
}
