class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        if x < 0:
            t = str(x)
            s = t[:0:-1]
            ret = int(s)
            if ret > 2**31 or ret < -2**31-1:
                return 0
            else:
                return -ret
        elif x > 0:
            t = str(x)
            s = t[::-1]
            ret = int(s)
            if ret > 2**31 or ret < -2**31-1:
                return 0
            else:
                return ret
        else:
            return 0
