#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else if (a == 0) {
		return b;
	}
	
	if (a > b) {
		return gcd(b, a % b);
	} else {
		return gcd(a, b % a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	int arr[n], minus[n - 1];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		minus[i] = abs(arr[i + 1] - arr[i]);
	}

	int gcd_res = minus[0];	
	for (int i = 1; i < n - 1; i++) {
		gcd_res = gcd(gcd_res, minus[i]);
	}
	
	for (int i = 2; i <= gcd_res / 2; i++) {
		if (gcd_res % i == 0) {
			cout << i << " ";
		}
	}
	
	cout << gcd_res << "\n";
}
