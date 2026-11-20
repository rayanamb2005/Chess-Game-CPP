/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Position.hpp
Travail : TRAVAIL_PRATIQUE 6
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe Position. Cette classe represente une position sur l'echiquier avec une
ligne et une colonne.
*/

#ifndef POSITION_HPP
#define POSITION_HPP

namespace modele {
    class Position {
    public:
        Position(int l, int c) : ligne(l), colonne(c) {}

        int ligne;
        int colonne;
    };

}
#endif