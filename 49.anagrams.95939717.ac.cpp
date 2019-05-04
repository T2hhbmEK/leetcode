/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/anagrams
 *
 * Medium (33.49%)
 * Total Accepted:    130284
 * Total Submissions: 388977
 * Testcase Example:  '[""]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> results;
        for (int i = 0; i < strs.size(); i++) {
        // {   int i = 0;
            string str = strs[i];
            string key(str);
            sort(key.begin(), key.end());
            auto search = groups.find(key);
            if (search != groups.end()) {
                search->second.push_back(str);
            } else {
                vector<string> group;
                group.push_back(str);
                groups.insert({key, group});
            }
        }
        for (auto pair : groups) {
            results.push_back(pair.second);
        }
        return results;
    }
};
