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

/* -----  2017/08/01  Problem: KotamanegiOJ_Otemae C  / Link: https://kotamanegi.com/JudgeSystem/Problems/view/index.php?page=27  ----- */
/* ------問題------

/* ------問題------

olphe君は575が大好きなので、5文字若しくは7文字の単語のみ存在する新たな言語、ゴーシチ語を考案しました。

ゴーシチ語には現在
N
N個の単語が存在しています。それらの単語の中から別々に三つ選ぶ際に575となる通り数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

5,7,5の組み合わせは5の登場回数に対してnC2,
と、7の登場回数の積。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string s[100005];
	ll se = 0;
	ll fi = 0;
	FOR(i, 0, N) {
		cin >> s[i];
		if (s[i].size() == 5)fi++;
		if (s[i].size() == 7)se++;
	}
	ans = se*fi*(fi - 1);
	cout << ans << endl;

	return 0;
}
