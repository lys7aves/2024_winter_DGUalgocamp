n = int(input())
chk = [[0 for _ in range(n)] for _ in range(n)]
cnt = 0

def dfs(k):
    global n, cnt, chk
    
    if k == n:
        cnt += 1
        return
    
    for i in range(n):
        if chk[k][i] > 0: continue
        
        for j in range(n):
            if k+j >= n: break
            if i-j >= 0: chk[k+j][i-j] += 1
            chk[k+j][i] += 1
            if i+j < n: chk[k+j][i+j] += 1
            
        dfs(k+1)
        
        for j in range(n):
            if k+j >= n: break
            if i-j >= 0: chk[k+j][i-j] -= 1
            chk[k+j][i] -= 1
            if i+j < n: chk[k+j][i+j] -= 1
            
dfs(0)

print(cnt)