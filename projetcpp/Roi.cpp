/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Roi.cpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Implementation de la classe Roi. Cette classe gere les deplacements du roi
(une case dans toutes les directions) et controle le nombre de rois crees
grace a un compteur statique et une exception.
*/

#include "Roi.hpp"
#include <stdexcept>
#include <cmath>
#include "TropDeRoisException.hpp"

namespace modele {

int Roi::nRois = 0;

Roi::Roi(Couleur c) : Piece(c) {
    if (nRois >= 2)
        throw modele::TropDeRoisException();
    nRois++;
}

Roi::~Roi() {
    nRois--;
}

bool Roi::mouvementValide(Position d, Position a) {
    int dl = abs(a.ligne - d.ligne);
    int dc = abs(a.colonne - d.colonne);
    return dl <= 1 && dc <= 1 && !(Piece::estMemePiece(d, a));
}

}