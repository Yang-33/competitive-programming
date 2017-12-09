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
#define FOR(i, s, e) for (LL(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/12/09  Problem: colocon-qual2018 C / Link: https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_c  ----- */
/* ------問題------

目当ての「マタタビ」を手に入れたあなたは、「すぬけそだて」を本格的に遊び始めました。
都市の道端とはいえやはり自然は弱肉強食の世界で、拾われたばかりのすぬけ君は弱りきっていました。 あなたは、ゲーム内アイテムを食べさせてあげることで、すぬけ君の体力を回復させようとしています。
さて、すぬけ君は好物が整数の書かれたカードであるという変わったねこです。カードをすぬけ君に与えると、あなたはむしゃむしゃと幸せそうにカードを食べるすぬけ君の愛らしい姿を眺めることができます。 しかし、カードを与えているうちに、あなたはカードを食べてもすぬけ君が喜ばないことがあることに気付きました。また、以下の性質を発見しました。
すぬけ君は、その日にこれまでに食べたどのカードに書かれた整数とも互いに素である整数の書かれたカードを食べたとき、喜ぶ。そうでないとき、悲しむ。
今日のカードショップには A 以上 B 以下の整数の書かれたカードが 1 枚ずつ売られています。 あなたは、このうちの 0 枚以上の任意の枚数を購入し、すべてのカードをすぬけ君に与えることにしました。このとき、すぬけ君を 1 度でも悲しませてはいけません。
カードの買い方は何通りあるでしょうか。

-----問題ここまで----- */
/* -----解説等-----

わかってたのにできなくてええってなった
偶数を2回選択してはいけないのは明らかで、
あとは全列挙をする。
これによってO(2^(N/2))とかになって間に合う。

----解説ここまで---- */


/*最大公約数を求める関数(再帰版ユーグリッドの互除法)*/
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

/*最小公倍数を求める関数。最小公倍数の性質( a×b÷[aとbの最大公約数] )を利用。*/
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }


LL A, B;

LL ans = 0LL;

LL dfs(LL a, int havodd, vector<LL>&v) {
	if (a > B) {
		return 1;
	}
	LL ret = 0;
	int ok = 1;
	FOR(i, 0, SZ(v)) {
		if (gcd(v[i], a) > 1)ok = 0;
	}// check

	//if (ok == 0)return 0;
	if (havodd == 0) {// 偶数をせんたくしてない
		ret += dfs(a + 1, 0, v); //no sentaku

		if (ok) {
			v.push_back(a);
			ret += dfs(a + 1, (a % 2) == 0, v);
			v.pop_back();
		}
	}
	else {
		ret += dfs(a + 1, 1, v);// no sentaku

		if (a % 2 == 0) {
			;
		}
		else if(ok) {
			v.push_back(a);
			ret += dfs(a + 1, 1, v);
			v.pop_back();
		}

	}


	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;
	VL aa;
	ans = dfs(A, 0, aa);

	cout << ans << "\n";

	return 0;
}
