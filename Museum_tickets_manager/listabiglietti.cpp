#include "listabiglietti.h"



listaBiglietti::smartp::smartp(nodo* s): punt(s)
{
	if (punt) punt->riferimenti++;
}

listaBiglietti::smartp::smartp(const smartp& s): punt(s.punt)
{
	if (punt) punt->riferimenti++;
}

listaBiglietti::smartp::~smartp()
{
	if (punt)
	{
		punt->riferimenti--;
		if (punt->riferimenti==0)
			delete punt;
	}
}

listaBiglietti::smartp& listaBiglietti::smartp::operator=(const smartp& s)
{
	if (this!=&s)
	{
		nodo* t=punt;
		punt=s.punt;
		if (punt) punt->riferimenti++;
		if (t)
		{
			t->riferimenti--;
			if (t->riferimenti==0)
				delete t;
		}
	}
	return *this;
}

listaBiglietti::nodo& listaBiglietti::smartp::operator*() const
{
	return *punt;
}

listaBiglietti::nodo* listaBiglietti::smartp::operator->() const
{
	return punt;
}

bool listaBiglietti::smartp::operator==(const smartp& s) const
{
	return punt==s.punt;
}

bool listaBiglietti::smartp::operator!=(const smartp& s) const
{
	return punt!=s.punt;
}



//fine smartp

listaBiglietti::nodo::nodo(): riferimenti(0) {}

listaBiglietti::nodo::nodo(biglietto* b, const smartp& s): info(b), riferimenti(0), next(s){}
listaBiglietti::nodo::~nodo()
{
	delete info;
}

//fine nodo

bool listaBiglietti::iteratore::operator==(const iteratore& it) const
{
	return punt==it.punt;
}

bool listaBiglietti::iteratore::operator!=(const iteratore& it) const
{
	return punt!=it.punt;
}

listaBiglietti::iteratore& listaBiglietti::iteratore::operator++()
{
	if (punt)
		punt=(*punt).next.punt;
	return *this;
}

listaBiglietti::iteratore listaBiglietti::iteratore::operator++(int)
{
	iteratore it=*this;
	if (punt)
		punt=(*punt).next.punt;
	return it;
}

//fine iteratore


listaBiglietti::iteratore listaBiglietti::begin() const
{
	iteratore it;
	it.punt=first.punt; //amicizia
	return it;
}

listaBiglietti::iteratore listaBiglietti::end() const
{
	iteratore it;
	it.punt=0;
	return it;
}

biglietto* listaBiglietti::operator[](const iteratore& it) const
{
	return it.punt->info;
}

//inizio metodi propri di listaBiglietti

void listaBiglietti::pushFront(biglietto* b)
{
	first=new nodo(b, first);
}

void listaBiglietti::pushBack(biglietto* b)
{
	if (first==0)
		first=new nodo(b, 0);
	else
	{
		smartp p=first;
		while (p->next!=0)
			p=p->next;
		p->next=new nodo(b, 0);
	}
}

biglietto* listaBiglietti::popFront()
{
	if (first==0)
		return 0;
	biglietto* b=first->info->clone();
	first=first->next;
	return b;
}

biglietto* listaBiglietti::popBack()
{
	if (first==0)
		return 0;
	if (first->next==0)
	{
		biglietto* b=first->info->clone();
		first=0;
		return b;
	} //first punta a lista con almeno due nodi

	smartp p=first, prec=0;
	while (p->next!=0)
	{
		prec=p;
		p=p->next;
	} //p punta all'ultimo nodo, prec punta al penultimo
	biglietto* b=p->info->clone();
	prec->next=0; //cancella lui in caso p->riferimenti sia 0
	return b;
}

void listaBiglietti::svuota()
{
	delete first.punt;
	first.punt=0;
}

bool listaBiglietti::vuota() const
{
	return first==0;
}

int listaBiglietti::bigliettiEmessiTot()
{
	if (!vuota())
	{
	int acc=0;
	for (iteratore i=begin(); i!=end(); ++i)
	{
		acc++;
	}
	return acc;
	}
	else
		return 0;
}

biglietto* listaBiglietti::togliBiglietto(QString i)
{
	smartp p=first, prec, q;
	smartp original=first;
	biglietto* bo=0;
	first=0;
	while (p!=0 && !(p->info->getId()==i))
	{
		q=new nodo(p->info, p->next);
		if (prec==0)
			first=q;
		else
			prec->next=q;
		prec=q;
		p=p->next;
	}
	if (p==0)
		first=original;
	else
		if (prec==0)
		{
			bo=original->info->clone();
			first=p->next;
		}
		else
		{
			bo=p->info->clone();
			prec->next=p->next;
		}
	return bo;
}

int listaBiglietti::giornoPiuRedditizio() const
{
	double giorni[7]={0, 0, 0, 0, 0, 0, 0};
	smartp p=first;
	while (p!=0)
	{
		switch(p->info->getData().dayOfWeek())
		{
		case(1):
			giorni[0]+=p->info->calcolaPrezzo();
			break;
		case(2):
			giorni[1]+=p->info->calcolaPrezzo();
			break;
		case(3):
			giorni[2]+=p->info->calcolaPrezzo();
			break;
		case(4):
			giorni[3]+=p->info->calcolaPrezzo();
			break;
		case(5):
			giorni[4]+=p->info->calcolaPrezzo();
			break;
		case(6):
			giorni[5]+=p->info->calcolaPrezzo();
			break;
		case(7):
			giorni[6]+=p->info->calcolaPrezzo();
			break;
		default:
			return -1;

		}
		p=p->next;
	}

	double max=-DBL_MAX; //inizializzato al minimo double esistente
	int ind=0;
	for (int i=0; i<7; i++)
	{
		if (giorni[i]>max)
		{
			max=giorni[i];
			ind=i;
		}
	}

	return ind+1;
}

int listaBiglietti::alaPiuRedditizia() const
{
	smartp p=first;
	vector<int> ali;
	vector<double> prezzi;

	while (p!=0)
	{
		bool aggiungi=true; //se devo aggiungere l'ala
		for (vector<int>::iterator i=ali.begin(); i!=ali.end() && aggiungi; ++i)
			if (p->info->getAla()==*i)
				aggiungi=false;
		if (aggiungi)
		{
			ali.push_back(p->info->getAla());
			prezzi.push_back(0);
		}
		p=p->next;
	} 		//trovato tutte le ali, inizializzato i prezzi a 0

	for (unsigned int i=0; i<ali.size(); i++)
	{
		p=first;
		while(p!=0)
		{
			if(p->info->getAla()==ali[i])
				prezzi[i]+=p->info->calcolaPrezzo();
			p=p->next;
		}
	} //popolato i prezzi

	double max=-DBL_MAX;
	int pos=-1;
	for (unsigned int i=0; i<prezzi.size(); i++)
	{
		if (prezzi[i]>max)
		{
			max=prezzi[i];
			pos=i;
		}
	}
	return ali[pos];
}


double listaBiglietti::redditoTotale() const
{
	smartp p=first;
	double acc=0;
	while (p!=0)
	{
		acc+=p->info->calcolaPrezzo();
		p=p->next;
	}
	return acc;
}


double listaBiglietti::redditoFasciaEta(int inizio, int fine) const
{
	smartp p=first;
	double acc=0;
	while (p!=0)
	{
		if (p->info->getEta()>=inizio && p->info->getEta()<=fine)
			acc+=p->info->calcolaPrezzo();
		p=p->next;
	}
	return acc;
}

biglietto* listaBiglietti::restituisciBiglietto(QString i) const
{
	if (first==0)
		return 0;
	else
	{
		smartp p=first;
		while (p!=0 && p->info->getId()!=i)
		{
			p=p->next;
		}
		if (p==0)
			return 0;
		else
			return p->info;
	}
}

bool listaBiglietti::ordinario(biglietto* bo)
{
	if (dynamic_cast<bigliettoOrdinario*>(bo))
		return true;
	return false;
}

bool listaBiglietti::bambini(biglietto* bo)
{
	if (dynamic_cast<ridottoBambini*>(bo))
		return true;
	return false;
}

bool listaBiglietti::disabili(biglietto* bo)
{
	if (dynamic_cast<ridottoDisabili*>(bo))
		return true;
	return false;
}
