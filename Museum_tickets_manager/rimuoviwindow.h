#ifndef RIMUOVIWINDOW_H
#define RIMUOVIWINDOW_H
#include <QDialog>
#include <QWidget>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QMessageBox>
#include "listabiglietti.h"
#include "bigliettoordinario.h"
#include "ridottobambini.h"
#include "ridottodisabili.h"
#include "confermawindow.h"
#include "mainwindow.h"

class rimuoviWindow: public QDialog
{
	Q_OBJECT

	private:
		QVBoxLayout *verticalLayout_4;
		QHBoxLayout *horizontalLayout_7;
		QVBoxLayout *verticalLayout;
		QVBoxLayout *verticalLayout_3;
		QVBoxLayout *verticalLayout_2;

		listaBiglietti* b;
		QLabel *pBaseLabel;
		QLabel *rFissaLabel;
		QLabel *dataLabel;
		QLabel *tipoLabel;
		QLabel *idLabel;
		QLabel *alaLabel;
		QLabel *accLabel;
		QLabel *rVarLabel;
		QLabel *etaLabel;
		QLabel *ultRimLabel;
		QLabel *idRimLabel;
		QLabel *risRimLabel;
		QLabel *pTotLabel;
		QLineEdit *idEdit;
		QLineEdit *idRimEdit;
		QLineEdit *idRisEdit;
		QLineEdit *pTotEdit;
		QDateEdit *dataDate;
		QRadioButton *codaRadio;
		QRadioButton *testaRadio;
		QSpinBox *alaSpin;
		QSpinBox *etaSpin;
		QDoubleSpinBox *pBaseSpin;
		QDoubleSpinBox *rVarSpin;
		QDoubleSpinBox *rFissaSpin;
		QComboBox *tipoCombo;
		QCheckBox *accCheck;
		QPushButton *rimButton;
		QPushButton *svuotaButton;
		QPushButton *annullaButton;
		QPushButton *codTesButton;
	private slots:
		void slRimuovi();
		void slModificaUltimo(biglietto*);
		void slCodaTesta();
		void slConfermaSvuota();

	signals:
		void sigModifica(biglietto*);

	public:
		rimuoviWindow(listaBiglietti* x, QWidget* parent=0);

};

#endif // RIMUOVIWINDOW_H
