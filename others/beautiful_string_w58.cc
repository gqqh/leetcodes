//http://hihocoder.com/contest/hiho58/problem/1
//http://hihocoder.com/discuss/question/2083
/*
 *给定一个字符串S，判断S中是否有一个子串s1，满足s1为“...a..ab..bc..c...”，abc为
 *  连续的三个字母，且其中abc的个数相等。
 */
 #include <iostream>
 #include <vector>
 #include <string>

 using namespace std;

 int main(int argc, char const *argv[]) {
     int N;
     cin >> N;
     vector<string> ret;
     for(int t = 0; t < N; ++t){
         int n;
         string str;
         cin >> n;
         cin >> str;
         if(n < 3){
              ret.push_back("NO");
              continue;
         }
         vector<char> chrs(n, 0);
         vector<int> nchrs(n, 0);

         int j = 0;
         for(int i = 0; i < n; i++){
             int k = 1;
             chrs[j] = str[i];
             while(i < n-1 && str[i] == str[i+1]){
                 ++k;
                 ++i;
             }
             nchrs[j] = k;
             ++j;
         }
     //     for(int i = 0; i < j; ++i){
     //      cout<< chrs[i]<<":"<<nchrs[i] << endl;
     //      }
        int i = 0;
        if(j < 2){
             ret.push_back("NO");
             continue;
        }
        for(; i < j - 2; ++i){
            if(chrs[i] + 1 == chrs[i+1] && chrs[i+1] + 1 == chrs[i+2]
                && nchrs[i] >= nchrs[i+1] && nchrs[i+2] >= nchrs[i+1]){
                     ret.push_back("YES");
                     break;
                }
        }
        if(i == j - 2)
          ret.push_back("NO");
     }

     for(int i = 0; i < N; i++)
          cout<<ret[i]<<endl;

     return 0;
 }
