#ifndef RIDOTTOBAMBINI_H
#define RIDOTTOBAMBINI_H
#include <bigliettoridotto.h>

class ridottoBambini: public bigliettoRidotto
{
	private:
		double riduzioneVariabile;
		static int sogliaEta;
	public:

		ridottoBambini(QString, double, int, int, QDate, double, double);
		double getRiduzioneVariabile() const;
		void setRiduzioneVariabile(double);
		static int getSogliaEta();
		static void setSogliaEta(int);
		double calcolaPrezzo() const;
		ridottoBambini* clone() const;
};


#endif // RIDOTTOBAMBINI_H
