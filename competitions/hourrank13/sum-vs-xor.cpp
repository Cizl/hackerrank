#include <iostream>
using namespace std;

int main() {
	long long n, out = 1;

	cin >> n;

	while (n > 0) {
		if (!(n % 2)) out *= 2;
		n /= 2;
	}

	cout << out << endl;

	return 0;
}
