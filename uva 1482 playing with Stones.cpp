#include <iostream>

using namespace std;


long long SG(long long k){

	if(k % 2 == 0){
		return k / 2;
	}
	else{
		return SG(k / 2);
	}
	
}

int main(){
	int cas, n;
	
	scanf("%d", &cas);
	while(cas--){
		scanf("%d", &n);
		
		long long s, v = 0;
		
		for(int i = 0; i < n; i++){
			scanf("%lld", &s);
			v ^= SG(s); //XOR
		}
		
		if(v) printf("YES\n");
		else printf("NO\n");
	}
} 
