t = input()

for _ in xrange(t):
    expression = raw_input()
    ans=''
    l=[]
    for char in expression:
        if char!=')':
           l.append(char)
        else:
           third=l[-1]
           second=l[-2]
           first=l[-3]
           l.pop(-1)
           l.pop(-1)
           l.pop(-1)
           l.pop(-1)
           l.append(first+third+second)
    print l[0]
