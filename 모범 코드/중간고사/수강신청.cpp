#include <bits/stdc++.h>

using namespace std;

int cnt[1010], s[1010][2];

int main()
{
	int a, b, c, n, i, j, answer=0;
	
	cin >> a >> b >> c;
	cin >> n;
	for(i=0; i<n; i++) cin >> s[i][0] >> s[i][1];
	
	for(i=0; i<n; i++){
		cnt[s[i][0]]++;
		cnt[s[i][1]]++;
		for(j=i+1; j<n; j++){
			cnt[s[j][0]]++;
			cnt[s[j][1]]++;
			
			if(cnt[a] * cnt[b] * cnt[c] > 0) answer++;
			
			cnt[s[j][0]]--;
			cnt[s[j][1]]--;
		}
		cnt[s[i][0]]--;
		cnt[s[i][1]]--;
	}
	
	cout << answer;
	
	return 0;
}