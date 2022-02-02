//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_POSTARE_H
#define PROIECT_OOP_POSTARE_H

#include <iostream>
#include "mesaj.h"

class postare : public mesaj {
    int nr = 2;
public:
    postare(const std::vector<utilizator<unsigned int>> &autorMesaj, int data, int ora,
            const std::vector<reactie> &reactii);
    void send() const;
    ~postare();
    std::shared_ptr<mesaj> clone() const override;
protected:
    void afisare(std::ostream &os) const override;
    void afisare(std::ostream &os, const postare &postare) const;
};

#endif //PROIECT_OOP_POSTARE_H
