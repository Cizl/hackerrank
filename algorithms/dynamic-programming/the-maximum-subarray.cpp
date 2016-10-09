#include <iostream>
#include <vector>

int main() {

	int t; // number of test cases
	std::cin >> t;

	while (t--) {
		int n; // array size
		std::cin >> n;

		std::vector<int> array;

		int ncont = 0, cont = 0;
		bool all_negative = true;

		for (int i = 0; i < n; i++) {
			int a;
			std::cin >> a;
			array.push_back(a);

			if (a >= 0) {
				all_negative = false;
				ncont += a;
			}
		}

		if (all_negative) {
			cont = ncont = array[0];
			for (int i = 1; i < n; i++) {
				if (array[i] > cont) {
					cont = ncont = array[i];
				}
			}
		} else {

			int curr = 0;

			for (int i = 0; i < n; i++) {
				curr += array[i];
				if (curr < 0) curr = 0;
				if (curr > cont) cont = curr;
			}
		}

		std::cout << cont << " " << ncont << std::endl;
	}
	
	return 0;
}

