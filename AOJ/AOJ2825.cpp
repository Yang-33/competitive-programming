#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/07/12  Problem: AOJ 2825  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2825  ----- */
/* ------���------



-----��肱���܂�----- */
/* -----�����-----

�{�Ԃł͏������k���ăL�����������B
����l�̎擾�\�ȓ_���ɂ��āA�ŏ��̂��̂͂�����ɑ΂��Ă��̐l�݂̂��𓚂�����̘̂a�A
�ő�̂��͕̂����l�𓚉\�Ȃ��̂����ׂĂ��̐l�����������Ƃ��ł��邱�Ƃ����͂��番����B
���������Ă���l���ŏ����_���Ƃ�Ƃ��ɂ���ȊO�̐l���ő哾�_���Ƃ�ۂ̍������߁A�t�]�D���ł���悤�ȓ_�̍ŏ��l���Ƃ�΂悢�B

----��������܂�---- */

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int N, M;
	while (cin >> N >> M) {
		if (N == 0 && M == 0)break;
		vector<ll> d(N + 1, 0), t(N + 1, 0);
		for (int i = 0; i < M; i++) {
			int S, k; cin >> S >> k;
			if (k == 1) {
				int c; cin >> c;
				d[c] += S;
			}
			else {
				int c;
				for (int j = 0; j < k; j++) {
					cin >> c;
					t[c] += S;
				}
			}
		}

		ll Ans = -1;

		for (int i = 1; i <= N; i++) {
			ll Min = INF;
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				Min = min(Min, d[j]);
			}
			Ans = max(Ans, (d[i] + t[i]) - Min + 1);
		}
		cout << Ans << endl;
	}
}