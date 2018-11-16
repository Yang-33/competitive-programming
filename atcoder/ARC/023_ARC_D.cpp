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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/16  Problem: ARC 023 D / Link: http://arc023.contest.atcoder.jp/tasks/arc023_d  ----- */
/* ------問題------

高橋君は、数列を作って、それに関していろいろ操作を施すのが好きです。特に、区間の和や区間の最大公約数を計算したりといった区間に関していろいろ操作を施すのが大好きです。
そこで、高橋君は、ある数列に関して、区間の最大公約数がとある値 x となるような区間の数を数えることにしました。 高橋君は、プログラムを使ってこの問題を解いたのですが、長い数列になればなるほど、時間がとても掛かってしまうことに気づきました。
あなたの仕事は、高橋君のために、数列が長いときでも高速に動作するプログラムを書くことです。 また、オマケ機能として、同じ数列に対して、いくつか x の候補があっても、全ての x　について計算できるよう、問い合わせ機能をつけてあげることにしました。
あなたには、 長さ n の数列 A={a1,a2,..,an} が与えられます。また、問い合わせの数 m と、 x1,x2,..,xm も与えられます。 それぞれの xi(1≦i≦m) について、区間に含まれる全ての数の最大公約数が xi となるような区間 [s,t](1≦s≦t≦n) の数を出力してください。
例えば、A={1,2,4} のとき、最大公約数が1となる区間は、[1,1],[1,2],[1,3]の3つであり、最大公約数が2となる区間は、[2,2],[2,3] の2つであり、 最大公約数が4となる区間は、[3,3] のみです。

-----問題ここまで----- */
/* -----解説等-----

左からの累積GCDを考える。i番目を見たときはi個の[0,j)が存在しているが、大きいNに対して、
gcdはa[i]か1しかありえない。(異なるならばlog2_MAXぐらいしかgcdは変化しないため)
したがって、適当に情報を保持して愚直に全部みて間に合う。
sparseTableはverifyに使えるとは思うけど全然自然な発想じゃない気がする。(よくある、解けるが思いつきはしない類のやつ)

----解説ここまで---- */

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	// [i,s)+sをしたときに、gcdは減少し、各列30種ぐらいしか存在しない
	// [0,s)+sをして、それぞれの累積をもてばよい
	// これはいつものswapするdpに、全ての値を保存しておけばよい
	// TLEするかもしれない

	// しなかった
	map<LL, LL>Map;
	map<LL, LL>Sum;
	FOR(i, 0, N) {
		map<LL, LL>nx;
		nx[a[i]] = 1;
		Sum[a[i]]++;
		for (auto it : Map) {
			nx[gcd(it.first, a[i])] += it.second;
			Sum[gcd(it.first, a[i])] += it.second;
		}
		nx.swap(Map);
	}


	FOR(_, 0, M) {
		LL x; cin >> x;
		cout << Sum[x] << endl;
	}

	return 0;
}
