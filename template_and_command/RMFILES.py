#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
PWD = os.getcwd()


top = "unuploaded"
for root, dirs, files in os.walk(top, topdown=False):
    for name in files:
        os.remove(os.path.join(root, name))
        if os.path.exists(PWD+"/"+name[:-4]):
            os.remove(PWD+"/"+name[:-4])
        
        
   # for name in dirs:
   #     os.rmdir(os.path.join(root, name))
   # 以下の階層も消したいときはコメントを消す
  
print("-!- we have deleted files on unuploaded and deleted execute files of these. -!-")
 # 実行時はsolve内でつかう
 # solve
 #   -unuploaded
 #		-filea.cpp
 #		-fileb.cpp
 #		-filec.cpp
 #		-filed.cpp
   