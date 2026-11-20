/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Echiquier.hpp
Travail : TRAVAIL_PRATIQUE 6
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe Echiquier. Cette classe represente le plateau de jeu sous forme de grille
8x8 et gere les pieces ainsi que leurs deplacements.
*/

#ifndef ECHIQUIER_HPP
#define ECHIQUIER_HPP

#include "Piece.hpp"
#include <memory>

namespace modele {
    class Echiquier {
        public:
            Echiquier();
            Piece* getPiece(Position p) const;
            void setPiece(Position p, std::unique_ptr<Piece> piece);
            bool deplacer(Position d, Position a);
            std::unique_ptr<Piece>& getCase(Position p);
            bool coupValide(Position d, Position a);
            bool roiEnDanger(Couleur couleur);

        private:
            std::unique_ptr<Piece> grille[8][8];
        };

}
#endif