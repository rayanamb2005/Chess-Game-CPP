/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Roi.hpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de la classe Roi heritant de la classe Piece. Cette classe definit
le comportement du roi aux echecs, notamment la validation de ses deplacements
et la gestion du nombre maximal de rois grace a un attribut statique.
*/

#ifndef ROI_HPP
#define ROI_HPP
#include "Piece.hpp"

namespace modele {

    class Roi : public Piece {
    public:
        Roi(Couleur c);
        ~Roi();

        bool mouvementValide(Position d, Position a) override;

    private:
        static int nRois;
        
    };
}
#endif