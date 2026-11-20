/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Partie.hpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe Partie. Cette classe represente une partie d'echecs,
gere le joueur courant, les deplacements de pieces et les differentes
positions de depart. Elle interagit avec la classe Echiquier pour manipuler
le plateau de jeu.
*/
#pragma once
#include "Echiquier.hpp"

namespace modele {

    class Partie {
    public:
        Partie();

        void nouvellePartie();
        void nouvellePartieClassique();
        void nouvellePartieTours();
        void nouvellePartieCavaliers();
        void preparerNouvellePartie();

        bool partieTerminee();
        bool jouerCoup(Position d, Position a);

        Couleur getJoueurCourant() const;
        Echiquier& getEchiquier();
        const Echiquier& getEchiquier() const;

    private:
        Echiquier echiquier_;
        Couleur joueurCourant_;
    };

}