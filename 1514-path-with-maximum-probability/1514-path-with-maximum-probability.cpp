
    #define ipair pair<int, double>
	class Solution
	{
		public:
			double maxProbability(int n, vector<vector < int>> &e, vector< double > &su, int st, int end)
			{
				vector<ipair> adj[n];

				for (int i = 0; i < e.size(); i++)
				{
					int a = e[i][0], b = e[i][1];
					adj[a].push_back({ b, su[i] });
					adj[b].push_back({ a, su[i] });
				}

				priority_queue<ipair, vector < ipair>, greater < ipair>> pq;
				pq.push({ 1.0, st });
				vector<double> dist(n, 0);
				dist[st] = 1.0;
				while (!pq.empty())
				{
					int u = pq.top().second;
					pq.pop();

					for (auto x: adj[u])
					{
						if (dist[x.first] < dist[u] *x.second)
						{
							dist[x.first] = dist[u] *x.second;
							pq.push({ dist[x.first], x.first });
						}
					}
				}

				return dist[end];
			}
	};
