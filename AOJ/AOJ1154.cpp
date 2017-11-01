#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/11/01  Problem: AOJ1154/ Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1154  ----- */
/* ------���------

�R���������C�F���� 48642.5�D �����́C���������_����o�肷�邱�ƂɌ��߂��D �������̑f���������ׂċ��߂邱�ƂɎ�����肾���C �����ł͂Ȃ��D

7 �Ŋ������]�肪 1 �܂��� 6 �ł��鐳������ 7N+{1,6} ���ƌĂ΂��D �������C�������ɂ����̂ŁC ���j�y�j���ƌĂڂ��D

���j�y�j�� a, b �ɑ΂��āC ���j�y�j�� x �����݂��� ax = b �����藧�Ƃ��C a �� b �̌��j�y�j�񐔂ƌĂԁD ���j�y�j�� a �����j�y�j�� b �̌��j�y�j�񐔂ł��邽�߂ɂ́C a �� b �̕��ʂ̈Ӗ��̖񐔂ł���ΕK�v�\���ł���ƁC �ȒP�ɏؖ��ł���D

1 ���傫�Ȍ��j�y�j���ł��ꎩ�g�� 1 �̑��Ɍ��j�y�j�񐔂������Ȃ����̂��C ���j�y�j�f���ƌĂԁD ���ʂ̈Ӗ��̑f���ł��錎�j�y�j���͌��j�y�j�f���ł��邪�C �t�͈�ʂɐ��藧���Ȃ��D ���Ƃ��΁C27 �͕��ʂ̈Ӗ��̑f���ł͂Ȃ����C���j�y�j�f���ł���D ���j�y�j�� a �̌��j�y�j�񐔂ł��錎�j�y�j�f�����C a �̌��j�y�j�f�����ƌĂԁD ���Ƃ��΁C 27 �͌��j�y�j�f���ł���C 216 = 27 �~ 8 �����藧�̂ŁC 27 �� 216 �̌��j�y�j�f�����̂ЂƂł���D

1 ���傫�Ȃǂ�Ȍ��j�y�j�����C 1 �ȏ�̌��j�y�j�f���̐ςƂ��ĕ\�����Ƃ��ł���D �\�����́C�����̈Ⴂ�𖳎����Ă��C�K��������ʂ�ł͂Ȃ��D ���Ƃ��΁C 216 = 6 �~ 6 �~ 6 = 8 �~ 27 �ł���D
�I��́C ���͂��ꂽ�e�X�̌��j�y�j���ɑ΂��āC ���̌��j�y�j�f���������ׂďo�͂���v���O�����������Ȃ��Ă͂Ȃ�Ȃ��D

-----��肱���܂�----- */
/* -----�����-----

���j�y�j�����ɗ񋓂��Ă����΁A�N�G���ɓ�����̂Ɋy�B

----��������܂�---- */
bool getuyou[300000];

void getuyouSet() {
	for (int i = 2; i < 300000; i++) {
		if ((i % 7) != 1 && i % 7 != 6) continue;
		bool f = false;
		for (int j = 2; j*j <= i; j++) {
			if (i%j != 0) continue;
			if (j % 7 == 1 || j % 7 == 6) {
				f = true;
				break;
			}
		}
		if (!f) {
			getuyou[i] = true;
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n;

    getuyouSet();

	while (cin >> n) {
		if (n == 1)break;
		cout << n << ":";
		for (int i = 6; i <= n; i++) {
			if (getuyou[i] == true && n%i == 0) {
				cout << " " << i;
			}
		}
		cout << endl;
	}
	return 0;
}