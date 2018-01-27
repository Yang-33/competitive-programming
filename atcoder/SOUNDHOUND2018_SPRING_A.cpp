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

/* -----  2018/01/27  Problem: soundhound2018_spring A / Link: https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_a  ----- */
/* ------問題------

kenkooooさんはSoundHound社で働いています。彼は会社の知名度を上げるため、SoundHoundに名前が似ている言葉を見つけてマーケティングを行うことにしました。
手始めに、2 単語からなる言葉で、それぞれの単語の頭文字を順につなげるとSHとなるような単語を似ていると見なすことにしました。

あなたの仕事は、2 単語 X Y からなる言葉が与えられたとき、頭文字を順につなげるとSHとなるか判定することです。

-----問題ここまで----- */
/* -----解説等-----

S.front()のほうが書くの速いかも

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string s, t;
	
	cin >> s >> t;
	if (s[0] == 'S'&&t[0] == 'H') {
		cout << "YES" << endl;
	}else
	cout << "NO" << "\n";

	return 0;
}
