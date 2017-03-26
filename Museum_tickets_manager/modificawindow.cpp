#include "modificawindow.h"

modificaWindow::modificaWindow(listaBiglietti* x, QWidget* parent): QDialog(parent), b(x)
{
	setWindowTitle("Modifica biglietto");
	resize(717, 707);;
	setModal(true);
	verticalLayout_14= new QVBoxLayout(this);
	verticalLayout_14->setContentsMargins(100, -1, 100, -1);


	horizontalLayout = new QHBoxLayout();

	horizontalLayout->setContentsMargins(-1, -1, -1, 50);
	verticalLayout = new QVBoxLayout();
	verticalLayout->setContentsMargins(-1, -1, 30, -1);
	verticalLayout_4 = new QVBoxLayout();
	verticalLayout_4->setContentsMargins(-1, 30, -1, 30);
	idLabel = new QLabel("ID", this);
	idLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_4->addWidget(idLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	idEdit = new QLineEdit(this);
	verticalLayout_4->addWidget(idEdit);

	verticalLayout->addLayout(verticalLayout_4);

	verticalLayout_5 = new QVBoxLayout();
	verticalLayout_5->setContentsMargins(-1, 0, -1, 44);

	pBaseLabel = new QLabel("Prezzo base", this);
	pBaseLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_5->addWidget(pBaseLabel, 0, Qt::AlignBottom);

	pBaseSpin = new QDoubleSpinBox(this);
	verticalLayout_5->addWidget(pBaseSpin);

	modPBaseButton = new QPushButton("Modifica prezzo base", this);
	verticalLayout_5->addWidget(modPBaseButton);

	verticalLayout->addLayout(verticalLayout_5);

	verticalLayout_6 = new QVBoxLayout();
	verticalLayout_6->setContentsMargins(-1, -1, -1, 56);

	etaLabel = new QLabel("Età", this);
	etaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_6->addWidget(etaLabel, 0, Qt::AlignBottom);


	etaSpin = new QSpinBox(this);
	verticalLayout_6->addWidget(etaSpin);

	modEtaButton = new QPushButton("Modifica età", this);
	verticalLayout_6->addWidget(modEtaButton);

	verticalLayout->addLayout(verticalLayout_6);

	verticalLayout_7 = new QVBoxLayout();
	verticalLayout_7->setContentsMargins(-1, -1, -1, 50);

	alaLabel = new QLabel("Ala", this);
	alaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_7->addWidget(alaLabel, 0, Qt::AlignBottom);

	alaSpin = new QSpinBox(this);
	alaSpin->setMinimum(1);
	verticalLayout_7->addWidget(alaSpin);

	modAlaButton = new QPushButton("Modifica ala", this);
	verticalLayout_7->addWidget(modAlaButton);
	verticalLayout->addLayout(verticalLayout_7);

	verticalLayout_8 = new QVBoxLayout();
	dataLabel = new QLabel("Data", this);
	dataLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_8->addWidget(dataLabel, 0, Qt::AlignBottom);

	dataDate = new QDateEdit(this);
	dataDate->setDate(QDate::currentDate());
	verticalLayout_8->addWidget(dataDate);

	modDataButton = new QPushButton("Modifica data", this);
	verticalLayout_8->addWidget(modDataButton);

	verticalLayout->addLayout(verticalLayout_8);

	horizontalLayout->addLayout(verticalLayout);

	verticalLayout_2 = new QVBoxLayout();
	verticalLayout_2->setContentsMargins(30, -1, -1, -1);
	verticalLayout_15 = new QVBoxLayout();
	verticalLayout_15->setContentsMargins(-1, 35, -1, 30);

	tipoLabel = new QLabel("Tipo", this);
	tipoLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_15->addWidget(tipoLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	tipoCombo = new QComboBox(this);
	verticalLayout_15->addWidget(tipoCombo);

	verticalLayout_2->addLayout(verticalLayout_15);

	verticalLayout_9 = new QVBoxLayout();
	verticalLayout_9->setContentsMargins(-1, -1, -1, 44);

	rFissaLabel = new QLabel("Riduzione fissa", this);
	rFissaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_9->addWidget(rFissaLabel, 0, Qt::AlignBottom);


	rFissaSpin = new QDoubleSpinBox(this);
	verticalLayout_9->addWidget(rFissaSpin);

	modRFissaButton = new QPushButton("Modifica riduzione fissa", this);
	verticalLayout_9->addWidget(modRFissaButton);

	verticalLayout_2->addLayout(verticalLayout_9);

	verticalLayout_10 = new QVBoxLayout();
	verticalLayout_10->setContentsMargins(-1, -1, -1, 56);

	rVarLabel = new QLabel("Riduzione variabile (%)", this);
	rVarLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_10->addWidget(rVarLabel, 0, Qt::AlignBottom);

	rVarSpin = new QDoubleSpinBox(this);
	verticalLayout_10->addWidget(rVarSpin);

	modRVarButton = new QPushButton("Modifica riduzione variabile", this);
	verticalLayout_10->addWidget(modRVarButton);

	verticalLayout_2->addLayout(verticalLayout_10);

	verticalLayout_11 = new QVBoxLayout();
	verticalLayout_11->setContentsMargins(-1, -1, -1, 50);

	accLabel = new QLabel("Accompagnatore", this);
	accLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_11->addWidget(accLabel, 0, Qt::AlignBottom);

	accCheck = new QCheckBox(this);
	accCheck->setEnabled(false);
	verticalLayout_11->addWidget(accCheck, 0, Qt::AlignHCenter);

	modAccButton = new QPushButton("Modifica accompagnatore", this);
	verticalLayout_11->addWidget(modAccButton);

	verticalLayout_2->addLayout(verticalLayout_11);

	verticalLayout_13 = new QVBoxLayout();
	verticalLayout_12 = new QVBoxLayout();

	pTotLabel = new QLabel("Prezzo totale", this);
	pTotLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_12->addWidget(pTotLabel, 0, Qt::AlignBottom);

	pTotEdit = new QLineEdit(this);
	pTotEdit->setReadOnly(true);
	verticalLayout_12->addWidget(pTotEdit);


	verticalLayout_13->addLayout(verticalLayout_12);

	risLabel = new QLabel("Risultato", this);
	risLabel->setAlignment(Qt::AlignCenter);
	verticalLayout_13->addWidget(risLabel);

	verticalLayout_13->addWidget(risLabel, 0, Qt::AlignBottom);

	risEdit = new QLineEdit(this);
	verticalLayout_13->addWidget(risEdit);

	verticalLayout_2->addLayout(verticalLayout_13);


	horizontalLayout->addLayout(verticalLayout_2);


	verticalLayout_14->addLayout(horizontalLayout);



	annullaButton = new QPushButton("Indietro", this);
	verticalLayout_14->addWidget(annullaButton);

	QWidget::setTabOrder(idEdit, pBaseSpin);
	QWidget::setTabOrder(pBaseSpin, modPBaseButton);
	QWidget::setTabOrder(modPBaseButton, etaSpin);
	QWidget::setTabOrder(etaSpin, modEtaButton);
	QWidget::setTabOrder(modEtaButton, alaSpin);
	QWidget::setTabOrder(alaSpin, modAlaButton);
	QWidget::setTabOrder(modAlaButton, dataDate);
	QWidget::setTabOrder(dataDate, modDataButton);
	QWidget::setTabOrder(modDataButton, rFissaSpin);
	QWidget::setTabOrder(rFissaSpin, modRFissaButton);
	QWidget::setTabOrder(modRFissaButton, rVarSpin);
	QWidget::setTabOrder(rVarSpin, modRVarButton);
	QWidget::setTabOrder(modRVarButton, accCheck);
	QWidget::setTabOrder(accCheck, modAccButton);
	QWidget::setTabOrder(modAccButton, annullaButton);


	tipoCombo->insertItem(0, "Ordinario");
	tipoCombo->insertItem(1, "Bambini");
	tipoCombo->insertItem(2, "Disabili");
	connect(this, SIGNAL(rejected()), parent, SIGNAL(sigAggiornaTutti()));
	connect(annullaButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(idEdit, SIGNAL(editingFinished()), this, SLOT(slVisualizza()));
	connect(modPBaseButton, SIGNAL(clicked(bool)), this, SLOT(slModPBase()));
	connect(modEtaButton, SIGNAL(clicked(bool)), this, SLOT(slModEta()));
	connect(modAlaButton, SIGNAL(clicked(bool)), this, SLOT(slModAla()));
	connect(modDataButton, SIGNAL(clicked(bool)), this, SLOT(slModData()));
	connect(modRFissaButton, SIGNAL(clicked(bool)), this, SLOT(slModRFissa()));
	connect(modRVarButton, SIGNAL(clicked(bool)), this, SLOT(slModRVar()));
	connect(modAccButton, SIGNAL(clicked(bool)), this, SLOT(slModAcc()));
	connect(this, SIGNAL(sigAggPTot(const biglietto*)), this, SLOT(slAggPTot(const biglietto*)));

}

void modificaWindow::slVisualizza()
{
	biglietto* bo=b->restituisciBiglietto(idEdit->text());
	if (bo==0)
		risEdit->setText("Biglietto non trovato");
	else
	{
		pBaseSpin->setValue(bo->getPrezzoBase());
		etaSpin->setValue(bo->getEta());
		alaSpin->setValue(bo->getAla());
		dataDate->setDate(bo->getData());
		if (listaBiglietti::ordinario(bo))
		{
			tipoCombo->setCurrentIndex(0);
			rFissaSpin->setEnabled(false);
			rVarSpin->setEnabled(false);
			accCheck->setEnabled(false);
			modRFissaButton->setEnabled(false);
			modRVarButton->setEnabled(false);
			modAccButton->setEnabled(false);
		}
		if (listaBiglietti::bambini(bo))
		{
			ridottoBambini* bo1=static_cast<ridottoBambini*>(bo);
			tipoCombo->setCurrentIndex(1);
			rFissaSpin->setEnabled(true);
			rVarSpin->setEnabled(true);
			accCheck->setEnabled(false);
			modRFissaButton->setEnabled(true);
			modRVarButton->setEnabled(true);
			rFissaSpin->setValue(bo1->getRiduzioneFissa());
			rVarSpin->setValue(bo1->getRiduzioneVariabile());
			modAccButton->setEnabled(false);
		}

		if (listaBiglietti::disabili(bo))
		{
			ridottoDisabili* bo1=static_cast<ridottoDisabili*>(bo);
			tipoCombo->setCurrentIndex(2);
			rFissaSpin->setEnabled(true);
			accCheck->setEnabled(true);
			rFissaSpin->setValue(bo1->getRiduzioneFissa());
			accCheck->setChecked(bo1->getAccompagnatore());
			modRVarButton->setEnabled(false);
			rVarSpin->setEnabled(false);
			modAccButton->setEnabled(true);
		}
		pTotEdit->setText(QString::number(bo->calcolaPrezzo(), 'f', 2)+"€");
		risEdit->setText("Biglietto visualizzato");
	}
}

bool modificaWindow::checkOk() const
{
	if (b->restituisciBiglietto(idEdit->text())!=0)
		return true;
	return false;
}

void modificaWindow::slModPBase()
{
	if (checkOk())
	{
		biglietto* bo=b->restituisciBiglietto(idEdit->text());
		bo->setPrezzoBase(pBaseSpin->value());
		risEdit->setText("Modificato prezzo base");
		emit sigAggPTot(bo);

	}
	else
		risEdit->setText("Biglietto non presente");
}

void modificaWindow::slModEta()
{
	if (checkOk())
	{
		biglietto* bo=b->restituisciBiglietto(idEdit->text());
		int eta=etaSpin->value();
		try
		{
			if (listaBiglietti::bambini(bo) && eta>static_cast<ridottoBambini*>(bo)->getSogliaEta())
				throw 1;
		}
		catch(int)
		{
			QMessageBox::critical(this,"Errore","Età non adatta ad un bambino!");
			return;
		}

		bo->setEta(etaSpin->value());
		risEdit->setText("Modificata età");
		emit sigAggPTot(bo);
	}
	else
		risEdit->setText("Biglietto non presente");
}

void modificaWindow::slModAla()
{
	if (checkOk())
	{
		(b->restituisciBiglietto(idEdit->text()))->setAla(alaSpin->value());
		risEdit->setText("Modificata ala");
	}
	else
		risEdit->setText("Biglietto non presente");
}

void modificaWindow::slModData()
{
	if (checkOk())
	{
		(b->restituisciBiglietto(idEdit->text()))->setData(dataDate->date());
		risEdit->setText("Modificata data");
	}
	else
		risEdit->setText("Biglietto non presente");
}

void modificaWindow::slModRFissa()
{
	if (checkOk())
	{
		biglietto* b1=b->restituisciBiglietto(idEdit->text());
		if (listaBiglietti::bambini(b1))
		{
			ridottoBambini* b2=static_cast<ridottoBambini*>(b1);
			b2->setRiduzioneFissa(rFissaSpin->value());
		}
		if (listaBiglietti::disabili(b1))
		{
			ridottoDisabili* b2=static_cast<ridottoDisabili*>(b1);
			b2->setRiduzioneFissa(rFissaSpin->value());
		}
		risEdit->setText("Modificata riduzione fissa");
		emit sigAggPTot(b1);
	}
	else
		risEdit->setText("Biglietto non presente");
}

void modificaWindow::slModRVar()
{
	if (checkOk())
	{
		biglietto* b1=b->restituisciBiglietto(idEdit->text());
		if (listaBiglietti::bambini(b1))
		{
			ridottoBambini* b2=static_cast<ridottoBambini*>(b1);
			b2->setRiduzioneVariabile(rVarSpin->value());
		}
		risEdit->setText("Modificata riduzione variabile");
		emit sigAggPTot(b1);
	}
	else
		risEdit->setText("Biglietto non presente");
}

void modificaWindow::slModAcc()
{
	if (checkOk())
	{
		biglietto* b1=b->restituisciBiglietto(idEdit->text());
		if (listaBiglietti::disabili(b1))
		{
			ridottoDisabili* b2=static_cast<ridottoDisabili*>(b1);
			b2->setAccompagnatore(accCheck->isChecked());
		}
		risEdit->setText("Modificato stato accompagnatore");
	}
	else
		risEdit->setText("Biglietto non presente");
}

void modificaWindow::slAggPTot(const biglietto * bo)
{
	pTotEdit->setText(QString::number(bo->calcolaPrezzo(), 'f', 2)+"€");
}
