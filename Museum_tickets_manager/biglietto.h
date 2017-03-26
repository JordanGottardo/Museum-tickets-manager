


//When I wrote this, only God and I understood what I was doing
//Now, God only knows



#ifndef BIGLIETTO_H
#define BIGLIETTO_H
#include <QDate>
#include <QString>
#include <iostream>
using std::ostream;
using std::endl;


class biglietto
{
	private:
		QString id;
		double prezzoBase;
		int eta;
		int ala;
		QDate data;
	public:
		biglietto(QString, double, int, int, QDate);
		virtual double calcolaPrezzo() const =0;
		QString getId() const;
		void setId(QString);
		double getPrezzoBase() const;
		void setPrezzoBase(double);
		int getEta() const;
		void setEta(int);
		int getAla() const;
		void setAla(int);
		QDate getData() const;
		void setData(QDate);
		virtual ~biglietto();
		virtual biglietto* clone() const =0;


};


#endif // BIGLIETTO_H
