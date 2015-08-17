//给定一个非负的整数n，返回其各位数字之和，重复此过程，直到只有一位数
//n=38-->11-->2 return 2;

class Solution {
public:
    int addDigits(int num) {
        int ret = 0;
        while(num > 9){
            ret = 0;
            while(num > 0){
                ret += num % 10;
                num /= 10;
            }
            num = ret;
        }
        return num;
    }
};
