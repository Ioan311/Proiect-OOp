//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_GRUP_H
#define PROIECT_OOP_GRUP_H

#include <iostream>
#include <vector>
#include "chat.h"
#include "utilizator.h"

class grup {
    std::string nume_grup;
    std::vector<chat> chats;
    std::vector<utilizator<int>> admin;
    std::vector<utilizator<int>> moderatori;
public:
    grup(const std::string &numeGrup, const std::vector<chat> &chats, const std::vector<utilizator<int>> &admin, const std::vector<utilizator<int>> &moderatori);

    friend std::ostream &operator<<(std::ostream &os, const grup &grup);
    void adauga(const chat &chat);
};


#endif //PROIECT_OOP_GRUP_H
