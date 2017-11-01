#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/11/01  Problem: AOJ1154/ Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1154  ----- */
/* ------–â‘è------

R”»’·“úŽC‰F’ˆ—ï 48642.5D ‚í‚ê‚í‚ê‚ÍC‰“™®”˜_‚©‚ço‘è‚·‚é‚±‚Æ‚ÉŒˆ‚ß‚½D ³®”‚Ì‘fˆö”‚ð‚·‚×‚Ä‹‚ß‚é‚±‚Æ‚ÉŽ—‚½–â‘è‚¾‚ªC ‚»‚¤‚Å‚Í‚È‚¢D

7 ‚ÅŠ„‚Á‚½—]‚è‚ª 1 ‚Ü‚½‚Í 6 ‚Å‚ ‚é³®”‚Í 7N+{1,6} ”‚ÆŒÄ‚Î‚ê‚éD ‚µ‚©‚µC”­‰¹‚µ‚É‚­‚¢‚Ì‚ÅC ŒŽ—j“y—j”‚ÆŒÄ‚Ú‚¤D

ŒŽ—j“y—j” a, b ‚É‘Î‚µ‚ÄC ŒŽ—j“y—j” x ‚ª‘¶Ý‚µ‚Ä ax = b ‚ª¬‚è—§‚Â‚Æ‚«C a ‚ð b ‚ÌŒŽ—j“y—j–ñ”‚ÆŒÄ‚ÔD ŒŽ—j“y—j” a ‚ªŒŽ—j“y—j” b ‚ÌŒŽ—j“y—j–ñ”‚Å‚ ‚é‚½‚ß‚É‚ÍC a ‚ª b ‚Ì•’Ê‚ÌˆÓ–¡‚Ì–ñ”‚Å‚ ‚ê‚Î•K—v\•ª‚Å‚ ‚é‚ÆC ŠÈ’P‚ÉØ–¾‚Å‚«‚éD

1 ‚æ‚è‘å‚«‚ÈŒŽ—j“y—j”‚Å‚»‚êŽ©g‚Æ 1 ‚Ì‘¼‚ÉŒŽ—j“y—j–ñ”‚ð‚à‚½‚È‚¢‚à‚Ì‚ðC ŒŽ—j“y—j‘f”‚ÆŒÄ‚ÔD •’Ê‚ÌˆÓ–¡‚Ì‘f”‚Å‚ ‚éŒŽ—j“y—j”‚ÍŒŽ—j“y—j‘f”‚Å‚ ‚é‚ªC ‹t‚Íˆê”Ê‚É¬‚è—§‚½‚È‚¢D ‚½‚Æ‚¦‚ÎC27 ‚Í•’Ê‚ÌˆÓ–¡‚Ì‘f”‚Å‚Í‚È‚¢‚ªCŒŽ—j“y—j‘f”‚Å‚ ‚éD ŒŽ—j“y—j” a ‚ÌŒŽ—j“y—j–ñ”‚Å‚ ‚éŒŽ—j“y—j‘f”‚ðC a ‚ÌŒŽ—j“y—j‘fˆö”‚ÆŒÄ‚ÔD ‚½‚Æ‚¦‚ÎC 27 ‚ÍŒŽ—j“y—j‘f”‚Å‚ ‚èC 216 = 27 ~ 8 ‚ª¬‚è—§‚Â‚Ì‚ÅC 27 ‚Í 216 ‚ÌŒŽ—j“y—j‘fˆö”‚Ì‚Ð‚Æ‚Â‚Å‚ ‚éD

1 ‚æ‚è‘å‚«‚È‚Ç‚ñ‚ÈŒŽ—j“y—j”‚àC 1 ŒÂˆÈã‚ÌŒŽ—j“y—j‘f”‚ÌÏ‚Æ‚µ‚Ä•\‚·‚±‚Æ‚ª‚Å‚«‚éD •\‚µ•û‚ÍC‡˜‚Ìˆá‚¢‚ð–³Ž‹‚µ‚Ä‚àC•K‚¸‚µ‚àˆê’Ê‚è‚Å‚Í‚È‚¢D ‚½‚Æ‚¦‚ÎC 216 = 6 ~ 6 ~ 6 = 8 ~ 27 ‚Å‚ ‚éD
‘IŽè‚ÍC “ü—Í‚³‚ê‚½ŠeX‚ÌŒŽ—j“y—j”‚É‘Î‚µ‚ÄC ‚»‚ÌŒŽ—j“y—j‘fˆö”‚ð‚·‚×‚Äo—Í‚·‚éƒvƒƒOƒ‰ƒ€‚ð‘‚©‚È‚­‚Ä‚Í‚È‚ç‚È‚¢D

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

ŒŽ—j“y—j”‚ðæ‚É—ñ‹“‚µ‚Ä‚¨‚¯‚ÎAƒNƒGƒŠ‚É“š‚¦‚é‚Ì‚ÉŠyB

----‰ðà‚±‚±‚Ü‚Å---- */
bool getuyou[300000];

void getuyouSet() {
	for (int i = 2; i < 300000; i++) {
		if ((i % 7) != 1 && i % 7 != 6) continue;
		bool f = false;
		for (int j = 2; j*j <= i; j++) {
			if (i%j != 0) continue;
			if (j % 7 == 1 || j % 7 == 6) {
				f = true;
				break;
			}
		}
		if (!f) {
			getuyou[i] = true;
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n;

    getuyouSet();

	while (cin >> n) {
		if (n == 1)break;
		cout << n << ":";
		for (int i = 6; i <= n; i++) {
			if (getuyou[i] == true && n%i == 0) {
				cout << " " << i;
			}
		}
		cout << endl;
	}
	return 0;
}