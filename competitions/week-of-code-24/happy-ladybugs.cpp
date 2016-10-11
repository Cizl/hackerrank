#include <iostream>
#include <string>
#include <map>

int main() {

	int g;
	std::cin >> g;


	while (g--) {
		std::map<char, int> colors;

		bool out = true;

		int n;
		std::cin >> n;

		char prev = 'x';
		while (n--) {
			char c;
			std::cin >> c;

			if (prev != c && colors[prev] < 2 && prev != 'x') {
				out = false;
			}

			prev = c;
			colors[c]++;
		}

		if (out) {
			std::cout << "YES" << std::endl;
			continue;
		} else {
			out = true;
		}

		if (colors['_'] == 0) {
			out = false;
		} else {
			for (auto a : colors) {
				if (a.first == '_') continue;
				if (a.second == 1) {
					out = false;
				}
			}
		}

		std::cout << (out ? "YES" : "NO") << std::endl;
	}

	return 0;
}
