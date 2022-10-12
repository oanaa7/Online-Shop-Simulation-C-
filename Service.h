#pragma once
#include "RepoFile.h"
#include "ValidatorProdusRetur.h"
#include <vector>

class Service{
private:
    RepoFile repo;
    ValidatorProdusRetur validator;

public:
    Service();
    Service(const RepoFile& repo);
    ~Service();
    void add_element(ProdusRetur elem);
    ProdusRetur *get_all();
    void update_elem(int cod, ProdusRetur neew);
    void delete_elem(int cod);
    int get_size();
    ProdusRetur find_by_id(int id);
    int get_by_id(int id);

    ProdusRetur* filtreaza_defectiuni(const char* tip, int& len);
    ProdusRetur* sortare_by_pret(ProdusRetur* &produse);
//    ProdusRetur* find_by_tip(ProdusRetur* &produse, const char* tip);


};