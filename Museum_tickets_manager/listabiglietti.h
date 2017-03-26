#ifndef LISTABIGLIETTI_H
#define LISTABIGLIETTI_H
#include <biglietto.h>
#include <cfloat>
#include <iostream>
#include <vector>
#include "bigliettoordinario.h"
#include "ridottobambini.h"
#include "ridottodisabili.h"
using std::cout;
using std::vector;

class listaBiglietti
{
	friend class iteratore;
	private:
		class nodo;
		class smartp
		{			
			public:
				nodo* punt;
				smartp(nodo* =0); //costruttore
				smartp(const smartp&);
				~smartp();
				smartp& operator=(const smartp&);
				nodo& operator*() const;
				nodo* operator->() const;
				bool operator==(const smartp&) const;
				bool operator!=(const smartp&) const;
		};
		class nodo
		{
			public:
			biglietto* info;
			int riferimenti;
			smartp next;
			nodo();
			nodo(biglietto*, const smartp&);
			~nodo();
		};
		smartp first; //campo dati di listaBiglietti
	public:
		class iteratore
		{
			friend class listaBiglietti;
			private:
				listaBiglietti::nodo* punt;
			public:
				bool operator==(const iteratore&) const;
				bool operator!=(const iteratore&) const;
				iteratore& operator++(); //++ prefisso
				iteratore operator++(int); //++ postfisso

		};

		iteratore begin() const;
		iteratore end() const;
		biglietto* operator[](const iteratore&) const;
		//fine iteratore

		//inizio metodi propri listaBiglietti
		void pushFront(biglietto*); //inserisce dall'inizio
		void pushBack(biglietto*); //inserisce dalla fine
		biglietto* popFront();
		biglietto* popBack();
		void svuota();
		bool vuota() const;
		int bigliettiEmessiTot();
		biglietto* togliBiglietto(QString);
		int giornoPiuRedditizio() const; // lun=1..7=dom
		int alaPiuRedditizia() const;
		double redditoTotale() const;
		double redditoFasciaEta(int=0, int=200) const; //di default prende tutte le età
		biglietto* restituisciBiglietto(QString) const;
		static bool ordinario(biglietto*);
		static bool bambini(biglietto*);
		static bool disabili(biglietto*);



};

#endif // LISTABIGLIETTI_H
