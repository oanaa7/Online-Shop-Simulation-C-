//
// Created by Oana on 5/18/2021.
//

#include <cstring>
#include <iostream>
#include "ProdusRetur.h"

ProdusRetur::ProdusRetur() {
    this->defect = NULL;

}

ProdusRetur::ProdusRetur(int id, const char *tip, int pret, int stoc, const char *defect): Produs(id, tip, pret, stoc) {
    this->defect = new char[strlen(defect) + 1];
    strcpy(this->defect, defect);

}

ProdusRetur::ProdusRetur(const ProdusRetur &pr): Produs(pr) {
    this->defect = new char[strlen(pr.defect) + 1];
    strcpy(this->defect, pr.defect);

}

ProdusRetur::~ProdusRetur() {
    if (this->defect)
    {
        delete[] this->defect;
        this->defect = NULL;
    }

}

char *ProdusRetur::get_defect() const{
    return defect;
}

void ProdusRetur::set_defect(char *defect) {
    if (this->defect)
    {
        delete[]this->defect;
    }
    if (defect == NULL)
    {
        this->defect = NULL;
    }
    else
    {
        this->defect = new char[strlen(defect) + 1];
        strcpy_s(this->defect, strlen(defect) + 1, defect);
    }

}

ProdusRetur &ProdusRetur::operator=(const ProdusRetur &p) {
    if (this !=&p)
    {
        Produs::operator=(p);
        this->set_defect(p.defect);
    }
    return *this;
}

bool ProdusRetur::operator==(const ProdusRetur &p) {
    return Produs::operator==(p) && strcmp(this->defect, p.defect) == 0;
}

istream &operator>>(istream & is, ProdusRetur &c) {
    int id,pret,stoc;
    char tip[20];
    char defect[10];
    cout << "Dati id-ul produsului: ";
    is >> id;
    cout << "Dati tipul produsului: ";
    is >> tip;
    cout << "Dati pretul produsului: ";
    is >> pret;
    cout << "Dati stocul: ";
    is >> stoc;
    cout << "Prezinta defectiuni: ";
    is >> defect;

    c.set_id(id);
    c.set_tip(tip);
    c.set_pret(pret);
    c.set_stoc(stoc);
    c.set_defect(defect);
    return is;
}

ostream &operator<<(ostream &os, const ProdusRetur &c) {
    os << "Produsul cu id: " << c.id << ", tipul: " << c.tip <<
       ", pretul: " << c.pret<<", stoc: "<<c.stoc<<", cu defectiuni: "<<c.defect<<endl;
    return os;
}

bool ProdusRetur::operator<(const ProdusRetur &pr) {
    return pret < pr.pret;
}

