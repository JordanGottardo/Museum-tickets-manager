#ifndef CONFERMAWINDOW_H
#define CONFERMAWINDOW_H
#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "listabiglietti.h"

class confermaWindow: public QDialog
{
	Q_OBJECT
	private:
		listaBiglietti* b;
		QHBoxLayout *horizontalLayout;
		QVBoxLayout *verticalLayout;
		QLabel *confermaLabel;
		QPushButton *okButton;
		QPushButton *annullaButton;
	private slots:
		void slSvuota();
	public:
		confermaWindow(listaBiglietti* x, QWidget* parent=0);

};

#endif // CONFERMAWINDOW_H
