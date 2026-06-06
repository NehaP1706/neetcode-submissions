class Solution {
public:
    int jump(vector<int>& nums) {
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // pq.push({0, nums[0], 0});

        // while(!pq.empty())
        // {
        //     auto top = pq.top();
        //     int jumps = top[0];
        //     int num = top[1];
        //     int i = top[2];

        //     pq.pop();

        //     if (i == nums.size() - 1)
        //     {
        //         return jumps;
        //     }

        //     for (int j = 1; j <= num; j++)
        //     {
        //         if (i + j < nums.size())
        //         {
        //             vector<int> sigh;
        //             sigh.push_back(jumps + 1);
        //             sigh.push_back(nums[i+j]);
        //             sigh.push_back(i+j);
        //             pq.push(sigh);
        //         }
        //     } 
        // }

        // return nums.size();

        int jumps = 0;
        int end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (i == end)
            {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};
