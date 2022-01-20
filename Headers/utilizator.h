//
// Created by Ioan on 11/27/2021.
//

#ifndef PROIECT_OOP_UTILIZATOR_H
#define PROIECT_OOP_UTILIZATOR_H

#include <iostream>
template <typename T>
class utilizator;

template <typename T>
std::ostream& operator<<(std::ostream& o, const utilizator<T>& user);

template <typename T>
class utilizator {
    std::string nume;
    T varsta;
    std::string locatie;
    std::string studii;
public:
    utilizator(const std::string &nume, T varsta, const std::string &locatie, const std::string &studii);
    void exist(T u);
    friend std::ostream &operator<< <>(std::ostream &os, const utilizator<T> &utilizator);
};

class varsta_invalid : public std::runtime_error {
public:
    varsta_invalid() : std::runtime_error("Utilizatorul este minor"){}
};

#endif //PROIECT_OOP_UTILIZATOR_H
