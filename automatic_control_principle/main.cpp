#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;
class Dynamic_Indicators
{
public:
	// Dynamic Indicators Initation List
	Dynamic_Indicators(double _wn, double _phi, double _zeta, double _deta, double _peak_time, double _adjusting_time, double _rise_time, double _overshoot, double _number_of_oscillations) : wn(_wn), phi(_phi), zeta(_zeta), deta(_deta), peak_time(_peak_time), adjusting_time(_adjusting_time), rise_time(_rise_time), overshoot(_overshoot), number_of_oscillations(_number_of_oscillations) {}
	// Constructor
	Dynamic_Indicators()
	{
		cout << "Constructor is call" << endl;
	}
	~Dynamic_Indicators()
	{
		cout << "Destructor is call" << endl;
	}
	// Menber Function
	void setParameters1()
	{
		cout << "请输入频率ωn，超调量σ:" << endl;
		cout << "频率ωn:";
		cin >> wn;
		cout << "超调量σ(100%):";
		cin >> overshoot;
	}
	void selectCalculateMode()
	{
		int select;
		cout << "请选择计算模式：" << endl;
		cout << "1.已知二阶系统的超调量σ，频率ωn" << endl;
		cout << "2.已知二阶系统的频率wn/ψ" << endl;
		cin >> select;
		if (select == 1)
		{ // second order system's dynamic indicators known
			setParameters1();
			calculate1(wn, overshoot);
			printResult();
		}
		else if (select == 2)
		{ // second order system's wn/phi/zeta/deta known
		}
	}
	void calculate1(double wn, double overshoot)
	{
		double zeta_square;
		zeta_square = pow(log(1 / overshoot), 2) / (pow(PI, 2) + pow(log(1 / overshoot), 2));
		zeta = sqrt(zeta_square);
		rise_time = (PI - phi) / (wn * sqrt(1 - pow(zeta, 2)));
		peak_time = PI / (wn * sqrt(1 - pow(zeta, 2)));
		cout << "调节时间误差范围为2%？5%？" << endl;
		cout << "Δ=";
		cin >> deta;
		if (deta == 5)
		{
			adjusting_time = 3.5 / (zeta * wn);
		}
		else if (deta == 2)
		{
			adjusting_time = 4.4 / (zeta * wn);
		}
		number_of_oscillations = (adjusting_time * wn * sqrt(1 - pow(zeta, 2))) / (2 * PI);
	}
	void printResult();
	double calculateAllInOne(double wn, double phi, double zeta, double deta);
	double incalculateAllInOne(double overshoot, double peak_time);

private:
	double wn, phi, zeta, deta;
	double rise_time, peak_time, overshoot, adjusting_time, number_of_oscillations;
};
void Dynamic_Indicators::printResult()
{
	cout << "-----------------------" << endl;
	cout << "上升时间tr：" << rise_time << "s" << endl;
	cout << "峰值时间tp：" << peak_time << "s" << endl;
	cout << "超调量σ(100%)：" << overshoot * 100.00 << endl;
	cout << "调节时间ts：" << adjusting_time << "s" << endl;
	cout << "振荡次数N：" << number_of_oscillations << endl;
	cout << "-----------------------" << endl;
}
double Dynamic_Indicators::calculateAllInOne(double wn, double phi, double zeta, double deta)
{
	rise_time = (PI - phi) / (wn * sqrt(1 - pow(zeta, 2)));
	peak_time = PI / (wn * sqrt(1 - pow(zeta, 2)));
	overshoot = exp((-PI * zeta) / (sqrt(1 - pow(zeta, 2))));
	if (deta == 5)
	{
		adjusting_time = 3.5 / (zeta * wn);
	}
	else if (deta == 2)
	{
		adjusting_time = 4.4 / (zeta * wn);
	}
	number_of_oscillations = (adjusting_time * wn * sqrt(1 - pow(zeta, 2))) / (2 * PI);
}
double Dynamic_Indicators::incalculateAllInOne(double overshoot, double peak_time)
{
	double zeta_square;
	zeta_square = pow(log(1 / overshoot), 2) / (pow(PI, 2) + pow(log(1 / overshoot), 2));
	zeta = sqrt(zeta_square);
	wn = (PI) / (peak_time * sqrt(1 - zeta_square));
	phi = acos(zeta);
}

void test()
{
	Dynamic_Indicators sys;
	sys.selectCalculateMode();
}

int main()
{
	test();
	system("pause");
	return 0;
}