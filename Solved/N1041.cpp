#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	unsigned long long int n;
	cin >> n;
	
	int dice[6];
	unsigned long long int min1 = 51, max1 = 0;
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		if (dice[i] < min1) {
			min1 = dice[i];
		}
		
		if (dice[i] > max1) {
			max1 = dice[i];
		}
	}
	
	if (n == 1) {
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			if (dice[i] == max1) continue;
			sum += dice[i];
		}
		
		cout << sum << "\n";
	} else {
		// 2개 면의 합의 최솟값 구하기 
		unsigned long long int min2 = 101;
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 6; j++) {
				if (i + j == 5) continue;
				
				unsigned long long int sum = dice[i] + dice[j];
				if (sum < min2) {
					min2 = sum;
				}
			}
		}
		
		// 3개 면의 합의 최솟값 구하기
		unsigned long long int min3 = 151;
		int case3[8][3] = {
			{0, 3, 4},
			{0, 2, 4},
			{0, 1, 3},
			{0, 1, 2},
			
			{5, 3, 4},
			{5, 2, 4},
			{5, 1, 3},
			{5, 1, 2}
		};
		
		for (int i = 0; i < 8; i++) {
			unsigned long long int sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += dice[case3[i][j]];
			}
			
			if (sum < min3) {
				min3 = sum;
			}
		}

		// 최솟값 구하기
		unsigned long long int result = min3 * 4 + min2 * (4 + (8 * (n - 2))) + min1 * (5 * (n - 2) * (n - 2) + 4 * (n - 2));
		cout << result << "\n";
	}
	
	return 0;
}
