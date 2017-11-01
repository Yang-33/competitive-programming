#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i<e;i++)
#define debug(x) cout << #x << " : " << x << endl

const int INF = (1 << 30);
const ll LINF = (1LL << 60);
/* -----  2017/11/01  Problem: AOJ1142  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1142&lang=jp  ----- */
/* ------���------

���{�̓S�����RJ�ݕ��́C���l�H��ɑ��ԏ�������������D���ԏ�̔z����}B-1�Ɏ����D
�ݕ���Ԃ�2���ȏ�72���ȉ��̉ݎԂ�A�����Ă���D�ݎԂ̎�ނ�26����C���̎�ނ�a�`z�̉p������1�����ŕ\���D������ނ̉ݎԓ��m�݂͌��ɋ�ʂ��ꂸ�C�܂��X�̉ݎԂ̌�������ʂ���Ȃ��D���������āC2�����ȏ�72�����ȉ��̉p�������̕��т�1�̗�Ԃ̕Ґ������S�ɕ\����D

���ԏ�ɓ���������Ԃ́C (storage lines�ɓ��钼�O��)�C�ӂ̘A���ӏ���2�ɕ��������D�����Ă��ꂼ��̕����́C���̕K�v�������(reversal line���g����)�O�㔽�]�����D�Ō�ɂ����2�̕�����C�ӂ̏����ōĂјA�����邱�ƂŁC�ŏI�I�ȕҐ������D�O�㔽�]�́C�������Ƃɍs���Ă��s��Ȃ��Ă��悢�D

���Ƃ��΁C�������̕Ґ����uabcd�v�̂Ƃ��C�Ґ��̕����̂�������3:1�C2:2�C1:3�̂����ꂩ�ł���D�����̂��������ꂼ��ɂ��āC�\���\�ȍŏI�Ґ��͎��̂悤�ɂȂ�(�u+�v�͍Ō�̘A���ʒu������):

[3:1]
abc+d  cba+d  d+abc  d+cba
[2:2]
ab+cd  ab+dc  ba+cd  ba+dc  cd+ab  cd+ba  dc+ab  dc+ba
[1:3]
a+bcd  a+dcb  bcd+a  dcb+a
�d���������Đ�����ƁC12��ނ̕Ґ������o���邱�ƂɂȂ�D

����������Ԃ̕Ґ����^����ꂽ�Ƃ��C��L�̑��ԏ�ɂ���č\���\�ȁC�݂��ɈقȂ�Ґ��̐����񓚂���D

-----��肱���܂�----- */
/* -----�����-----

�S���̋�؂�ŕ������ĕ��ёւ������̂�set���Ƃ�΂悢�B

----��������܂�---- */
int M;

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> M;
	FOR(_i, 0, M) {
		string s;
		cin >> s;
		set<string>se;
		se.insert(s);
		FOR(i, 0, s.size() - 1) {
			string s1 = s.substr(0, 1 + i);
			string s1r = s.substr(0,1+i);
			string s2 = s.substr(1 + i);
			string s2r = s.substr(1 + i);
			reverse(s1r.begin(), s1r.end());
			reverse(s2r.begin(), s2r.end());
			se.insert(s1 + s2r);
			se.insert(s1r + s2);
			se.insert(s1r + s2r);
			se.insert(s2 + s1);
			se.insert(s2 + s1r);
			se.insert(s2r + s1);
			se.insert(s2r + s1r);
		}

		cout << se.size() << endl;
	}
}