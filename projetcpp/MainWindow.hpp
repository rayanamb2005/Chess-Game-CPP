/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : MainWindow.hpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe MainWindow. Cette classe represente la fenetre principale du jeu d'echecs,
gere l'interface graphique et les interactions avec le modele Echiquier.
*/

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "Roi.hpp"
#include "Cavalier.hpp"
#include "Echiquier.hpp"
#include "DepTemp.hpp"
#include "Tour.hpp"
#include "Partie.hpp"
#include "TropDeRoisException.hpp"
#include "Position.hpp"

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>
#include <QWidget>

namespace vue{
    const int nbrCase = 8;

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

    private slots:
        void caseCliquee();
        void demarrerNouvellePartie();

    private:
        QWidget* widgetCentral_;

        QGridLayout* dispositionGrille_;

        QLabel* labelTour_;

        QPushButton* boutonCases_[nbrCase][nbrCase];
        QPushButton* boutonNouvellePartie_;

        QComboBox* listePositionsDepart_;
        
        QString styleCase(int ligne, int colonne) const;
        QString styleCaseAvecPiece(int ligne, int colonne) const;

        modele::Partie partie_;

        bool caseSelectionnee_ = false;

        int ligneDepart_ = -1;
        int colonneDepart_ = -1;
        int indicePositionCourante_ = 0;


        void mettreAJourTour();
        void resetSelection();
        void creerMenuNouvellePartie();
        void demarrerPartieSelonIndice(int indicePosition);
        void reinitialiserCouleurs();
        void afficherCase(int ligne, int colonne);
        void afficherEchiquier();
        void afficherErreurCase(int ligne, int colonne);
        void creerEchiquier();
    };
}
#endif;