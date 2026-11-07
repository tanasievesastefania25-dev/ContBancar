#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class ContBancar
{
private:
static int numarConturi;
const int idCont;
string titularCont;
double* istoricTranzactii;
int numarTranzactii;
public:
//constructor fara param
	ContBancar():idCont(numarConturi++)
	{
	this->titularCont="NA";
	this->istoricTranzactii=NULL;
	this->numarTranzactii=0;
}
//constr cu param
	ContBancar(string titularContInit, double* istoricTranzactiiInit, int numarTranzactiiInit) :idCont(numarConturi++) {
		if (titularContInit.length() > 0)
		{
			this->titularCont=titularContInit;

		}
		else {
			this->titularCont="NA";
		}
		if (numarTranzactiiInit > 0 && istoricTranzactii != nullptr)
		{
			this->numarTranzactii=numarTranzactiiInit;
			this->istoricTranzactii=new double[numarTranzactiiInit];
			for (int i = 0;i < numarTranzactiiInit;i++)
			{
				this->istoricTranzactii[i]=istoricTranzactiiInit[i];
			}
			}
		else
		{
			this->numarTranzactii=0;
			this->istoricTranzactii=NULL;
		}
		
	


}
//destructor
	~ContBancar()
	{
	if(istoricTranzactii!=NULL)
	{ 
		delete[]this->istoricTranzactii;
}
}
//constructorul de copiere 
	ContBancar( const ContBancar& c) :idCont(numarConturi++)
	{
	this->titularCont=c.titularCont;
	this->numarTranzactii=c.numarTranzactii;
	if(c.istoricTranzactii != nullptr && c.numarTranzactii>0)
	{
	this->istoricTranzactii=new double[c.numarTranzactii];
	for (int i = 0;i < c.numarTranzactii;i++)
	{
		this->istoricTranzactii[i] = c.istoricTranzactii[i];
}
}
	else {
		this->istoricTranzactii=nullptr;
	}
}
//operator=
	ContBancar& operator=(const ContBancar& c)
	{
		if (this == &c)
		{
			return *this;
		}

		if (istoricTranzactii != NULL)
		{
		delete[]this->istoricTranzactii;
		}
		this->titularCont=c.titularCont;
		this->numarTranzactii=c.numarTranzactii;
		this->istoricTranzactii=new double[c.numarTranzactii];
		for (int i = 0;i < c.numarTranzactii;i++)
		{
			this->istoricTranzactii[i]=c.istoricTranzactii[i];
		}
		return *this;
}
//operator<<
	friend ostream& operator<<(ostream& out, const ContBancar& c)
	{
	out<<c.idCont<<endl;
	out<<c.titularCont<<endl;
	out<<c.numarTranzactii<<endl;
	for (int i = 0;i < c.numarTranzactii;i++)
	{
		out<<c.istoricTranzactii[i];
		if (i < c.numarTranzactii)
		{
			out<<endl;
		}

	}
	return out;

}
//setter si getter titularCont si istoricTranzactii
//pt titularCont
string getTitularCont()
{
return this->titularCont;
}
void setTitularCont( const string titularContNou ) {
	if (titularContNou.length() > 0)
	{
		this->titularCont=titularContNou;
}

}
  double* getIstoricTranzactii() {

	  if (this->istoricTranzactii == nullptr || this->numarTranzactii <= 0)
	  {
		  return nullptr;
	}
	double* copie=new double[this->numarTranzactii];
	for(int i=0;i<numarTranzactii;i++)
	{
	copie[i]=this->istoricTranzactii[i];
}
return copie;
}
int getNumarTranzactii()
{
return this->numarTranzactii;
}
void setIstoricTranzactii(const double* istoricTranzactiiNou, int numarNou)
{
	//p1 validari
	if (istoricTranzactiiNou==nullptr || numarNou <= 0)
	{
		return;
	}
	//p2 sterg vechiul vector
	if (this->istoricTranzactii != nullptr)
	{
		delete[] this->istoricTranzactii;
	
}
//p3 refac cu val noi
this->numarTranzactii=numarNou;
this->istoricTranzactii=new double[numarNou];
for (int i = 0;i < numarNou;i++)
{
	this->istoricTranzactii[i]=istoricTranzactiiNou[i];
}
}



};
int ContBancar::numarConturi=0;

int main()
{
//constr fara param
ContBancar c1;
cout<<c1<<endl;

//constructor cu param
double t[]={100,-30,250.5};

ContBancar c2("Popescu",t,3);
cout<<c2<<endl;

//constructor de copiere 
;
ContBancar c4=c2;
cout<<c4<<endl;

//getter si setter 
double nou[]={500, -20};
c2.setIstoricTranzactii(nou,2);
double* p=c2.getIstoricTranzactii();
for(int i=0;i<c2.getNumarTranzactii();i++)
{
cout<<p[i]<<" ";
}
cout<<endl;
delete[]p;
}