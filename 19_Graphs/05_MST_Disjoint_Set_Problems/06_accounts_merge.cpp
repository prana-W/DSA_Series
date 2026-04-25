#include <bits/stdc++.h>
using namespace std;
 
//? Pg: 159

class DSU {

    vector<int>size, parent;

    public:
        
        DSU(int n) {
            for (int i = 0; i < n+1; i++) {
                parent.push_back(i);
                size.push_back(1);
            }
        }

        int findUPar(int n) {
            if (parent[n] == n) return n;

            return parent[n] = findUPar(parent[n]);
        }

        void unionBySize(int u, int v) {
            int upU = findUPar(u);
            int upV = findUPar(v);

            if(upU == upV) return;

            if(size[upU] < size[upV]) {
                parent[upU] = upV;
                size[upV] += size[upU];
            }
            else {
                parent[upV] = upU;
                size[upU] += size[upV];
            }
        }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

    int n = accounts.size();
    unordered_map<string, int>mapMailNode;
    DSU ds(n);

    // Map mails with the index (node)
    for (int i = 0; i < n; i++) {

        // Start with index to tackle the mails only
        for (int j = 1; j < accounts[i].size(); j++) {
            string mail = accounts[i][j];

            if (mapMailNode.find(mail) == mapMailNode.end()) {
                mapMailNode[mail] = i;
            }
            else {
                // Map the current node (index) with the ultimate parent node
                ds.unionBySize(mapMailNode[mail], i);
            }

        }
    }

    // Add all the mails to their ultimate parent node
    vector<vector<string>>mails(n);

    for (auto elem : mapMailNode) {
        string mail = elem.first;
        int node = elem.second;

        int ultimateParent = ds.findUPar(node);

        mails[ultimateParent].push_back(mail);
    }

    // Add name and sorted mails in final answer

    vector<vector<string>>ans;

    for (int i = 0; i < n; i++) {

        // If node has no mail
        if(mails[i].size() == 0) continue;

        // Sort the mails
        sort(mails[i].begin(), mails[i].end());

        vector<string>temp;

        // Add name of the account holder
        temp.push_back(accounts[i][0]);

        // Add all the sorted emails
        for (auto elem : mails[i]) {
            temp.push_back(elem);
        }

        // Finally add in the answer
        ans.push_back(temp);            
    }

    return ans;
    
}