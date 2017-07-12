#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/07/12  Problem: AOJ 1282  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1282&lang=jp ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----

構文解析。
BNFに従って頑張って書くとできる。

----解説ここまで---- */

ll N;
string s[2000];
ll ans = 0LL;
map<char, int >cmax;
map<pair<char,int>, int>val;

int getnum(int i, int &pos) {
	int res = 0;
	while (isdigit(s[i][pos])) {
		res *= 10;
		res += s[i][pos] - '0';
		pos++;
	}
	return res;
}





//無理,false なら-1
int expression(int i, int &id) {
	if (isdigit(s[i][id]))return getnum(i, id);
	if (id < s[i].size()) {
		char name = s[i][id]; id++;
	//	cout << "on expr "; debug(name);
		if (cmax[name] == 0)return -1;//未定義
		id++;//[
		int num = expression(i, id);
		//cout << id << " "; debug(num);
		id++;// ]
		//a[num],未定義
		if (val.find(make_pair(name, num)) == val.end())return -1;
		if (num == -1 || cmax[name] <= num)return -1;
		
		
		return val[make_pair(name, num)];

	}
	//cerr << "error on exp" << endl;
	return -1;
}



//代入か実数値代入

bool assignment(int i, int &id) {
	char name = s[i][id]; id++;
	if (cmax[name] == 0)return false;
	//cout << "on asign "; debug(name);
	id ++;//  [
	int num = expression(i, id);
	//cout << id << " "; debug(num);
	if (cmax[name] <= num || num == -1)return false;
	id++;//]
	id++;//=
	int rnum = expression(i, id);
	//cout << id << " "; debug(rnum);

	if (rnum == -1)return false;
	//代入的なもの
	val[make_pair(name, num)] = rnum;
	return true;

}



bool declaration(int i, int &id) {
	char name = s[i][0];
	id += 2;
	int mxnum = getnum(i, id);
	id++;
	cmax[name] = mxnum;//これを超えたらアウト
	//debug(name);
	//debug(mxnum);
	return 1;
}

bool program(int i, int &id) {
	bool is_dec = 1;
	FOR(j, 0, s[i].size()) {
		if (s[i][j] == '=')is_dec = 0;
	}
	if (is_dec == 0)return assignment(i, id);
	else return declaration(i, id);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		cmax.clear();
		val.clear();
		N = 0;
		bool end = 0;
		while (1) {
			cin >> s[N];
			if (s[N][0] == '.')break;
			if (end == 1)continue;
			int id = 0;
			if (!program(N, id)) {
				cout << N+1 << endl;
				N++;
				end = 1;
			}
			N++;
		}
		if (N == 0)break;
		if (end == 0)cout << 0 << endl;
	}
	return 0;
}
