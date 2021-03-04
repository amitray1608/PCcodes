def jimteshoo(jmtesh):
	return jimtesh
def jiteshBolte(jimtesh1,jimtesh2):
	s=len(set(jimtesh1+jimtesh2))
	return s
for t in range(int(input())):
	n=int(input())
	l=input().split()
	jiteshBantai={}
	for i in l:
	    p=i[1:]
	    if p in jiteshBantai:
		    jiteshBantai[p].append(i[0])
	    else:
		    jiteshBantai[p]=[i[0]]
	bantai=list(jiteshBantai.keys())
	s=0
	for i in range(len(jiteshBantai)):
		for j in range(i+1,len(jiteshBantai)):
			jimtesh=jiteshBolte(jiteshBantai[bantai[i]],jiteshBantai[bantai[j]])
			s+=(jimtesh-len(jiteshBantai[bantai[i]]))*(jimtesh-len(jiteshBantai[bantai[j]]))
	answer = s*2
	print(jimteshoo(answer))
