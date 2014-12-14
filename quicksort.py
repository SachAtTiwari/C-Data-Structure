#!/usr/bin/env python

import random
 
def quicksort(a, start, end):
    if start < end:
      pivot = partition(a, start, end)
      print "pivot: ",pivot
      quicksort(a, start, pivot - 1)
      quicksort(a, pivot + 1, end)

def partition(a, start, end):
    #pivot = start + random.randrange(end - start + 1)
    #swap(a, pivot, end)
    if len(set(a)) <= 1:
        return (start + end)/2

    pivot = a[end]
    
    for i in range(start, end):
      if a[i] <= a[end]:
        swap(a, i, start)
        start += 1
 
    swap(a, start, end)
    return start
 
def swap(a, x, y):
    tmp = a[x]
    a[x] = a[y]
    a[y] = tmp

def main():
    a = [8,4,6,21,5]
    #a = [8,8,8,8,8]
    quicksort(a,0,len(a)-1)
    lena = len(a)

	#print lena
    for i in a:
	    print i

if __name__=="__main__":
    main()	
