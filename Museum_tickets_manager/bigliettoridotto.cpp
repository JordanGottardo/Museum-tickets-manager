#include "bigliettoridotto.h"

bigliettoRidotto::bigliettoRidotto(QString i, double p, int e, int a, QDate d, double r): biglietto(i, p, e, a, d), riduzioneFissa(r)
{
}

double bigliettoRidotto::getRiduzioneFissa() const
{
	return riduzioneFissa;
}

void bigliettoRidotto::setRiduzioneFissa(double r)
{
	riduzioneFissa=r;
}
