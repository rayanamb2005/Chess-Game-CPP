/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Piece.hpp
Travail : TRAVAIL_PRATIQUE 6
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe abstraite Piece. Cette classe definit les attributs communs aux pieces
du jeu d'echecs ainsi que l'interface pour valider les mouvements.
*/

#ifndef PIECE_HPP
#define PIECE_HPP

#include "Position.hpp"

namespace modele {
    enum class Couleur { Blanc, Noir };

    class Piece {
    public:
        Piece(Couleur c) : couleur(c) {}
        Couleur getCouleur() const { return couleur; }

        virtual ~Piece() = default;
        bool estMemePiece(Position d, Position a) 
        {
            return (d.ligne == a.ligne && d.colonne == a.colonne);
        }
        
        virtual bool mouvementValide(Position d, Position a) = 0;

    protected:
        Couleur couleur;
    };
}
#endif