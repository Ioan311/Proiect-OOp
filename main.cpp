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
#include "Headers/postare.h"
#include "Headers/data_invalida.h"
#include "Headers/Story.h"
#include "Headers/Profile.h"

int main()
{
    utilizator<unsigned int> l1{"Mihai", 21, "Bucuresti", "FMI"};
    utilizator<unsigned int> l2{"Andrei", 28, "Constanta", "Universitatea Ovidius"};
    utilizator<unsigned int> l3{"Ioan", 19, "Ploiesti", "CEVM"};
    utilizator<int> l4{"George", 32, "Iasi", "UMF"};
    utilizator<int> l5{"Sorin", 22, "Cluj", "Babeș-Bolyai"};

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

    chat t1{"FMI 2020", {l5}, {std::make_shared<mesaj> (m1)}};
    t1.adauga(p1);
    t1.send();

    chat t2{"CTI 26", {l4}, {std::make_shared<mesaj> (m2)}};
    chat t3{"Grupa 261", {l5}, {std::make_shared<mesaj> (m3)}};

    t1.adauga(l4);
    t3.adauga(l5);

    t1.adauga(m3);

    grup s("Studentii", {t1, t2, t3}, {l4}, {l5});

    s.adauga(t1);
    s.adauga(t3);
    try{
        utilizator<int> l4{"Paul", 15, "Timisoara", "Scoala Gimnaziala Nr. 30"};
        mesaj m4{{l1}, 32, 25, "Text", {r1}};
    }catch(varsta_invalid& error) {
        std::cout << error.what() << "\n";
    }catch (data_invalida& error) {
        std::cout << error.what() << "\n";
    }
    CreateMine myStory;
    myStory.NewStory("Tap to view");
    myStory.NewStory("Tap to view");
    myStory.ReportStory();
    Profile p;
    Frame f();
    Decorate d();
    //d->display();
    std::cout << s;
    std::cout << mesaj::getIdMax() << "\n";
    return 0;
}
