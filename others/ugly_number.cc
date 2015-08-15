/*把只包含因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含因子7。
 * 习惯上我们把1当做是第一个丑数。
 * 求按从小到大的顺序的第N个丑数。
 **/
/*从1依次判断一个数是不是丑数。
 */
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
/*
//1是丑数，从2开始判断每一个数是否是丑数，判断方法就是，先一直除以2，在一直除以
//3，再一直除以5，直到不含2,3,5这三个因数，如果为1，则返回1，否则返回0
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if(index < 0) return 0;
		else if(index == 1) return 1;
		int i = 2; //从2开始判断
		for(int count = 1; count < index; i++){ //输出index个丑数
			if(is_ugly(i)) count++;
		}
		return i-1;
	}
	//time ./a.out 1500 == 0.002s
private:
	bool is_ugly(int i){
		//i > 1
		while(i % 2 == 0) i >>= 1;
		while(i % 3 == 0) i /= 3;
		while(i % 5 == 0) i /= 5;
		return (i == 1 ? true : false);
	}
};
*/
//令第一个丑数为max = 1，因为下一个丑数一定是前某一个丑数×2或者×3或者×5所得，
//使用三个数last2，last3，last5，（均初始化为1，这三个数表示last2*2 > max，
//last3*3 > max, last5*5 > max）,这三个数表示推荐丑数的起始位置，
//每推荐一个丑数，则向后移动一个数
class Solution {
public:

	int GetUglyNumber_Solution(int index) {
		if(index < 0) return 0;

		vector<int> ret(index, 0); //保存丑数
		//三个推荐位置，其中last2表示[(last2-1)*2 <= max < last2*2],余同
		int last2 = 0;
		int last3 = 0;
		int last5 = 0;

		ret[0] = 1;
		int count = 1;
		// cout<<count<<"|"<<last2<<"|"<<last3<<"|"<<last5<<"|"<<1<<endl;
		//last_i*i <= max < last_i * i,
		while(count < index){
			int min = min_u(ret[last2] * 2, ret[last3] * 3, ret[last5] * 5);
			ret[count] = min;
			while(ret[last2]*2 <= ret[count]) last2++;
			while(ret[last3]*3 <= ret[count]) last3++;
			while(ret[last5]*5 <= ret[count]) last5++;
			count ++;
		// cout<<count<<"|"<<last2<<"|"<<last3<<"|"<<last5<<"|"<<min<<endl;
		}
//time ./a.out 1500 == 16.415s
		return ret[count-1];
	}
private:
	//推荐一个最小的unly值
	int min_u(int a, int b, int c){
		a = a < b ? a : b;
		if(a < c)
		 	return a;
		return c;
	}
};

int main(int argc, char ** argv)
{
	int index = 10;
	if(argc == 2)
		index = atoi(argv[1]);
	Solution test;
	cout << test.GetUglyNumber_Solution(index) << endl;
	return 0;
}
