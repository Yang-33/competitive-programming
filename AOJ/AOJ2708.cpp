#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl
const int INF = (1 << 30);
const ll LINF = (1LL << 60);

/* -----  2017/11/01  Problem: AOJ2708 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2708  ----- */
/* ------���------

������ ABC �ŕ\������`�q�z�񂪂���B���Ȃ��͎��̑�������񂩍s���A���̈�`�q�z������������Ă������Ƃ��ł���B
���� A�CB�CC �̂��� 1 ��I�ԁB����� x �Ƃ����B��`�q�z��Ɋ܂܂�邷�ׂĂ� x �����ꂼ�� ABC �֓����ɒu��������B
A�CB�CC ��������Ȃ镶���� S ���^������B��`�q�z��� S �Ɉ�v�������邩���肹��B

-----��肱���܂�----- */
/* -----�����-----

�͂܂葱�����B
�t���V���~���[�V���������Ƃ���ABC�ɂȂ�΂悢�B
���A���u�����s������ɑI�����������񂪑��݂��Ȃ������`�F�b�N���Ȃ���΂Ȃ�Ȃ������I

----��������܂�---- */
string S;

string replace(string S, string from, string to) {
	auto pos = S.find(from);
	while (pos != string::npos) {
		S.replace(pos, from.size(), to);
		pos = S.find(from, pos + to.size());
	}
	return S;
}

void dfs(string S) {
	if (S == "ABC") {
		cout << "Yes" << endl;
		exit(0);
	}
	string T[3] = { "A","B","C" };
	string U = replace(S, "ABC", "X");
	if (S == U) return;

	FOR(i, 0, 3) if (count(U.begin(), U.end(), T[i][0]) == 0) dfs(replace(U, "X", T[i]));

}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> S;
	dfs(S);
	cout << "No" << endl;

	return 0;
}