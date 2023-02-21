#include <iostream>
#include <math.h>
#define PI 3.14
class Dynamic_Indicators
{
public:
	// Dynamic Indicators Initation List
	Dynamic_Indicators(double _wn, double _phi, double _zeta, double _deta, double _peak_time, double _adjusting_time, double _rise_time, double _overshoot, double _number_of_oscillations) : wn(_wn), phi(_phi), zeta(_zeta), deta(_deta), peak_time(_peak_time), adjusting_time(_adjusting_time), rise_time(_rise_time), overshoot(_overshoot), number_of_oscillations(_number_of_oscillations) {}
	// Constructor
	Dynamic_Indicators()
	{
		std::cout << "Constructor is call" << std::endl;
	}
	~Dynamic_Indicators()
	{
		std::cout << "Destructor is call" << std::endl;
	}
	// Menber Function
	void setParameters1()
	{
		std::cout << "请输入频率ωn，超调量σ:" << std::endl;
		std::cout << "频率ωn:";
		std::cin >> wn;
		std::cout << "超调量σ(100%):";
		std::cin >> overshoot;
	}
	void selectCalculateMode()
	{
		int select;
		std::cout << "请选择计算模式：" << std::endl;
		std::cout << "1.已知二阶系统的超调量σ，频率ωn" << std::endl;
		std::cout << "2.已知二阶系统的频率wn/ψ" << std::endl;
		std::cin >> select;
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
		std::cout << "调节时间误差范围为2%？5%？" << std::endl;
		std::cout << "Δ=";
		std::cin >> deta;
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
void Dynamic_Indicators::printResult(){
	std::cout << "-----------------------" << std::endl;
	std::cout << "上升时间tr：" << rise_time << "s" << std::endl;
	std::cout << "峰值时间tp：" << peak_time << "s" << std::endl;
	std::cout << "超调量σ(100%)：" << overshoot*100 << "%" << std::endl;
	std::cout << "调节时间ts：" << adjusting_time << "s" << "（误差Δ=" << deta << "%）" << std::endl;
	std::cout << "振荡次数N：" << number_of_oscillations << std::endl;
	std::cout << "-----------------------" << std::endl;
}
double Dynamic_Indicators::calculateAllInOne(double wn, double phi, double zeta, double deta){
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