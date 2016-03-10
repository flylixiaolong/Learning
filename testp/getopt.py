#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import re
import json

opt=[]
fd=os.popen('gcc -Q -O3 --help=opt')
for line in fd:
    if 'enabled' in line:
        opt.append(line.split()[0]);
print opt
json.dump(opt,open('cc_flags.json',w))
print len(opt)

