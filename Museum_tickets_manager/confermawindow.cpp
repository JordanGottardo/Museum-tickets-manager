#include "confermawindow.h"

confermaWindow::confermaWindow(listaBiglietti* x, QWidget* parent): QDialog(parent), b(x)
{
	setWindowTitle("Conferma rimozione");
	resize(358, 137);
	setModal(true);


	verticalLayout = new QVBoxLayout(this);
	verticalLayout->setContentsMargins(50, 25, 50, 25);
	confermaLabel = new QLabel("Sei sicuro di voler eliminare definitivamente la lista?", this);

	verticalLayout->addWidget(confermaLabel, 0, Qt::AlignHCenter);
	horizontalLayout = new QHBoxLayout();

	confermaLabel->setGeometry(40, 30, 271, 31);
	okButton = new QPushButton("Ok", this);
	annullaButton = new QPushButton("Annulla", this);
	horizontalLayout->addWidget(okButton);
	horizontalLayout->addWidget(annullaButton);
	verticalLayout->addLayout(horizontalLayout);

	connect(annullaButton, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(okButton, SIGNAL(clicked(bool)), this, SLOT(slSvuota()));
	connect(okButton, SIGNAL(clicked(bool)), this, SLOT(close()));

}

void confermaWindow::slSvuota()
{
	b->svuota();
}

