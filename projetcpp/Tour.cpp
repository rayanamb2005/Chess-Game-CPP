/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Tour.cpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe Tour. Cette classe definit les mouvements de la tour en ligne droite,
horizontalement ou verticalement.
*/

#include "Tour.hpp"

using namespace modele;

Tour::Tour(Couleur c) : Piece(c) {}

bool Tour::mouvementValide(Position d, Position a) {
    return ((d.ligne == a.ligne || d.colonne == a.colonne)
    && !(Piece::estMemePiece(d, a)));
}

