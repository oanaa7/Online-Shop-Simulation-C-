#pragma once
#include "ProdusRetur.h"

class Repo{
protected:
    ProdusRetur* vector;
    int dim;

public:
    Repo();
    ~Repo();
    Repo(const Repo& other);

    void add_elem(ProdusRetur c);
    void delete_elem(int id);
    void update_elem(int id, ProdusRetur new_t);

    int get_size();
    ProdusRetur* get_all();
    void  realocMemorie(int n);

};