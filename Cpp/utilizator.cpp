//
// Created by Ioan on 11/27/2021.
//

#include "../Headers/utilizator.h"

template <typename T>
utilizator<T>::utilizator(const std::string &nume, T varsta, const std::string &locatie, const std::string &studii) : nume(nume), varsta(varsta), locatie(locatie),studii(studii) {}

template <typename T>
std::ostream &operator<<(std::ostream &os, const utilizator<T> &utilizator) {
    os << "nume: " << utilizator.nume << " varsta: " << utilizator.varsta << " locatie: " << utilizator.locatie << " studii: " << utilizator.studii << "\n";
    return os;
}
template <typename T>
void utilizator<T>::exist(T u){
    u = 18;
    if(varsta > u) // u este varsta minima
        std::cout << "Avem utilizator " << "\n";
    else
        throw varsta_invalid();
}

template class utilizator<int>;
template class utilizator<unsigned int>;
template
std::ostream& operator<< <>(std::ostream& o, const utilizator<int>& x);

