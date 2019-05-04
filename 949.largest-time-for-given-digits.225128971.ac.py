#
# @lc app=leetcode id=949 lang=python3
#
# [949] Largest Time for Given Digits
#
# https://leetcode.com/problems/largest-time-for-given-digits/description/
#
# algorithms
# Easy (33.76%)
# Total Accepted:    8K
# Total Submissions: 23.7K
# Testcase Example:  '[1,2,3,4]'
#
# Given an array of 4 digits, return the largest 24 hour time that can be
# made.
# 
# The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from
# 00:00, a time is larger if more time has elapsed since midnight.
# 
# Return the answer as a string of length 5.  If no valid time can be made,
# return an empty string.
# 
# 
# 
# 
# Example 1:
# 
# 
# Input: [1,2,3,4]
# Output: "23:41"
# 
# 
# 
# Example 2:
# 
# 
# Input: [5,5,5,5]
# Output: ""
# 
# 
# 
# 
# Note:
# 
# 
# A.length == 4
# 0 <= A[i] <= 9
# 
# 
# 
#
from typing import Generator

def permutation(*L: List[int]) -> Generator[None, List[int], None]:
    if len(L) == 0:
        yield([])
        return
    cnt = set()
    for i, x in enumerate(L):
        if x in cnt:
            continue
        cnt.add(x)
        for tail in permutation(*L[:i], *L[i+1:]):
            yield [x] + tail


# P = permutation(*list(range(4)))
# P = list(P)

P = [[0, 1, 2, 3], [0, 1, 3, 2], [0, 2, 1, 3], [0, 2, 3, 1], [0, 3, 1, 2], [0, 3, 2, 1], [1, 0, 2, 3], [1, 0, 3, 2], [1, 2
, 0, 3], [1, 2, 3, 0], [1, 3, 0, 2], [1, 3, 2, 0], [2, 0, 1, 3], [2, 0, 3, 1], [2, 1, 0, 3], [2, 1, 3, 0], [2, 3, 0, 1
], [2, 3, 1, 0], [3, 0, 1, 2], [3, 0, 2, 1], [3, 1, 0, 2], [3, 1, 2, 0], [3, 2, 0, 1], [3, 2, 1, 0]]


# print (list(G))

class Solution:
    def to_time_str(self, A: List[int]) -> str:
        return "{}{}:{}{}".format(*A)

    def check_time(self, A: List[int]) -> bool:
        return A[0] * 10 + A[1] < 24 and A[2] * 10 + A[3] < 60

    def largestTimeFromDigits(self, A: List[int]) -> str:
        A = sorted(A, reverse=True)
        # for B in permutation(*A):
        for p in P:
            B = [A[i] for i in p]
            # print (B)
            if self.check_time(B):
                return self.to_time_str(B)
        return ""
