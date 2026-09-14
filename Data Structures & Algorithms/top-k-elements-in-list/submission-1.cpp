class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;

        for (int num : nums) {
            counts[num]++;
        }

        vector<vector<int>> buckets(n + 1);
        for (const auto& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        vector<int> result;
        result.reserve(k);

        for (int freq = n; freq >= 1; freq--) {
            for (int num : buckets[freq]) {
                result.push_back(num);
                
                if (result.size() == k) return result;
            }
        }
    
    return result;
    }
};
