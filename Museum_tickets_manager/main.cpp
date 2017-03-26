#include "mainwindow.h"
#include "aggiungiwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}



/*#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <QString>
#include <bigliettoOrdinario.h>
#include <ridottoBambini.h>
#include <listabiglietti.h>
#include <QDate>
using namespace std;
int main(int argc, char *argv[])
{

	ifstream IN;
	ofstream OUT;
	IN.open("input.txt");
	OUT.open("output.txt");
	if (IN && OUT)
	{
	string i;
	double p;
	int a, y, m, d, e;
	double r,v;
	int f=1;
	IN>>i>>p>>e>>a>>y>>m>>d>>r>>v;
	biglietto* b1=new ridottoBambini(i, p, e, a, y, m, d, r, v);
	IN>>i>>p>>e>>a>>y>>m>>d>>r>>v;
	biglietto* b2=new ridottoBambini(i, p, e, a, y, m, d, r, v);
	IN>>i>>p>>e>>a>>y>>m>>d;
	biglietto* b3=new bigliettoOrdinario(i, p, e, a, y, m, d);
	listaBiglietti b;
	cout<<b1->calcolaPrezzo()<<endl;
	cout<<b2->calcolaPrezzo()<<endl;
	cout<<b3->calcolaPrezzo()<<endl;

	b.pushBack(b1);
	b.pushBack(b2);
	b.pushBack(b3);

	b.modificaAla("A1", 2222);
	cout<<b[b.begin()]->getAla();
	//cout<<(b3->getData()).dayOfWeek();
	//cout<<b1->calcolaPrezzo()+b2->calcolaPrezzo()+b3->calcolaPrezzo()<<endl;
	//cout<<b.redditoFasciaEta(10, 14);
	//cout<<b.alaPiuRedditizia();

	IN.close();
	OUT.close();
	}
	else
		cout<<"Errore";
	return 0;

}

*/










