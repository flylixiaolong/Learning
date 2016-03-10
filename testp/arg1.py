#!/usr/bin/evn python
#-*- coding:utf-8 -*-

import argparse

argparser = argparse.ArgumentParser()
argparser.add_argument('--parallel-compile', action='store_true',
                       help="present if compiling can be done in parallel")
args=argparser.parse_args()
