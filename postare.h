//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_POSTARE_H
#define PROIECT_OOP_POSTARE_H

#include <ostream>
#include "Headers/mesaj.h"
enum class Style {
    bold = 1,
    italic = 2,
    underline = 3
};
std::ostream &operator<<(std::ostream &os, const Style &postare);

class postare : public mesaj {
    int nr = 2;
    Style s;
public:
    postare(const std::vector<utilizator> &autorMesaj, int data, int ora,
            const std::vector<reactie> &reactii);
    //postare(Style postare);
    void send() const;
    ~postare();
    std::shared_ptr<mesaj> clone() const override;
protected:
    void afisare(std::ostream &os) const override;
    void afisare(std::ostream &os, const postare &postare) const;
};
template <typename T>
using enableStd = typename std::enable_if<
        std::is_same<T, Style>::value,
        std::ostream &>::type;

#endif //PROIECT_OOP_POSTARE_H
