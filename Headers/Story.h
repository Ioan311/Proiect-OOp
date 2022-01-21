//
// Created by Ioan on 1/21/2022.
//

#ifndef PROIECT_OOP_STORY_H
#define PROIECT_OOP_STORY_H
#include <iostream>
#include <cstring>
#include <vector>
// Using Factory method
class Story {
    char nume[30];
public:
    Story(char *newName);
    virtual void Deschis() = 0;
    virtual void Inchis() = 0;
    const char *getNume() const;
};


class MyStory : public Story {
public:
    MyStory(char *newName);
    void Deschis();
    void Inchis();
};

class Create {
    int index;
    Story *sry[10];
public:
    Create();
    void NewStory(char *name);
    void DeschideStory();
    void ReportStory();
    virtual Story *CreateStory(char*) = 0;
};
class CreateMine : public Create {
public:
    CreateMine();
    Story *CreateStory(char *newName);
};

#endif //PROIECT_OOP_STORY_H
