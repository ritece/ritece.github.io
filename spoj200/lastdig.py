t=input()
d={2:[2,4,8,6],3:[3,9,7,1],4:[4,6],7:[7,9,3,1],8:[8,4,2,6],9:[9,1]}
for i in xrange(t):
	a,b=map(int,raw_input().split())
	a=a%10
        if b==0:
	   print 1
	else:
           if a in d:
		if b%len(d[a])==0:
			print d[a][-1]
		else:
			print d[a][(b%len(d[a]))-1]
	   else:
		print a	

