/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : mainModele.cpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Fonction de test du modele du jeu d'echecs. Permet de verifier les mouvements des pieces,
les deplacements sur l'echiquier et la gestion des exceptions.
*/

#include <iostream>
#include "Roi.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Echiquier.hpp"
#include "DepTemp.hpp"
#include "Partie.hpp"

using namespace modele;

int mainModele() {

    {
        Roi r(Couleur::Blanc);
        std::cout << r.mouvementValide({0,0}, {1,1}) << std::endl;
        std::cout << r.mouvementValide({0,0}, {2,2}) << std::endl;
    }

    {
        Echiquier e;
        e.setPiece({0,0}, std::make_unique<Tour>(Couleur::Blanc));
        std::cout << e.deplacer({0,0}, {0,5}) << std::endl;
        std::cout << e.deplacer({0,5}, {1,6}) << std::endl;
    }

    try {
        Roi r1(Couleur::Blanc);
        Roi r2(Couleur::Noir);
        Roi r3(Couleur::Blanc);
    }
    catch (const std::exception& e) {
        std::cout << "Exception attrapee: " << e.what() << std::endl;
    }

    {
        Echiquier e2;
        e2.setPiece({0,0}, std::make_unique<Tour>(Couleur::Blanc));
        {
            DeplacementTemporaire temp(e2, {0,0}, {0,5});
            std::cout << (e2.getPiece({0,5}) != nullptr) << std::endl;
        }
        std::cout << (e2.getPiece({0,0}) != nullptr) << std::endl;
    }

    {
        Partie partie;
        std::cout << (partie.getJoueurCourant() == Couleur::Blanc) << std::endl;
        std::cout << partie.jouerCoup({0,0}, {0,5}) << std::endl;
        std::cout << (partie.getJoueurCourant() == Couleur::Noir) << std::endl;
        partie.nouvellePartieTours();
        partie.nouvellePartieCavaliers();
        std::cout << partie.jouerCoup({0,0}, {1,1}) << std::endl;
        std::cout << partie.partieTerminee() << std::endl;
        std::cout << (partie.getEchiquier().getPiece({0,0}) != nullptr) << std::endl;
    }

    return 0;
}