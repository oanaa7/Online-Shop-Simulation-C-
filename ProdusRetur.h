#pragma once
#include "Produs.h"

class ProdusRetur: public Produs {
protected:
    char* defect;   // da/nu
public:
    ProdusRetur();
    ProdusRetur(int id, const char* tip, int pret, int stoc, const char* defect);
    ProdusRetur(const ProdusRetur& produs);
    ~ProdusRetur();
    char* get_defect() const;
    void set_defect(char* defect);

    ProdusRetur& operator=(const ProdusRetur& produs);
    bool operator==(const ProdusRetur& produs);

    bool operator<(const ProdusRetur &);

    friend istream& operator >> (istream&, ProdusRetur&);

    friend ostream& operator << (ostream&, const ProdusRetur&);

};