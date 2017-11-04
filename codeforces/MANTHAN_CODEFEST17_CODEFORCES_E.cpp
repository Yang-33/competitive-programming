#include "bits/stdc++.h"
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

/* -----  2017/11/01  Problem: ketadp6 / Link: http://codeforces.com/contest/855/problem/E  ----- */
/* ------問題------

クエリがたくさん来る。
[l,r]に含まれる、b進数であらわしたとき、leading zeroを考慮した、0~b-1の登場回数が全て偶数回の数値の総数は？

-----問題ここまで----- */
/* -----解説等-----

今までのノリでメモ化すると 70*10*(2^10)*2*2となってクエリがたくさん来ると計算が終わらなくなる。
そこでじっくり考えると？less=1のものは情報が何度も同じものを計算していることに気が付く。
したがってless==0のものは愚直に計算し、(これは桁数程度しか計算の必要がない)あとはメモ化すればよい。
詳細は以下。かなりはまったけど勉強になった！

----解説ここまで---- */

string to_any_base_String(int base, long long  val) //二進数表示
{
	const int size = 30;
	int index = size - 1;
	string str(size, '0');
	while (val != 0) {
		str[index] = '0' + val%base;
		val /= base;
		index--;
	}
	return str;
}

LL dp[70][10][1 << 10][2];
LL f(string& target, int i, int base, int bitmask = 0, bool lz = 1, bool less = 0) {
	if (i == -1) {
		return (bitmask == 0) && (lz != 1);
	}
	if (dp[i][base][bitmask][lz] != -1 && less == 1)return dp[i][base][bitmask][lz];
	LL res = 0;
	int num = target[i] - '0';
	int Max = less ? base - 1 : num;
	FOR(nx, 0, Max + 1) {
		bool zero = lz&(nx == 0);
		res += f(target, i - 1, base, (zero ? bitmask : (bitmask ^ (1 << nx))), zero, less | (nx < Max));
		//cout << nx << " " << res << endl;
	}

	if (less == 1)return (dp[i][base][bitmask][lz] = res);
	return res;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Q; cin >> Q;
	// クエリに対して計算をする。
	// f(a,p):=a以下のbase pのものでleading zeroを考慮した0-p-1が偶数回出現する個数
	// query(base,l,r) = f(r,base)-f(r-1,base)をだす
	// 1クエリの計算量は18 *base * 2 * 2
	// いけそう bitmaskがあるのでいけませんね
	// はい　桁数は最悪base =2 でlog(2)10^18あればよい
	// 考えると何かわかる
	// 再計算がだるいなあという気持ちになるが、
	// less==0は持ちあげるときはつかいまわせるよねという気持ちになる
	// leading zeroの練習

	// 二時間後、やっとバグの原因に気付く
	// 再利用するためには最高桁の情報に依存することになるので、これを分けるためにS=s[0]+s[1]+s[2]...があったときに
	// 頭から掘っていていたのを、S(N)=s[n-1]+s[n-2]+s[n-3]...としてあげなければならない
	fill(***dp, ***dp + 70 * 10 * (1 << 10LL) * 2, -1);
	FOR(_, 0, Q) {
		int base; LL l, r; cin >> base >> l >> r;
		l--;
		string L; string R;

		do {
			L += char('0' + l%base);
			l /= base;
		} while (l);
		do {
			R += char('0' + r%base);
			r /= base;
		} while (r);
		//debug(_); debug(L); debug(R);
		//reverseとかして満足していた
		LL ll = f(L, SZ(L) - 1, base);
		//debug(ll);
		LL rr = f(R, SZ(R) - 1, base);
		//debug(rr);

		cout << rr - ll << "\n";
	}
	return 0;
}
