#!/usr/bin/env python
#-*- coding:utf-8 -*-

from multiprocessing import Process,Queue
import os,time,re

def start_evince(name,queue):
    print 'Run child process %s (%s).' % (name,os.getpid())
    os.popen('time -f "%U\n%S" -o time.txt evince ~/OpenTuner/files/*.pdf')
    results=re.findall('\d+.\d+',os.popen('cat time.txt').read())
    queue.put(sum(map(float,results))) 

def stop_evince(name):
    print 'Run child process %s (%s).' % (name,os.getpid())
    time.sleep(30)
    os.popen('pkill evince')

def test_evince():
    i=0;
    times=[]
    queue = Queue()
    while i< 5:
        i += 1
        print 'Start %i test...' % i
        print 'Run parent process %s (%s).' %('parent',os.getpid())
        startp = Process(target=start_evince,args=('start evince',queue))
        startp.start()
        stopp = Process(target=stop_evince,args=('stop evince',)) 
        stopp.start()
        startp.join()
        stopp.join()
        times.append(queue.get())
        print 'Test %i end...' % i
    print "%0.2f" % (sum(times)/len(times))
if __name__=='__main__':
    test_evince()
