#include <iostream>
#include <cmath>
using namespace std;

bool coprime(int a, int b) {
	for (int i = 2; i <= a; i++) {
		if (b % i == 0 && a % i == 0) return false;
	}
	return true;
}


int main() {
	int n, out = 0;

	cin >> n;

	for (int k = 3; k <= n; k++) {
		for (int p = 2; p < k; p++) {
			for (int q = p + 1; q < k; q++) {
			
				if (p * q == k && coprime(p, q)) {
					out++;
				}
			}
		}
	}

	cout << out << endl;

	return 0;
}
