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
class reactie {
    std::string nume_reactie;
public:
    enum Reaction {
        HAHA, ANGRY, SAD, HEART, WOW
    };
    reactie(const std::string &numeReactie) : nume_reactie(numeReactie) {}

    friend std::ostream &operator<<(std::ostream &os, const Reaction &reactie) {
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

    friend std::ostream &operator<<(std::ostream &os, const reactie &reactie) {
        os << "nume_reactie: " << reactie.nume_reactie << "\n";
        return os;
    }
};
class mesaj {
    std::vector<utilizator> autor_mesaj;
    int data;
    int ora;
    std::string tip_mesaj;
    std::vector<reactie> reactii;
public:
    mesaj(const std::vector<utilizator> &autorMesaj, int data, int ora, const std::string &tipMesaj, const std::vector<reactie> &reactii) : autor_mesaj(autorMesaj), data(data), ora(ora), tip_mesaj(tipMesaj), reactii(reactii) {}

    friend std::ostream &operator<<(std::ostream &os, const mesaj &mesaj) {
        os << "trimis de: ";
        for(const auto & utilizator : mesaj.autor_mesaj)
            os << utilizator;
        os << " data: " << mesaj.data << " ora: " << mesaj.ora << " tip_mesaj: " << mesaj.tip_mesaj << " reactii: ";
        for(const auto & reactie : mesaj.reactii)
            os << reactie;
        return os;
    }

    void adaugaReactie(reactie reaction) {
        reactii.push_back(reaction);
    }
};
class chat {
    std::string nume_chat;
    std::vector<utilizator> utilizatori;
    std::vector<mesaj> mesaje;
public:
    friend std::ostream &operator<<(std::ostream &os, const chat &chat) {
        os << "nume_chat: " << chat.nume_chat << " utilizatori: ";
        for(const auto & utilizator : chat.utilizatori)
            os << utilizator;
        os << " mesaje: ";
        for(const auto & mesaj : chat.mesaje)
            os << mesaj;
        return os;
    }

public:
    void adaugaUtilizator(utilizator user) {
        utilizatori.push_back(user);
    }

    chat(const std::string &numeChat) : nume_chat(numeChat) {}

    chat(const std::string &numeChat, const std::vector<utilizator> &utilizatori, const std::vector<mesaj> &mesaje) : nume_chat(numeChat), utilizatori(utilizatori), mesaje(mesaje) {}

    chat(const chat& copie) {
        nume_chat = copie.nume_chat;
        utilizatori = copie.utilizatori;
        mesaje = copie.mesaje;
    }

    chat& operator=(const chat& copie) {
        if(this != &copie) {
            nume_chat = copie.nume_chat;
            utilizatori = copie.utilizatori;
            mesaje = copie.mesaje;
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
    std::vector<utilizator> admin;
    std::vector<utilizator> moderatori;
public:
    grup(const std::string &numeGrup, const std::vector<chat> &chats, const std::vector<utilizator> &admin, const std::vector<utilizator> &moderatori) : nume_grup(numeGrup), chats(chats), admin(admin), moderatori(moderatori) {}

    friend std::ostream &operator<<(std::ostream &os, const grup &grup) {
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
    void adaugaChat(chat chat) {
        chats.push_back(chat);
    }
};


int main()
{
    utilizator l1{"Mihai", 21, "Bucuresti", "FMI"};
    utilizator l2{"Andrei", 28, "Constanta", "Universitatea Ovidius"};
    utilizator l3{"Ioan", 19, "Ploiesti", "CEVM"};

    reactie r1{"HaHa"};
    reactie r2{"Angry"};
    reactie r3{"Sad"};

    mesaj m1{{l1}, 13, 3, "Text", {r1, r3}};
    mesaj m2{{l2}, 11, 2, "Imagine", {r1, r2}};
    mesaj m3{{l3}, 10, 1, "Video", {r3}};

    m1.adaugaReactie(r1);
    m2.adaugaReactie(r2);

    chat t1{"FMI 2020", {l1}, {m1}};
    chat t2{"CTI 26", {l3}, {m2}};
    chat t3{"Grupa 261", {l2}, {m3}};

    t1.adaugaUtilizator(l1);
    t3.adaugaUtilizator(l2);

    grup s("Studentii", {t1, t2, t3}, {l3}, {l1});

    s.adaugaChat(t1);
    s.adaugaChat(t3);

    std::cout << s;
    return 0;
}
