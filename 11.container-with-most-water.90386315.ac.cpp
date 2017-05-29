/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water
 *
 * Medium (36.32%)
 * Total Accepted:    129573
 * Total Submissions: 356719
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& a) {
        int r = 0;
        int i = 0;
        int j = a.size()-1;
        while(i<j) {
            int h = a[i] > a[j] ? a[j]:a[i];
            int w = (j-i)*h;
            r = w>r? w:r;
            while(a[i] <= h && i<j) i++;
            while(a[j] <= h && i<j) j--;
        }
        return r;
    }
};
