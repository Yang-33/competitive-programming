#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/11/01  Problem:AOJ1153  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1153  ----- */
/* ------���------

���Y�ƉԎq�͂��ꂼ��J�[�h�������������Ă���D �e�J�[�h�ɂ͓_����������Ă���D
���Y�̃J�[�h�ƉԎq�̃J�[�h�� 1 �����������āC ���ꂼ��̎��J�[�h�̍��v�_�����������Ȃ�悤�ɂ������D
�ǂ̃J�[�h�Ƃǂ̃J�[�h������������悢���D
�������C�J�[�h���������Ȃ��Ă����v�_�����������ꍇ�ł��C �K���J�[�h�̌������s�����̂Ƃ���D
�e�f�[�^�Z�b�g�ɑ΂��C �ӂ��̐��� 1 �s�ɂЂƂ̋󔒂ŋ�؂��ďo�͂���D
�ŏ��̐��͑��Y���Ԏq�ɓn���J�[�h�̓_���C 2 �Ԗڂ̐��͉Ԏq�����Y�ɓn���J�[�h�̓_���ł���D
�Ȃ��C���v�𓙂�������悤�ȃJ�[�h�̌����̕��@����������ꍇ�́C ��������J�[�h�̓_���̘a���ŏ��ƂȂ���̂��o�͂��邱�ƁD

�J�[�h�̓_���̍��v�𓙂�������悤�Ȍ��������݂��Ȃ��ꍇ�� -1 �݂̂��܂� 1 �s���o�͂��邱�ƁD �o�͌`���ɏ]��Ȃ��]�v�ȕ������܂�ł͂Ȃ�Ȃ��D

-----��肱���܂�----- */
/* -----�����-----

���ۂɃV���~���[�V�������s���΂悢�B
���̍ہA(��������J�[�h�̘a,id,id)�݂����Ȃ̂�����Ƃ��ꂵ���B

----��������܂�---- */

ll N, M;
ll ans1, ans2;
int a[120];
int b[120];

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		FOR(i, 0, 120)a[i] = b[i] = INF;


		ll asum = 0;
		ll bsum = 0;
		FOR(i, 0, N) {
			cin >> a[i];
			asum += a[i];

		}
		FOR(i, 0, M) {
			cin >> b[i];
			bsum += b[i];
		}
		sort(a, a + N);
		sort(b, b + M);
		vector<pair<int, pii>>v;
		FOR(i, 0, N) {
			FOR(j, 0, M) {
				if (asum - a[i] + b[j] == bsum + a[i] - b[j]) {
					v.push_back(make_pair(a[i] + b[j], make_pair(a[i], b[j])));
				}
			}
		}
		sort(v.begin(), v.end());
		if (v.size() == 0) {
			cout << "-1" << endl;
		}
		else {
			ans1 = v[0].second.first;
			ans2 = v[0].second.second;
			cout <<ans1 << " " << ans2 << endl;
		}
	}
	return 0;
}