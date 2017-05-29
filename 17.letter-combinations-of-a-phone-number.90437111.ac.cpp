/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number
 *
 * Medium (33.77%)
 * Total Accepted:    145235
 * Total Submissions: 430059
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 * 
 * 
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> r;
        if (digits.size() == 0) return r;
        int sum = 1;
        for (int i = 0; i < digits.size(); i++){
            vector<char> c = letter(digits[i]);
            sum *= c.size();
        }
        for (int i = 0; i < sum; i++){
            string s;
            int tmpi = i;
            for (int j = (int)digits.size()-1; j >= 0; j--) {
                vector<char> chars = letter(digits[j]);
                int size = (int)chars.size();
                s = chars[tmpi%size]+s;
                tmpi /= size;
            }
            r.push_back(s);
        }
        return r;
    }
    
    vector<char> letter(char c) {
        if (c == '1' || c == '0') return {};
        if (c == '7') return {'p','q','r','s'};
        if (c == '8') return {'t','u','v'};
        if (c == '9') return {'w','x','y','z'};
        return {
            static_cast<char>('a'+(c-'2')*3),
            static_cast<char>('a'+(c-'2')*3+1),
            static_cast<char>('a'+(c-'2')*3+2)
        };
    }
};
