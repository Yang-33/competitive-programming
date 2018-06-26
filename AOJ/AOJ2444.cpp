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

/* -----  2018/06/26  Problem: AOJ 2444 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444  ----- */
/* ------問題------

長さnの文字列s=s1,s2,…,snおよびm個のクエリが与えられる。 各クエリqk (1 ≤ k ≤ m)は、"L++", "L--", "R++", "R--"の4種類のいずれかであり、 k番目のクエリqkに対してl[k]とr[k]を以下で定義する。
L++：l[k]=l[k-1]+1,r[k]=r[k-1]
L--：l[k]=l[k-1]-1,r[k]=r[k-1]
R++：l[k]=l[k-1],r[k]=r[k-1]+1
R--：l[k]=l[k-1],r[k]=r[k-1]-1
但し、l[0]=r[0]=1である。
この時、m個の部分文字列 sl[k], sl[k]+1, …, sr[k]-1, sr[k] (1 ≤ k ≤ m) について、何種類の文字列が作られるかを答えよ。

-----問題ここまで----- */
/* -----解説等-----

Rollinghashで重複がおきないとすると、ある部分文字列を陽にもたなくても数値でできるので、生成時間がO(1)でできる。
あとはこれをsetにつっこめばよい。

----解説ここまで---- */

using uLL = unsigned long long;
const uLL _base = 1e9 + 7;
struct RollingHash {
	vector<uLL> hashed, power;
	RollingHash(const string& s) {
		int sz = s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);

		power[0] = 1;
		for (int i = 0; i < sz; i++) {
			power[i + 1] = power[i] * _base;
		}
		for (int i = 0; i < sz; i++) {
			hashed[i + 1] = (hashed[i] + s[i]) * _base;
		}
	}
	uLL get(int l, int r) { // [l, r)
		return((hashed[r] - hashed[l] * power[r - l]));
	}
	uLL connect(int h1, int h2, int h2len) {
		return(h1 * power[h2len] + h2);
	}
	int LCP(RollingHash& b, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return(low);
	}
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, Q;
	string t;
	cin >> N >> Q >> t;
	RollingHash rh(t);
	set<uLL>Se;
	int L = 0;
	int R = 1;
	FOR(i, 0, Q) {
		string s;
		cin >> s;
		if (s == "R++") {
			R++;
		}
		else if (s == "R--") {
			R--;
		}
		else if (s == "L++") {
			L++;
		}
		else if (s == "L--") {
			L--;
		}
		Se.insert(rh.get(L,R));
	}
	cout << Se.size() << endl;

	return 0;
}
