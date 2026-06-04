class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int s : stones)
        {
            pq.push(s);
        }

        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();

            if (!pq.empty())
            {
                int y = pq.top();
                pq.pop();

                if (x == y)
                {
                    continue;
                }
                else
                {
                    pq.push(x - y);
                }
            }
            else
            {
                return x;
            }
        }

        return pq.size();
    }
};
