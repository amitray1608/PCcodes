def solution(n):
   nn = int(n)
   count = 0
   while(nn > 0):
      if(len(n) == 1):
         if n == '3':
            count += 2
            break
         if(n == '1'):
            break
      if nn%2 == 0:
         nn = nn//2
         n = str(nn)
         count+=1
      else:
         if(nn-1)%4 == 0:
            nn = nn-1
            count+=1
         else:
            nn = nn+1
            count+=1
   return count

print(solution("12345"))
