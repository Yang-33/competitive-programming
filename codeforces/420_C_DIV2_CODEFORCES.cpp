#include "bits/stdc++.h"
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

/* -----  2017/06/25  Problem: CodeForces420 C div2 / Link: http://codeforces.com/contest/821/problem/C  ----- */
/* ------���------

add num
remove�Ƃ������߃Z�b�g��2N�񗈂�B
add���߂ł�stack�ɂ����ς݁Aremove�Ŏ�菜�������̂��S�~���Ɏ̂Ă�B
�S�~�����N...1�ƂȂ�悤�ɂ������B
add�ŐςݏI������C�ӂ̃^�C�~���O�Őς񂾂��̂����ւ��邱�Ƃ��ł���B
�ŏ��ŉ������ւ���΃S�~�������ꂢ�ɐ��ڂ���邩�B

-----��肱���܂�----- */
/* -----�����-----

����remove�����邽�тɍŏ��̐����͏����Ȃ��Ă͂����Ȃ��B
�Ԉ���Ă��鐔����top�ɂ���Ƃ��͂�����N���A���Ă��悢�B���̍ۈ����������Ƃ���B
���Ȃ炸�����̂������Ă����Ԃ�remove������̂ł���͐������B

----��������܂�---- */

ll N;

ll ans = 0LL;

int main()
{

	cin >> N; cin.ignore();
	vector<int>sta;
	priority_queue<int, vector<int>, greater<int>> q;
	ll p = 1;
	ll mati = 0;
	ll dp[400000];
	FOR(i, 0, 400000)dp[i] = LINF;

	bool resetnow = 0;
	FOR(i, 0, 2 * N) {
		string s;
		getline(cin, s);
		if (s[0] == 'a') {
			ll num = 0;
			FOR(j, 1, s.size()) {
				if (s[j] >= '0'&&s[j] <= '9') {
					num *= 10;
					num += s[j] - '0';
				}
			}
			sta.pb(num);
			q.push(num);
		}
		else {//remove
			if (sta.size() == 0 || sta.back() == q.top()) {
				if (sta.size())sta.pop_back();
			}
			else {
				ans++;
				sta.clear();
			}
			q.pop();
		}
	}

	printf("%lld\n", ans);

	return 0;
}