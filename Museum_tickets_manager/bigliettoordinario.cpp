#include "bigliettoordinario.h"

bigliettoOrdinario::bigliettoOrdinario(QString i, double p, int e, int a, QDate d): biglietto(i, p, e, a, d)
{}

double bigliettoOrdinario::calcolaPrezzo() const
{
	return getPrezzoBase();
}

bigliettoOrdinario* bigliettoOrdinario::clone() const
{
	return new bigliettoOrdinario(*this);
}
