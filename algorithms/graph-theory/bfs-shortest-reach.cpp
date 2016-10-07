#include <iostream>
#include <queue>
#include <vector>

#define DIST 6

int main() {

	int q; // number of queryies
	int n; // number of nodes
	int m; // number of edges

	std::cin >> q;

	for (int i = 0; i < q; i++) {
		std::cin >> n >> m;

		std::vector<std::vector<int> > am;
		std::vector<int> v;
		am.insert(am.begin(), n, v);

		for (int j = 0; j < m; j++) {
			int a, b;
			std::cin >> a >> b;
			am[a - 1].push_back(b - 1);
			am[b - 1].push_back(a - 1);
		}

		int s; // starting node
		std::cin >> s;

		std::vector<int> dist;
		dist.insert(dist.begin(), n, -1);

		int d = 0;

		std::queue<std::pair<int, int> > q;
		q.push(std::make_pair(s - 1, 0));

		while (!q.empty()) {
			std::pair<int, int> p = q.front();
			q.pop();

			int node = p.first;
			int d = p.second;

			if (dist[node] != -1) continue;

			dist[node] = d;

			for (std::vector<int>::iterator it = am[node].begin(); 
					it != am[node].end(); it++) {
				q.push(std::make_pair(*it, d + DIST));
			}
		}

		for (int j = 0; j < n; j++) {
			if (dist[j] == 0) continue;
			std::cout << dist[j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
