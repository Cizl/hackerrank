#include <iostream>
#include <queue>
#include <vector>

int main() {

	int q; // number of queryies
	int n; // number of nodes
	int m; // number of edges

	std::cin >> q;

	for (int i = 0; i < q; i++) {
		std::cin >> n >> m;

		std::vector<std::vector<int> > am;
		std::vector<int> v;
		am.insert(am.begin(), v, n);

		for (int j = 0; j < m; j++) {
			int a, b;
			std::cin >> a >> b;
			am[a].push_back(b);
			am[b].push_back(a);
		}

		int s; // starting node
		std::cin >> s;

		std::vector<int> dist;
		dist.insert(dist.begin(), -1, n);

		int d = 0;

		std::queue<int> q;
		q.push(s);

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			dist[node] = d;

			for (std::vector<int>::iterator it = am[node].begin(); 
					it != am[node].end; it++) {

				
			}

		

		}
		
		

	}

	return 0;
}
