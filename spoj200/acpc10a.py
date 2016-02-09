a,b,c=map(int,raw_input().split())

while a!=0 or b!=0 or c!=0:
      if b-a == c-b:
           if b-a!=0:
              print 'AP',c+b-a
           else:
              print 'GP',c*(b/a)
      else:
          print 'GP',c*(b/a)
      a,b,c = map(int,raw_input().split())       
