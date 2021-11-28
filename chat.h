//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_CHAT_H
#define PROIECT_OOP_CHAT_H

#include <iostream>
#include <vector>
#include "utilizator.h"
#include "mesaj.h"

class chat {
    std::string nume_chat;
    std::vector<utilizator> utilizatori;
    std::vector<mesaj> mesaje;
public:
    friend std::ostream &operator<<(std::ostream &os, const chat &chat);

public:
    void adaugaUtilizator(const utilizator &user);

    chat(const std::string &numeChat);

    chat(const std::string &numeChat, const std::vector<utilizator> &utilizatori, const std::vector<mesaj> &mesaje);

    chat(const chat& copie);

    chat& operator=(const chat& copie);

    ~chat();
};


#endif //PROIECT_OOP_CHAT_H
