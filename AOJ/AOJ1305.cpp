#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i = s; i< t ; i++)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define UNIQ(a) (a).erase(unique(ALL(a)),end(a))
#define debug(a) cout<<#a<<":="<<a<<endl;
#define debeg2(a) cout<<#a<<":="<<a<<" ";
using LL = long long; using ll = LL;
using VI = vector<int>; using VL = vector<LL>;
using VVI = vector<VI>; using VVL = vector<VL>;

const LL LINF = 1e18; const LL INF = 1e9;

/* -----  2018/05/23  Problem: AOJ1305 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1305  ----- */
/* ------問題------

ラベル名とラベル名または人間のリストが渡される。
ラベル1にふくまれる人数を答えよ。

-----問題ここまで----- */
/* -----解説等-----

やっていけばよい。

----解説ここまで---- */


ll N;
set<string> s;
map<string, int> mp;
vector<string> S_split(string& S) {
	vector<string> ret;
	int l = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '.' || S[i] == ':' || S[i] == ',') {
			ret.push_back(S.substr(l, (i - l)));
			l = i + 1;
		}
	}
	return ret;
}

ll solve() {
	s.clear();
	mp.clear();
	ll res = 0;
	vector<string> S(N);
	for (int i = 0; i < N; i++) cin >> S[i];

	using pii = pair<int, int>;
	map<string, vector<string>>Map;
	string top;
	for (int i = 0; i < N; i++) {
		vector<string> parsed = S_split(S[i]);
		if (!i)top = parsed[0];
		FOR(k, 1, SZ(parsed)) {
			Map[parsed[0]].push_back(parsed[k]);
		}

	}
	vector<string>target = Map[top];
	map<string, int >checked;
	FOR(i, 0, SZ(target)) {
		if (Map[target[i]].size() == 0) {
			continue;
		}

		if (checked[target[i]]) {
			target[i] = "#";
		}
		else {
			checked[target[i]] = 1;
			FOR(j, 0, SZ(Map[target[i]])) {
				target.push_back(Map[target[i]][j]);
			}
			target[i] = "#";
		}
	}
	set<string>se;
	FOR(i, 0, SZ(target)) {
		if (target[i] == "#") {
		}
		else {
			se.insert(target[i]);
		}
	}

	return se.size();
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while (cin >> N, N) {
		cout << solve() << endl;
	}
	return 0;
}