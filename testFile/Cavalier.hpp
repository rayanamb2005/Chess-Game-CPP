/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Cavalier.hpp
Travail : TRAVAIL_PRATIQUE 6
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
        Cavalier(Couleur c) : Piece(c) {}

        bool mouvementValide(Position d, Position a) override {
            int dl = abs(a.ligne - d.ligne);
            int dc = abs(a.colonne - d.colonne);
            return ((dl == 2 && dc == 1) || (dl == 1 && dc == 2) ) 
                && !(Piece::estMemePiece(d, a));
        }
    };

}
#endif