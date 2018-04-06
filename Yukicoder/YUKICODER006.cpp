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

/* -----  2018/04/06  Problem: yukicoder 006  / Link: http://yukicoder.me/problems/no/006  ----- */
/* ------問題------

ハッシュに興味を持ったFrankは、ハッシュアルゴリズムに、このようなアルゴリズムを考えた。
自然数の各桁を足した合計、それも二桁以上になる場合は、それを繰り返す。
つまり、
hash(4)=4,
hash(17)=hash(1+7)=hash(8)=8,
hash(119)=hash(1+1+9)=hash(11)=hash(2)=2のようになる。

しかし実際使ってみるとコリジョン（計算値がかぶってしまうこと）が多く、あまり使い物にならなかった。

それでも諦めきれないFrankに対して、あなたは「落ち着け、素数を数えるんだ」と言った。
やけになったFrankは、自然数 [K,N]　(K≤i≤N の範囲ということ） の中の連続した素数列で上記のハッシュアルゴリズムを使用し、コリジョンが起こらない（値がかぶらない）最大の範囲を考えようとしている。
言った手前、申し訳なくなったあなたは、Frankの代わりに求めてあげることにした。

範囲[K,N] (K≤i≤N の範囲)に含まれる連続した素数列で上記のハッシュアルゴリズムを使用した時に、
すべて異なる値になる最大の長さの素数列を求め、元の素数列の最初の素数を求めてください。
(複数同じ長さの素数列がある場合は、数が大きい方を選択する）

-----問題ここまで----- */
/* -----解説等-----

しゃくとり、年越しでバグらせず書けるようになった。
桁に含まれる9は無視できるから、今回のhash値は(n-1)%9 + 1 ということに後から気がついた

----解説ここまで---- */

#define primeN 400002 //78493個
// 78493番目までの素数のリストを返す Ｏ(NloglogN)
vector<int > make_prime() {
	vector<int >a;
	bool prime[primeN + 1];// 外部だとハッシュ表みたいになる
	FOR(i, 0, primeN + 1) {
		prime[i] = 1;
	}prime[0] = prime[1] = 0;

	for (int i = 2; i <= primeN; i++) {
		if (prime[i]) {
			a.push_back((long long)i);
			for (int j = i * 2; j <= primeN; j += i)
				prime[j] = 0;
		}
	}
	return a;
}
#undef primeN 

LL K, N;

int ans = 0;

int f(int x) {
	int sum = x;
	int ret = sum;
	do {
		sum = ret;
		ret = 0;
		while (sum) {
			ret += sum % 10;
			sum /= 10;
		}
	} while (ret > 9);
	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> K >> N;
	vector<int> a = make_prime();
	int i = 0, j = 0;
	while (a[i] < K)i++;
	j = i;
	int ansid = a[i];
	ans = 1;
	VI used(10, 0);
	while (a[i] <= N) {

		for (;a[j]<=N && !used[f(a[j])] ;j++ ) { // [i,j)が正しい区間
			used[f(a[j])] = 1;
		}
		if (ans <= j - i) {
			ans = j - i;
			ansid = a[i];
		}
		used[f(a[i])] = 0;
		i++;
	}
	//cout << ans << "\n";
	cout << ansid << endl;
	return 0;
}
