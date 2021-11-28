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
        os << mesaj;
    return os;
}

void chat::adaugaUtilizator(const utilizator &user) {
    utilizatori.push_back(user);
}

chat::chat(const std::string &numeChat) : nume_chat(numeChat) {}

chat::chat(const std::string &numeChat, const std::vector<utilizator> &utilizatori, const std::vector<mesaj> &mesaje) : nume_chat(numeChat), utilizatori(utilizatori), mesaje(mesaje) {}

chat::chat(const chat &copie) {
    nume_chat = copie.nume_chat;
    utilizatori = copie.utilizatori;
    mesaje = copie.mesaje;
}

chat &chat::operator=(const chat &copie) {
    if(this != &copie) {
        nume_chat = copie.nume_chat;
        utilizatori = copie.utilizatori;
        mesaje = copie.mesaje;
    }
    return *this;
}

chat::~chat() {
    std::cout << "Destructor chat\n";
}
