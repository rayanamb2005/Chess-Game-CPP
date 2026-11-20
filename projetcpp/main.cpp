/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : main.cpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Point d'entree du programme. Ce fichier initialise l'application Qt et lance
l'interface graphique du jeu d'echecs en instanciant la fenetre principale.
*/

#include "MainWindow.hpp"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    vue::MainWindow fenetre;
    fenetre.show();

    return app.exec();
}
  