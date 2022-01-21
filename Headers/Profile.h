//
// Created by Ioan on 1/21/2022.
//

#ifndef PROIECT_OOP_PROFILE_H
#define PROIECT_OOP_PROFILE_H
#include <iostream>
//Using Decorate method
class Profile {
public:
    virtual void display();
};

class Frame : public Profile {
    Profile* f;
public:
    Frame(Profile* f_);
    void display();
};
enum class Colors{
    Green,
    RED,
    PINK,
    BLUE
};
class Decorate : public Profile {
   Frame* d;
   Colors* border;
public:
    Decorate(Frame* d_);
    void setColor();
    void display();
};
#endif //PROIECT_OOP_PROFILE_H
