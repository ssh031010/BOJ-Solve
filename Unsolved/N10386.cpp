#include <bits/stdc++.h>

using namespace std;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);

	while (true) {
		int n1, n2;
		cin >> n1 >> n2;
		
		if (n1 == 0 && n2 == 0) break;
		
		int r1_part[n1];
		for (int i = 0; i < n1; i++) {
			cin >> r1_part[i];
		}
		
		int r2_part[n2];
		for (int i = 0; i < n2; i++) {
			cin >> r2_part[i];
		}
		
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
	}
}
