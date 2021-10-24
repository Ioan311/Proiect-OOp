//
// Created by Ioan on 10/24/2021.
//
#include <iostream>
#include <string>
#include <vector>

class utilizator {
    std::string nume;
    int varsta;
    std::string locatie;
    std::string studii;
public:
    utilizator(const std::string &nume, int varsta, const std::string &locatie, const std::string &studii) : nume(nume), varsta(varsta), locatie(locatie),studii(studii) {}

    friend std::ostream &operator<<(std::ostream &os, const utilizator &utilizator) {
        os << "nume: " << utilizator.nume << " varsta: " << utilizator.varsta << " locatie: " << utilizator.locatie << " studii: " << utilizator.studii << "\n";
        return os;
    }
};

class chat {
    std::string nume_chat;
    std::vector<utilizator> utilizatori;
public:
    friend std::ostream &operator<<(std::ostream &os, const chat &chat) {
        os << "nume_chat: " << chat.nume_chat << " utilizatori: ";
        for(const auto & utilizator : chat.utilizatori)
            os << utilizator;
        return os;
    }

public:
    void adauga(utilizator user) {
        utilizatori.push_back(user);
    }

    chat(const std::string &numeChat) : nume_chat(numeChat) {}

    chat(const std::string &numeChat, const std::vector<utilizator> &utilizatori) : nume_chat(numeChat), utilizatori(utilizatori) {}

    chat(const chat& copie) {
        nume_chat = copie.nume_chat;
        utilizatori = copie.utilizatori;
    }

    chat& operator=(const chat& copie) {
        if(this != &copie) {
            nume_chat = copie.nume_chat;
            utilizatori = copie.utilizatori;
        }
        return *this;
    }

    ~chat() {
        std::cout << "Destructor chat\n";
    }
};
class grup {
    std::string nume_grup;
    std::vector<chat> chats;
public:
    grup(const std::string &numeGrup, const std::vector<chat> &chats) : nume_grup(numeGrup), chats(chats) {}

    friend std::ostream &operator<<(std::ostream &os, const grup &grup) {
        os << "nume_grup: " << grup.nume_grup << "chats: ";
        for(const auto & chat : grup.chats)
            os << chat;
        return os;
    }
    void adauga(chat cht) {
        chats.push_back(cht);
    }
};


int main()
{
    utilizator l1{"Mihai", 21, "Bucuresti", "FMI"};
    utilizator l2{"Andrei", 28, "Constanta", "Universitatea Ovidius"};
    utilizator l3{"Ioan", 19, "Ploiesti", "CEVM"};
    chat t1{"FMI 2020", {l1}};
    chat t2{"CTI 26", {l3}};
    chat t3{"Grupa 261", {l2}};
    grup s("Studentii", {t1, t2, t3});
    std::cout << s;
    return 0;
}
