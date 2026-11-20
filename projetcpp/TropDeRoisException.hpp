/*
Auteur : Anta Rayana Mbaye et Mohamed Lamine Gueye
Fichier : TropDeRoisException.hpp
Travail : PROJET
Section # : SECTION 5
Equipe # : 5_16
Description :
Declaration de l'exception TropDeRoisException. Cette exception est lancee lorsqu'un nombre
invalide de rois est cree.
*/

#ifndef TROPDEROISEXCEPTION_HPP
#define TROPDEROISEXCEPTION_HPP

#include <stdexcept>

namespace modele
{
    class TropDeRoisException : public std::runtime_error {
    public:
        TropDeRoisException() : std::runtime_error("Trop de rois !") {}
    };
}
#endif