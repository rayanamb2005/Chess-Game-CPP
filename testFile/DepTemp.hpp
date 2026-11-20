/*
Autheur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : DepTemp.hpp
Travail : TRAVAIL_PRATIQUE 6
Section # : SECTION 5
�quipe # : 5_16
Description :
D�claration de la classe DeplacementTemporaire. Cette classe permet d�effectuer un d�placement
temporaire sur l��chiquier afin de tester une situation (ex : v�rifier la validit� d�un coup),
puis de restaurer automatiquement l��tat initial gr�ce � son destructeur.
*/

#ifndef DEPTEMP_HPP
#define DEPTEMP_HPP

#include "Echiquier.hpp"

namespace modele {
    class DeplacementTemporaire {
    public:
        DeplacementTemporaire(Echiquier& e, Position d, Position a)
            : echiquier_(e), depart(d), arrivee(a)
        {
            pieceCapturee = std::move(echiquier_.getCase(arrivee));
            echiquier_.getCase(arrivee) = std::move(echiquier_.getCase(depart));
        }
        ~DeplacementTemporaire() {
            echiquier_.getCase(depart) = std::move(echiquier_.getCase(arrivee));
            echiquier_.getCase(arrivee) = std::move(pieceCapturee);
        }
    private:
        Echiquier& echiquier_;
        Position depart;
        Position arrivee;
        std::unique_ptr<Piece> pieceCapturee;
    };

}
#endif