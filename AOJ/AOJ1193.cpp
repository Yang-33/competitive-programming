#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		double x, y, s;
		cin >> x >> y >> s;
		if (x == 0 && y == 0 && s == 0) break;

		int ret = -1;

		for (double a = 1; a < 1000; a += 1) {
			for (double b = a; b < 1000; b += 1) {
				int suma = a + a*x / 100;
				int sumb = b + b*x / 100;
				if (suma + sumb == s) {
					int ssuma = a + a*y / 100;
					int ssumb = b + b*y / 100;
					ret = max(ret, ssuma + ssumb);
				}
			}
		}
		cout << ret << endl;
	}

  return 0;
}