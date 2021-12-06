//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_POSTARE_H
#define PROIECT_OOP_POSTARE_H

#include "Headers/mesaj.h"

class postare : public mesaj {
public:
    postare(const std::vector<utilizator> &autorMesaj, int data, int ora,
            const std::vector<reactie> &reactii);
    void send() const;
    ~postare();

    std::shared_ptr<mesaj> clone() const override;
};


#endif //PROIECT_OOP_POSTARE_H
