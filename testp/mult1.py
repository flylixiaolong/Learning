#!/usr/bin/env python
#-*- coding:utf-8 -*-

from multiprocessing import Process
import os

def run_proc(name):
    print "Run child process %s(%s)..." % (os.getpid(),name)

if __name__=='__main__':
   print "parent process %s..." % os.getpid()
   p = Process(target=run_proc,args=("test",))
   print "Process will start."
   p.start();
   p.join()
   print "Process end"

