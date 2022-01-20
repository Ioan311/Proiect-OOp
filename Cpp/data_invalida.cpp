//
// Created by Ioan on 1/19/2022.
//

#include "../Headers/data_invalida.h"

data_invalida::data_invalida(const std::string &arg) :
runtime_error("Eroare data: " + arg) {}

data_prea_mare::data_prea_mare() : data_invalida("Data prea mare") {}

ora_invalida::ora_invalida() : data_invalida("Eroare ora") {}
