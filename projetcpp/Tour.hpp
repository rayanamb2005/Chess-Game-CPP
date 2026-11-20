/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Tour.hpp
Travail : PROJET
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
        Tour(Couleur c);

        bool mouvementValide(Position d, Position a) override;
        
    };
}
#endif