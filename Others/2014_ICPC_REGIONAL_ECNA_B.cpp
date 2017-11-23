#include  <bits/stdc++.h>
using namespace std;


/* -----  2017/11/23  Problem:   
2014-2015 ACM-ICPC East Central North America Regional Contest (ECNA 2014) B / Link: http://codeforces.com/gym/100641  ----- */
/* ------問題------

文字列の省略形を考える。
aaaaaは5aと表記できる。
abcbcbcbcaはa4(bc)aと表記できる。
与えられた文字列を最小の文字列に省略せよ。

-----問題ここまで----- */
/* -----解説等-----

自明O(|S|^3)とみせかけて、どの文字を基本にして省略するかを決めるのにO(|S|)書けていしまう。
okadukiさんいわくこれはロリハでO(1)らしい。
わからんけど通った。
実質寿司コンテストの問題と一緒だった。

----解説ここまで---- */

using LL = long long;

const int MAX = 510;
int dp[MAX][MAX];
int loop[MAX][MAX];
string S;

LL MOD = 1e9 + 7;
LL X = 107;
LL hsh[510];
LL P[510];

void build() {
	int N = S.size();
	P[0] = 1;
	hsh[0] = 0;
	for (int i = 0; i<N; ++i) {
		hsh[i + 1] = (hsh[i] * X + S[i]) % MOD;
		P[i + 1] = P[i] * X % MOD;
	}
}
LL lr(int l, int r) {
	return (hsh[r] + MOD - hsh[l] * P[r - l] % MOD) % MOD;
}


int dig(int x) {
	int res = 0;
	while (x > 0) res++, x /= 10;
	return res;
}

int solve(int l, int r) {
	if (r - l <= 2) return r - l;
	int& res = dp[l][r];
	if (res) return res;
	res = r - l;

	for (int len = 1; len<r - l; ++len) {
		int rgt = l + len;
		LL pat = lr(l, l + len);
		for (; rgt + len <= r; rgt += len) {
			if (lr(rgt, rgt + len) != pat) break;
		}
		int num = (rgt - l) / len;
		int pat_len = solve(l, l + len);
		int rest = solve(rgt, r);
		if (len == 1) {
			// num len rest
			if (num == 1) {
				res = min(res, pat_len + rest);
			}
			else
				res = min(res, dig(num) + pat_len + rest);
		}
		else {
			// num ( len ) rest
			if (num == 1)
				res = min(res, pat_len + rest);
			else
				res = min(res, dig(num) + pat_len + 2 + rest);
		}
	}
	return res;
}

int main() {
	for (int t = 1;; ++t) {
		cin >> S;
		if (S == "0") break;
		fill((int*)dp, (int*)dp + MAX*MAX, 0);
		build();

		int N = S.size();
		cout << "Case " << t << ": " << solve(0, N) << endl;
	}

	return 0;
}