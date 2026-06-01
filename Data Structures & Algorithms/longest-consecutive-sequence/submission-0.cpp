class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {

        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {

        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int getmaxsize(int n)
    {
        int maxi = 0;

        for (int i=0; i<n; i++)
        {
            maxi = max(maxi, size[i]);
        }

        return maxi;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (int x : st) {
            if (!st.count(x - 1)) { 
                int len = 1;
                int cur = x;

                while (st.count(cur + 1)) {
                    cur++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};
