//
// Created by Ioan on 11/28/2021.
//

#include "grup.h"

grup::grup(const std::string &numeGrup, const std::vector<chat> &chats, const std::vector<utilizator> &admin,
           const std::vector<utilizator> &moderatori) : nume_grup(numeGrup), chats(chats), admin(admin), moderatori(moderatori) {}

std::ostream &operator<<(std::ostream &os, const grup &grup) {
    os << "nume_grup: " << grup.nume_grup << " chats: ";
    for(const auto & chat : grup.chats)
        os << chat;
    os << "admin: ";
    for(const auto & utilizator : grup.admin)
        os << utilizator;
    os << "moderatori: ";
    for(const auto & utilizator : grup.moderatori)
        os << utilizator;
    return os;
}

void grup::adauga(const chat &chat) {
    chats.push_back(chat);
}
