#include <iostream>
#include <vector>

int main() {

	int n, m; // city dimensions
	int k; // number of train tracks

	std::cin >> n >> m >> k;

	std::vector<std::vector<std::pair<int, int> > > tracks;
	std::vector<std::pair<int, int> > v;
	tracks.insert(tracks.begin(), n, v);

	for (int i = 0; i < k; i++) {

		int r, c1, c2;
		std::cin >> r >> c1 >> c2;
		r--; c1--; c2--;

		std::pair<int, int> track = std::make_pair(c1, c2);
		std::cout << "track: " << track.first << " " << track.second << std::endl;

		// Binary search
		int left = 0, right = tracks[r].size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (tracks[r][left].first < track.first) {
				left = mid + 1;
			}
			else if (tracks[r][right].first > track.first) {
				right = mid - 1;
			}
			else {
				break;
			}
			
		}

		std::cout << ".............. " << std::endl;
		for (auto a : tracks[r]) {
			std::cout << a.first << " " << a.second << " | ";
		}
		std::cout << std::endl;
		std::cout << track.first << " " << track.second << " -> " << left << std::endl;
		std::cout << ".............. " << std::endl;

		if (tracks[r].empty()) {
			tracks[r].push_back(track);
		}
		else if (track.first == tracks[r][left].first) {
std::cout << "    | " << tracks[r][left].first << " " << tracks[r][left].second
	<< " <> " << track.first << " " << track.second << "   -> " << left<< std::endl;

			if (track.second > tracks[r][left].second) {
				tracks[r][left].second = track.second;
			}
		}
		else if (track.first <= tracks[r][left - 1].second + 1) {
			if (track.second > tracks[r][left - 1].second) {
				tracks[r][left - 1].second = track.second;
			}
		}
		else {
			tracks[r].insert(tracks[r].begin() + left, track);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < tracks[i].size(); j++) {
			std::cout << "(" << tracks[i][j].first << ", " << tracks[i][j].second
				<< ") - ";
		}
		std::cout << std::endl;
	}

	return 0;
}
