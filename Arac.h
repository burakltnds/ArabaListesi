#ifndef ARAC_H
#define ARAC_H
#include <iostream>
using namespace std;
class Arac
{
private:
	int max;
	string vitesTipi, yakitTipi;
public:
	Arac(int max, string vitesTipi, string yakitTipi) :max(max), vitesTipi(vitesTipi), yakitTipi(yakitTipi) {}
	int getMax() const { return max; }
	void setMax(int max) { this->max = max; }
	string getVitesTipi() const { return vitesTipi; }
	void setVitesTipi(string vitesTipi) { this->vitesTipi = vitesTipi; }
	string getYakitTipi() const { return yakitTipi; }
	void setYakitTipi(string yakitTipi) { this->yakitTipi = yakitTipi; }
	void bilgileriYazdir() const
	{
		cout << "Aracin maksimum hizi: " << max << endl;
		cout << "Aracin vites tipi: " << vitesTipi << endl;
		cout << "Aracin yakit tipi: " << yakitTipi << endl;
	}
	void YakitAl() {
		cout << "Yakit alindi..." << endl;
	}
};

#endif // ARAC_H