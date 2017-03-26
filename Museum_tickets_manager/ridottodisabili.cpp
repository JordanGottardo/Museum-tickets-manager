#include "ridottodisabili.h"


ridottoDisabili::ridottoDisabili(QString i, double p, int e, int a, QDate d, double r, bool ac): bigliettoRidotto(i, p, e, a, d, r), accompagnatore(ac)
{

}

double ridottoDisabili::calcolaPrezzo() const
{
	return 0;
}

bool ridottoDisabili::getAccompagnatore() const
{
	return accompagnatore;
}

void ridottoDisabili::setAccompagnatore(bool a)
{
	accompagnatore=a;
}

ridottoDisabili* ridottoDisabili::clone() const
{
	return new ridottoDisabili(*this);
}
