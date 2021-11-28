//
// Created by Ioan on 11/28/2021.
//

#include "reactie.h"

enum Reaction {
   HAHA, ANGRY, SAD, HEART, WOW
};
std::ostream &operator<<(std::ostream &os, const reactie::Reaction &reactie) {
    switch (reactie) {
        case HAHA:
            os << "😆";
            break;
        case ANGRY:
            os << "😠";
            break;
        case SAD:
            os << "😢";
            break;
        case HEART:
            os << "❤";
            break;
        case WOW:
            os << "😲";
            break;
    }
    return os;
}

reactie::reactie(reactie::Reaction reactie) : reactie_(reactie) {}

std::ostream &operator<<(std::ostream &os, const reactie &reactie) {
    os << "reactie_: " << reactie.reactie_ << "\n";
    return os;
}

reactie &reactie::operator++() {
    ++nr;
    return *this;
}
reactie reactie::operator++(int) {
    reactie r1(*this);
    ++(*this);
    return r1;
}