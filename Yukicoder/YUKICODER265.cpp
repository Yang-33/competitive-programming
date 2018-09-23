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

/* -----  2018/09/19  Problem: yukicoder 265  / Link: http://yukicoder.me/problems/no/265  ----- */
/* ------問題------

高校生の田中君は、数学のテストを受けています。
しかし田中君はある問題が解けず、このままでは赤点になってしまいます。
ある問題とは、微分を含む一変数多項式を解く問題です。

田中君の脳はインターネットに接続しており、テスト中でも式をコンピュータに送信し答えを受け取ることができます。
田中君のために、与えられた式を計算して解くプログラムを組んであげてください。

式に現れる演算子は足し算を表す'+',かけ算を表す'*'だけとなっています。
式に現れる値は定数と変数'x'、式f(x)の導関数"d{f(x)}"です。
(f(x)の導関数は一般的なライプニッツの記法でddx{f(x)}ですが式を簡単化するため"d{f(x)}"としています。)

演算子が限られているため,xn=x∗x∗x∗...∗x∗xとxのn乗がn個のx同士のかけ算で表されることに注意してください。
演算子の優先順序は、現実の世界と同様の '+' < '*' です。

-----問題ここまで----- */
/* -----解説等-----

構文解析はいつもどおり書けば良くて、あとは微分を書けば良い。
mergeするためには、(係数、次数)(逆だったかも)をもてばよい。

----解説ここまで---- */

using PII = pair<LL, LL>;
vector<PII>expr0(const string& s, int& i);
vector<PII>expr1(const string& s, int& i);
vector<PII>expr2(const string& s, int& i);

vector<PII> expr0(const string& s, int& i) {
	auto res = expr1(s, i);
	while (s[i] == '+'&&i < SZ(s)) {
		i++;
		auto res2 = expr1(s, i);
		for (auto it : res2) {
			res.push_back(it);
		}
	}
	return res;
}
vector<PII> expr1(const string& s, int& i) {
	auto res = expr2(s, i);
	while (s[i] == '*' && i < SZ(s)) {
		i++;
		auto res2 = expr2(s, i);
		PII last = res.back();
		last.first *= res2.front().first;
		last.second += res2.front().second;
		res.back() = last;
	}
	return res;
}
vector<PII> differentiation(const vector<PII>& poly) {
	vector<PII>res;
	for (auto const &it : poly) {
		if (it.second) {
			res.push_back(PII(it.second*it.first, it.second - 1));
		}
	}
	return res;
}


vector<PII>expr2(const string& s, int& i) {
	if (s[i] == 'd') {
		i++;
		assert(s[i] == '{');
		i++;
		auto res = expr0(s, i);
		// differentiation
		res = differentiation(res);
		assert(s[i] == '}');
		i++; // '{'
		return res;
	}
	else if (s[i] == 'x') {
		PII a = PII(1, 1);
		i++;
		return vector<PII>({ a });
	}
	else { // num
		assert(isdigit(s[i]));
		PII a = PII(s[i] - '0', 0);
		i++;
		return vector<PII>({ a });
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; cin >> N;
	int d; cin >> d;
	string s; cin >> s;
	int i = 0;
	auto res = expr0(s, i);
	vector<LL>ans(d + 1);
	for (const auto& it : res) {
		ans[it.second] += it.first;
	}
	FOR(i, 0, d + 1) {
		cout << ans[i] << " \n"[i == d];
	}

	return 0;
}
