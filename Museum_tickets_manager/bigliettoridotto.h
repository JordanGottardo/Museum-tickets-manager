#ifndef BIGLIETTORIDOTTO_H
#define BIGLIETTORIDOTTO_H
#include <biglietto.h>


class bigliettoRidotto: public biglietto
{
	private:
		double riduzioneFissa;
	public:
		bigliettoRidotto(QString, double, int, int, QDate, double);
		double getRiduzioneFissa() const;
		void setRiduzioneFissa(double);
};

#endif // BIGLIETTORIDOTTO_H
