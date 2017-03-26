#include "ridottobambini.h"


ridottoBambini::ridottoBambini(QString i, double p, int e, int a, QDate d, double r, double v): bigliettoRidotto(i, p, e, a, d, r), riduzioneVariabile(v)
{
}


double ridottoBambini::getRiduzioneVariabile() const
{
	return riduzioneVariabile;
}

void ridottoBambini::setRiduzioneVariabile(double v)
{
	riduzioneVariabile=v;
}

int ridottoBambini::getSogliaEta()
{
	return sogliaEta;
}

void ridottoBambini::setSogliaEta(int s)
{
	sogliaEta=s;
}

double ridottoBambini::calcolaPrezzo() const
{
	double prezzo=getPrezzoBase()-getRiduzioneFissa()-( ( (sogliaEta-getEta())*(riduzioneVariabile/100) )*getPrezzoBase());
	if (prezzo<0)
		return 0;
	return prezzo;
}
ridottoBambini* ridottoBambini::clone() const
{
	return new ridottoBambini(*this);
}

int ridottoBambini::sogliaEta=18;
