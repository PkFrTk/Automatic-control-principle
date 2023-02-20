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
	//Dynamic Indicators Initation
	Dynamic_Indicators(double _wn, double _phi, double _zeta, double _deta) :wn(_wn), phi(_phi), zeta(_zeta), deta(_deta) {}
	Dynamic_Indicators(double _peak_time, double _adjusting_time, double _rise_time, double _overshoot, double _number_of_oscillations) :peak_time(_peak_time), adjusting_time(_adjusting_time), rise_time(_rise_time), overshoot(_overshoot), number_of_oscillations(_number_of_oscillations) {}
	//Menber Function
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
	system("pause");
	return 0;
}