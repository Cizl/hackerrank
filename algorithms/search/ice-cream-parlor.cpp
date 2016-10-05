#include <iostream>
#include <map>
using namespace std;

int main() {

	int t; // number of trips to the parlor

	cin >> t;


	for (int i = 0; i < t; i++) {
		int n; // number of flavors
		int m; // total pool of money
		cin >> m >> n;
			
		map<int, int> map;

		int c[10000];

		for (int j = 0; j < n; j++) {
			cin >> c[j];
			map[c[j]] = j + 1;
		}

		int out1, out2;

		for (int j = 0; j < n; j++) {
			std::map<int, int>::iterator it;
			it = map.find(m - c[j]);

			if (it != map.end() && map[m - c[j]] != (j + 1)) {
				out1 = j + 1;
				out2 = map[m - c[j]];
			}
		}

		
		if (out2 < out1) {
			int tmp = out2;
			out2 = out1;
			out1 = tmp;
		}

		cout << out1 << " " << out2 << endl;
	}

	return 0;
}
