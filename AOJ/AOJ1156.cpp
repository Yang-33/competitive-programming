#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl
/* -----  2017/11/01  Problem: AOJ1156  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1156  ----- */
/* ------���------

���{�b�g���g�����Q�[�������悤�D ���{�b�g�� 1 ��C�}�X�ڏ�ɋ�؂�ꂽ�����`�̔Ֆʏ�ɒu����Ă���i�} D-1�j�D ���{�b�g�́C�ŏ��k�����ɂ���X�^�[�g�n�_�̃}�X�ɓ������������Ĕz�u����Ă���D �Q�[���̖ړI�́C���{�b�g��쓌���ɂ���S�[���̃}�X�܂ŗU�����邱�Ƃł���D
���{�b�g�́C���� 5 ��ނ̖��߂����s���邱�Ƃ��ł���D

�u���i (Straight)�v:
���݂̐i�s�����̂܂܁C���̃}�X�ɑO�i����D
�u�E�� (Right)�v:
�i�s������ 90 �x�E�ɕς��āC���̃}�X�ɑO�i����D
�u���] (Back)�v:
�i�s������ 180 �x�ς��āC���̃}�X�ɑO�i����D
�u���� (Left)�v:
�i�s������ 90 �x���ɕς��āC���̃}�X�ɑO�i����D
�u��~ (Halt)�v:
���݂̃}�X�Ŏ~�܂��āC�Q�[�����I������D
�e�}�X�ɂ́C��q�̖��߂̂����ꂩ�����蓖�Ă��Ă���i��F�} D-2�j�D ����Ɏ��s���ׂ��ʂ̖��߂��v���C���[���^���Ȃ�����C ���{�b�g�́C���݂���}�X�̖��߂����s����D �v���C���[�������I�ɖ��߂�^����ۂ́C���̓s�x�C ���߂̎�ނɉ������R�X�g���x�����K�v������D

���{�b�g�́C�����ꏊ�����x���K��邱�Ƃ�������Ă���D ����ŁC���{�b�g���ՖʊO�ɑO�i����悤�Ȗ��߂����s�����ꍇ��C �S�[���ɒ����O�ɒ�~���߂����s�����ꍇ�́C���i�ƂȂ�D

���Ȃ��̎d���́C ���{�b�g���X�^�[�g�n�_����S�[���n�_�ɗU�����邽�߂ɕK�v�ȍŏ��R�X�g�����߂�v���O�������������Ƃł���D

-----��肱���܂�----- */
/* -----�����-----

�}�X�Ɉړ����Ă����Ƃ��ɈȑO�̏�񂪕K�v�Ȃ̂ŁA�_�C�N�X�g��������Ƃ��ɒ��_�𑝂₵�Ă��΂悢�B

----��������܂�---- */
const int INF = 1e9;
const ll LINF = 1e16;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool is_in(int x, int y, int h, int w) {
	return (0 <= x&&x < w && 0 <= y&&y < h);
}

int masu[35][35];
int dist[35][35][5];
int co[4];

int main() {
	cin.tie(0); ios::sync_with_stdio(false);


	while (true) {
		FOR(i, 0, 35)FOR(j, 0, 35)masu[i][j] = -1;
		FOR(i, 0, 35)FOR(j, 0, 35)FOR(k, 0, 4)dist[i][j][k] = INF;

		int H, W;
		cin >> W >> H;
		if (W == 0 && H == 0)break;
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				cin >> masu[i][j];
			}
		}
		FOR(i, 0, 4)cin >> co[i];

		//cost,y,x,dirct
		using Ty = tuple<int, int, int, int>;
		priority_queue<Ty, vector<Ty>, greater<Ty>>q;
		q.push(Ty(0, 0, 0, 0));
		dist[0][0][0] = 0;

		while (!q.empty()) {
			Ty a = q.top(); q.pop();
			int x, y, cost, dir, dir2;
			tie(cost, y, x, dir) = a;
			dir2 = dir;
			if (dist[y][x][dir] < cost)continue;
			int command = masu[y][x];
			
			
			if (command == 0) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (is_in(nx, ny, H, W))
				if (dist[ny][nx][dir] > cost) {
					dist[ny][nx][dir] = cost;
					q.push(Ty(cost, ny, nx, dir));
				}
			}
			else if (command == 1) {
				dir2 = (dir + 1) % 4;
				int nx = x + dx[dir2];
				int ny = y + dy[dir2];
				if (is_in(nx, ny, H, W))
				if (dist[ny][nx][dir2] > cost) {
					dist[ny][nx][dir2] = cost;
					q.push(Ty(cost, ny, nx, dir2));
				}
			}
			else if (command == 2) {
				dir2 = (dir + 2) % 4;
				int nx = x + dx[dir2];
				int ny = y + dy[dir2];
				if (is_in(nx, ny, H, W))
				if (dist[ny][nx][dir2] > cost) {
					dist[ny][nx][dir2] = cost;
					q.push(Ty(cost, ny, nx, dir2));
				}
			}
			else if (command == 3) {
				dir2 = (dir - 1 + 4) % 4;
				int nx = x + dx[dir2];
				int ny = y + dy[dir2];
				if (is_in(nx, ny, H, W))
				if (dist[ny][nx][dir2] > cost) {
					dist[ny][nx][dir2] = cost;
					q.push(Ty(cost, ny, nx, dir2));
				}
			}
			else if (command == 4) {
				;
			}
			//cost

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (is_in(nx, ny, H, W)) {
				if (dist[ny][nx][dir] > cost + co[0]) {
					dist[ny][nx][dir] = cost + co[0];
					q.push(Ty(dist[ny][nx][dir], ny, nx, dir));
				}
			}
			dir2 = (dir + 1) % 4;
			 nx = x + dx[dir2];
			 ny = y + dy[dir2];
			if (is_in(nx, ny, H, W)) {
				if (dist[ny][nx][dir2] > cost + co[1]) {
					dist[ny][nx][dir2] = cost + co[1];
					q.push(Ty(dist[ny][nx][dir2], ny, nx, dir2));

				}
			}
			dir2 = (dir + 2) % 4;
			 nx = x + dx[dir2];
			 ny = y + dy[dir2];
			if (is_in(nx, ny, H, W)) {
				if (dist[ny][nx][dir2] > cost + co[2]) {
					dist[ny][nx][dir2] = cost + co[2];
					q.push(Ty(dist[ny][nx][dir2], ny, nx, dir2));

				}
			}
			dir2 = (dir - 1 + 4) % 4;
			 nx = x + dx[dir2];
			 ny = y + dy[dir2];
			if (is_in(nx, ny, H, W)) {
				if (dist[ny][nx][dir2] > cost + co[3]) {
					dist[ny][nx][dir2] = cost + co[3];
					q.push(Ty(dist[ny][nx][dir2], ny, nx, dir2));
				}
			}
		}

		ll ans = LINF;
		FOR(i, 0, 4) {
			ans = min(ans, (ll)dist[H - 1][W - 1][i]);
		}
		cout << ans << endl;
	}


	return 0;
}