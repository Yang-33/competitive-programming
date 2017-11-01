#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl
/* -----  2017/11/01  Problem: AOJ1155  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1155   ----- */
/* ------���------

�O�l�_���͒l�Ƃ��� "�^"�C"�U" �ɉ��� "���m" �������_���̌n�ł���D �ȉ��ł́C"�U"�C"���m"�C"�^" �� 0, 1, 2 �ł��ꂼ��\���D

"-" ��P�����Z�q�i���Ȃ킿�C�l�ЂƂ��󂯎��֐���\���L���j�Ƃ��C "*" �� "+" ��񍀉��Z�q�i���Ȃ킿�C�l�ӂ����󂯎��֐���\���L���j�Ƃ���D �����́C���ꂼ��ے� (NOT), �_���� (AND), �_���a (OR) ��\�����Z�q�ł���C �O�l�_���ɂ����邱���̉��Z�͕\ C-1 �Ɏ����悤�ɒ�`�ł���D

�\ C-1: �O�l�_�����Z�q�̐^���l�\
-X		(X*Y)		(X+Y)

P, Q, R ���O�l�_���̕ϐ��Ƃ���D �^����ꂽ�_�����𖞑�����C �܂�_�����̒l�� 2 �ɂȂ�悤�� (P,Q,R) �̎O�g�����ʂ肠�邩�𓚂���̂����Ȃ��̖������D �_�����͈ȉ��̂����ꂩ�̌`���ł���i������ X, Y �͂܂��_�����ł���Ƃ���j�D

�萔: 0, 1 �܂��� 2
�ϐ�: P, Q �܂��� R
�ے�: -X
�_����: (X*Y)
�_���a: (X+Y)
��L�̂悤�ɁC�ӂ��̘_�����̘_���ς�_���a�͕K�����ʂň͂ށD

���Ƃ��΁C���� (P*Q) �ɑ΂��ẮC(P,Q,R) �� (2,2,0)�C(2,2,1)�C(2,2,2) �̏ꍇ�C �����̏ꍇ�̂݁C���̘_�����̒l�� 2�ƂȂ�̂ŁC3���o�͂���΂悢�D

-----��肱���܂�----- */
/* -----�����-----

�\����́B
LL(1)�Ȃ̂ł����3^3�ʂ�̑g�ݍ��킹��S����������΂悢�B

----��������܂�---- */
const int INF = 1e9;
const ll LINF = 1e16;
int N;
string expr0(int &i, string &s);
string expr1(int &i, string &s);

void changes(string &s, char a, char b, char c) {
	FOR(i, 0, s.size()) {
		if (s[i] == 'P') {
			s[i] = a;
		}
		else	if (s[i] == 'Q') {
			s[i] = b;
		}
		else	if (s[i] == 'R') {
			s[i] = c;
		}
	}
}

string expr1(int &i, string &s) {
	if (isdigit(s[i])) {
		string num = to_string(s[i] - '0');
		i++;
		return num;
	}
	if (s[i] == '-') {
		i++;
		string num = expr1(i, s);
		if (num == "2")return "0";
		if (num == "0")return "2";
		if (num == "1")return "1";
	}
	if (s[i] == '(') {
		i++;
		string num = expr0(i, s);
		i++;
		return num;
	}
	return "";
}

string expr0(int &i, string &s) {
	string num = expr1(i, s);
	int flag = -1;
	while (i < N && (s[i] == '+' || s[i] == '*')) {
		char op = s[i];
		i++;
		if (op == '+') {
			num += expr0(i, s);
			flag = 1;
		}
		else if (op == '*') {
			num += expr0(i, s);
			flag = 2;
		}
	}

	if (flag == 1) {
		FOR(k, 0, num.size()) {
			if (num[k] == '2')return "2";
		}
		FOR(k, 0, num.size()) {
			if (num[k] == '1')return "1";
		}
		return "0";
	}
	else if (flag == 2) {
		FOR(k, 0, num.size()) {
			if (num[k] == '0')return "0";
		}
		FOR(k, 0, num.size()) {
			if (num[k] == '1')return "1";
		}
		return  "2";
	}
	return num;

}


int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (true) {
		string S; cin >> S;
		if (S[0] == '.')break;
		int ans = 0;
		N = S.size();
		FOR(i, 0, 3) {
			FOR(j, 0, 3) {
				FOR(k, 0, 3) {
					string ss = S;
					changes(ss, '0' + i, '0' + j, '0' + k);
					int p = 0;
					if (expr0(p, ss) == "2") {
						ans++;
					}
				}
			}
		}


		cout << ans << endl;
	}


	return 0;
}