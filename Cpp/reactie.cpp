//
// Created by Ioan on 11/28/2021.
//

#include "../Headers/reactie.h"


std::ostream &operator<<(std::ostream &os, const Reaction &reactie) {
    switch (reactie) {
        case Reaction::HAHA:
            os << "😆";
            break;
        case Reaction::ANGRY:
            os << "😠";
            break;
        case Reaction::SAD:
            os << "😢";
            break;
        case Reaction::HEART:
            os << "❤";
            break;
        case Reaction::WOW:
            os << "😲";
            break;
    }
    return os;
}

reactie::reactie(const Reaction reactie) : reactie_(reactie) {}

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