#!/usr/bin/env python
#-*- coding:utf-8 -*-
def g():
    print "fly"
def f():
    print "hello"
    return g()
def f1():
    print "world"
    return f()

if __name__=="__main__":
   f1() 
