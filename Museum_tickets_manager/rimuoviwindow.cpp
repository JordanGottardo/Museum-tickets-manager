#include "rimuoviwindow.h"


rimuoviWindow::rimuoviWindow(listaBiglietti* x, QWidget* parent): QDialog(parent), b(x)
{
	setWindowTitle("Rimozione biglietto");
	resize(727, 585);
	setModal(true);

	verticalLayout_4 = new QVBoxLayout(this);
	verticalLayout_4->setContentsMargins(100, 20, 100, 30);
	horizontalLayout_7 = new QHBoxLayout();

	verticalLayout = new QVBoxLayout();
	verticalLayout->setContentsMargins(-1, 35, 30, 0);

	idRimLabel = new QLabel("ID", this);
	idRimLabel->setAlignment(Qt::AlignCenter);
	idRimLabel->setMaximumSize(QSize(16777215, 30));
	verticalLayout->addWidget(idRimLabel);

	idRimEdit = new QLineEdit(this);
	verticalLayout->addWidget(idRimEdit);

	rimButton = new QPushButton("Rimuovi biglietto da ID", this);
	verticalLayout->addWidget(rimButton);

	codTesButton = new QPushButton("Rimuovi coda/testa", this);
	verticalLayout->addWidget(codTesButton);

	verticalLayout_3 = new QVBoxLayout();
	verticalLayout_3->setSpacing(0);
	verticalLayout_3->setContentsMargins(-1, 0, -1, 200);

	codaRadio = new QRadioButton("Coda", this);
	verticalLayout_3->addWidget(codaRadio, 0, Qt::AlignHCenter|Qt::AlignTop);

	testaRadio = new QRadioButton("Testa", this);
	verticalLayout_3->addWidget(testaRadio, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	verticalLayout->addLayout(verticalLayout_3);

	svuotaButton = new QPushButton("Svuota lista", this);
	verticalLayout->addWidget(svuotaButton);

	risRimLabel = new QLabel("Risultato", this);
	risRimLabel->setMaximumSize(QSize(16777215, 30));
	risRimLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(risRimLabel);

	idRisEdit = new QLineEdit(this);
	idRisEdit->setReadOnly(true);
	verticalLayout->addWidget(idRisEdit);

	horizontalLayout_7->addLayout(verticalLayout);

	verticalLayout_2 = new QVBoxLayout();
	verticalLayout_2->setContentsMargins(30, 31, -1, 0);


	ultRimLabel = new QLabel("Ultimo biglietto rimosso", this);
	ultRimLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(ultRimLabel);

	idLabel = new QLabel("ID", this);
	idLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(idLabel);

	idEdit = new QLineEdit(this);
	idEdit->setReadOnly(true);
	verticalLayout_2->addWidget(idEdit);

	pBaseLabel = new QLabel("Prezzo base", this);
	pBaseLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(pBaseLabel);

	pBaseSpin = new QDoubleSpinBox(this);
	pBaseSpin->setReadOnly(true);
	verticalLayout_2->addWidget(pBaseSpin);

	etaLabel = new QLabel("Età", this);
	etaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(etaLabel);

	etaSpin = new QSpinBox(this);
	etaSpin->setReadOnly(true);
	verticalLayout_2->addWidget(etaSpin);

	alaLabel = new QLabel("Ala", this);
	alaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(alaLabel);

	alaSpin = new QSpinBox(this);
	alaSpin->setReadOnly(true);
	verticalLayout_2->addWidget(alaSpin);

	dataLabel = new QLabel("Data", this);
	dataLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(dataLabel);

	dataDate = new QDateEdit(this);
	dataDate->setReadOnly(true);
	verticalLayout_2->addWidget(dataDate);

	tipoLabel = new QLabel("Tipo", this);
	tipoLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(tipoLabel);

	tipoCombo = new QComboBox(this);
	verticalLayout_2->addWidget(tipoCombo);

	rFissaLabel = new QLabel("Riduzione fissa", this);
	rFissaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(rFissaLabel);

	rFissaSpin = new QDoubleSpinBox(this);
	rFissaSpin->setReadOnly(true);
	verticalLayout_2->addWidget(rFissaSpin);

	rVarLabel = new QLabel("Riduzione variabile (%)", this);
	rVarLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(rVarLabel);

	rVarSpin = new QDoubleSpinBox(this);
	rVarSpin->setReadOnly(true);
	verticalLayout_2->addWidget(rVarSpin);

	accLabel = new QLabel("Accompagnatore", this);
	accLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(accLabel);

	accCheck = new QCheckBox(this);
	accCheck->setEnabled(false);
	verticalLayout_2->addWidget(accCheck, 0, Qt::AlignHCenter);

	pTotLabel = new QLabel("Prezzo totale", this);
	pTotLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_2->addWidget(pTotLabel);

	pTotEdit = new QLineEdit(this);
	pTotEdit->setReadOnly(true);
	verticalLayout_2->addWidget(pTotEdit);

	horizontalLayout_7->addLayout(verticalLayout_2);
	verticalLayout_4->addLayout(horizontalLayout_7);

	annullaButton = new QPushButton("Indietro", this);
	verticalLayout_4->addWidget(annullaButton);

	codaRadio->setChecked(true);
	QWidget::setTabOrder(idRimEdit, rimButton);
	QWidget::setTabOrder(rimButton, codaRadio);
	QWidget::setTabOrder(codaRadio, testaRadio);
	QWidget::setTabOrder(testaRadio, codTesButton);
	QWidget::setTabOrder(codTesButton, svuotaButton);
	QWidget::setTabOrder(svuotaButton, annullaButton);

	tipoCombo->insertItem(0, "Ordinario");
	tipoCombo->insertItem(1, "Bambini");
	tipoCombo->insertItem(2, "Disabili");
	connect(rimButton, SIGNAL(clicked(bool)), this, SLOT(slRimuovi()));
	connect(this, SIGNAL(rejected()), parent, SIGNAL(sigAggiornaTutti()));
	connect(annullaButton, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(this, SIGNAL(sigModifica(biglietto*)), this, SLOT(slModificaUltimo(biglietto*)));
	connect(codTesButton, SIGNAL(clicked(bool)), this, SLOT(slCodaTesta()));
	connect(svuotaButton, SIGNAL(clicked(bool)), this, SLOT(slConfermaSvuota()));

}

void rimuoviWindow::slRimuovi()
{
	if (b->vuota())
		idRisEdit->setText("Lista vuota!");
	else
	{
		if (idRimEdit->text()=="")
			QMessageBox::critical(this,"Errore","L'ID non può essere vuoto!");
		else
		{
		biglietto* bo=b->togliBiglietto(idRimEdit->text());
		if (bo)
		{
			idRisEdit->setText("Biglietto ID:"+bo->getId()+" rimosso");
			emit sigModifica(bo);
		}
		else
			idRisEdit->setText("Biglietto non trovato!");
		}
	}
}

void rimuoviWindow::slModificaUltimo(biglietto * bo)
{
	//contratto: bo!=0

	idEdit->setText(bo->getId());
	pBaseSpin->setValue(bo->getPrezzoBase());
	etaSpin->setValue(bo->getEta());
	alaSpin->setValue(bo->getAla());
	dataDate->setDate(bo->getData());

	if (dynamic_cast<bigliettoOrdinario*>(bo))
	{
		tipoCombo->setCurrentIndex(0);
		rFissaSpin->setEnabled(false);
		rVarSpin->setEnabled(false);
	}
	else
		if (dynamic_cast<ridottoBambini*>(bo))
		{
			ridottoBambini* bo1=dynamic_cast<ridottoBambini*>(bo);
			tipoCombo->setCurrentIndex(1);
			rFissaSpin->setEnabled(true);
			rVarSpin->setEnabled(true);
			rFissaSpin->setValue(bo1->getRiduzioneFissa());
			rVarSpin->setValue(bo1->getRiduzioneVariabile());
		}
		else
			if (dynamic_cast<ridottoDisabili*>(bo))
			{
				ridottoDisabili* bo1=dynamic_cast<ridottoDisabili*>(bo);
				tipoCombo->setCurrentIndex(2);
				rFissaSpin->setEnabled(true);
				rFissaSpin->setValue(bo1->getRiduzioneFissa());
				accCheck->setChecked(bo1->getAccompagnatore());
			}

	pTotEdit->setText(QString::number(bo->calcolaPrezzo(), 'f', 2)+"€");
	delete bo;
}

void rimuoviWindow::slCodaTesta()
{
	if (b->vuota())
		idRisEdit->setText("Lista vuota!");
	else
	{
		biglietto* bo;
		if (codaRadio->isChecked())
		{
			bo=b->popBack();
			idRisEdit->setText("Rimosso biglietto dalla coda");
		}
		else
		{
			bo=b->popFront();
			idRisEdit->setText("Rimosso biglietto dalla testa");
		}
		emit sigModifica(bo);
	}
}

void rimuoviWindow::slConfermaSvuota()
{
	confermaWindow* confWindow=new confermaWindow(b, this);
	confWindow->show();
}




