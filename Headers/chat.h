//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_CHAT_H
#define PROIECT_OOP_CHAT_H

#include <iostream>
#include <vector>
#include <memory>
#include "utilizator.h"
#include "mesaj.h"

class chat {
    std::string nume_chat;
    std::vector<utilizator> utilizatori;
    std::vector<std::shared_ptr<mesaj>> mesaje;
public:
    friend std::ostream &operator<<(std::ostream &os, const chat &chat);

public:
    void adauga(const utilizator &user);
    void adauga(const mesaj &mesaj);
    chat(const std::string &numeChat);
    chat(const std::string &numeChat, const std::vector<utilizator> &utilizatori, const std::vector<std::shared_ptr<mesaj>> &mesaje);
    chat(const chat& copie);
    chat& operator=(chat copie);
    friend void swap(chat& c1, chat& c2);
    ~chat();

    void send();
};


#endif //PROIECT_OOP_CHAT_H
