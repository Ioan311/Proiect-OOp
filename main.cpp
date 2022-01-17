//
// Created by Ioan on 10/24/2021.
//
#include <iostream>
#include <string>
#include <vector>
#include "Headers/utilizator.h"
#include "Headers/reactie.h"
#include "Headers/mesaj.h"
#include "Headers/chat.h"
#include "Headers/grup.h"
#include "postare.h"

int main()
{
    utilizator l1{"Mihai", 21, "Bucuresti", "FMI"};
    utilizator l2{"Andrei", 28, "Constanta", "Universitatea Ovidius"};
    utilizator l3{"Ioan", 19, "Ploiesti", "CEVM"};

    reactie r1{Reaction::HAHA};
    reactie r2{Reaction::ANGRY};
    reactie r3{Reaction::SAD};

    std::cout << mesaj::getIdMax() << "\n";

    //New
    postare p1{{l1}, 10, 12, {r1}};
    std::cout << mesaj::getIdMax() << "\n";
    p1.send();
    mesaj m1{{l1}, 13, 3, "Text", {r1, r3}};
    m1.send();


    mesaj m2{{l2}, 11, 2, "Imagine", {r1, r2}};
    mesaj m3{{l3}, 10, 1, "Video", {r3}};

    m1.adauga(r1);
    m2.adauga(r2);

    chat t1{"FMI 2020", {l1}, {std::make_shared<mesaj> (m1)}};
    t1.adauga(p1);
    t1.send();

    chat t2{"CTI 26", {l3}, {std::make_shared<mesaj> (m2)}};
    chat t3{"Grupa 261", {l2}, {std::make_shared<mesaj> (m3)}};

    t1.adauga(l1);
    t3.adauga(l2);

    t1.adauga(m3);

    grup s("Studentii", {t1, t2, t3}, {l3}, {l1});

    s.adauga(t1);
    s.adauga(t3);

    std::cout << s;
    std::cout << mesaj::getIdMax() << "\n";
    return 0;
}
