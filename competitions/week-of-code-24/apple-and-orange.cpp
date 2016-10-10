#include <iostream>
#include <vector>

int main() {

	int s, t; // start and end of the house
	int a, b; // first and second tree
	int m, n; // no of apples and oranges

	std::cin >> s >> t;
	std::cin >> a >> b;
	std::cin >> m >> n;

	int out1 = 0, out2 = 0;
	int d;

	for (int i = 0; i < m; i++) {
		std::cin >> d;
		if (a + d <= t && a + d >= s) out1++;
	}

	for (int i = 0; i < n; i++) {
		std::cin >> d;
		if (b + d <= t && b + d >= s) out2++;
	}

	std::cout << out1 << std::endl << out2 << std::endl;

	return 0;
}
