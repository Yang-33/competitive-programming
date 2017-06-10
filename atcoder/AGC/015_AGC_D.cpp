#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/05/27  Problem: AGC 015 D / Link: http://agc015.contest.atcoder.jp/tasks/agc015_d  ----- */
/* ------問題------

ぬけす君は、A 以上 B 以下の整数から 1 個以上選んで、それらの整数の bitwise or を取ってできる整数を持っています。 
ぬけす君が持っている整数としてありうるものは何通りあるでしょうか。

-----問題ここまで----- */
/* -----解説等-----

A,Bの頭の数が同じときはそれ以上の数が作れないことが確定しているので、
頭の数字が違うところまで、数を減らしてもよい。
これによって以下、正規化された数について考える。
A=0101...0
B=1001...1
とA,Bの頭の数が違うことが確定している。
[A,B]のかずは必ず作ることができる。
これについてこの間の数にBと同じ桁数の100000..00が存在する。
これをTとする。
[A,T)について作成可能、[T,B]について作成可能である。
B以上の数についても作成可能な場合がある。
これは[A,T)の数でBよりも大きい数が作成可能な場合である。
B=Tのとき、[A,T)の数だけ新たに数を作ることができる。
そうでないとき、Bの二番目に高いbitが00100...00であるとき、T以上の100...00をすべて持つので、
二番目に高いビットより下の桁について00111...11までの数を作ることができる。

また、一番高い桁を除いてAのほうが大きい数を持つ時、さらに大きい数を作ることができる。
その時は[A,T)の最上位ビットを1にしたものを加える。
そうでない時はBの二番目に高い1のbitよりも上のビットも1にできるので最上位ビット1についてはすべての数を作ることができることになる。

あと、正規化したことでA≠NAの場合があるので例外処理をすればよい。

----解説ここまで---- */

ll A, B;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;

	stack<int>a, b;
	ll AA, BB;
	AA = A; BB = B;

	//おんなじ部分は削る
	while (AA != BB) {
		a.push(AA % 2);
		b.push(BB % 2);
		AA /= 2;
		BB /= 2;
	}

	ll RA = 0; ll RB = 0;//正規化済みの数
	while (!a.empty()) {
		RA = RA * 2 + a.top(); a.pop();
		RB = RB * 2 + b.top(); b.pop();
	}
	if (RA == RB) {
		cout << 1 << endl;
		return 0;
	}

	if (RA == 0) {
		ll h = 1;
		while (h <= RB)h *= 2;
		h /= 2;
		ans = 2 * h - 1;
		if (RA != A)ans++;//元の数と違えば2^(桁)通り
		cout << ans << endl;
		return 0;
	}

	if (RA == 1) {
		ll h = 1;
		while (h <= RB)h *= 2;
		h /= 2;
		ans = 2 * h - 1;
		cout << ans << endl;
		return 0;
	}

	ll h = 1;
	while (h <= RB)h *= 2;
	h /= 2;
	debug(h);
	ll ans = h - RA;//[RA,2^(h)=(Bの最高の桁))

	ll h2 = 1;
	while (h + h2 <= RB)h2 *= 2;//RBの二番目の高いビット
	h2 /= 2;

	if (h2 > 0) {
		ans += h2 * 2;//[100...0,1001...0]は2^(二番目のbit)
		ll s = max(h2 * 2, RA);
		ans += h - s;
	}
	else {
		ans += h - RA + 1;
		//100..0には[RA,01111...]までのORをとっても重複する数がないので2*([RA,01111...])+(10000..0)
	}

	cout << ans << endl;

	return 0;
}
