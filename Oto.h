#ifndef OTO_H
#define OTO_H
#include <iostream>
#include "Arac.h"
#include <string>
using namespace std;
class Oto :public Arac
{
private:
	string marka, model;
public:
	Oto(int max, string vitesTipi, string yakitTipi, string marka, string model) :Arac(max, vitesTipi, yakitTipi), marka(marka), model(model) {}
	string getMarka() const { return marka; }
	void setMarka(string marka) { this->marka = marka; }
	string getModel() const { return model; }
	void setModel(string model) { this->model = model; }
	string bilgileriYazdir()
	{
		return "Aracin maksimum hizi: " + to_string(getMax()) + "\n"+
			"Aracin vites tipi: " + getVitesTipi() + "\n" +
			"Aracin yakit tipi: " + getYakitTipi() + "\n" +
			"Aracin markasi: " + marka + "\n" +
			"Aracin modeli: " + model + "\n"
			+"***************************"+"\n";
		
	}
	void YakitAl()
	{
		cout << "Otomobile Yakit Alindi..." << endl;
	}
};

#endif // OTO_H
