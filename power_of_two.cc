#include <iostream>

using namespace std;
/*
 * Given an integer, write a function to determine if it is a power of two. */
class Solution {
public :
	bool isPowerOfTwo(int n){
		if(n <= 0)
			return false;
		unsigned int count = 0;
		for(int i = 0; i < sizeof(int)*8; i++){
			count += n & 0x1;
			n >>= 1;
		}
		
		return (count == 1 ? true : false);
	}
};

int main()
{
	Solution test;
	for(int i = 0; i <= 1024; ++i)
		cout<< i <<"\t" << test.isPowerOfTwo(i) << endl;
	return 0;
}
