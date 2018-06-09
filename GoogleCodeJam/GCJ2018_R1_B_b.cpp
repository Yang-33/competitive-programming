#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) if(0)cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

// Œ¯‚µ‚¢‚ªA‚ª‚ñ‚Î‚é

string solve() {
	int In; cin >> In;


	int M, N;
	vector<PII>xline;
	vector<PII>yline;
	{
		int d, x, y;
		cin >> d >> x >> y;
		M = d + x;
		N = d - y;
	}
	int mc = 1, nc = 1;
	int mid = 0, nid = 0;

	FOR(i, 1, In) {
		int d, x, y;
		cin >> d >> x >> y;
		if (d + x == M) {
			mc++;
		}
		else {
			xline.push_back(PII(mid, mc));
			M = d + x;
			mid = i;
			mc = 1;
		}
		if (d - y == N) {
			nc++;
		}
		else {
			yline.push_back(PII(nid, nc));
			N = d - y;
			nid = i;
			nc = 1;
		}
	}

	xline.push_back(PII(mid, mc));
	yline.push_back(PII(nid, nc));

	//FOR(i, 0, SZ(xline)) {
	//	cout << xline[i].first << " " << xline[i].second<<endl;
	//}
	//cout << "--------------" << endl;
	//FOR(i, 0, SZ(yline)) {
	//	cout << yline[i].first << " " << yline[i].second << endl;;
	//}
	PII ans(0, 0);
	set<PII>ansset;

	FOR(i, 0, SZ(xline)) {
		set<int>manaid;
		int xid, xcnt;
		tie(xid, xcnt) = xline[i];
		debug(xid);
		debug(xcnt);
		int yidx = lower_bound(ALL(yline), PII(xid + xcnt, -1)) - yline.begin();
		debug(yidx);
		int yid, ycnt;
		if (yidx) {
			tie(yid, ycnt) = yline[yidx - 1];
			debug(yid);
			debug(ycnt);
			if (manaid.count(yid)) {
				;
			}
			else {
				manaid.insert(yid);
				if (xid <= yid + ycnt && yid <= xid + xcnt) {//merge can
					int len = max(xid + xcnt - 1, yid + ycnt - 1) - min(yid, xid) + 1;
					if (ans.first == len) {
						ans.second++;
						int tx, ty;
						tx = xid, ty = yid;
						if (tx < ty)
							ansset.insert(PII(tx, ty));
						else ansset.insert(PII(ty, tx));
					}
					else if (ans.first < len) {
						ans.first = len;
						ans.second = 1;
						ansset.clear();
						int tx, ty;
						tx = xid, ty = yid;
						if (tx < ty)
							ansset.insert(PII(tx, ty));
						else ansset.insert(PII(ty, tx));
					}
				}
			}
		}
		if (yidx!=SZ(yline)) {
			tie(yid, ycnt) = yline[yidx];
			debug(yid);
			debug(ycnt);
			if (manaid.count(yid));
			else {
				manaid.insert(yid);
				if (xid <= yid + ycnt && yid <= xid + xcnt) {//merge can
					int len = max(xid + xcnt - 1, yid + ycnt - 1) - min(yid, xid) + 1;

					if (ans.first == len) {
						ans.second++;
						int tx, ty;
						tx = xid, ty = yid;
						if (tx < ty)
							ansset.insert(PII(tx, ty));
						else ansset.insert(PII(ty, tx));

					}
					else if (ans.first < len) {
						ans.first = len;
						ans.second = 1;
						ansset.clear();
						int tx, ty;
						tx = xid, ty = yid;
						if (tx < ty)
							ansset.insert(PII(tx, ty));
						else ansset.insert(PII(ty, tx));
					}
				}
			}
		}
		yidx = lower_bound(ALL(yline), PII(xid, -1)) - yline.begin();
		debug(yidx);
		debug(yidx-1);
		yid, ycnt;
		if (yidx) {
			tie(yid, ycnt) = yline[yidx - 1];
			debug(yid);
			debug(ycnt);
			if (manaid.count(yid));
			else {
				manaid.insert(yid);

				if (xid <= yid + ycnt && yid <= xid + xcnt) {//merge can
					int len = max(xid + xcnt - 1, yid + ycnt - 1) - min(yid, xid) + 1;
					if (ans.first == len) {
						ans.second++;
						int tx, ty;
						tx = xid, ty = yid;
						if (tx < ty)
							ansset.insert(PII(tx, ty));
						else ansset.insert(PII(ty, tx));
					}
					else if (ans.first < len) {
						ans.first = len;
						ans.second = 1;
						ansset.clear();
						int tx, ty;
						tx = xid, ty = yid;
						if (tx < ty)
							ansset.insert(PII(tx, ty));
						else ansset.insert(PII(ty, tx));
					}
				}
			}
		}
		if (yidx != SZ(yline)) {
			tie(yid, ycnt) = yline[yidx];
			debug(yid);
			debug(ycnt);
			if (manaid.count(yid));
			else {
				manaid.insert(yid);
				if (xid <= yid + ycnt && yid <= xid + xcnt) {//merge can
					int len = max(xid + xcnt - 1, yid + ycnt - 1) - min(yid, xid) + 1;
					if (ans.first == len) {
						ans.second++;
						int tx, ty;
						tx = xid, ty = yid;
						if (tx < ty)
							ansset.insert(PII(tx, ty));
						else ansset.insert(PII(ty, tx));
					}
					else if (ans.first < len) {
						ans.first = len;
						ans.second = 1;
						ansset.clear();
						int tx, ty;
						tx = xid, ty = yid;
						if (tx < ty)
							ansset.insert(PII(tx, ty));
						else ansset.insert(PII(ty, tx));
					}
				}
			}
		}


		debug(ans.first);
		debug(ans.second);
	}

	

	ans.second = SZ(ansset);

	string out = "";

	out += to_string(ans.first) + " " + to_string(ans.second);
	return out;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		cout << "Case #" << t + 1 << ": " << solve() << "\n";
	}

	return 0;
}
