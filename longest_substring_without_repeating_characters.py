#/usr/bin/env   python2
#-*- coding:utf8 -*-
#3 longest substring without repeating characters.
#https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        #使用一个字典记录上一个该字母的出现位置，初始值为-1
        #一个字母与上一个该字母之间的距离，最大值即最长子串
        length = 0
        last_end = -1
        last = {}
        for i,c in enumerate(s):
            tmp = i - last.get(c, last_end)
            last[c] = i
            
            length = tmp if tmp > length else length

        return length




if __name__ == "__main__":
    test = Solution()
    s = "abba"
    print test.lengthOfLongestSubstring(s)
