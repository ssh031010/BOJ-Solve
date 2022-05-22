#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	
	if (a < b) {
		return gcd(a, b % a);
	} else {
		return gcd(b, a % b);
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

void printNumber(int top, int bottom) {
	// 일반 분수 -> 연분수꼴로 출력 
	int t = top, b = bottom, div = gcd(top, bottom);
	
	if (t < 0) {
		t = -t;
	}
	
	t /= div;
	b /= div;
	
	if (b == 1) {
		cout << t << "\n";
	} else {
		cout << t / b << " ";
		t %= b;
		
		while (t != 1) {
			int tmp = t;
			t = b;
			b = tmp;
			
			cout << t / b << " ";
			
			div = gcd(t, b);
			t /= div;
			b /= div;
			
			t %= b;
		}
		
		cout << b << " ";
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int count = 1;

	while (true) {
		int n1, n2;
		cin >> n1 >> n2;
		
		if (n1 == 0 && n2 == 0) break;
		
		cout << "Case " << count << ": \n";
		
		int r1_part[n1];
		for (int i = 0; i < n1; i++) {
			cin >> r1_part[i];
		}
		
		int r2_part[n2];
		for (int i = 0; i < n2; i++) {
			cin >> r2_part[i];
		}
		
		// 연분수 -> 일반 분수로 바꾸기 
		int top1 = 1, bottom1 = r1_part[n1 - 1];
		if (n1 == 1) {
			top1 = r1_part[n1 - 1];
			bottom1 = 1;
		} else {
			for (int i = n1 - 2; i >= 0; i--) {
				top1 += bottom1 * (r1_part[i]);
				if (i != 0) {
					int tmp = top1;
					top1 = bottom1;
					bottom1 = tmp;
				}
			}
		}
		
		int top2 = 1, bottom2 = r2_part[n2 - 1];
		if (n2 == 1) {
			top2 = r2_part[n2 - 1];
			bottom2 = 1;
		} else {
			for (int i = n2 - 2; i >= 0; i--) {
				top2 += bottom2 * (r2_part[i]);
				if (i != 0) {
					int tmp = top2;
					top2 = bottom2;
					bottom2 = tmp;
				}
			}
		}
		
		int n_lcm = lcm(bottom1, bottom2);
		
		int sum_top = top1 * (n_lcm / bottom1) + top2 * (n_lcm / bottom2);
		int sum_bottom = n_lcm;
		
		printNumber(sum_top, sum_bottom);
		
		int minus_top = top1 * (n_lcm / bottom1) - top2 * (n_lcm / bottom2);
		int minus_bottom = n_lcm;
		
		printNumber(minus_top, minus_bottom);
		
		int multiply_top = top1 * top2;
		int multiply_bottom = bottom1 * bottom2;
		
		printNumber(multiply_top, multiply_bottom);
		
		int division_top = top1 * bottom2;
		int division_bottom = bottom1 * top2;
		
		printNumber(division_top, division_bottom);
	}
	
	return 0;
}
