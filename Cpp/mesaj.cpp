//
// Created by Ioan on 11/28/2021.
//

#include "../Headers/mesaj.h"

mesaj::mesaj(const std::vector<utilizator> &autorMesaj, int data, int ora, const std::string &tipMesaj,
             const std::vector<reactie> &reactii) : autor_mesaj(autorMesaj), data(data), ora(ora), tip_mesaj(tipMesaj), reactii(reactii) {}

std::ostream &operator<<(std::ostream &os, const mesaj &mesaj) {
    os << "trimis de: ";
    for(const auto & utilizator : mesaj.autor_mesaj)
        os << utilizator;
    os << " data: " << mesaj.data << " ora: " << mesaj.ora << " tip_mesaj: " << mesaj.tip_mesaj << " reactii: ";
    for(const auto & reactie : mesaj.reactii)
        os << reactie;
    return os;
}

void mesaj::adauga(const reactie &reaction) {
    reactii.push_back(reaction);
}
