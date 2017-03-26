#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QWidget>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QPalette>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "listabiglietti.h"
#include "aggiungiwindow.h"
#include "rimuoviwindow.h"
#include "modificawindow.h"
#include "visualizzawindow.h"
#include "sogliawindow.h"
#include "bigliettoordinario.h"
#include "ridottobambini.h"
#include "ridottodisabili.h"
class MainWindow : public QMainWindow
{
		Q_OBJECT

	private:
		listaBiglietti b;
		QPalette *pal;
		QAction *apriAction;
		QAction *nuovoAction;
		QAction *salvaAction;
		QAction *esciAction;
		QWidget* centralWidget;
		QVBoxLayout *verticalLayout;
		QPushButton* insButton;
		QPushButton* togliButton;
		QPushButton* modButton;
		QPushButton* visButton;
		QPushButton* sogliaButton;
		QSpacerItem *horizontalSpacer;

		QLabel *biglLabel;
		QSpinBox *biglSpin;
		QLabel *alaLabel;
		QSpinBox *alaSpin;
		QLabel *giorLabel;
		QLineEdit *giorEdit;
		QLabel *guadLabel;
		QLineEdit *guadEdit;
		QSpacerItem *horizontalSpacer_2;
		QPushButton *fascButton;
		QLabel *iniLabel;
		QSpinBox *iniSpin;
		QLabel *finLabel;
		QSpinBox *finSpin;
		QLabel *fascLabel;
		QLineEdit *fascEdit;
		QPushButton *escButton;
		QMenuBar *menuBar;
		QMenu *menuFile;

	public:
		MainWindow(QWidget *parent = 0);

	private slots:
		void slAggiungi();
		void slTogli();
		void slModifica();
		void slVisualizza();
		void slBigliettiEmessi();
		void slGiorno();
		void slAla();
		void slGuadagnoTot();
		void slFascia();
		void slSoglia();

		void slApriFile();
		void slSalva();
		void slSalvaXml(QFile&);

	signals:
		void sigAggiornaTutti();



};

#endif // MAINWINDOW_H
