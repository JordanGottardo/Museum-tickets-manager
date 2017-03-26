#ifndef SOGLIAWINDOW_H
#define SOGLIAWINDOW_H



#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QString>
#include "ridottobambini.h"
#include "mainwindow.h"
class sogliaWindow: public QDialog
{
	Q_OBJECT
	private:
		QVBoxLayout *verticalLayout;
		QHBoxLayout *horizontalLayout;
		QPushButton *annullaButton;
		QPushButton *okButton;
		QLabel *sogliaLabel;
		QSpinBox *sogliaSpin;
	private slots:
		void slModSoglia();
	public:
		sogliaWindow(QWidget* =0);
};

#endif // SOGLIAWINDOW_H
