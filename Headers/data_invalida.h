//
// Created by Ioan on 1/19/2022.
//

#ifndef PROIECT_OOP_DATA_INVALIDA_H
#define PROIECT_OOP_DATA_INVALIDA_H
#include <iostream>

class data_invalida : public std::runtime_error {
public:
    data_invalida(const std::string &arg);
};

class data_prea_mare : public data_invalida {
public:
    data_prea_mare();
};

class ora_invalida : public data_invalida {
public:
    ora_invalida();
};

#endif //PROIECT_OOP_DATA_INVALIDA_H
