//
// Created by Ioan on 11/28/2021.
//

#ifndef PROIECT_OOP_REACTIE_H
#define PROIECT_OOP_REACTIE_H

#include <iostream>


enum class Reaction {
    HAHA, ANGRY, SAD, HEART, WOW
};

std::ostream &operator<<(std::ostream &os, const Reaction &reactie);

class reactie {
public:


private:
    int nr = 1;
    Reaction reactie_;
public:
    reactie(Reaction reactie);

    friend std::ostream &operator<<(std::ostream &os, const reactie &reactie);
    reactie& operator++();
    reactie operator++(int);
};


#endif //PROIECT_OOP_REACTIE_H
