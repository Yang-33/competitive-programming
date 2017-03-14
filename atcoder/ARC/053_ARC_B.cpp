#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<climits> //INT_MIN/MAX
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/03/14  Problem: ARC053 B / Link: http://arc053.contest.atcoder.jp/tasks/arc053_b ----- */
/* ------問題------

高橋君は文字列 S を持っています。S は英小文字のみからなります。

まず、高橋君は S の文字を任意の順番に並べ替え、文字列 S' を作ります。

次に、高橋君は S' を任意の位置で分割し、何個かの文字列 s1，s2，…，sN を作ります（N は任意）。ただし、各 si は回文でなければなりません。

各 si の長さの最小値を X とします。高橋君は X をできるだけ大きくしようとしています。X の最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

奇数個ある文字を核として回分列を生成しようと考える。
一つの核にくっつけられる偶数個の文字列について、片側に（偶数個の総数）/2
とあらわせるので、これを核の個数で割ればよい。よってこれを二倍したものが一番低いものにくっつく
偶数個の列であるのでこれに１を加えればよい。
核がない場合はそのまま数を出力しておく。

----解説ここまで---- */

string N;
int c[30];
ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N.size()) {
		c[N[i] - 'a']++;
	}

	int k = 0;
	FOR(i, 0, 26) {
		if (c[i] % 2 == 1)k++;
	}

	if (k == 0) {
		cout << N.size() << endl;
	}
	else {
		ans = 1 + ((N.size() - k) / 2 )/ k * 2;
		cout << ans << endl;
	}
	return 0;
}