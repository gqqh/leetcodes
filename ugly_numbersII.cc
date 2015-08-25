//把只包含因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做是第一个丑数。
// 求按从小到大的顺序的第N个丑数。

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

//令第一个丑数为max = 1，因为下一个丑数一定是前某一个丑数×2或者×3或者×5所得，
//使用三个数last2，last3，last5，（均初始化为1，这三个数表示last2*2 > max，
//last3*3 > max, last5*5 > max）,这三个数表示推荐丑数的起始位置，
//每推荐一个丑数，则向后移动一个数
class Solution {
public:
    //使用类似找第i个素数的方法，就是标记法
    //因为丑数一定是由2,3,5各种乘得到的
    //所以使用last2, last3, last5记录在这个丑数之前，2,3,5的因子在哪儿
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;

        vector<int> ugly(n, 0);
        ugly[0] = 1; //1是第一个丑数
        int last2 = 0, last3 = 0, last5 = 0;

        int count = 1;
        while(count < n){
            //从last2*3，last3*3，last5*5这三个丑数中，选择一个最小的就是下一个丑数
            int next_ugly = min_u(ugly[last2]*2, ugly[last3]*3, ugly[last5]*5);
            ugly[count] = next_ugly;

            //更新last2，last3，last5,循环不变式是i * ugly[lasti] <= next_ugly
            while(ugly[last2]*2 <= ugly[count]) last2++;
            while(ugly[last3]*3 <= ugly[count]) last3++;
            while(ugly[last5]*5 <= ugly[count]) last5++;
            //i * [lasti] > next_ugly

            count++;
        }

        return ugly[count-1];

    }
private:
    int min_u(int a, int b, int c){
        a = a < b ? a : b;
        return (a < c ? a : c);
    }
};

int main(int argc, char ** argv)
{
	int n = 10;
	if(argc == 2)
		n = atoi(argv[1]);
	Solution test;
	cout << n<<"|"<<test.nthUglyNumber(n) << endl;
	return 0;
}
