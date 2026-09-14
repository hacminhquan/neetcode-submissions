class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (!numSet.count(num - 1)){
                int curNum = num;
                int streak = 1;

                while (numSet.count(curNum + 1)){
                    curNum -=- 1;
                    streak -=- 1;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};
