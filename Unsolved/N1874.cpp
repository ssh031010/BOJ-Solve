ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	bool is_stopped = false;
	
	int target = arr[0];
	int now = 0;
	int idx = 0;
	
	int res_idx = 0;
	char res_arr[200001] = {};
	
	stack<int> stack;
	while (true) {
		if (stack.empty()) {
			if (now == 0) {
				stack.push(++now);
				res_arr[res_idx++] = '+';
				cout << "t1\n";
			} else {
				if (now != target) {
					is_stopped = true;
					cout << "t2\n";
				}
				cout << "t3\n";
				break;
			}
		} else {
			if (stack.top() == target) {
				stack.pop();
				target = arr[++idx];
				res_arr[res_idx++] = '-';
				cout << "t4\n";
			} else if (now < target) {
				stack.push(++now);
				res_arr[res_idx++] = '+';
				cout << "t5\n";
			} else {
				is_stopped = true;
				cout << "t6\n";
				break;
			}
		}
	}
	
	if (is_stopped) {
		for (int i = 0; res_arr[i] != '\0'; i++) {
			cout << res_arr[i] << "\n";
		}
	} else {
		cout << "NO\n";
	}
