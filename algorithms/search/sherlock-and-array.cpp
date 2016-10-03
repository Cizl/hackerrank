#include <iostream>
using namespace std;

int main() {
	
	int t; // number of test cases
	int n; // number of elements in the array

	int sum[100001]; 
	// sum[i] = sum of first i elements, 0 <= i <= n, sum[0] = 0

	cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;

			sum[j] = sum[j - 1] + a;
		}
		
		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}

		// Binary search

		int left = 0, right = n;
		bool found = false;

		while (left <= right) {
			int mid = left + (right - left) / 2; // !! 

			if (sum[mid - 1] < sum[n] - sum[mid]) {
				left = mid + 1;
			}
			else if (sum[mid - 1] > sum[n] - sum[mid]) {
				right = mid - 1;
			}
			else {
				cout << "YES" << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "NO" << endl;
		}
	}

	return 0;
}
