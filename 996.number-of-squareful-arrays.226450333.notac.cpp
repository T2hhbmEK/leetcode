/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 *
 * https://leetcode.com/problems/number-of-squareful-arrays/description/
 *
 * algorithms
 * Hard (47.98%)
 * Total Accepted:    4.9K
 * Total Submissions: 10.2K
 * Testcase Example:  '[1,17,8]'
 *
 * Given an array A of non-negative integers, the array is squareful if for
 * every pair of adjacent elements, their sum is a perfect square.
 * 
 * Return the number of permutations of A that are squareful.  Two permutations
 * A1 and A2 differ if and only if there is some index i such that A1[i] !=
 * A2[i].
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,17,8]
 * Output: 2
 * Explanation: 
 * [1,8,17] and [17,8,1] are the valid permutations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2]
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 12
 * 0 <= A[i] <= 1e9
 * 
 */
class Permutation {
public:
    Permutation(vector<int> &A): A_(A), i_(0){
        if (A_.size() > 1) {
            vector<int> B = vector<int>(A_.begin()+1, A_.end());
            per_ = new Permutation(B);
        }
    }
    ~Permutation() {
        if (per_) {
            delete per_;
        }
    }
    vector<int> next() {
        vector<int> G;
        if (A_.size() == 1) {
            G.push_back(A_[0]);
            i_++;
        } else {
            G.push_back(A_[i_]);
            vector<int> B = per_->next();
            G.insert(G.end(), B.begin(), B.end());
            if (per_->isDone()) {
                int i = i_;
                while(i_ < A_.size() && A_[i_] == A_[i]) {
                    i_++;
                }
                delete per_;
                per_ = nullptr;
                if (i_ < A_.size()) {
                    vector<int> B;
                    B.insert(B.end(), A_.begin(), A_.begin()+i_);
                    B.insert(B.end(), A_.begin()+i_+1, A_.end());
                    per_ = new Permutation(B);
                }
            }
        }
        return G;
    }
    bool isDone() {
        return i_ >= A_.size();
    }
    vector<int> A_;
    int i_;
    Permutation* per_ = nullptr;
};

class Solution {
public:
    bool isSquareful(int a) {
        int a2 = sqrt(a);
        // cout << a << " " << a2 << " " << (a == a2*a2) << endl;
        return a == a2*a2;
    }
    bool isSquareful(vector<int>& A) {
        for (int i=1; i < A.size(); ++i) {
            if (!isSquareful(A[i-1] + A[i])) {
                return false;
            }
        }
        return true;
    }
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        Permutation P(A);
        int r = 0;
        while (!P.isDone()) {
            vector<int> p = P.next();
            // for (const auto& x: p) {
            //     cout << x << " ";
            // }
            if (isSquareful(p)) {
                // cout << "ok";
                r++;
            }
            // cout << endl;
        }
        return r;
    }
};
