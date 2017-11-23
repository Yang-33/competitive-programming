#include <bits/stdc++.h>
#define FOR(i,s,t) for(int i=s;i<t;i++)
#define REP(i,n) FOR((i),0,(n))
using namespace std;
using VI = vector<int>;
using VSS = vector<string>;
using VVI = vector<VI>;
#define SZ(s) ((int)(s.size()))
#define PB push_back
#define ALL(xs) begin(xs),end(xs)
using LL = long long;
using VL = vector<LL>;

/* -----  2017/11/23  Problem:   
2014-2015 ACM-ICPC East Central North America Regional Contest (ECNA 2014) A / Link: http://codeforces.com/gym/100641  ----- */
/* ------問題------

連分数がある。これを四則演算したときの結果を連分数で表示せよ。
ただし2番め以降の項は正に限定される。

-----問題ここまで----- */
/* -----解説等-----

戦犯問題
C++が書けないために足を引っ張った。
連分数を分数に直すときは、最もネストの深い部分から普通にやっていけば良い。
分数を連分数で表すときは、頭から順に作っていけば良い。
これらは分数とは別に書くのが吉。

----解説ここまで---- */



struct frac {
	LL  p, q; // q/p
	frac(LL a, LL b) {
		p = a, q = b;
		if (p<0)p = -p, q = -q;
	}

	LL gcd(LL x, LL y) {
		return __gcd(abs(x), abs(y));
	}
	frac yakubun() {
		LL g = gcd(p, q);
		p = p / g;
		q = q / g;
		return frac(p, q);
	}
	frac operator +(const frac &a) {
		return frac(p*a.p, q*a.p + a.q*p).yakubun();
	}
	frac operator -(const frac &a) {

		return frac(p*a.p, q*a.p - a.q*p).yakubun();
	}
	frac operator *(const frac &a) {
		return frac(p*a.p, q*a.q).yakubun();
	}
	frac operator /(const frac &a) {
		return frac(p*a.q, q*a.p).yakubun();
	}

};

frac to_frac(VL &xs) {
	frac t(1, 0);
	for (int i = SZ(xs) - 1; i >= 0; i--) {
		t = t + frac(1, xs[i]);
		if (i>0)
			t = frac(t.q, t.p).yakubun();
	}
	return t.yakubun();
}

void trans(frac A, VL& xs) {
	A.yakubun();
	if (A.q<0) {
		LL s = abs(((A.q - A.p + 1) / A.p));
		A.q += s*A.p;
		trans(A, xs);
		xs[0] -= s;
		return;
	}
	if (A.q >= A.p) {
		xs.PB(A.q / A.p);
		A.q %= A.p;
	}
	else if (SZ(xs) == 0) {
		xs.PB(0);
	}
	if (A.q == 0) {
		return;
	}
	if (A.q == 1) {
		xs.push_back(A.p); return;
	}
	//  assert(A.p>0);
	LL x = A.p / A.q;
	xs.PB(x);
	frac B(A.q, A.p - x*A.q);
	B.yakubun();
	// cout<<"xs"<<SZ(xs)<<"  ;"<<xs.back()<<endl;
	// if(xs.size()>10)return ;
	trans(B, xs);
}


int main() {

	int r1, r2;
	int cnt = 1;
	while (cin >> r1 >> r2, r1 | r2) {
		VL a1(r1);
		VL a2(r2);
		FOR(i, 0, r1) {
			cin >> a1[i];
		}
		FOR(i, 0, r2) {
			cin >> a2[i];
		}

		frac R1 = to_frac(a1);
		frac R2 = to_frac(a2);
		R1.yakubun();
		R2.yakubun();

		cout << "Case " << cnt << ":" << endl;
		cnt++;

		VL p;
		trans(R1 + R2, p);
		FOR(i, 0, SZ(p)) {
			cout << p[i] << " ";
		}cout << endl;

		VL mi;
		frac M = R1 - R2;

		trans(R1 - R2, mi);
		FOR(i, 0, SZ(mi)) {
			cout << mi[i] << " ";
		}cout << endl;

		VL mul;
		trans(R1*R2, mul);
		FOR(i, 0, SZ(mul)) {
			cout << mul[i] << " ";
		}cout << endl;

		VL div;
		trans(R1 / R2, div);
		FOR(i, 0, SZ(div)) {
			cout << div[i] << " ";
		}cout << endl;

	}  // +-*/

	return 0;
}
