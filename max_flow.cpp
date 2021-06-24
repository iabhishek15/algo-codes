int const nax = 511;
vector<map<int,int>> Node(nax); 
int N, M;

int Max_Flow() {
	int max_flow = 0;
	int source = 1;
	int sink = N;
	for (int i = 0; i < M * M; ++i) {
		map<int,int> flow_dirn;
		vector<int> visit(N + 1);
		queue<int> q;
		q.push(source);
		int flow = 1e9 + 7;
		while ((int)q.size()) {
			int top = q.front();
			q.pop();
			visit[top] = 1;
			for (auto x : Node[top]) {
				if (x.second && !visit[x.first]) {
					flow = min(flow, x.second);
					q.push(x.first);
					flow_dirn[x.first] = top;
				}
			}
		}
		if (flow_dirn.count(sink) == 0) break;
		int curr = sink;
		while (flow_dirn[curr]) {
			int new_curr = flow_dirn[curr];
			Node[new_curr][curr] -= flow;
			Node[curr][new_curr] += flow;
			curr = new_curr;
		}
		max_flow += flow;
	}
	return max_flow;
}
