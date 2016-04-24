#!/usr/bin/env python3
def make_counter():
    count = 0
    def counter():
        count += 1
        return count
    return counter

if __name__=="__main__":
    cnt=make_counter()
    cnt()
    cnt2=make_counter()
    print(cnt())
    print(cnt2())
