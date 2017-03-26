#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

	setWindowTitle("Museum Tickets Manager");
	resize(924, 664);
	apriAction=new QAction(QIcon(":/Immagini/openFile.png"),tr("Apri"),this);
	salvaAction=new QAction(QIcon(":/Immagini/save.png"),"Salva",this);
	esciAction=new QAction(QIcon(":/Immagini/quit.png"),"Esci",this);


	centralWidget= new QWidget(this);
	verticalLayout = new QVBoxLayout(centralWidget);
	verticalLayout->setContentsMargins(250, 25, 250, 25);


	insButton= new QPushButton("Inserisci biglietti", centralWidget);
	verticalLayout->addWidget(insButton);

	togliButton= new QPushButton("Rimuovi biglietti", centralWidget);
	verticalLayout->addWidget(togliButton);

	modButton= new QPushButton("Modifica biglietti", centralWidget);
	verticalLayout->addWidget(modButton);

	visButton = new QPushButton("Visualizza lista", centralWidget);
	verticalLayout->addWidget(visButton);

	sogliaButton = new QPushButton("Modifica soglia età", centralWidget);
	verticalLayout->addWidget(sogliaButton);

	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	verticalLayout->addItem(horizontalSpacer);

	biglLabel = new QLabel("Numero biglietti emessi", centralWidget);
	verticalLayout->addWidget(biglLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	biglSpin = new QSpinBox(centralWidget);
	biglSpin->setReadOnly(true);
	verticalLayout->addWidget(biglSpin);




	alaLabel = new QLabel("Ala più redditizia", centralWidget);
	verticalLayout->addWidget(alaLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	alaSpin = new QSpinBox(centralWidget);
	alaSpin->setReadOnly(true);
	verticalLayout->addWidget(alaSpin);

	giorLabel = new QLabel("Giorno più redditizio", centralWidget);
	verticalLayout->addWidget(giorLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	giorEdit = new QLineEdit(centralWidget);
	giorEdit->setReadOnly(true);
	verticalLayout->addWidget(giorEdit, 0, Qt::AlignVCenter);

	guadLabel = new QLabel("Guadagno totale", centralWidget);
	verticalLayout->addWidget(guadLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	guadEdit = new QLineEdit(centralWidget);
	guadEdit->setReadOnly(true);
	verticalLayout->addWidget(guadEdit, 0, Qt::AlignVCenter);

	horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	verticalLayout->addItem(horizontalSpacer_2);

	fascButton = new QPushButton("Calcola guadagno fascia età", centralWidget);
	verticalLayout->addWidget(fascButton);

	iniLabel = new QLabel("Inizio fascia", centralWidget);
	verticalLayout->addWidget(iniLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	iniSpin = new QSpinBox(centralWidget);
	verticalLayout->addWidget(iniSpin);

	finLabel = new QLabel("Fine fascia", centralWidget);
	verticalLayout->addWidget(finLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	finSpin = new QSpinBox(centralWidget);
	verticalLayout->addWidget(finSpin);

	fascLabel = new QLabel("Guadagno fascia età", centralWidget);
	verticalLayout->addWidget(fascLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

	fascEdit = new QLineEdit(centralWidget);
	fascEdit->setReadOnly(true);
	verticalLayout->addWidget(fascEdit);

	escButton = new QPushButton("Esci", centralWidget);
	verticalLayout->addWidget(escButton);

	setCentralWidget(centralWidget);


	QWidget::setTabOrder(insButton, togliButton);
	QWidget::setTabOrder(togliButton, modButton);
	QWidget::setTabOrder(modButton, visButton);
	QWidget::setTabOrder(visButton, sogliaButton);
	QWidget::setTabOrder(sogliaButton, fascButton);
	QWidget::setTabOrder(fascButton, iniSpin);
	QWidget::setTabOrder(iniSpin, finSpin);
	QWidget::setTabOrder(finSpin, escButton);
	////////COLORI
	//setStyleSheet("background:rgb(112, 128, 144);");
	//insButton->setStyleSheet("background:rgb(198, 226, 255);");
	menuBar = new QMenuBar(this);
	menuBar->setGeometry(0, 0, 1271, 21);
	menuFile = new QMenu("File", menuBar);
	setMenuBar(menuBar);

	menuBar->addAction(menuFile->menuAction());
	menuFile->addAction(apriAction);
	menuFile->addAction(salvaAction);
	menuFile->addAction(esciAction);


	connect(insButton, SIGNAL(clicked(bool)), this, SLOT(slAggiungi()));
	connect(togliButton, SIGNAL(clicked(bool)), this, SLOT(slTogli()));
	connect(modButton, SIGNAL(clicked(bool)), this, SLOT(slModifica()));
	connect(visButton, SIGNAL(clicked(bool)), this, SLOT(slVisualizza()));
	connect(escButton, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

	connect(fascButton, SIGNAL(clicked(bool)), this, SLOT(slFascia()));

	connect(sogliaButton, SIGNAL(clicked(bool)), this, SLOT(slSoglia()));
	connect(apriAction, SIGNAL(triggered(bool)), this, SLOT(slApriFile()));
	connect(salvaAction, SIGNAL(triggered(bool)), this, SLOT(slSalva()));
	connect(esciAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

	connect(this, SIGNAL(sigAggiornaTutti()), this, SLOT(slAla()));
	connect(this, SIGNAL(sigAggiornaTutti()), this, SLOT(slBigliettiEmessi()));
	connect(this, SIGNAL(sigAggiornaTutti()), this, SLOT(slGiorno()));
	connect(this, SIGNAL(sigAggiornaTutti()), this, SLOT(slGuadagnoTot()));
	connect(this, SIGNAL(sigAggiornaTutti()), this, SLOT(slFascia()));
}

void MainWindow::slAggiungi()
{
	aggiungiWindow* aggWindow= new aggiungiWindow(&b, this);
	aggWindow->show();
}

void MainWindow::slTogli()
{
	rimuoviWindow* rimWindow=new rimuoviWindow(&b, this);
	rimWindow->show();
}

void MainWindow::slModifica()
{
	modificaWindow* modWindow=new modificaWindow(&b, this);
	modWindow->show();
}

void MainWindow::slVisualizza()
{
	visualizzaWindow* visWindow=new visualizzaWindow(&b, this);
	visWindow->show();
}

void MainWindow::slBigliettiEmessi()
{
	biglSpin->setValue(b.bigliettiEmessiTot());
}

void MainWindow::slGiorno()
{
	if (b.vuota())
		giorEdit->setText("Lista vuota!");
	else
	{
		switch(b.giornoPiuRedditizio())
		{
		case(1):
			giorEdit->setText("Lunedì");
			break;
		case(2):
			giorEdit->setText("Martedì");
			break;
		case(3):
			giorEdit->setText("Mercoledì");
			break;
		case(4):
			giorEdit->setText("Giovedì");
			break;
		case(5):
			giorEdit->setText("Venerdì");
			break;
		case(6):
			giorEdit->setText("Sabato");
			break;
		case(7):
			giorEdit->setText("Domenica");
			break;
		default:
			giorEdit->setText("Lista vuota");
		}
	}
}

void MainWindow::slAla()
{
	if (b.vuota())
		alaSpin->setValue(0);
	else
		alaSpin->setValue(b.alaPiuRedditizia());
}

void MainWindow::slGuadagnoTot()
{
	if (b.vuota())
		guadEdit->setText("Lista vuota!");
	else
		guadEdit->setText(QString::number(b.redditoTotale(), 'f', 2)+"€");
}

void MainWindow::slFascia()
{
	if (b.vuota())
		fascEdit->setText("Lista vuota!");
	else
	{
		int inizio=iniSpin->value(), fine=finSpin->value();
		fascEdit->setText(QString::number(b.redditoFasciaEta(inizio, fine), 'f', 2)+"€");
	}
}

void MainWindow::slSoglia()
{
	sogliaWindow* sogWindow=new sogliaWindow(this);
	sogWindow->show();
}




void MainWindow::slApriFile()
{
	QString nomeFile;
	nomeFile=QDir::currentPath()+"/dati.xml";
	QFile file(nomeFile);
	QXmlStreamReader xmlReader(&file);
	if(file.open(QFile::ReadOnly)|| QFile::Text) //apro il file
	{
		b.svuota();
		while(!xmlReader.atEnd() && !xmlReader.hasError())
		{
			QXmlStreamReader::TokenType token=xmlReader.readNext();
			if(token==QXmlStreamReader::StartDocument)
				continue;
			if(xmlReader.isStartElement())
			{
				QString id="";
				double prezzoBase=0;
				int eta=0;
				int ala=0;
				QDate data;
				if(xmlReader.name()=="Ordinario")
				{
					while(!(xmlReader.tokenType()==xmlReader.EndElement))
					{
						if(xmlReader.name()=="Id")
							id=xmlReader.readElementText();
						if(xmlReader.name()=="PrezzoBase")
						{
							QString sPrezzoBase=xmlReader.readElementText();
							prezzoBase=sPrezzoBase.toDouble();
						}
						if(xmlReader.name()=="Eta")
						{
							QString sEta=xmlReader.readElementText();
							eta=sEta.toInt();
						}

						if(xmlReader.name()=="Ala")
						{
							QString sAla=xmlReader.readElementText();
							ala=sAla.toInt();
						}

						if(xmlReader.name()=="Data")
						{
							QString sData=xmlReader.readElementText();
							data=QDate::fromString(sData, "dd.MM.yyyy");
						}
						xmlReader.readNext();
					}
					bigliettoOrdinario* bo=new bigliettoOrdinario(id, prezzoBase, eta, ala, data);
					b.pushBack(bo);
				}

				if(xmlReader.name()=="Bambini")
				{
					double rFissa=0;
					double rVar=0;
					while(!(xmlReader.tokenType()==xmlReader.EndElement))
					{
						if(xmlReader.name()=="Id")
							id=xmlReader.readElementText();
						if(xmlReader.name()=="PrezzoBase")
						{
							QString sPrezzoBase=xmlReader.readElementText();
							prezzoBase=sPrezzoBase.toDouble();
						}
						if(xmlReader.name()=="Eta")
						{
							QString sEta=xmlReader.readElementText();
							eta=sEta.toInt();
						}

						if(xmlReader.name()=="Ala")
						{
							QString sAla=xmlReader.readElementText();
							ala=sAla.toInt();
						}

						if(xmlReader.name()=="Data")
						{
							QString sData=xmlReader.readElementText();
							data=QDate::fromString(sData, "dd.MM.yyyy");
						}

						if(xmlReader.name()=="RiduzioneFissa")
						{
							QString sRFissa=xmlReader.readElementText();
							rFissa=sRFissa.toDouble();
						}
						if(xmlReader.name()=="RiduzioneVariabile")
						{
							QString sRVar=xmlReader.readElementText();
							rFissa=sRVar.toDouble();
						}
						xmlReader.readNext();
					}
					ridottoBambini* bo=new ridottoBambini(id, prezzoBase, eta, ala, data, rFissa, rVar);
					b.pushBack(bo);
				}

				if(xmlReader.name()=="Disabili")
				{
					double rFissa=0;
					bool acc=0;
					while(!(xmlReader.tokenType()==xmlReader.EndElement))
					{
						if(xmlReader.name()=="Id")
							id=xmlReader.readElementText();
						if(xmlReader.name()=="PrezzoBase")
						{
							QString sPrezzoBase=xmlReader.readElementText();
							prezzoBase=sPrezzoBase.toDouble();
						}
						if(xmlReader.name()=="Eta")
						{
							QString sEta=xmlReader.readElementText();
							eta=sEta.toInt();
						}

						if(xmlReader.name()=="Ala")
						{
							QString sAla=xmlReader.readElementText();
							ala=sAla.toInt();
						}

						if(xmlReader.name()=="Data")
						{
							QString sData=xmlReader.readElementText();
							data=QDate::fromString(sData, "dd.MM.yyyy");
						}

						if(xmlReader.name()=="RiduzioneFissa")
						{
							QString sRFissa=xmlReader.readElementText();
							rFissa=sRFissa.toDouble();
						}
						if (xmlReader.name()=="Accompagnatore")
						{
							QString sAcc=xmlReader.readElementText();
							if (sAcc=="1")
								acc=1;
						}
						xmlReader.readNext();
					}
						ridottoDisabili* bo=new ridottoDisabili(id, prezzoBase, eta, ala, data, rFissa, acc);
						b.pushBack(bo);
				}
			}
		}
	}
	emit sigAggiornaTutti();
}

void MainWindow::slSalva() //aggiungere controllo file vuoto
{
	QString nomeFile;
	nomeFile=QDir::currentPath()+"/dati.xml";
	QFile file(nomeFile);
	if (file.open(QIODevice::WriteOnly))
		slSalvaXml(file);

}

void MainWindow::slSalvaXml(QFile& file)
{
	QXmlStreamWriter xmlWriter;
	xmlWriter.setDevice(&file);
	xmlWriter.setAutoFormatting(true);
	xmlWriter.writeStartDocument();
	xmlWriter.writeStartElement("MuseumTicketsManager");

	for (listaBiglietti::iteratore i=b.begin(); i!=b.end(); ++i)
	{
		biglietto* bo=b[i];
		QString id=bo->getId();
		double pBase=bo->getPrezzoBase();
		int eta=bo->getEta();
		int ala=bo->getAla();
		QDate data=bo->getData();
		if (listaBiglietti::ordinario(bo))
		{
			xmlWriter.writeStartElement("Ordinario");
			xmlWriter.writeTextElement("Id",id);
			xmlWriter.writeTextElement("PrezzoBase",QString::number(pBase, 'f', 2));
			xmlWriter.writeTextElement("Eta", QString::number(eta));
			xmlWriter.writeTextElement("Ala", QString::number(ala));
			xmlWriter.writeTextElement("Data", data.toString("dd.MM.yyyy"));
			xmlWriter.writeEndElement();
		}

		if (listaBiglietti::bambini(bo))
		{
			ridottoBambini* b1=dynamic_cast<ridottoBambini*>(bo);
			double rFissa=b1->getRiduzioneFissa();
			double rVar=b1->getRiduzioneVariabile();
			xmlWriter.writeStartElement("Bambini");
			xmlWriter.writeTextElement("Id",id);
			xmlWriter.writeTextElement("PrezzoBase",QString::number(pBase, 'f', 2));
			xmlWriter.writeTextElement("Eta", QString::number(eta));
			xmlWriter.writeTextElement("Ala", QString::number(ala));
			xmlWriter.writeTextElement("Data", data.toString("dd.MM.yyyy"));
			xmlWriter.writeTextElement("RiduzioneFissa", QString::number(rFissa, 'f', 2));
			xmlWriter.writeTextElement("RiduzioneVariabile", QString::number(rVar, 'f', 2));
			xmlWriter.writeEndElement();
		}

		if (listaBiglietti::disabili(bo))
		{
			ridottoDisabili* b1=dynamic_cast<ridottoDisabili*>(bo);
			double rFissa=b1->getRiduzioneFissa();
			bool acc=b1->getAccompagnatore();
			QString sAcc="0";
			if (acc)
				sAcc="1";
			xmlWriter.writeStartElement("Disabili");
			xmlWriter.writeTextElement("Id",id);
			xmlWriter.writeTextElement("PrezzoBase",QString::number(pBase, 'f', 2));
			xmlWriter.writeTextElement("Eta", QString::number(eta));
			xmlWriter.writeTextElement("Ala", QString::number(ala));
			xmlWriter.writeTextElement("Data", data.toString("dd.MM.yyyy"));
			xmlWriter.writeTextElement("RiduzioneFissa", QString::number(rFissa, 'f', 2));
			xmlWriter.writeTextElement("Accompagnatore", sAcc);
			xmlWriter.writeEndElement();
		}
	}
	xmlWriter.writeEndElement();
	xmlWriter.writeEndDocument();
	file.close();
}


