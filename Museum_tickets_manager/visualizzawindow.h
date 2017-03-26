#ifndef VISUALIZZAWINDOW_H
#define VISUALIZZAWINDOW_H
#include <QDialog>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include "biglietto.h"
#include "listabiglietti.h"
#include "bigliettoordinario.h"
#include "ridottobambini.h"
#include "ridottodisabili.h"

class visualizzaWindow: public QDialog
{
	private:
		listaBiglietti *b;
		QVBoxLayout *verticalLayout;
		QPlainTextEdit *visualizzaPlain;
		QPushButton *annullaButton;
		void visualizzaLista() const;
	public:
		visualizzaWindow(listaBiglietti *, QWidget* =0);
};

#endif // VISUALIZZAWINDOW_H
