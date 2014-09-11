#include <vector>
#include <unordered_map>
using namespace std;
#pragma once



struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
	typedef unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> Nodes;

	UndirectedGraphNode *cloneGraph(Nodes &nodes, UndirectedGraphNode *node)
	{
		if (!node) return NULL;

		auto it = nodes.find(node);
		if (it != nodes.end()) {
			clone = it->second;
		}
		else
		{
			clone = new UndirectedGraphNode(node->label);
			nodes[node] = clone;
		}

		for (UndirectedGraphNode *n : node->neighbors) {
			auto it = std::find(n->neighbors.begin(), n->neighbors.end(), node);
			n->neighbors.erase(it);
		}

		UndirectedGraphNode *clone;
		

		for (UndirectedGraphNode *n : node->neighbors) {
			clone->neighbors.push_back(cloneGraph(nodes, n));
		}

		for (UndirectedGraphNode *n : node->neighbors) {
			n->neighbors.push_back(node);
		}

		return clone;
	}

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		Nodes nodes;
		return cloneGraph(nodes, node);
	}

	void connect(UndirectedGraphNode *a, UndirectedGraphNode *b) {
		a->neighbors.push_back(b);
		b->neighbors.push_back(a);
	}

	void test() {
		UndirectedGraphNode *n0 = new UndirectedGraphNode(-1);
		UndirectedGraphNode *n1 = new UndirectedGraphNode(1);
		connect(n0, n1);
		connect(n1, n1);

		UndirectedGraphNode *result = cloneGraph(n0);
		cout << "done";
	}
};