//
// Created by Ioan on 11/27/2021.
//

#include "../Headers/utilizator.h"


utilizator::utilizator(const std::string &nume, int varsta, const std::string &locatie, const std::string &studii) : nume(nume), varsta(varsta), locatie(locatie),studii(studii) {}

std::ostream &operator<<(std::ostream &os, const utilizator &utilizator) {
    os << "nume: " << utilizator.nume << " varsta: " << utilizator.varsta << " locatie: " << utilizator.locatie << " studii: " << utilizator.studii << "\n";
    return os;
}
