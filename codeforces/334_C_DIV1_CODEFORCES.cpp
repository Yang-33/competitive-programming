#include "bits/stdc++.h"
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

/* -----  2017/09/16  Problem: 334_C_div1_codeforces  / Link: http://codeforces.com/problemset/problem/603/C  ----- */
/* ------���------

n�̃R�C���̎R������A���ꂼ��̎Ri�ɂ�a[i]���̃R�C��������BKevin��Nicky�͌��݂Ɉȉ��̑���̂����ꂩ���s���B

�R��1�I�сA���̎R����R�C����1����菜��
�R�C�����������i2x���j����R��1�I�сA���̎R���R�C����x������k�̎R�ɒu��������
������s���Ȃ��Ȃ����v���C���[�������ƂȂ�B���҂��őP���ł����Ƃ��ǂ��炪�����낤���B

-----��肱���܂�----- */
/* -----�����-----

K�������̂Ƃ��͒u���������Ֆʂ�grundy���͉��ł��낤��0�ɂȂ�B
K����̂Ƃ��͂����ł͂Ȃ��Agrundy�����v�Z���Ȃ��Ă͂Ȃ�Ȃ��B
�K���J�ڂ�2��ނ����Ȃ��̂ŁA������悭��͂��Ă݂��(�菑���Ŏ���)
������x�̋K���������Ă���B
K�����̂Ƃ��́A�����ɈӖ����Ȃ��̂�grundy(n)=mex(grundy(n-1))
K��̂Ƃ��́AN���grundy(n)=mex(grundy(n-1)),�����ŁAgrundy(n)=mex(grundy(n-1),grundy(n/2))
�ƂȂ�B
�ꌅ�̐��͂���ɓ��Ă͂܂�Ȃ��ꍇ������̂ŁA���߂��ށB
N���傫���̂Ń������͂ł��Ȃ����J�ڂ������logN��grundy�����킩��̂ŁA����ł܂ɂ����B

----��������܂�---- */

LL N, K;

LL ans = 0LL;
LL even[3] = { 0,1,2 };
LL grundy_even(LL x) {
	if (x >= 3) {
		if (x % 2 == 0)return 1;
		else return 0;
	}
	else {
		return even[x];
	}
}
LL odd[5] = { 0,1,0,1,2 };

LL grundy_odd(LL x) {
	if (x <= 4)return odd[x];
	if (x % 2 == 1)return 0;
	else {
		set<int>se;
		se.insert(0);
		if (x % 2 == 0)se.insert(grundy_odd(x / 2));

		LL subg = 0;
		while (se.count(subg))subg++;
		return subg;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	LL g = 0;

	FOR(i, 0, N) {
		LL a; cin >> a;
		if (K % 2 == 0) {
			g ^= grundy_even(a);
		}
		else {
			g ^= grundy_odd(a);
		}
	}


	cout << ((g != 0) ? "Kevin" : "Nicky") << "\n";

	return 0;
}