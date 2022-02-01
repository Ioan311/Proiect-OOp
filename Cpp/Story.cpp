//
// Created by Ioan on 1/21/2022.
//

#include "../Headers/Story.h"

Story::Story(const std::string &newName) {
    std::string nume = newName;
}

const std::string &Story::getNume() const {
    return nume;
}

MyStory::MyStory(const std::string &newName) : Story(newName){}

void MyStory::Deschis() {
    std::cout << "MyStory: Deschis()" << "\n";
}

void MyStory::Inchis() {
    std::cout << "MyStory: Inchis()" << "\n";
}

Create::Create() : index(0) {
    std::cout << "Create: StoryTime" << "\n";
}

void Create::DeschideStory() {}

void Create::NewStory(const std::string &name) {
    std::cout << "Create: NewStory()" << "\n";
    sry[index] = CreateStory(name);
    sry[index++]->Deschis();
}

void Create::ReportStory() {
    std::cout << "Create: ReportStory()" << "\n";
    for(int i = 0; i < index; i++)
        std::cout << " " << sry[i]->getNume() << "\n";
}

CreateMine::CreateMine() {
    std::cout << "CreateMine: StoryTime" << "\n";
}

MyStory CreateMine::CreateStory(const std::string &newName) {
    std::cout << "CreateMine: CreateStory()" << "\n";
    return  MyStory(newName);
}

