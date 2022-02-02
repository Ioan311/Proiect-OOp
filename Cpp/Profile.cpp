//
// Created by Ioan on 1/21/2022.
//

#include "../Headers/Profile.h"

void Profile::display() {
    std::cout << "Interface of my profile" << "\n";
}

Frame::Frame(const std::vector<std::shared_ptr<Profile>> &f_) {
    f = f_;
}

void Frame::display() {
    //f.display();
    std::cout << "Adding a frame" << "\n";
}

Decorate::Decorate(std::vector<std::shared_ptr<Frame>> &d_) {
    d = d_;
}

void Decorate::setColor() {
    if(border == Colors::Green)
        std::cout << "The border is green";
    else if(border == Colors::RED)
        std::cout << "The border is red";
    else if(border == Colors::PINK)
        std::cout << "The border is pink";
    else if(border == Colors::BLUE)
        std::cout << "The border is blue";
}

void Decorate::display() {
    //d->display();
    std::cout << "Decorating" << "\n";
}
