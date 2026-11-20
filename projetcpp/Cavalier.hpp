/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Cavalier.hpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe Cavalier. Cette classe definit les mouvements du cavalier en forme de L.
*/

#ifndef CAVALIER_HPP
#define CAVALIER_HPP
#include "Piece.hpp"
#include <cmath>

namespace modele {

    class Cavalier : public Piece {
    public:
        Cavalier(Couleur c);
        bool mouvementValide(Position d, Position a) override;
    };

}
#endif