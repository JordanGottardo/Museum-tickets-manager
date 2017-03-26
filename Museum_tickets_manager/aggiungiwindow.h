#ifndef AGGIUNGIWINDOW_H
#define AGGIUNGIWINDOW_H
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QComboBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QMessageBox>
#include "listabiglietti.h"
#include "mainwindow.h"
#include "bigliettoordinario.h"
#include "ridottobambini.h"
#include "ridottodisabili.h"

class aggiungiWindow: public QDialog
{
	Q_OBJECT
	private:
		listaBiglietti* b;
		QVBoxLayout *verticalLayout;
		QLabel *idLabel;
		QLineEdit *idEdit;
		QLabel *pBaseLabel;
		QDoubleSpinBox *pBaseSpin;
		QLabel *etaLabel;
		QSpinBox *etaSpin;
		QLabel *alaLabel;
		QSpinBox *alaSpin;
		QLabel *dataLabel;
		QDateEdit *dataDate;
		QLabel *tipoLabel;
		QComboBox *tipoCombo;
		QLabel *rFissaLabel;
		QDoubleSpinBox *rFissaSpin;
		QLabel *rVarLabel;
		QDoubleSpinBox *rVarSpin;
		QLabel *accLabel;
		QCheckBox *accCheck;
		QSpacerItem *horizontalSpacer;
		QSpacerItem *horizontalSpacer_2;
		QPushButton *insButton;
		QRadioButton *codaRadio;
		QRadioButton *testaRadio;
		QSpacerItem *horizontalSpacer_3;
		QLabel *pTotLabel;
		QLineEdit *pTotEdit;
		QSpacerItem *horizontalSpacer_4;
		QSpacerItem *horizontalSpacer_5;
		QPushButton *annullaButton;

	public:
		aggiungiWindow(listaBiglietti* x, QWidget* parent=0);

	private slots:
		void aggiungiBiglietto();
		void cambiatoTipo(int);

};

#endif // AGGIUNGIWINDOW_H
