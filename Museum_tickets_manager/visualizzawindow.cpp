#include "visualizzawindow.h"

visualizzaWindow::visualizzaWindow(listaBiglietti* x, QWidget* parent): QDialog(parent), b(x)
{
	setWindowTitle("Visualizza lista");
	setModal(true);
	resize(1550, 552);

	verticalLayout = new QVBoxLayout(this);
	verticalLayout->setContentsMargins(50, 25, 50, 25);
	visualizzaPlain = new QPlainTextEdit(this);
	visualizzaPlain->setObjectName(QStringLiteral("visualizzaPlain"));
	visualizzaPlain->setReadOnly(true);
	verticalLayout->addWidget(visualizzaPlain);
	annullaButton = new QPushButton("Indietro", this);
	annullaButton->setObjectName(QStringLiteral("annullaButton"));
	verticalLayout->addWidget(annullaButton);
	connect(annullaButton, SIGNAL(clicked(bool)), this, SLOT(close()));
	visualizzaLista();

}



void visualizzaWindow::visualizzaLista() const
{
	visualizzaPlain->clear();
	if (b->vuota())
		visualizzaPlain->appendPlainText("Lista vuota!");
	else
	{
		for (listaBiglietti::iteratore i=b->begin(); i!=b->end(); ++i)
		{
		biglietto* bo=(*b)[i];
		QString biglietto="■ID:"+bo->getId() +"            Prezzo base:"+QString::number(bo->getPrezzoBase(),'f', 2)+ "€            Età: "+QString::number(bo->getEta())+" anni            Ala: "+QString::number(bo->getAla())+ "            Data: "+QString::number(bo->getData().day())+'/'+QString::number(bo->getData().month())+'/'+QString::number(bo->getData().year())+ "            Prezzo tot:"+QString::number(bo->calcolaPrezzo(),'f', 2)+"€	";

		if (listaBiglietti::ordinario(bo))
			biglietto=biglietto+"Tipo: Ordinario";
		else
			if (listaBiglietti::bambini(bo))
			{
				ridottoBambini* b1=static_cast<ridottoBambini*>(bo);
				biglietto=biglietto+ "Tipo: Ridotto bambini	"+ "Riduzione fissa: "+QString::number(b1->getRiduzioneFissa(),'f', 2)+"€        Riduzione variabile: "+QString::number(b1->getRiduzioneVariabile(), 'f', 2)+ "€";
			}
			else
				if (listaBiglietti::disabili(bo))
				{
					ridottoDisabili* b1=static_cast<ridottoDisabili*>(bo);
					biglietto=biglietto+ "Tipo: Ridotto disabili	"+ "Riduzione fissa: "+QString::number(b1->getRiduzioneFissa(),'f', 2)+"€			Accompagnatore: ";
				 if (b1->getAccompagnatore())
					biglietto=biglietto+"Sì";
				 else
					biglietto=biglietto+"No";
				}
		visualizzaPlain->appendPlainText(biglietto);

		}

	}
}

