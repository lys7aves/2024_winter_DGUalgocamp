#include <bits/stdc++.h>

using namespace std;

int n, m, answer;
int s[1010], fs[1010][1010], a[1010];
int cnt[1010];

void dfs(int p, int c)
{
	int i;
	
	if(c >= answer) return;
	
	if(p == n){
		bool flag=true;
		for(i=0; i<m; i++) flag &= cnt[s[i]] > 0;
		
		if(flag) answer = c;
		
		return;
	}
	
	for(i=0; i<a[p]; i++) cnt[fs[p][i]]++;
	dfs(p+1, c+1);
	
	for(i=0; i<a[p]; i++) cnt[fs[p][i]]--;
	dfs(p+1, c);
}

int main()
{
	int i, j;
	
	cin >> n >> m;
	for(i=0; i<m; i++) cin >> s[i];
	
	for(i=0; i<n; i++){
		cin >> a[i];
		for(j=0; j<a[i]; j++) cin >> fs[i][j];
	}
	
	answer = n+1;
	dfs(0, 0);
	
	if(answer == n+1) cout << -1;
	else cout << answer;
	
	return 0;
}