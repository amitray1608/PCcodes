import math
def primefactorize(x,prime):
cnt=0
while(x%2==0):
x=x//2
cnt+=1
if(2 in prime):
prime[2]+=cnt
else:
prime[2]=cnt
for i in range(3,int(math.sqrt(x))+1,2):
cnt=0
while x % i== 0:
cnt+=1
x = x / i
if(cnt>0):
if(i in prime):
prime[i]+=cnt
else:
prime[i]=cnt
if x > 2:
if(x in prime):
prime[x]+=1
else:
prime[x]=1
return prime

t=int(input())
for _ in range(t):
n=int(input())
d=dict()
d[1]=-1

for i in range(n-1):
    a,b=map(int,input().split())
    d[b]=a
c=list(map(int,input().split()))
q=int(input())
for _ in range(q):
    prime=dict()
    x,y=map(int,input().split())
    if(x==y):
        prime=primefactorize(c[x-1],prime)
        ans=1
        for key in prime:
            ans*=(prime[key]+1)
        print(ans)   
    else:    
        l1=[]
        l2=[]
        while(d[x]!=-1):
            l1.append(x)
            x=d[x]
        l1.append(1)
        while(d[y]!=-1):
            l2.append(y)
            y=d[y]
        l2.append(1)
        ll1=len(l1)
        ll2=len(l2)
        while(ll1!=0 and ll2!=0 and l1[ll1-1]==l2[ll2-1]):
            rec=l1[ll1-1]
            ll1-=1
            ll2-=1
        prime=primefactorize(c[rec-1],prime)
        for i in range(ll1+1):
            if(ll1==0 or i==ll1):
                break
            prime=primefactorize(c[l1[i]-1],prime)
        for i in range(ll2+1):
            if(ll2==0 or i==ll2):
                break
            prime=primefactorize(c[l2[i]-1],prime)
        ans=1
        for key in prime:
            ans*=(prime[key]+1)
        print(ans)
