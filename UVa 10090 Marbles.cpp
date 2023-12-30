#include <iostream>
#include <cmath>

using namespace std;

long long x, y;
long long gcd(long long a, long long b){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	else{
		long long ans = gcd(b, a%b);
		long long tmp = y;
		y = x - (a/b) * y;
		x= tmp;
		return ans;
	}
}

int main(){
	long long n, c1, n1, c2, n2;
	
	while(scanf("%lld", &n)){
		if(n == 0) break;
		scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
		
		long long g = gcd(n1, n2);
		long long downk = ceil(1.0 * (-n)*x / n2);
		long long upk = floor(1.0 * n*y / n1);
		
		if(downk > upk || n%g){
			printf("failed\n");
			continue;
		}
		if(c1*n2 < c2*n1){
			x = n * x / g + n2 / g *upk;
			y = n * y / g - n1 / g *upk;
		}
		else{
			x = n * x / g + n2 / g *downk;
			y = n * y / g - n1 / g *downk;
		}
		printf("%lld %lld\n", x, y);
	}
}
