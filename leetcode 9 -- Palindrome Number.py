class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        if x < 0:
            return False
        if x == 0:
            return True
        x = str(x)
        mid = len(x)/2
        if len(x)%2 == 0:
            return x[:mid][::-1] == x[mid:]
        else:
            return x[:mid][::-1] == x[mid+1:]
