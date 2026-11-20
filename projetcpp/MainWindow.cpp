/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : MainWindow.cpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Implementation de la classe MainWindow. Cette classe gere l'interface graphique du jeu d'echecs,
incluant la creation de l'echiquier, l'affichage des pieces, la gestion des clics utilisateurs
et les interactions avec le modele du jeu.
*/

#include "MainWindow.hpp"
#include <memory>
#include <QString>
#include <QFont>
#include <QLabel>
#include <QMessageBox>
#include <QTimer>
namespace vue {
    const QString caseBeige = "background-color: burlywood; color: black;";
    const QString caseMarron = "background-color: saddlebrown; color: black;";

    const int tailleFenetre = 700;
    const int demiCases = nbrCase / 2;
    const int colonneControleDepart = 0;
    const int nLignesControle = 1;

    const int ligneControleNouvellePartie = nbrCase + 1;

    const int indicePositionClassique = 0;
    const int indicePositionAvecTours = 1;
    const int indicePositionAvecCavaliers = 2;

    void MainWindow::resetSelection() {
        caseSelectionnee_ = false;
        ligneDepart_ = -1;
        colonneDepart_ = -1;
    }

    MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent),
        widgetCentral_(new QWidget(this)),
        dispositionGrille_(new QGridLayout())
    {
        setWindowTitle("Jeu d'echec");
        resize(tailleFenetre, tailleFenetre);

        widgetCentral_->setLayout(dispositionGrille_);
        setCentralWidget(widgetCentral_);
        dispositionGrille_->setSpacing(0);

        labelTour_ = new QLabel(this);
        labelTour_->setAlignment(Qt::AlignCenter);
        labelTour_->setStyleSheet("font-weight: bold; font-size: 18px;");

        dispositionGrille_->addWidget(labelTour_, nbrCase + 2, 0, 1, nbrCase + 1);

        creerEchiquier();
        creerMenuNouvellePartie();
        afficherEchiquier();
        mettreAJourTour();
    }

    MainWindow::~MainWindow() {}

    QString MainWindow::styleCase(int ligne, int colonne) const
    {
        if ((ligne + colonne) % 2 == 0) {
            return caseBeige;
        }
        else {
            return caseMarron;
        }
    }

    QString MainWindow::styleCaseAvecPiece(int ligne, int colonne) const
    {
        QString chaineStyle = styleCase(ligne, colonne);

        modele::Piece* piece = 
            partie_.getEchiquier().getPiece(modele::Position(ligne, colonne));

        if (piece != nullptr) {
            if (piece->getCouleur() == modele::Couleur::Blanc) {
                chaineStyle += " color: white;";
            }
            else {
                chaineStyle += " color: black;";
            }
        }

        return chaineStyle;
    }

    void MainWindow::mettreAJourTour()
    {
        if (partie_.getJoueurCourant() == modele::Couleur::Blanc) {
            labelTour_->setText("Tour : Blanc");
        }
        else {
            labelTour_->setText("Tour : Noir");
        }
    }

    void MainWindow::creerEchiquier()
    {
        const int tailleCase = 80;
        const int taillePolice = 40;


        for (int j = 0; j < nbrCase; j++) {
            QLabel* label = new QLabel(QString(QChar('A' + j)));
            label->setAlignment(Qt::AlignCenter);
            label->setStyleSheet("font-weight: bold; font-size: 16px;");
            dispositionGrille_->addWidget(label, 0, j + 1);
        }

        for (int i = 0; i < nbrCase; i++) {
            QLabel* label = new QLabel(QString::number(nbrCase - i));
            label->setAlignment(Qt::AlignCenter);
            label->setStyleSheet("font-weight: bold; font-size: 16px;");
            dispositionGrille_->addWidget(label, i + 1, 0);
        }

        for (int i = 0; i < nbrCase; i++) {
            for (int j = 0; j < nbrCase; j++) {
                boutonCases_[i][j] = new QPushButton(this);
                boutonCases_[i][j]->setFixedSize(tailleCase, tailleCase);
                QFont police = boutonCases_[i][j]->font();
                police.setPointSize(taillePolice);
                police.setBold(true);
                boutonCases_[i][j]->setFont(police);


                boutonCases_[i][j]->setStyleSheet(styleCase(i, j));

                boutonCases_[i][j]->setProperty("ligne", i);
                boutonCases_[i][j]->setProperty("colonne", j);
                connect(boutonCases_[i][j], &QPushButton::clicked, 
                    this, &MainWindow::caseCliquee);
                dispositionGrille_->addWidget(boutonCases_[i][j], i + 1, j + 1);
            }
        }
    }
  
    void MainWindow::creerMenuNouvellePartie()
    {
        listePositionsDepart_ = new QComboBox(this);

        listePositionsDepart_->addItem("Position classique");
        listePositionsDepart_->addItem("Position avec tours");
        listePositionsDepart_->addItem("Position avec cavaliers");

        boutonNouvellePartie_ = new QPushButton("Nouvelle partie", this);
        boutonNouvellePartie_->setStyleSheet("font-weight: bold;");

        connect(boutonNouvellePartie_, &QPushButton::clicked,
            this, &MainWindow::demarrerNouvellePartie);

        dispositionGrille_->addWidget(listePositionsDepart_,
            ligneControleNouvellePartie, colonneControleDepart,
            nLignesControle, demiCases);
        dispositionGrille_->addWidget(boutonNouvellePartie_, 
            ligneControleNouvellePartie, demiCases, 1, demiCases + 1);
    }
   
    void MainWindow::afficherCase(int ligne, int colonne)
    {
        modele::Piece* piece = 
            partie_.getEchiquier().getPiece(modele::Position(ligne, colonne));

        if (piece == nullptr) {
            boutonCases_[ligne][colonne]->setText("");
            boutonCases_[ligne][colonne]->setStyleSheet(styleCase(ligne, colonne));
            return;
        }

        QString chaineSymbole;

        if (dynamic_cast<modele::Roi*>(piece)) {
            chaineSymbole = "R";
        }
        else if (dynamic_cast<modele::Tour*>(piece)) {
            chaineSymbole = "T";
        }
        else if (dynamic_cast<modele::Cavalier*>(piece)) {
            chaineSymbole = "C";
        }

        QString chaineStyle = styleCase(ligne, colonne);

        if (piece->getCouleur() == modele::Couleur::Blanc) {
            chaineStyle += " color: white;";
        }
        else {
            chaineStyle += " color: black;";
        }

        boutonCases_[ligne][colonne]->setText(chaineSymbole);
        boutonCases_[ligne][colonne]->setStyleSheet(chaineStyle);
    }

    void MainWindow::afficherEchiquier()
    {
        for (int i = 0; i < nbrCase; i++) {
            for (int j = 0; j < nbrCase; j++) {
                afficherCase(i, j);
            }
        }
    }

    void MainWindow::reinitialiserCouleurs()
    {
        for (int i = 0; i < nbrCase; i++) {
            for (int j = 0; j < nbrCase; j++) {
                boutonCases_[i][j]->setStyleSheet(styleCaseAvecPiece(i, j));
            }
        }
    }

    void MainWindow::afficherErreurCase(int ligne, int colonne)
    {
        boutonCases_[ligne][colonne]->setStyleSheet
            ("background-color: red; color: white;");
        QTimer::singleShot(500, this, [this, ligne, colonne]() {
            boutonCases_[ligne][colonne]->setStyleSheet
                (styleCaseAvecPiece(ligne, colonne));
        });
    }

    void MainWindow::caseCliquee()
    {
        QPushButton* bouton = qobject_cast<QPushButton*>(sender());
        if (bouton == nullptr) {
            return;
        }

        int ligne = bouton->property("ligne").toInt();
        int colonne = bouton->property("colonne").toInt();

        if (!caseSelectionnee_) {
            if (boutonCases_[ligne][colonne]->text().isEmpty()) {
                return;
            }

            caseSelectionnee_ = true;
            ligneDepart_ = ligne;
            colonneDepart_ = colonne;

            reinitialiserCouleurs();
            boutonCases_[ligne][colonne]->setStyleSheet
                ("background-color: khaki; color: green;");
            return;
        }

        modele::Position depart(ligneDepart_, colonneDepart_);
        modele::Position arrivee(ligne, colonne);

        bool deplacementValide = partie_.jouerCoup(depart, arrivee);

        if (deplacementValide) {
            afficherEchiquier();
            reinitialiserCouleurs();
            mettreAJourTour();

            if (partie_.partieTerminee()) {
                QMessageBox::information(this, "Fin de partie",
                    "La partie est terminee.");
            }
            else if (partie_.getEchiquier().roiEnDanger(modele::Couleur::Blanc)) {
                QMessageBox::information(this, "Echec",
                    "Le roi blanc est en echec.");
            }
            else if (partie_.getEchiquier().roiEnDanger(modele::Couleur::Noir)) {
                QMessageBox::information(this, "Echec",
                    "Le roi noir est en echec.");
            }
        }
        else {
            reinitialiserCouleurs();
            afficherErreurCase(ligne, colonne);
        }

        resetSelection();
    }

    void MainWindow::demarrerNouvellePartie()
    {
        indicePositionCourante_ = listePositionsDepart_->currentIndex();
        demarrerPartieSelonIndice(indicePositionCourante_);
    }

    void MainWindow::demarrerPartieSelonIndice(int indicePosition)
    {
        resetSelection();

        switch (indicePosition) {
        case indicePositionClassique:
            partie_.nouvellePartieClassique();
            break;

        case indicePositionAvecTours:
            partie_.nouvellePartieTours();
            break;

        case indicePositionAvecCavaliers:
            partie_.nouvellePartieCavaliers();
            break;

        default:
            partie_.nouvellePartieClassique();
            break;
        }

        afficherEchiquier();
        mettreAJourTour();
    }

}


