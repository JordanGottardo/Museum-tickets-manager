#include "sogliawindow.h"

sogliaWindow::sogliaWindow(QWidget* parent): QDialog(parent)
{
	setWindowTitle("Modifica soglia età");
	setModal(true);
	resize(918, 235);

	verticalLayout = new QVBoxLayout(this);
	verticalLayout->setContentsMargins(150, 30, 150, 30);
	sogliaLabel = new QLabel("Inserisci la nuova soglia d'età per il calcolo del prezzo dei biglietti ridotti per bambini. Attuale: "+QString::number(ridottoBambini::getSogliaEta())+" anni", this);

	verticalLayout->addWidget(sogliaLabel, 0, Qt::AlignHCenter);
	sogliaSpin = new QSpinBox(this);
	verticalLayout->addWidget(sogliaSpin);
	horizontalLayout = new QHBoxLayout();
	okButton = new QPushButton("Ok", this);
	horizontalLayout->addWidget(okButton);
	annullaButton = new QPushButton("Annulla", this);
	horizontalLayout->addWidget(annullaButton);
	verticalLayout->addLayout(horizontalLayout);

	connect(okButton, SIGNAL(clicked(bool)), this, SLOT(slModSoglia()));
	connect(okButton, SIGNAL(clicked(bool)), parent, SIGNAL(sigAggiornaTutti()));
	connect(okButton, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(annullaButton, SIGNAL(clicked(bool)), this, SLOT(close()));

}

void sogliaWindow::slModSoglia()
{
	ridottoBambini::setSogliaEta(sogliaSpin->value());
}


