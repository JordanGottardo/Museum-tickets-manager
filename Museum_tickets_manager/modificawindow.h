#ifndef MODIFICAWINDOW_H
#define MODIFICAWINDOW_H
#include <QDialog>
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QDialog>
#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>
#include "listabiglietti.h"
#include "ridottobambini.h"
#include "ridottodisabili.h"
#include "mainwindow.h"

class modificaWindow: public QDialog
{
		Q_OBJECT
	private:
		listaBiglietti *b;
		QVBoxLayout *verticalLayout_14;
		QHBoxLayout *horizontalLayout;
		QVBoxLayout *verticalLayout;
		QVBoxLayout *verticalLayout_4;
		QVBoxLayout *verticalLayout_5;
		QVBoxLayout *verticalLayout_6;
		QVBoxLayout *verticalLayout_7;
		QVBoxLayout *verticalLayout_8;
		QVBoxLayout *verticalLayout_2;
		QVBoxLayout *verticalLayout_15;

		QVBoxLayout *verticalLayout_9;
		QVBoxLayout *verticalLayout_10;

		QVBoxLayout *verticalLayout_11;

		QVBoxLayout *verticalLayout_13;
		QVBoxLayout *verticalLayout_12;
		QPushButton *modAlaButton;
		QPushButton *modDataButton;
		QPushButton *modEtaButton;
		QPushButton *modRFissaButton;
		QPushButton *modRVarButton;
		QPushButton *modAccButton;
		QPushButton *modPBaseButton;
		QPushButton *annullaButton;
		QLabel *rFissaLabel;
		QLabel *pBaseLabel;
		QLabel *dataLabel;
		QLabel *idLabel;
		QLabel *tipoLabel;
		QLabel *alaLabel;
		QLabel *rVarLabel;
		QLabel *accLabel;
		QLabel *pTotLabel;
		QLabel *etaLabel;
		QCheckBox *accCheck;
		QLabel *risLabel;
		QLineEdit *risEdit;
		QLineEdit *idEdit;
		QLineEdit *pTotEdit;
		QDoubleSpinBox *pBaseSpin;
		QDoubleSpinBox *rFissaSpin;
		QDoubleSpinBox *rVarSpin;
		QSpinBox *alaSpin;
		QSpinBox *etaSpin;
		QDateEdit *dataDate;
		QComboBox *tipoCombo;
	private slots:
		void slVisualizza();
		void slModPBase();
		void slModEta();
		void slModAla();
		void slModData();
		void slModRFissa();
		void slModRVar();
		void slModAcc();
		void slAggPTot(const biglietto*);

	signals:
		void sigAggPTot(const biglietto*);
	public:
		modificaWindow(listaBiglietti*, QWidget* =0);
		bool checkOk() const; //controlla se è stato visualizzato un biglietto legale
};



#endif // MODIFICAWINDOW_H
