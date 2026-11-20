/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : Partie.cpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Implementation de la classe Partie. Cette classe permet d'initialiser
les differentes configurations de debut de partie, de gerer les coups
joues par les joueurs, d'alterner les tours et de determiner si la
partie est terminee.
*/

#include "Partie.hpp"
#include "Roi.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"

namespace modele {
    const int nLignesEchiquier = 8;
    const int nColonnesEchiquier = 8;

    const int ligneBlanc = 0;
    const int ligneNoir = nLignesEchiquier - 1;

    const int colonneTourGauche = 0;
    const int colonneRoiBlanc = 1;
    const int colonnePieceDroiteBlanc = 2;

    const int colonnePieceGaucheNoir = 5;
    const int colonneRoiNoir = 6;
    const int colonneTourDroite = 7;

    void viderEchiquier(Echiquier& echiquier)
    {
        for (int i = 0; i < nLignesEchiquier; i++) {
            for (int j = 0; j < nColonnesEchiquier; j++) {
                echiquier.setPiece({ i, j }, nullptr);
            }
        }
    }

    Partie::Partie() {
        nouvellePartie();
    }

    void Partie::nouvellePartie()
    {
        nouvellePartieClassique();
    }

    void Partie::preparerNouvellePartie()
    {
        viderEchiquier(echiquier_);

        echiquier_.setPiece(
            { ligneBlanc, colonneRoiBlanc },
            std::make_unique<Roi>(Couleur::Blanc)
        );

        echiquier_.setPiece(
            { ligneNoir, colonneRoiNoir },
            std::make_unique<Roi>(Couleur::Noir)
        );

        joueurCourant_ = Couleur::Blanc;
    }

    void Partie::nouvellePartieClassique()
    {
        preparerNouvellePartie();

        echiquier_.setPiece(
            { ligneBlanc, colonneTourGauche },
            std::make_unique<Tour>(Couleur::Blanc)
        );

        echiquier_.setPiece(
            { ligneBlanc, colonnePieceDroiteBlanc },
            std::make_unique<Cavalier>(Couleur::Blanc)
        );

        echiquier_.setPiece(
            { ligneNoir, colonnePieceGaucheNoir },
            std::make_unique<Cavalier>(Couleur::Noir)
        );

        echiquier_.setPiece(
            { ligneNoir, colonneTourDroite },
            std::make_unique<Tour>(Couleur::Noir)
        );
    }

    void Partie::nouvellePartieTours()
    {
        preparerNouvellePartie();

        echiquier_.setPiece(
            { ligneBlanc, colonneTourGauche },
            std::make_unique<Tour>(Couleur::Blanc)
        );

        echiquier_.setPiece(
            { ligneBlanc, colonnePieceDroiteBlanc },
            std::make_unique<Tour>(Couleur::Blanc)
        );

        echiquier_.setPiece(
            { ligneNoir, colonnePieceGaucheNoir },
            std::make_unique<Tour>(Couleur::Noir)
        );

        echiquier_.setPiece(
            { ligneNoir, colonneTourDroite },
            std::make_unique<Tour>(Couleur::Noir)
        );
    }

    void Partie::nouvellePartieCavaliers()
    {
        preparerNouvellePartie();

        echiquier_.setPiece(
            { ligneBlanc, colonneTourGauche },
            std::make_unique<Cavalier>(Couleur::Blanc)
        );

        echiquier_.setPiece(
            { ligneBlanc, colonnePieceDroiteBlanc },
            std::make_unique<Cavalier>(Couleur::Blanc)
        );

        echiquier_.setPiece(
            { ligneNoir, colonnePieceGaucheNoir },
            std::make_unique<Cavalier>(Couleur::Noir)
        );

        echiquier_.setPiece(
            { ligneNoir, colonneTourDroite },
            std::make_unique<Cavalier>(Couleur::Noir)
        );
    }

    bool Partie::jouerCoup(Position d, Position a) {
        Piece* p = echiquier_.getPiece(d);

        if (!p)
            return false;

        if (p->getCouleur() != joueurCourant_)
            return false;

        if (!echiquier_.coupValide(d, a))
            return false;

        echiquier_.deplacer(d, a);

        joueurCourant_ = (joueurCourant_ == Couleur::Blanc)
            ? Couleur::Noir : Couleur::Blanc;

        return true;
    }

    Couleur Partie::getJoueurCourant() const
    {
        return joueurCourant_;
    }

    Echiquier& Partie::getEchiquier()
    {
        return echiquier_;
    }

    const Echiquier& Partie::getEchiquier() const
    {
        return echiquier_;
    }

    bool Partie::partieTerminee() 
    {
        for (int ligneDepart = 0; ligneDepart < nLignesEchiquier; ligneDepart++) {
            for (int colonneDepart = 0; colonneDepart < nColonnesEchiquier; 
                colonneDepart++) {

                Position depart(ligneDepart, colonneDepart);
                Piece* piece = echiquier_.getPiece(depart);

                if (piece == nullptr) {
                    continue;
                }

                if (piece->getCouleur() != joueurCourant_) {
                    continue;
                }
                for (int ligneArrivee = 0; ligneArrivee < nLignesEchiquier; 
                    ligneArrivee++) {
                    for (int colonneArrivee = 0; colonneArrivee < 
                        nColonnesEchiquier; colonneArrivee++) {

                        Position arrivee(ligneArrivee, colonneArrivee);

                        if (echiquier_.coupValide(depart, arrivee)) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
}