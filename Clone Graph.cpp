/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        UndirectedGraphNode * newnode = new UndirectedGraphNode(node->label);
        map[node] = newnode;
        while (!q.empty()) {
            UndirectedGraphNode * cur = q.front();
            q.pop();
            for (int i = 0; i < cur->neighbors.size(); i++) {
                UndirectedGraphNode *p = cur->neighbors[i];
                if (map.find(p) == map.end()) {
                    q.push(p);
                    UndirectedGraphNode *newp = new UndirectedGraphNode(p->label);
                    map[p] = newp;
                }
                map[cur]->neighbors.push_back(map[p]);
            }
        }
        return newnode;
    }
};