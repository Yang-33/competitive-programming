#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(e);(i)++)

/* 2017/01/15 ��� DPL_3_B Name/Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B */
/* -----�����-----
���: �ő咷���`
��ӂ� 1 cm �̃^�C�����AH �~ W ���ׂ��Ă��܂��B
�^�C���͉���Ă�����́A�Y��Ȃ��̂̂����ꂩ�ł��B
�Y��ȃ^�C���݂̂��g���Ăł��钷���`�̖ʐς̍ő�l�����߂Ă��������B

�����`�̏ꍇ�ł͏���dp�ł������������`�̏ꍇ�ɂ͏�肭�����Ȃ��̂�
����͊e��ɑ����^�C���̐���dp�ŋ��߁A�e�s�ɑ΂��ăq�X�g�O���������`�̍ő�l�Ɠ��l�̌v�Z���s���B
�v�Z�ʂ� H*�q�X�g�O�����ő咷���` ����A�n(H*W)�ƂȂ�B


��P�������ł����Ԃł̓X�^�b�N�ɍ����Ƌ�Ԃ�ςށB�i�������񑝉���Ԃł͉������Ȃ��j
�����łȂ��Ƃ��ɂ̓X�^�b�N�̃g�b�v�������݂̋�Ԃ̐�[���傫���Ȃ�܂ŃX�^�b�N������o���A�v�Z���s���B
�����O�̂Ƃ��́A�Ō�̋�ԍ��[�ƌ��݂̍������L�^�����̋�Ԃֈڂ�B

*/

#define MAX_W 1400 
#define MAX_H 1400
int tile[MAX_H][MAX_W];
int dp[MAX_H][MAX_W];
struct Rectangle { int h; int pos; };//height and position
int ans = 0;

int LargestRectangle(int size, int buf[]) {
    stack<Rectangle> S;
    int maxv = 0;
    buf[size] = 0;

    FOR(i, 0, size + 1) {
        Rectangle rect;
        rect.h = buf[i];
        rect.pos = i;
        if (S.empty()) {
            S.push(rect);
        }
        else {
            if (S.top().h < rect.h) {
                S.push(rect);
            }
            else if (S.top().h > rect.h) { 
                //���[�v����O�ꂽ�ۂ̏����͒ʏ�ʂ�X�^�b�N�ɐςނ���
                int target = i; //pre.pos
                while (!S.empty() && S.top().h >= rect.h) {
                    Rectangle pre = S.top(); S.pop();
                    int area = pre.h * (i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
    }
    return maxv;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    FOR(i, 0, H) {
        FOR(j, 0, W) {
            cin >> tile[i][j];
        }
    }
    FOR(i, 0, H) {
        FOR(j, 0, W) {
            if (tile[i][j] == 1) { //dirty
                dp[i][j] = 0;
            }
            else { //clean
                if (i == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + 1;
            }
        }
    }

    FOR(i, 0, H) {
        ans = max(ans, LargestRectangle(W, dp[i]));
    }

    cout << ans << endl;

    return 0;
}OB
