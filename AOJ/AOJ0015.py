# -*- coding: utf-8 -*-
#/* -----  2017/10/03  Problem: AOJ 0015  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0015&lang=jp ----- */
#/* ------問題------
#
#　2数を足し、80桁以上の整数なら overflowと出力
#
#-----問題ここまで----- */
#/* -----解説等-----
#
# Pythonなら無思考でできる。c++なら文字列で受け取って足し算を愚直に実装するのがよさそう
#
#----解説ここまで---- */

##Python解

N = int(input())
for i in range(N):
	a=int(input())
	b=int(input())
	if len(str(a+b)) >80:
		print("overflow")
	else :
		print(a+b)


