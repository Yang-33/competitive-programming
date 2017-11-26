import math
import decimal

a = int(input())
b = int(input())

# /* -----  2017/11/26  Problem: tcs_codevita_2017_round2 B / Link: __CONTEST_URL__  ----- */
#/* ------問題------
#
#すべてが奇数の数字のみでなる数字のうち、N番目にちいさいものは。
#
#-----問題ここまで----- */
#/* -----解説等-----
#
#C++で桁DPをしようとしたが、あたいが大きすぎるため断念。
#また、5進数っぽいのでそれで書き直したが、失敗してしまったので、OEISをつかった。
#pythonは数字のことをあまり考えなくていいのでこっちで書いた。
#
#----解説ここまで---- */


n = int(input())
ans = decimal.Decimal(0)
N = n


M = math.floor(math.log(4 * N + 1,5))
for j in range(0,int(M)):
    b = decimal.Decimal((4 * N + 1 - math.pow(5,M)) / (4 * math.pow(5,j)))

    ans +=decimal.Decimal( ((2 *math.floor(b) + 1) % 10) * math.pow(10,j))

print(int(ans))
