#ifndef BIGLIETTOORDINARIO_H
#define BIGLIETTOORDINARIO_H
#include <biglietto.h>


class bigliettoOrdinario: public biglietto
{
	public:
		bigliettoOrdinario(QString, double, int, int, QDate);
		double calcolaPrezzo() const;
		bigliettoOrdinario* clone() const;
};




#endif // BIGLIETTOORDINARIO_H
