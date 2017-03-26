#include "biglietto.h"

biglietto::biglietto(QString i, double p, int e, int a, QDate d): id(i), prezzoBase(p), eta(e), ala(a), data(d)
{
}

QString biglietto::getId() const
{
	return id;
}

void biglietto::setId(QString ni)
{
	id=ni;
}

double biglietto::getPrezzoBase() const
{
	return prezzoBase;
}

void biglietto::setPrezzoBase(double p)
{
	prezzoBase=p;
}


int biglietto::getEta() const
{
	return eta;
}

void biglietto::setEta(int e)
{
	eta=e;
}

int biglietto::getAla() const
{
	return ala;
}

void biglietto::setAla(int a)
{
	ala=a;
}

QDate biglietto::getData() const
{
	return data;
}

void biglietto::setData(QDate d)
{
	data=d;
}

biglietto::~biglietto()
{

}


