#include <iostream>
#include <math.h>

class Dynamic_Indicators
{
public:
	//Constructor
	Dynamic_Indicators() {
		std::cout << "Constructor is call" << std::endl;
	}
	~Dynamic_Indicators() {
		std::cout << "Destructor is call" << std::endl;
	}
	//Dynamic Indicators Initation List
	Dynamic_Indicators(double _wn, double _phi, double _zeta, double _deta) :wn(_wn), phi(_phi), zeta(_zeta), deta(_deta) {}
	Dynamic_Indicators(double _peak_time, double _adjusting_time, double _rise_time, double _overshoot, double _number_of_oscillations) :peak_time(_peak_time), adjusting_time(_adjusting_time), rise_time(_rise_time), overshoot(_overshoot), number_of_oscillations(_number_of_oscillations) {}
	//Menber Function
	void selectCalculateMode(){
		int select;
		std::cout << "请选择计算模式：";
		std::cout << "1.已知二阶系统的动态指标（上升时间等）";
		std::cout << "2.已知二阶系统的频率wn/ψ" << std::endl;
		std::cin >> select;
		if (select == 1) { //second order system's dynamic indicators known

		}
		else if (select == 2) { //second order system's wn/phi/zeta/deta known

		}
	}
	void printParameters(){
		std::cout << "请输入频率wn，" << std::endl;
	}
	void setParameters(double _wn, double _phi, double _zeta, double _deta) {
		wn = _wn;
		phi = _phi;
		zeta = _zeta;
		deta = _deta;
	}
	void calculate(double wn, double pi, double phi, double zeta, double deta) {
		rise_time = (pi - phi) / (wn * sqrt(1 - pow(zeta, 2)));
		peak_time = pi / (wn * sqrt(1 - pow(zeta, 2)));
		overshoot = exp((-pi * zeta) / (sqrt(1 - pow(zeta, 2))));
		if (deta == 5) {
			adjusting_time = 3.5 / (zeta * wn);
		}
		else if (deta == 2) {
			adjusting_time = 4.4 / (zeta * wn);
		}
		number_of_oscillations = (adjusting_time * wn * sqrt(1 - pow(zeta, 2))) / (2 * pi);
	}
	void incalculate(double overshoot, double peak_time){
		double zeta_square;
		zeta_square = pow(log(1/overshoot),2)/(pow(pi,2)+pow(log(1/overshoot),2));
		zeta = sqrt(zeta_square);
		wn = (pi)/(peak_time*sqrt(1-zeta_square));
		phi = acos(zeta);
	}
private:
	double pi = 3.14;
	double wn, phi, zeta, deta;
	double rise_time, peak_time, overshoot, adjusting_time, number_of_oscillations;
};

void test() {
	Dynamic_Indicators sys;
	//sys.setParameters();
}

int main()
{
	test();
	system("pause");
	return 0;
}