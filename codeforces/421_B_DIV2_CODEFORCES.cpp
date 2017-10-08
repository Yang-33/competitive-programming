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

/* -----  2017/06/27  Problem: CodeForces421 B div2 / Link: http://codeforces.com/contest/820/problem/B  ----- */
/* ------���------

��N�p�`�̒��_������łł���p�x�̂���a�x�ɍł��߂����_�W���̖��O��.
ex: 4 45: ans:1 2 4

-----��肱���܂�----- */
/* -----�����-----

�����p�`�̈�̒��_����ق��̒��_�ɐ��������ƍŏ��P�ʂ�180/N�łł��Ă��邱�ƂɋC���t���B
��������{���������̂ɂ��āAa�ɍł��߂��p�x�����߁A2 1 X �Əo�͂���΂����B

----��������܂�---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int a;
	cin >> N >> a;
	double ee = 180.0 / N;
	double aa = INF;
	int id = -1;
	FOR(i, 0, N - 2) {
		if (abs(ee*(i + 1) - a) < aa) {
			aa = abs(ee*(i + 1)-a);
			id = i + 1;
		}
	}
	cout << 2 + id << " " << 1 << " " << 2 << endl;



	return 0;
}