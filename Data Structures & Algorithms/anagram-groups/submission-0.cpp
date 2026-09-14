class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const string& s : strs) {
            string key(26, '\0');
            for (char c : s) {
                key[c - 'a']++;
            }
            map[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(map.size());
        
        for (auto& [_, group] : map) {
            result.push_back(std::move(group));
        }

        return result;
    }
};
