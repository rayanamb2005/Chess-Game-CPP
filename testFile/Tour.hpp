/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Tour.hpp
Travail : TRAVAIL_PRATIQUE 6
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe Tour. Cette classe definit les mouvements de la tour en ligne droite,
horizontalement ou verticalement.
*/

#ifndef TOUR_HPP
#define TOUR_HPP

#include "Piece.hpp"

namespace modele {
    class Tour : public Piece {
    public:
        Tour(Couleur c) : Piece(c) {}

        bool mouvementValide(Position d, Position a) override {
            return ((d.ligne == a.ligne || d.colonne == a.colonne) 
                && !(Piece::estMemePiece(d,a))) ;
        }
    };
}
#endif