#include <stdio.h>
#include <stdlib.h>

/*用牛顿迭代法求解平方根,用切线与x轴的交点逐渐趋近f(x) = x^m - n与x轴的交点
 * Xn+1 = Xn - f(Xn)/f'(x)
 */
//x^m - n
double f(double x, double n, int m){
	double ret = 1.0;
	while(m-- > 0)
		ret *= x;
	return ret - n;
}
//f'(x) = m * x^m-1
double fd(double x, int m){
	double ret = 1.0 * m;
	while(--m > 0)
		ret *= x;
	return ret;
}
double sqrtm(double num, int m){
	if(num < 0.0000001)
		return 0;
	//x0的选取 num / m;
	double ret = num / m * 1.0;
	double x = ret - f(ret, num, m)/fd(ret, m);
	while(x-ret > 0.00000001 || ret - x > 0.00000001){
		ret = x;
		x = ret - f(ret, num, m) / fd(ret, m);
	}
	return ret;
}

int main(int argc, char ** argv)
{
	int n = 2 ;
	int m = 2;
	if(argc == 3){
		n = atoi(argv[1]);
		m = atoi(argv[2]);
	}
	if(m == 0 || n == 1){
		printf("1 over!\n");
		return 0;
	}
	printf("root of %d (%lf) = %lf\n", m, n * 1.0, sqrtm(n, m));
	return 0;
}
