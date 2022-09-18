#include <iostream>
#include <cmath>
using namespace std;
// вспомогательные функции
double f(double x, int i) {
	if (i == 1) return x - cos(x);
	else return x - 10 * cos(x);
}
double f_d(double x, int i) {
	if (i == 1) return 1 + sin(x);
	else return 1 + 10*sin(x);
}
double fi_x(double x, int i) {
	if (i == 1) return cos(x);
	else return 10 * cos(x);
}
// метод Ньтона
void newton(double x_0, double eps, int i) {
	double x = x_0; int cnt = 0;
	while (true) {
		x = x - f(x, i) / f_d(x, i);
		cnt += 1;
		if (fabs(f(x, i)) < eps) break;
	}
	cout << "Число " << x << " является корнем " << i << " уравнения, полученным при "
		<< cnt << " попытке" << endl;
}
// метод половинного деления
void bin_poisk(double lt, double rt, double eps, int i) {
	int cnt = 0; double md = (lt + rt) / 2;
	while (fabs(f(md, i)) >= eps) {
		if (f(lt, i) * f(md, i) < 0) rt = md;
		else lt = md;
		md = (lt + rt) / 2;
		cnt += 1;
	}
	cout << "Число " << md << " является корнем " << i << " уравнения, полученным при "
		<< cnt << " попытке" << endl;
}
// метод итерации
void iteration(double x, double eps, int i) {
	int cnt = 0; double x_n;
	x_n = x; x = fi_x(x, i); cnt += 1;
	while (fabs(x - x_n) >= eps && cnt < 100000) {
		x_n = x;
		x = fi_x(x, i);
		cnt += 1;
	}
	cout << "Число " << x << " является корнем " << i << " уравнения, полученным при "
		<< cnt << " попытке" << endl;
}
// ...
