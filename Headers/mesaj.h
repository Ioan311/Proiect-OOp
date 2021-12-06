//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_MESAJ_H
#define PROIECT_OOP_MESAJ_H

#include <iostream>
#include <vector>
#include <memory>
#include "utilizator.h"
#include "reactie.h"

class mesaj {
    std::vector<utilizator> autor_mesaj;
    int data;
    int ora;
    std::string tip_mesaj;
    std::vector<reactie> reactii;
public:
    mesaj(const std::vector<utilizator> &autorMesaj, int data, int ora, const std::string &tipMesaj, const std::vector<reactie> &reactii);

    friend std::ostream &operator<<(std::ostream &os, const mesaj &mesaj);

    void adauga(const reactie &reaction);

    virtual void send() const;
    virtual std::shared_ptr<mesaj> clone() const;
    virtual ~mesaj();
};

#endif //PROIECT_OOP_MESAJ_H
