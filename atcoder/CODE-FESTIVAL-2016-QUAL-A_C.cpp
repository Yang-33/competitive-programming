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

/* -----  2018/02/24  Problem: code-festival-2016-qual-a_c / Link: https://code-festival-2016-quala.contest.atcoder.jp/tasks/codefestival_2016_qualA_c?lang=en  ----- */
/* ------問題------

高橋君は、英小文字のみからなる文字列 s を持っています。 高橋君は s に対して、次の操作をちょうど K 回行います。
s から好きな位置の文字をひとつ選び、その文字を次のアルファベットへ変える。 ただし、z の次のアルファベットは a であるとする。
例えば、aaz の 2 文字目を選んで操作を行うと、aaz → abz となります。 続けて、abz の 3 文字目を選んで操作を行うと、abz → aba となります。
高橋君は、操作をちょうど K 回行った後の s を、辞書順でできるだけ小さくしたいと考えています。 操作をちょうど K 回行った後の s のうち、辞書順で最小のものを求めてください。

-----問題ここまで----- */
/* -----解説等-----


愚直にシュミレーションはできないけど、各文字26単位でしか変わらないので、最後だけmod26で表現すればよい。
400点の基準ってなんなんだろう

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string S; int K;
	cin >> S >> K;
	string ans;


	FOR(i, 0, SZ(S)) {
		if (S[i] == 'a')continue;
		int diff = 'z' - S[i] + 1;
		if (diff <= K) {
			S[i] = 'a';
			K -= diff;
		}
	}
	int diff = S[SZ(S)-1]-'a';
	if (K)K %= 26;
	diff += K;
	diff %= 26;
	S[SZ(S) - 1] = 'a'+ diff ;

	ans = S;
	cout << ans << "\n";

	return 0;
}
