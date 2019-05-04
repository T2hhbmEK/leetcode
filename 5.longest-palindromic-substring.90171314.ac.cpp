/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring
 *
 * Medium (25.10%)
 * Total Accepted:    198706
 * Total Submissions: 791614
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * Example:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()==0) return s;
        string t;
        for (char c:s) {
            t+='#';
            t+=c;
        }
        t.push_back('#');
        int c = 0;
        vector<int> r;
        int imax=0;
        r.push_back(0);
        for (int i=1;i<t.size();i++) {
            r.push_back(0);
            if (2*c-i>=0 && i+r[2*c-i] < c+r[c]) {
                r[i]=r[2*c-i];
            } else {
                c=i;
                r[i]=c+r[c]-i>0? c+r[c]-i:0;
                for(int j=i+1;j<t.size()&&2*i-j>=0&&t[j]==t[2*i-j];j++){
                    r[i]++;
                }
            }
            if (r[i]>r[imax]) {
                imax=i;
            }
        }
        return s.substr((imax-r[imax])/2,r[imax]);
        //return t.substr(imax-r[imax],2*r[imax]+1);
        //string rr;
        //for(int i:r){rr+=to_string(i);}
        //return rr;
    }
};
