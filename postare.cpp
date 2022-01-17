//
// Created by Ioan on 11/28/2021.
//

#include "postare.h"

std::ostream &operator<<(std::ostream &os, const Style &postare) {
    switch(postare) {
        case Style::bold:
            os << Style::bold << "Bold";
            break;
        case Style::italic:
            os << Style::italic << "Italic";
            break;
        case Style::underline:
            os << Style::underline << "Underlined";
            break;
    }
    return os;
}
void postare::afisare(std::ostream &os, const postare &postare) const {
    os << "s: " << s << ", ";
    mesaj::afisare(os);
}

postare::postare(const std::vector<utilizator> &autorMesaj, int data, int ora,
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
    os << "nr: " << nr << ", ";
    mesaj::afisare(os);
}
