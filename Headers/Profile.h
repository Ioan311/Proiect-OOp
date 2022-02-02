//
// Created by Ioan on 1/21/2022.
//

#ifndef PROIECT_OOP_PROFILE_H
#define PROIECT_OOP_PROFILE_H
#include <iostream>
#include <memory>
#include <vector>
//Using Decorate method
class Profile {
public:
    virtual void display();
};

class Frame : public Profile {
    std::vector<std::shared_ptr<Profile>>f;
public:
    Frame(const std::vector<std::shared_ptr<Profile>> &f_);
    void display();
};
enum class Colors{
    Green,
    RED,
    PINK,
    BLUE
};
class Decorate : public Profile {
   std::vector<std::shared_ptr<Frame>> d;
   Colors border;
public:
    Decorate(std::vector<std::shared_ptr<Frame>> &d_);
    void setColor();
    void display();
};
#endif //PROIECT_OOP_PROFILE_H
