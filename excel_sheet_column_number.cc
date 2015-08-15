//把A->1,B->2,...,Z->26,AA->27,AB->28....
//字符串从前往后遍历，依次累加

class Solution {
public:
	/*效率略低
    int titleToNumber(string s) {
		int len = s.size();
		int ret = 0;

		for(int i = 0; i < len; i++){
			ret *= 26;
			ret += s[i] - 'A' + 1;
		}

		return ret;
    }*/
	int titleToNumber(string s) {
		int ret = 0;

		for(string::iterator sb = s.begin(), se = s.end(); sb != se; sb++){
			ret *= 26;
			ret += *sb - 'A' + 1;
		}

		return ret;
    }
};
