/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Cavalier.cpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe Cavalier. Cette classe definit les mouvements du cavalier en forme de L.
*/

#include "Cavalier.hpp"

using namespace modele;

Cavalier::Cavalier(Couleur c) : Piece(c) {}

bool Cavalier::mouvementValide(Position d, Position a) {
    int dl = abs(a.ligne - d.ligne);
    int dc = abs(a.colonne - d.colonne);
    return ((dl == 2 && dc == 1) || (dl == 1 && dc == 2))
        && !(Piece::estMemePiece(d, a));
}