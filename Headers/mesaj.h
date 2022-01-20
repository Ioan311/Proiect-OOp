//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_MESAJ_H
#define PROIECT_OOP_MESAJ_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "utilizator.h"
#include "reactie.h"

class mesaj {
    const int id;
    static int id_max;
protected:
    std::vector<utilizator<int>> autor_mesaj;
    int data;
    int ora;
    std::string tip_mesaj;
    std::vector<reactie> reactii;
    virtual void afisare(std::ostream& os) const;
public:
    mesaj(const std::vector<utilizator<int>> &autorMesaj, int data, int ora, const std::string &tipMesaj, const std::vector<reactie> &reactii);
    mesaj(const mesaj&);

    friend std::ostream &operator<<(std::ostream &os, const mesaj &mesaj);

    void adauga(const reactie &reaction);

    virtual void send() const;
    virtual std::shared_ptr<mesaj> clone() const;
    virtual ~mesaj();
    static int getIdMax();
};

#endif //PROIECT_OOP_MESAJ_H
