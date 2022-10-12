#include <cstring>
#include <iostream>
#include "Produs.h"

Produs::Produs() {
    this->id=0;
    this->tip = NULL;
    this->pret=0;
    this->stoc=0;


}

Produs::Produs(int id, const char *tip, int pret, int stoc) {
    this->id = id;
    if(tip == NULL)
    {
        this->tip = NULL;
    }
    else
    {
        this->tip = new char[strlen(tip) + 1];
        strcpy_s(this->tip, strlen(tip) + 1, tip);
    }
    this->pret= pret;
    this->stoc= stoc;

}

Produs::Produs(const Produs &produs) {
    this->id = produs.id;
    this->pret = produs.pret;
    this->stoc = produs.stoc;
    if(produs.tip == NULL)
    {
        this->tip = NULL;
    }
    else
    {
        this->tip = new char[strlen(produs.tip) + 1];
        strcpy_s(this->tip, strlen(produs.tip) + 1, produs.tip);
    }

}

Produs::~Produs() {
    if (this->tip)
    {
        delete[] this->tip;
        this->tip = NULL;
    }

}

int Produs::get_id() {
    return this->id;
}

int Produs::get_pret() {
    return this->pret;
}

int Produs::get_stoc() {
    return this->stoc;
}

char *Produs::get_tip() {
    return this->tip;
}

void Produs::set_id(int id) {
    this->id = id;

}

void Produs::set_pret(int pret) {
    this->pret = pret;
    }

void Produs::set_stoc(int stoc) {
    this->stoc=stoc;

}

void Produs::set_tip(const char *tip) {
    if (this->tip)
    {
        delete[]this->tip;
    }
    if (tip == NULL)
    {
        this->tip = NULL;
    }
    else
    {
        this->tip = new char[strlen(tip) + 1];
        strcpy_s(this->tip, strlen(tip) + 1, tip);
    }


}

Produs &Produs::operator=(const Produs &c) {
    if(this != &c){
        if(tip)
            delete[] tip;
        id=c.id;
        tip=new char[strlen(c.tip) + 1];
        strcpy(tip, c.tip);
        pret = c.pret;
        stoc = c.stoc;
    }
    return *this;
}

bool Produs::operator==(const Produs &produs) {
    return strcmp(this->tip, produs.tip) == 0 &&
           this->id == produs.id &&
           this->stoc == produs.stoc &&
           this->pret == produs.pret;


}

istream &operator>>(istream &is, Produs &c) {
    int id,pret,stoc;
    char tip[20];
    cout << "Dati id-ul produsului: ";
    is >> id;
    cout << "Dati tipul produsului: ";
    is >> tip;
    cout << "Dati pretul produsului: ";
    is >> pret;
    cout << "Dati stocul: ";
    is >> stoc;
    c.set_id(id);
    c.set_tip(tip);
    c.set_pret(pret);
    c.set_stoc(stoc);
    return is;

}

ostream &operator<<(ostream &os,const Produs &c) {
    os << "Produsul cu id: " << c.id << ", tipul: " << c.tip <<
       ", pretul: " << c.pret<<", stoc: "<<c.stoc;
    return os;

}



