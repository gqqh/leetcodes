//在一个string中找一个最长的回文子串

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
	/*
	//蛮力算法，两重循环，每次判断str[i,,...,j]是否是回文，i>=0, j < n, i<j;
	//时间复杂度O(n^3),空间复杂度为O(1) TLE
	string longestPalindrome(string s) {
		int max_len = 1;
		int pos = 0;
		int len = s.size();

		for(int i = 0; i < len - max_len; i++){
			for(int j = len-i; j > max_len; j--){
				//这一部分可以使用空间换时间的方法，使用一个二维数组表，
				//表示substr(i, j)是否是一个回文
				//if(s[i] == s[j] && table[i+1, j-1] == 1)
				if(is_palindrome(s.substr(i, j))){
					max_len = j;
					pos = i;
					break;
				}
			}
		}

		return s.substr(pos, max_len);
	}
private:
	bool is_palindrome(string str){
		int e = str.size() - 1;
		int b = 0;
		bool flag = true;
		while(b < e){
			if(str[b] != str[e]){
				flag = false;
				break;
			}
			b++;
			e--;
		}

		return flag;
	}*/
/*
	//使用从中间往两边拓展，但是要分长度为奇数和偶数两种情况，
	// 可以借鉴manacher算法的预处理方式，将串的长度强行改成奇数得到串T，
	// len(T)=2*len+3;前后各加一个哨岗('^'和'$')。同时使用一个数组P表示T中
	// 以某个字符为中心得到的回文的长度，最后求出最大的长度m及其下标p，就是回文最大长度，
	// 回文在T中的起始位置为(p-m),在原串中的起始位置为(p-m-1)/2即返回strsub((p-m-1)/2, m)
	//时间复杂度也是O(n^2)
	string longestPalindrome(string s) {
		string ret;
		if(s.empty()) return ret;
		string r = pre_process(s);
		cout<<"s:"<<s<<endl;
		cout<<"r:"<<r<<endl;
		int len = r.size();
		vector<int> table(len, 0);

		int p = 0, max = 0;
		for(int i = 1; i < len -1; i++){
			int k = 1;
			while(r[i-k] == r[i+k]) k++;
			table[i] = k-1;
			if(k-1 > max){
				max = k-1;
				p = i;
			}
		}
		for(int i = 0; i < len; i++)cout<<i<<"|"<<r[i]<<"|"<<table[i]<<endl;
		cout<<"p : "<<p<<", max :" << max<<endl;
		return s.substr((p-max-1)/2, max);
	}
private:
	string pre_process(string s){
		int len = s.size();
		string ret = "^";
		for(int i = 0; i < len; i++){
			ret.push_back('#');
			ret.push_back(s[i]);
		}
		ret += "#$";
		return ret;
	}
*/
//参考[http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html]
//manacher算法，对字符串s预处理，将串的长度强行改成奇数得到串T，
// len(T)=2*len+3;s中每个字符左右都加一个'#'，并且在T前后各加一个哨岗('^'和'$')。
// 同时使用一个数组P表示T中以某个字符为中心得到的回文的长度，
// 最后求出最大的长度m及其下标p，就是回文最大长度，回文在T中的起始位置为(p-m),
// 在原串中的起始位置为(p-m-1)/2即返回strsub((p-m-1)/2, m)
//该算法最主要就是求数组P的过程很经典，与上述中心展开算法的区别就在于就P数组。
//思想就是利用T中字符具有一定的对称性，每次计算p[id]时，因为id左边的所有P都
// 求出来了，所以有假设，p[i]=m，则有在T[i,i+1,...,i+m]这一段是
// 跟T[i-m,...,i-1,i]这一段相同的，所以对于j属于[i+1, ..., i+m]这一段都可以
// 直接赋值p[j] = p[j'],j'为j关于i的对称点j'属于[i-m,...,i-1],j'=i*2-j
// 然后如果j+p[j]>=i+p[i]也就意味着，中心点为j的这个点，它的左右对称的点中右边
// 那一个不在p[i]的范围内了，所以需要比较T[i-p[i]-1]与T[i+p[i]+1]如果相等，
// 则p[i]要+1，否则不用+1
//时间复杂度也是O(n)，空间复杂度也是O(n)
string longestPalindrome(string s) {
	string ret;
	if(s.empty()) return ret;
	string t = pre_process(s);
	cout<<"s:"<<s<<endl;
	cout<<"t:"<<t<<endl;
	int len = t.size();
	vector<int> p(len, 0);

	int c = 0, r = 0;
	//C表示当前处理的中心，R表示前面的某个P[]最右包含到哪了
	//求第i个字符P[i]，此时前面i-1个都处理完了
	for(int i = 1; i < len -1; i++){
		int i_l = c*2 - i;
		if(r > i){
			p[i] = min(p[i_l], r-i);
		}
		//扩展P[i]
		while(t[i+p[i]+1] == t[i-p[i]-1]) p[i]++;

		if(i+p[i] > r){
			c = i;
			r = i+p[i];
		}
	}
	for(int i = 0; i < len; i++)cout<<i<<"|"<<t[i]<<"|"<<p[i]<<endl;
	int p_max = 0, max = 0;
	for(int i = 0; i < len; i++){
		if(p[i] > max){
			max = p[i];
			p_max = i;
		}
	}
	cout<<"p_max : "<<p_max<<", max :" << max<<endl;
	return s.substr((p_max-max-1)/2, max);
}
private:
string pre_process(string s){
	int len = s.size();
	//假设字符串中不会出现'^'和'$'
	string ret = "^";
	for(int i = 0; i < len; i++){
		ret.push_back('#');
		ret.push_back(s[i]);
	}
	ret += "#$";
	return ret;
}
};

int main(void)
{
	Solution test;
	// string s("acba");
	string s("mwwfjysbkebpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtchkqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxejtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgfttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdwsrfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvopxklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfszermqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosctttxvsbmqpnolfmapywtpfaotzmyjwnd");
	cout << test.longestPalindrome(s) << endl;

	return 0;
}
