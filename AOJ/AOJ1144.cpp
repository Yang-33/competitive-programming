#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl
const int INF = (1 << 30);
const ll LINF = (1LL << 60);

/* -----  2017/11/01  Problem: AOJ1144  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1144  ----- */
/* ------���------

MM-21���ł��I�����s�b�N�ȗ��J�[�����O�����s���Ă���. ������, ���̃��[���͒n���̂��̂Ƃ͂������قȂ��Ă���, �}�X�ڏ�̕X�̔Տ�Ő΂�������g���čs����. �X�^�[�g�ʒu����S�[���ʒu�܂Ő΂𓞒B������ړ��񐔂̏��Ȃ��������̂ł���.
�} D-1 �ɔՖʂ̗������. �Տ�̃}�X�ڂɂ͏�Q�����z�u����Ă��邱�Ƃ�����. �Ֆʂɂ�, �X�^�[�g�ƃS�[���Ƃ������ʂȃ}�X���������, �����ɂ͏�Q���͂Ȃ�. (�X�^�[�g�ƃS�[������v���邱�Ƃ͂Ȃ�.) ����͂��߂��΂͏�Q�����Ȃ�������ǂ��܂ł��i��ł����̂�, �S�[���ɓ��B������ɂ�, ��Q���𗘗p���Ă�������΂��~��, ���炽�߂Ċ��点�Ă��K�v�����낤.
�΂̓����͈ȉ��̋K���ɏ]��:

�Q�[���̊J�n����, �΂̓X�^�[�g�Ŏ~�܂��Ă���.
�΂̓����� x, y �����Ɍ���. �ȂȂ߂ɂ͓����Ȃ�.
�~�܂��Ă���΂�, ���点�邱�Ƃɂ���ē����o��. ���̎��̕�����, �������̃}�X�ɏ�Q�����Ȃ������Ȃ�ǂ���ł��悢(�} D-2(a)).
�����o�����΂�, ���̂����ꂩ���N����܂�, ���������ɓ���������.
��Q���ɂԂ������ꍇ(�} D-2(b), (c)).
�΂͏�Q���̈��O�̃}�X�Ŏ~�܂�.
��Q���͏��ł���.
�ՊO�ɏo���ꍇ.
���s�ŃQ�[���͏I���.
�S�[���̏�ɗ����ꍇ.
�����Ő΂͎~�܂�, �����ŃQ�[���͏I���.
1 ��̃Q�[�����̊��点��񐔂̍ő�� 10 �ł���. ���̉񐔂ŃS�[���ɐ΂𓞒B�����邱�Ƃ��ł��Ȃ��ꍇ, ���s�ŃQ�[���͏I���.

�} D-2: �΂̓����̗�
�ȏ�̏����̂��Ƃ�, �X�^�[�g�ʒu�ɂ���΂��S�[���ʒu�ɓ��B�����邱�Ƃ��ł��邩, �ł���Ȃ�ŏ����񊊂点��΂悢����m�肽��.

-----��肱���܂�----- */
/* -----�����-----

�Ֆʂ��ω�����B
���������ĎQ�Ƃ͎g���Ȃ��̂ł����ɋC��t���邾���ł��Ƃ̓V���~���[�V����������B

----��������܂�---- */
int ans = -1;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(pii at,int n, vector<vector<int>> masu) {
	if (n == 10) return;
	int y = at.first, x = at.second;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i], xx = x+  dx[i];
		if (masu[yy][xx] == 1) continue;
		if (masu[yy][xx] == -1)  continue; 
		if (masu[yy][xx] == 3) { if (ans == -1) ans = n+1; else ans = min(ans, n+1); return; }
		bool f = false;
		while (masu[yy + dy[i]][xx + dx[i]] != 1) {
			yy += dy[i];
			xx += dx[i];
			if (masu[yy][xx] == -1) { f = true; break; }
			if (masu[yy][xx] == 3) { if (ans == -1) ans = n + 1; else ans = min(ans, n + 1); return; }
		}
		if (f) continue;
		if (masu[yy + dy[i]][xx + dx[i]] == 1) {
			masu[yy + dy[i]][xx + dx[i]] = 0;
			dfs({ yy,xx }, n + 1, masu);
			masu[yy + dy[i]][xx + dx[i]] = 1;
		}
	}
	return;
}


int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int w, h;
	while (cin >> w >> h, w|h) {
		ans = -1;
		vector<vector<int>> masu(h + 2, vector<int>(w + 2, -1));
		pii s;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> masu[i][j];
				if (masu[i][j] == 2) s = { i,j };
			}
		}
		dfs(s,0, masu);
		cout << ans << endl;
	}
}