#ifndef RIDOTTODISABILI_H
#define RIDOTTODISABILI_H
#include <bigliettoridotto.h>

class ridottoDisabili: public bigliettoRidotto
{
	private:
		bool accompagnatore;
	public:
		ridottoDisabili(QString, double, int, int, QDate, double, bool);
		double calcolaPrezzo() const;
		bool getAccompagnatore() const;
		void setAccompagnatore(bool);
		ridottoDisabili* clone() const;
};

#endif // RIDOTTODISABILI_H
