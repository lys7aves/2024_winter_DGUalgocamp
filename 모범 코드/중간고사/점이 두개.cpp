#include <bits/stdc++.h>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

char arr[60][60];
int dist[60][60];
queue<int> que;

void dfs(int x, int y)
{
    if(arr[x][y] != 'X') return;
    if(dist[x][y]) return;
    dist[x][y] = 1;
    que.push(x);
    que.push(y);
    
    for(int i=0; i<4; i++) dfs(x+dx[i], y+dy[i]);
}

int main()
{
    int n, m, i, j, x, y, nx, ny;
    
    cin >> n >> m;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(i=1; i<=n; i++){
        for(j=1; j<m; j++){
            if(arr[i][j] == 'X'){
                dfs(i,j);
                break;
            }
        }
        if(j < m) break;
    }
    
    while(!que.empty()){
        x = que.front(); que.pop();
        y = que.front(); que.pop();
        
        for(i=0; i<4; i++){
            nx = x+dx[i];
            ny = y+dy[i];
            
            if(dist[nx][ny]) continue;
            if(arr[nx][ny] == 'X'){
                cout << dist[x][y] - 1;
                return 0;
            }
			if(arr[nx][ny] != '.') continue;
            dist[nx][ny] = dist[x][y] + 1;
            
            que.push(nx);
            que.push(ny);
        }
    }
    return 0;
}