//
// Created by Ioan on 11/27/2021.
//

#ifndef PROIECT_OOP_UTILIZATOR_H
#define PROIECT_OOP_UTILIZATOR_H

#include <iostream>

class utilizator {
    std::string nume;
    int varsta;
    std::string locatie;
    std::string studii;
public:
    utilizator(const std::string &nume, int varsta, const std::string &locatie, const std::string &studii);

    friend std::ostream &operator<<(std::ostream &os, const utilizator &utilizator);
};

#endif //PROIECT_OOP_UTILIZATOR_H
