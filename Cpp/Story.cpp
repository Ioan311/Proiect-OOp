//
// Created by Ioan on 1/21/2022.
//

#include "../Headers/Story.h"

Story::Story(char *newName) {
    strcpy(nume, newName);
}

const char *Story::getNume() const {
    return nume;
}

MyStory::MyStory(char *newName) : Story(newName){}

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

void Create::NewStory(char *name) {
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

Story *CreateMine::CreateStory(char *newName) {
    std::cout << "CreateMine: CreateStory()" << "\n";
    return new MyStory(newName);
}
