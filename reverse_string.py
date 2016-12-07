#344 reverse string
#https://leetcode.com/problems/reverse-string/

class Solution(object):
    def reverseString(self, s):
        """
        :type s:    str
        :rtype:     str
        """
        return s[::-1]

if __name__ == "__main__":
    test = Solution()
    s = "hello"
    print test.reverseString(s)
