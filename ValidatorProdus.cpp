#include <cstring>
#include "ValidatorProdus.h"
#include "ValidatorExceptie.h"


void ValidatorProdus::validate(Produs &p) {
    if(p.get_stoc() < 0)
        throw MyException("Stocul nu poate fi negativ!");
    if(p.get_pret() < 0)
        throw MyException("Pretul nu poate fi negativ!");
    if(strcmp(p.get_tip(), "bluza")!=0 && strcmp(p.get_tip(), "rochie")!=0 && strcmp(p.get_tip(), "pantaloni")!=0)
        throw MyException("Tipul poate fi doar: rochie, pantaloni sau bluza!");


}
