import math

def min(list):
	i = 0
	for n in range(0, len(list)):
		if list[i] > list[n]:
			i = n
	return i

def max(list):
	i = 0
	for n in range(0, len(list)):
		if list[i] < list[n]:
			i = n
	return i

def avg(list):
	return sum(list)/len(list)

def find(list, val):
	for n in range(0, len(list)):
		if val == list[n]:
			return n
	return -1

def avg2(list):
	n = 1
	for x in list:
		n *= x
	return math.pow(n, 1/len(list))