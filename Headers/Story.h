//
// Created by Ioan on 1/21/2022.
//

#ifndef PROIECT_OOP_STORY_H
#define PROIECT_OOP_STORY_H
#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
// Using Factory method

class Story {
    std::string nume;
public:
    Story(const std::string &newName);
    virtual void Deschis() = 0;
    virtual void Inchis() = 0;
    const std::string &getNume() const;
};


class MyStory : public Story {
public:
    MyStory(const std::string &newName);
    void Deschis();
    void Inchis();
};

class Create {
    int index;
    std::vector<std::shared_ptr<Story>> sry;
public:
    Create();
    void NewStory(const std::string &name);
    void DeschideStory();
    void ReportStory();
    virtual std::shared_ptr<Story> CreateStory(const std::string &nume) = 0;
};
class CreateMine : public Create {
public:
    CreateMine();
    std::shared_ptr<Story> CreateStory(const std::string &nume);
};

#endif //PROIECT_OOP_STORY_H
