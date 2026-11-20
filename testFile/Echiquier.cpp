/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Echiquier.cpp
Travail : TRAVAIL_PRATIQUE 6
Section # : SECTION 5
Equipe # : 5_16
Description :
Implementation de la classe Echiquier. Cette classe initialise la grille du plateau, permet
d'acceder aux pieces, de les placer et de gerer les deplacements en respectant les regles de base.
*/

#include "Echiquier.hpp"
#include "Roi.hpp"
#include "DepTemp.hpp"

namespace modele {

    Echiquier::Echiquier() {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                grille[i][j] = nullptr;
    }

    Piece* Echiquier::getPiece(Position p) const {
        return grille[p.ligne][p.colonne].get();
    }

    void Echiquier::setPiece(Position p, std::unique_ptr<Piece> piece) {
        grille[p.ligne][p.colonne] = std::move(piece);
    }

    std::unique_ptr<Piece>& Echiquier::getCase(Position p) {
        return grille[p.ligne][p.colonne];
    }
    bool Echiquier::deplacer(Position d, Position a) {
        if (getPiece(d) == nullptr) {
            return false;
        }
        grille[a.ligne][a.colonne] = std::move(grille[d.ligne][d.colonne]);
        grille[d.ligne][d.colonne] = nullptr;

        return true;
    }

    bool Echiquier::coupValide(Position d, Position a) {
        Piece* p = getPiece(d);
        if (p == nullptr)
            return false;

        if (!p->mouvementValide(d, a))
            return false;

        Piece* pieceArrivee = getPiece(a);
        if (pieceArrivee != nullptr) {
            if (dynamic_cast<Roi*>(pieceArrivee)) {
                return false;
            }

            if (pieceArrivee->getCouleur() == p->getCouleur()) {
                return false;
            }
        }

        DeplacementTemporaire temp(*this, d, a);

        if (roiEnDanger(p->getCouleur()))
            return false;

        return true;
    }

    bool Echiquier::roiEnDanger(Couleur couleur) {
        Position roiPos(0,0);

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Piece* p = getPiece({i,j});
                if (p && dynamic_cast<Roi*>(p)) {
                    if (p->getCouleur() == couleur)
                        roiPos = {i,j};
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Piece* p = getPiece({i,j});
                if (p && p->getCouleur() != couleur) {
                    if (p->mouvementValide({i,j}, roiPos))
                        return true;
                }
            }
        }

        return false;
    }

}