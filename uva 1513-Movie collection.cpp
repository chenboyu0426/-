#include <iostream>
#include <cstring>

#define lowbit(x) ((x)&(-x)) 

using namespace std;

int disk[200005]; 
int bit[200005]; //紀錄此位置上有沒有 movie disk 
const int maxn = 1e5 + 5;

void add(int p, int v){
	
	while(p < 2 * maxn){
		bit[p] += v;
		p += lowbit(p);
	}
}

int sum(int p){
	
	int ret = 0;
	while(p > 0){
		ret += bit[p];
		p -= lowbit(p);
	}
	return ret;
}

int main(){
	int cas, n, m, move;
	
	scanf("%d", &cas);
	while(cas--){
		
		memset(bit, 0, sizeof(bit));
		scanf("%d%d", &n, &m);

		for(int i = 1; i <= n; i++){
			disk[i] = n-i+1;
			add(disk[i], 1);
		}
		
		int N = n;
		
		for(int i = 1; i <= m; i++){
			scanf("%d", &move);
			printf("%d%s", n - sum(disk[move]), i != m ? " " : "\n");
			add(disk[move], -1);
			disk[move] = ++N;
			add(disk[move], 1);
		}
		
	}
} 
