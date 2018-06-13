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

/* -----  2018/06/14  Problem: AOJ 2681 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2681  ----- */
/* ------問題------

括弧列がN個与えられる。これらの括弧列とはvalidとは限らない。
括弧列はそのままでN個を任意の順番で並び替えたときにvalidにすることができるかを判定せよ。

-----問題ここまで----- */
/* -----解説等-----

なんか貪欲にやっていきたい。
括弧を整理して状態を4つに分けて、半分づつmergeすればよい。
1: (( のみ
2: ))(((( [右括弧が多い]
3: )) のみ
4: ))))(( [左括弧が多い]

1.2/3.4を多い括弧側のものを維持できるようにmergeすれば良い。
これはsortで適当にできる。
右側の状態と左側の状態を維持できたとき、これらの括弧の対応が取れれば良い。

----解説ここまで---- */

PII f(string & s) {
	int R = 0;
	FOR(i, 0, SZ(s)) {
		if (s[i] == '(')R++;
		else if (s[i] == ')'&&R > 0)R--;
	}
	int L = 0;
	FORR(i, SZ(s) - 1, 0 - 1) {
		if (s[i] == ')')L++;
		else if (s[i] == '('&&L > 0)L--;
	}
	return PII(L,R);
}

#define RR second 
#define LL first
PII f2(vector<PII>& alR, vector<PII>& overR) {
	int ok = 1;
	int res = 0;
	FOR(i, 0, SZ(alR)) {
		res += alR[i].RR;
	}
	// sort // less L and more R 
	sort(ALL(overR), [](const PII &a, const PII & b) {
		return a.LL < b.LL;
	});

	FOR(i, 0, SZ(overR)) {
		int L = overR[i].LL;
		int R = overR[i].RR;
		if (res < L)ok = 0;
		res = res - L + R;
	}
	return PII(res, ok);
}




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector<PII>alR, alL;
	vector<PII>overR, overL;

	FOR(i, 0, N) {
		string s;
		cin >> s;
		PII x = f(s);// F: <- L, S: -> R
		if (x.RR&&x.LL == 0)alR.push_back(x);
		else if (x.RR == 0 && x.LL)alL.push_back(PII(x.second,x.first));
		else if (x.RR >= x.LL)overR.push_back(x);
		else overL.push_back(PII(x.second,x.first));
	}

	PII resR = f2(alR, overR);
	PII resL = f2(alL, overL);

	if (resR.first == resL.first && resR.second && resL.second) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
