#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

long long int free(std::vector<std::pair<int, int>> &tracks) {

	std::sort(tracks.begin(), tracks.end());

	auto track = tracks.begin();

	int c1 = track->first, c2 = track->second;

	long long int out = 0;
	track++;

	while (track != tracks.end()) {
		if (track->first <= c2) {
			c2 = (c2 < track->second) ? track->second : c2;
		} else {
			out += (c2 - c1 + 1);
			c1 = track->first;
			c2 = track->second;
		}
		track++;
	}
	
	out += (c2 - c1 + 1);

	return out;
}

int main() {

	int n, m; // city dimensions
	int k; // number of train tracks

	std::cin >> n >> m >> k;

	std::map<int, std::vector<std::pair<int, int>>> tracks;

	for (int i = 0; i < k; i++) {
		
		int r, c1, c2;
		std::cin >> r >> c1 >> c2;
		tracks[r].push_back(std::make_pair(c1, c2));
	}

	long long int result = (long long)n * m;
	for (auto &it : tracks) {
		result -= free(it.second);
	}

	std::cout << result << std::endl;

	return 0;
}
