class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return true;

        for (int x : nums)
        {
            if (x == 1)
                return false;
        }

        DisjointSet ds(n);

        unordered_map<int, int> owner;

        for (int i = 0; i < n; i++)
        {
            int x = nums[i];

            vector<int> factors;

            for (int p = 2; p * p <= x; p++)
            {
                if (x % p == 0)
                {
                    factors.push_back(p);

                    while (x % p == 0)
                        x /= p;
                }
            }

            if (x > 1)
                factors.push_back(x);

            for (int p : factors)
            {
                if (owner.find(p) == owner.end())
                {
                    owner[p] = i;
                }
                else
                {
                    ds.unionBySize(i, owner[p]);
                }
            }
        }

        int root = ds.findUPar(0);

        for (int i = 1; i < n; i++)
        {
            if (ds.findUPar(i) != root)
                return false;
        }

        return true;
    }
};