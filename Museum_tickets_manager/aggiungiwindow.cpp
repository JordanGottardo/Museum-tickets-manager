#include "aggiungiwindow.h"

aggiungiWindow::aggiungiWindow(listaBiglietti* x, QWidget* parent): QDialog(parent), b(x)
{
	setWindowTitle("Inserimento biglietto");
	setModal(true);
	resize(894, 771);
	verticalLayout = new QVBoxLayout(this);
	verticalLayout->setContentsMargins(250, 50, 250, 50);
	idLabel = new QLabel("ID", this);
	idLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(idLabel);

	idEdit = new QLineEdit(this);
	verticalLayout->addWidget(idEdit);

	pBaseLabel = new QLabel("Prezzo base", this);
	pBaseLabel->setAlignment(Qt::AlignCenter);

	verticalLayout->addWidget(pBaseLabel);

	pBaseSpin = new QDoubleSpinBox(this);
	verticalLayout->addWidget(pBaseSpin);

	etaLabel = new QLabel("Età", this);
	etaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(etaLabel);

	etaSpin = new QSpinBox(this);
	verticalLayout->addWidget(etaSpin);

	alaLabel = new QLabel("Ala", this);
	alaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(alaLabel);

	alaSpin = new QSpinBox(this);
	alaSpin->setMinimum(1);
	verticalLayout->addWidget(alaSpin);

	dataLabel = new QLabel("Data", this);
	dataLabel->setAlignment(Qt::AlignCenter);

	verticalLayout->addWidget(dataLabel);

	dataDate = new QDateEdit(this);
	dataDate->setDate(QDate::currentDate());
	verticalLayout->addWidget(dataDate);

	tipoLabel = new QLabel("Tipo", this);
	tipoLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(tipoLabel);

	tipoCombo = new QComboBox(this);
	verticalLayout->addWidget(tipoCombo);

	rFissaLabel = new QLabel("Riduzione fissa", this);
	rFissaLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(rFissaLabel);

	rFissaSpin = new QDoubleSpinBox(this);
	verticalLayout->addWidget(rFissaSpin);

	rVarLabel = new QLabel("Riduzione variabile (%)", this);
	rVarLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(rVarLabel);

	rVarSpin = new QDoubleSpinBox(this);
	verticalLayout->addWidget(rVarSpin);

	accLabel = new QLabel("Accompagnatore", this);
	accLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(accLabel);

	accCheck = new QCheckBox(this);
	verticalLayout->addWidget(accCheck, 0, Qt::AlignHCenter);

	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	verticalLayout->addItem(horizontalSpacer);

	horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	verticalLayout->addItem(horizontalSpacer_2);

	insButton = new QPushButton("Inserisci biglietto", this);
	verticalLayout->addWidget(insButton);

	codaRadio = new QRadioButton("Coda", this);
	verticalLayout->addWidget(codaRadio, 0, Qt::AlignHCenter);

	testaRadio = new QRadioButton("Testa", this);
	verticalLayout->addWidget(testaRadio, 0, Qt::AlignHCenter);

	horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	verticalLayout->addItem(horizontalSpacer_3);

	pTotLabel = new QLabel("Prezzo totale", this);
	pTotLabel->setAlignment(Qt::AlignCenter);
	verticalLayout->addWidget(pTotLabel);

	pTotEdit = new QLineEdit(this);
	pTotEdit->setReadOnly(true);
	verticalLayout->addWidget(pTotEdit);

	horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	verticalLayout->addItem(horizontalSpacer_4);

	horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	verticalLayout->addItem(horizontalSpacer_5);

	annullaButton = new QPushButton("Indietro", this);
	verticalLayout->addWidget(annullaButton);

	QWidget::setTabOrder(idEdit, pBaseSpin);
	QWidget::setTabOrder(pBaseSpin, etaSpin);
	QWidget::setTabOrder(etaSpin, alaSpin);
	QWidget::setTabOrder(alaSpin, dataDate);
	QWidget::setTabOrder(dataDate, tipoCombo);
	QWidget::setTabOrder(tipoCombo, rFissaSpin);
	QWidget::setTabOrder(rFissaSpin, rVarSpin);
	QWidget::setTabOrder(rVarSpin, accCheck);
	QWidget::setTabOrder(accCheck, codaRadio);
	QWidget::setTabOrder(codaRadio, testaRadio);
	QWidget::setTabOrder(testaRadio, insButton);
	QWidget::setTabOrder(insButton, annullaButton);
	QWidget::setTabOrder(annullaButton, pTotEdit);
	tipoCombo->insertItem(0, "Ordinario");
	tipoCombo->insertItem(1, "Bambini");
	tipoCombo->insertItem(2, "Disabili");

	rFissaSpin->setEnabled(false);
	rVarSpin->setEnabled(false);
	accCheck->setEnabled(false);
	codaRadio->setChecked(true);

	connect(this, SIGNAL(rejected()), parent, SIGNAL(sigAggiornaTutti()));
	connect(annullaButton, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(insButton, SIGNAL(clicked(bool)), this, SLOT(aggiungiBiglietto()));
	connect(tipoCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(cambiatoTipo(int)));


}

	void aggiungiWindow::aggiungiBiglietto()
	{
		bool coda;
		if (codaRadio->isChecked())
			coda=1;
		else
			coda=0;

		QString id=idEdit->text();
		if (id=="")
			QMessageBox::critical(this,"Errore","L'ID non può essere vuoto!");
		else
		{
			double pBase=pBaseSpin->value();
			int eta=etaSpin->value();
			int ala=alaSpin->value();
			QDate data=dataDate->date();
			biglietto* bo;
			if (tipoCombo->currentIndex()==0) //ordinario
			{
				bo=new bigliettoOrdinario(id, pBase, eta, ala, data);
			}
			else
				if (tipoCombo->currentIndex()==1) //bambini
				{
					try
					{
						if (eta>ridottoBambini::getSogliaEta())
							throw 1;
					}
					catch(int)
					{
						QMessageBox::critical(this,"Errore","Età non adatta ad un bambino! Scegliere un'altra tipologia di biglietto");
						return;
					}
					double rFissa=rFissaSpin->value();
					double rVar=rVarSpin->value();
					bo=new ridottoBambini(id, pBase, eta, ala, data, rFissa, rVar);


				}
			else
			if (tipoCombo->currentIndex()==2) //disabili
			{
				double rFissa=rFissaSpin->value();
				bool acc=accCheck->isChecked();
				bo=new ridottoDisabili(id, pBase, eta, ala, data, rFissa, acc);
			}
			if (coda)
				b->pushBack(bo);
			else
				b->pushFront(bo);
			pTotEdit->setText(QString::number(bo->calcolaPrezzo(), 'f', 2)+"€");
		}
	}
	void aggiungiWindow::cambiatoTipo(int n)
	{
		if (n==0) //ordinario
		{
			rFissaSpin->setEnabled(false);
			rFissaSpin->setValue(0);
			rVarSpin->setEnabled(false);
			rVarSpin->setValue(0);
			accCheck->setEnabled(false);
			accCheck->setChecked(false);

		}
		else
			if (n==1) //bambini
			{
				rFissaSpin->setEnabled(true);
				rVarSpin->setEnabled(true);
				accCheck->setEnabled(false);
				accCheck->setChecked(false);
			}
			else //disabili
			{
				rFissaSpin->setEnabled(true);
				rVarSpin->setEnabled(false);
				accCheck->setEnabled(true);
			}
	}
