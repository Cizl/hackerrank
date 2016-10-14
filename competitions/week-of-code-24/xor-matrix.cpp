#include <iostream>
#include <vector>

int main() {

	int n, m;
	std::cin >> n >> m;
	m--;

	std::vector<std::vector<int> > rows;
	std::vector<int> row;

	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		row.push_back(a);
	}

	rows.push_back(row);

	for (int i = 0; i < n; i++) {
		std::vector<int> newRow;
		for (int j = 1; j < n; j++) {
			newRow.push_back(row[j] ^ row[j - 1]);
		}
		newRow.push_back(row[0] ^ row.back());

		for (auto a : newRow) {
			std::cout << a << " ";
		}
		std::cout << std::endl;

		rows.push_back(newRow);
		row = newRow;
	}

	std::vector<int> out;
	if (m > n) {
		out = rows[m % n + 1];
	} else {
		out = rows[m];
	}

	for (auto a : out) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	return 0;
}
