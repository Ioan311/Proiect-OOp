//
// Created by Ioan on 11/28/2021.
//

#include "../Headers/grup.h"

grup::grup(const std::string &numeGrup, const std::vector<chat> &chats, const std::vector<utilizator<int>> &admin,
           const std::vector<utilizator<int>> &moderatori) : nume_grup(numeGrup), chats(chats), admin(admin), moderatori(moderatori) {}

std::ostream &operator<<(std::ostream &os, const grup &grup) {
    os << "nume_grup: " << grup.nume_grup << " chats: ";
    for(const auto & chat : grup.chats)
        os << chat;
    os << "admin: ";
    for(int i = 0; i < grup.admin.size(); i++){
        os << grup.admin[i] << "\n";
    }
    os << "moderatori: ";
    for(int i = 0; i < grup.moderatori.size(); i++){
        os << grup.moderatori[i] << "\n";
    }
    return os;
}

void grup::adauga(const chat &chat) {
    chats.push_back(chat);
}
