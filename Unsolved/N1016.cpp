#include <bits/stdc++.h>

using namespace std;

int main() {
	long long min, max;
	cin >> min >> max;
	
	bool isNotPrime[1000001];
	isNotPrime[0] = false;
	isNotPrime[1] = false;
	
	for (int i = 2; i * i <= 1000000; i++) {
		for (int j = i * i; j <= 1000000; j += i) {
			isNotPrime[j] = true;
		}
	}
	
	int count = 0;
	for (long long i = min; i <= max; i++) {
		bool isReqNumber = true;
		for (long long j = 2; j <= sqrt(i); j++) {
			if (isNotPrime[j]) continue;
			
			if (i % (j * j) == 0) {
				isReqNumber = false;
				break;
			}
		}
		
		if (isReqNumber) {
			count++;
		}
	}
	
	cout << count << "\n";
	return 0;
}
