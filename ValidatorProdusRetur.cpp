//
// Created by Oana on 5/21/2021.
//

#include <cstring>
#include "ValidatorProdusRetur.h"
#include "ValidatorExceptie.h"

void ValidatorProdusRetur::validate(ProdusRetur &p) {
    if(p.get_stoc() < 0)
        throw MyException("Stocul nu poate fi negativ!");
    if(p.get_pret() < 0)
        throw MyException("Pretul nu poate fi negativ!");
    if(strcmp(p.get_tip(), "bluza")!=0 && strcmp(p.get_tip(), "rochie")!=0 && strcmp(p.get_tip(), "pantaloni")!=0)
        throw MyException("Tipul poate fi doar: rochie, pantaloni sau bluza!");
    if(strcmp(p.get_defect(), "da")!=0 && strcmp(p.get_defect(), "nu")!=0)
        throw MyException("Defectiunea poate fi doar: da sau nu");
};

