//
// Created by Ioan on 11/28/2021.
//

#include "../Headers/postare.h"

postare::postare(const std::vector<utilizator<unsigned int>> &autorMesaj, int data, int ora,
                 const std::vector<reactie> &reactii) : mesaj(autorMesaj, data, ora, "post", reactii) {}

void postare::send() const {
    //mesaj::send();
    std::cout << "postare send\n";
    for(int i = 0; i < 2; ++i)
        std::cout << '\a' << '\a';
}

postare::~postare() {
    std::cout << "Destructor colind\n";
}

std::shared_ptr<mesaj> postare::clone() const {
    return std::make_shared<postare>(*this);
}

void postare::afisare(std::ostream &os) const {
    os << "**" << ora << "**";
    os << "_" << data << "_";
    os << "<u>" << nr << "</u>" << ", ";
    //mesaj::afisare(os);
}
