//
// Created by Ioan on 11/28/2021.
//

#include "../Headers/mesaj.h"
#include "../Headers/data_invalida.h"

int mesaj::id_max = 1;

mesaj::mesaj(const std::vector<utilizator<int>> &autorMesaj, int data, int ora, const std::string &tipMesaj, const std::vector<reactie> &reactii) : autor_mesaj(autorMesaj), data(data), ora(ora), tip_mesaj(tipMesaj), reactii(reactii),
    id(id_max){
    id_max++;
    if (data > 31)
        throw data_prea_mare();
    if (ora > 23)
        throw ora_invalida();
}

std::ostream &operator<<(std::ostream &os, const mesaj &mesaj) {
    mesaj.afisare(os);
    return os;
}

void mesaj::adauga(const reactie &reaction) {
    reactii.push_back(reaction);
}

void mesaj::send() const {
    std::cout << "mesaj send\n";
    for(int i = 0; i < ora; ++i)
        std::cout << '\a';

}

mesaj::~mesaj() {
    std::cout << "Destructor mesaj\n";
}

std::shared_ptr<mesaj> mesaj::clone() const {
    return std::make_shared<mesaj>(*this);
}

void mesaj::afisare(std::ostream &os) const{
    const auto& mesaj = *this;
    os << "id: " << id << "trimis de: ";
    for(const auto & utilizator: mesaj.autor_mesaj)
        os << utilizator;
    os << " data: " << mesaj.data << " ora: " << mesaj.ora << " tip_mesaj: " << mesaj.tip_mesaj << " reactii: ";
    for(const auto & reactie : mesaj.reactii)
        os << reactie;
}

mesaj::mesaj(const mesaj &copie) : id(id_max), reactii(copie.reactii), tip_mesaj(copie.tip_mesaj), ora(copie.ora), data(copie.data), autor_mesaj(copie.autor_mesaj) {
    id_max++;
}

int mesaj::getIdMax() {
    return id_max;
}
template class
utilizator<int>;