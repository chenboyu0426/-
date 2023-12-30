#include <iostream>

using namespace std;

int x, y;

int gcd(int a, int b){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	else{
		int ans = gcd(b, a%b);
		int tmp = y;
		y = x - (a/b)*y;
		x = tmp;
		return ans;
	}
}

int main(){
	int a, b;
	
	while(scanf("%d%d", &a, &b) != EOF){
		printf("%d %d %d\n", x, y, gcd(a,b));
	}
}
