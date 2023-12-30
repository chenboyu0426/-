#include <iostream>

using namespace std;

struct state{
	int sum, id, key;
}s[150005], c[150005]; // s–じ ; c 程 

int n, p, ans, cnt;
char s1[150005], s2[150005];

int find(int key){ //array c患搭计いbinary searchт <= key程┮矪
	int l = 0, r = cnt - 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(c[mid].key <= key) r = mid;
		else l = mid + 1;
	}
	return c[l].id;
}

bool solve(){
	ans = 0;
	cnt = 1;
	s[0].sum = s[0].id = s[0].key = 0;
	c[0] = s[0];
	for(int i = 1; i <= n; i++){
		s[i].sum = s[i-1].sum + (s1[i-1] != s2[i-1]);
		s[i].id = i; s[i].key = i * p - 100 * s[i].sum;
		if(s[i].key < c[cnt-1].key){ // s[i] keyヘ玡程 
			c[cnt++] = s[i];
		}else{
			int t = find(s[i].key);
			ans = max(ans, s[i].id - t);
		}
	}
	if(ans) return true;
	return false; 
}

int main()
{	
	while(scanf("%d%d", &n, &p) && n != 0)
	{	
		cin >> ws;
		scanf("%s%s", &s1, &s2);
		if(solve()) printf("%d\n", ans);
		else printf("No solution.\n");
	}
	return 0;
} 
