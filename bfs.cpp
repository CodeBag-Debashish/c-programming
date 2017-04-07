#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adjLst,int start,int x) {
	// create a boolean array having size equal to the no of vertices
	// intialize all with false
	vector<bool> visited(adjLst.size(),false);
	// create a Queue to store nodes
	queue<int> Q;
	visited[start] = true;
	// push the start node
	Q.push(start);
	while(!Q.empty()) {
		int s = Q.top();
		Q.pop();

		// now explore adj of s and mark the visited
		if(s != e) {
			for(auto e:adjLst[s]) {
				if(!visited[e]) {
					visited[e] = true;
					Q.push(e);
				}
			}
		}
	}
}



int main() {
	int n,T,x;
	cin >> T;
	// start
	for(int qq=1;qq<=T;qq++) {
		cin >> n;
		vector<vector<int>> adjLst(n);
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cin >> x;
				if(x == 1) {
					adjLst[i].push_back(j);
				}
			}
		}

		// check reachable nodes first

		std::vector<bool> visited(adjLst.size(),false);
		queue<int> Q;
		visited[start] = true;
		Q.push(start);
		while(!Q.empty()) {
			int s = Q.top();
			Q.pop();
			for(auto e:adjLst[s]) {
				if(!visited[e]) {
					visited[e] = true;
					Q.push(e);
				}
			}
		}
		vector<int> vtx;
		for(int i=0;i<n;i++) {
			if(visited[i]) vtx.push_back(i);
		}
		for(int v=0;v<n;v++) {
			// if it is reachable from start then only
			if(visited[v]) {
				bfs(adjLst,start,v);
			}
		}
	
	} // end

}