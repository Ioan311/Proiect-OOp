//
// Created by Ioan on 11/28/2021.
//

#include "../Headers/chat.h"

std::ostream &operator<<(std::ostream &os, const chat &chat) {
    os << "nume_chat: " << chat.nume_chat << " utilizatori: ";
    for(const auto & utilizator : chat.utilizatori)
        os << utilizator;
    os << " mesaje: ";
    for(const auto & mesaj : chat.mesaje)
        os << *mesaj;
    return os;
}

void chat::adauga(const utilizator &user) {
    utilizatori.push_back(user);
}

void chat::adauga(const mesaj &mesaj_) {
    mesaje.push_back(mesaj_.clone());
}

chat::chat(const std::string &numeChat) : nume_chat(numeChat) {}

chat::chat(const std::string &numeChat, const std::vector<utilizator> &utilizatori, const std::vector<std::shared_ptr<mesaj>> &mesaje) : nume_chat(numeChat), utilizatori(utilizatori), mesaje(mesaje) {}


chat::chat(const chat &copie) : nume_chat(copie.nume_chat) {
    for(const auto &mesaj : copie.mesaje)
        mesaje.push_back(mesaj->clone());
}

chat &chat::operator=(const chat &copie) {
    if(this != &copie) {
        auto mesaje_noi = std::vector <std::shared_ptr <mesaj>>();
        for(const auto &mesaj : copie.mesaje) {
            mesaje_noi.push_back(mesaj->clone());
        }
        mesaje = mesaje_noi;
        nume_chat = copie.nume_chat;
    }
    return *this;
}

chat::~chat() {
    std::cout << "Destructor chat\n";
}

void chat::send() {
    for (const auto& mesaj: mesaje) {
        mesaj->send();
    }

}


