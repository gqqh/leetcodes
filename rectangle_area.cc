#include <iostream>
using namespace std;
/*
 *矩形覆盖面积,两个面积和(s_total)减去相交的面积(s_join)
 * s_join = [max(A,E), max(B,F)], [min(C,G), min(D,H)]
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A > C || B > D || E > G || F > H)
          return 0;
        int s_total = (D-B)*(C-A) + (G-E)*(H-F);
        int A1 = max(A, E);
        int B1 = max(B, F);
        int C1 = min(C, G);
        int D1 = min(D, H);
        int s_join = 0;
        if(A1 < C1 && B1 < D1)
            s_join = (D1-B1)*(C1-A1);

        return (s_total - s_join);
    }
};

int main(){
  Solution test;
  cout << test.computeArea(-2, -2, 2, 2, 3, 3, 4, 4) << endl;
  return 0;
}
