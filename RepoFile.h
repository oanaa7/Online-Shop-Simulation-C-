#pragma once
#include <iostream>
#include <fstream>
#include "ProdusRetur.h"
#include "Repo.h"
using namespace std;

class RepoFile : public Repo {
private:
    string filename;
public:
    RepoFile();
    RepoFile(string filename);
    ~RepoFile();
    void add_elem(ProdusRetur p);
    void delete_elem(int id);
    void update_elem(int id, ProdusRetur p);

    void load_from_file() {
        ifstream f(this->filename);
        int nr;
        f>>nr;
        for(int i=0;i<nr; i++){
            int id, stoc, pret;
            char tip[20];
            char defect[10];
            f >> id;
            f >> tip;
            f >> pret;
            f >> stoc;
            f >> defect;
            ProdusRetur e(id, tip, pret, stoc, defect);
            this->add_elem(e);
        }
        f.close();

    }
    void save_to_file(){
        ofstream g(this->filename);

        g<<this->dim<<endl;

        for(int i=0; i<this->dim; i++){
            g << this->vector[i].get_id()<<endl
              <<this->vector[i].get_tip()<<endl
              << this->vector[i].get_pret()<<endl
              << this->vector[i].get_stoc()<<endl
              << this->vector[i].get_defect()<<endl;
        }
        g.close();
    }

//    void add_elem(Carte elem){
//        repo.add_elem(elem);
//        this->save_to_file();
//    }


};