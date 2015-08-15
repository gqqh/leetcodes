//int sqrt(int t)
//求一个整数的平方根，且平方根也是整数，直接用二分搜索吧。。。
//也可以用牛顿迭代法，求任何一个数的开m方根，详见sqrtm.cc

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) return 0;
        else if(x < 4) return 1;
        int b = 0, e = x / 2 + 1;
        //b < e, b*b <= x < e*e
        while(b + 1 != e){
            int m = (b+e)/2;
            if(m >= 46341){ //46341 == sqrt(2**31)
                e = m;
                continue;
            }
            unsigned long long t = m*m;

            if(t == x)
                return m;
            else if(t < x)
                b = m;
            else
                e = m;
        }

        return b;
    }
};
