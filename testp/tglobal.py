#!/usr/bin/env python3
#-*- coding:utf-8 -*-

import sglobal

b=[2]

def seta():
    sglobal.a=['a','b','c','d','e']
    nonlocal b=[1]
if __name__=="__main__":
    seta()
    print(sglobal.a)
    print(b)
