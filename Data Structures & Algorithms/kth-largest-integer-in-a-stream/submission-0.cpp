class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kay;

    KthLargest(int k, vector<int>& nums) {
        for (int n : nums)
        {
            pq.push(n);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        kay = k;
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > kay)
        {
            pq.pop();
        }

        return pq.top();
    }
};
