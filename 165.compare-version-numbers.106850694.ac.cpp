/*
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (20.57%)
 * Total Accepted:    94.3K
 * Total Submissions: 458.5K
 * Testcase Example:  '"1"\n"0"'
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise
 * return 0.
 * 
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 * 
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1.size() <= 0 && version2.size() <= 0) {
            return 0;
        }
        int v1 = parseL1(version1), v2 = parseL1(version2);
        if (v1 > v2) {
            return 1;
        } else if (v1 < v2) {
            return -1;
        } else {
            return compareVersion(version1, version2);
        }
    }
    
    int parseL1(string& version) {
        if (version.size() <= 0) {
            return 0;
        }
        auto p = version.begin();
        while(*p != '.' && p != version.end()) {
            p++;
        }
        int r = stoi(version.substr(0,p-version.begin()));
        if (p == version.end()) {
            version = version.substr(p-version.begin(),0);
        } else {
            version = version.substr(p+1-version.begin());
        }
        return r;
    }
};
