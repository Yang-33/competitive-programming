#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;
bool cc[30];

/* ‚³‚«‚É•¶Žš•ÏŠ·ƒŠƒXƒg‚ð‚©‚ñ‚è‚µ‚Ä‚Â‚­‚Á‚Ä‚µ‚Ü‚¦‚Î‚¦‚¦‚ñ‚â */
/* TLE */

//•¡†‚³‚ê‚½‚à‚Ì‚ðˆÃ†‰»‚µ‚ÄŒ³‚Ì‚à‚Æ‚ðˆê’v‚·‚é‚©‚ð”»’è
bool f(string s, string &a) {
	FOR(i, 0, 26)cc[i] = false;
	FOR(i, 0, s.size()) {
		//cout << s[i] << endl;
		if (s[i] != 'a' && cc[s[i] - 'a'] == false) {
			//cout << "use "<<s[i] << endl;
			cc[s[i] - 'a'] = 1;
			s[i] = s[i] - 1;
		}
	}

	//	cout << "moto: " << a << "  now: " << s << endl;
	if (s == a)return 1;
	else return 0;

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (1) {
		string s;
		//		scanf("%s", &s);
		cin >> s;
		string str;
		str = s;
		ll ans = 0;
		vector<string >v;
		if (s == "#")break;
		ll ss = s.size();
		FOR(i, 0, 1 << ss) {
			str = s;
			//ˆÃ†‰»‚Å‚Í-A•¡†‚Å‚Í+
			bool ff = 1;
			FOR(j, 0, ss) {
				if (i >> j & 1 && str[ss - 1 - j] == 'z') {
					ff = 0;
					break;
				}

				if (i >> j & 1 && str[ss - 1 - j] != 'z')str[ss - 1 - j] += 1;
			}
			if (ff == 0)continue;
			//			cout<<"henkanmae : " << str << endl;
			if (f(str, s)) {
				ans++;
				v.push_back(str);
			}


		}
		//printf("%d\n", ans);
		cout << ans << endl;
		if (ans >= 10) {
			FOR(i, 0, 5) {
				//printf("%s\n", v[i]);
				cout << v[i] << endl;
			}
			FOR(i, v.size() - 5, v.size()) {
				//printf("%s\n", v[i]);
				cout << v[i] << endl;
			}
		}
		else {
			FOR(i, 0, v.size()) {
				//printf("%s\n", v[i]);
				cout << v[i] << endl;
			}

		}
	}

	return 0;
}