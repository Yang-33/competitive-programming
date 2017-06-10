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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/06/10  Problem: ARC 071 C / Link: http://arc071.contest.atcoder.jp/tasks/arc071_c  ----- */
/* ------問題------

A, B からなる文字列に対して、次の操作を考えます。

文字列中の 1 文字を選ぶ。それが A なら BB で、 B なら AA で置き換える。
AAA か BBB であるような部分文字列を選び、消す。
例えば、ABA という文字列で 1 番目の操作を 1 文字目に対して行うと、 BBBA となります。
また、BBBAAAA に対して 2 番目の操作を 4 文字目から 6 文字目に対して行うと、 BBBA となります。

これらの操作を何回でも好きな順で行うことができます。

文字列 S,T と q 個のクエリ ai,bi,ci,di が与えられます。 
各クエリに対して、 S の部分文字列 SaiSai+1…Sbi を T の部分文字列 TciTci+1…Tdi にすることができるか判定してください。

-----問題ここまで----- */
/* -----解説等-----

文字が減っていくだけではなく増やす操作もできる。何度も遷移させていると必ず文字列は数文字以内に落ち着き、これは復元可能であることが分かる。
ABは削除可能、AAA,BBB,BA等が削除可能であることを考えると、A=1,B=2としてクエリの数列の和について3で割った余りが等しければ同じになることが分かる。
クエリにこたえるには累積和かセグ木を用いればよい。

これは実験系の問題かな。

----解説ここまで---- */



ll N;
ll sums[100010];
ll sumt[100010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string S, T;
	cin >> S >> T;
	sums[0] = 0;
	FOR(i, 0, S.size()) {
		if (S[i] == 'A')sums[i + 1] = 1;
		else if (S[i] == 'B')sums[i + 1] = 2;
	}
	sumt[0] = 0;
	FOR(i, 0, T.size()) {
		if (T[i] == 'A')sumt[i + 1] = 1;
		else if (T[i] == 'B')sumt[i + 1] = 2;
	}
	FOR(i, 0, S.size()) {
		sums[i + 1] += sums[i];
	}
	FOR(i, 0, T.size()) {
		sumt[i + 1] += sumt[i];
	}
	ll Q;  cin >> Q;
	FOR(i, 0, Q) {
		int s1, s2, t1, t2;
		cin >> s1 >> s2 >> t1 >> t2;
		if ((sums[s2] - sums[s1 - 1]) % 3 == (sumt[t2] - sumt[t1 - 1]) % 3)
			cout << "YES" << endl;
		else  cout << "NO" << endl;

	}

	return 0;
}
