//
// Created by Oana on 5/18/2021.
//
#include <cstring>
#include "RepoFile.h"
#include "Service.h"
#include "ValidatorExceptie.h"


Service::Service() {

}
Service::Service(const RepoFile &repo) {
    this->repo = repo;

}

Service::~Service() {

}

void Service::add_element(ProdusRetur elem) {
    if(this->get_by_id(elem.get_id())!=0)
    {
        throw MyException("ID-ul exista deja!");
    }
    this->validator.validate(elem);
    repo.add_elem(elem);

}

ProdusRetur *Service::get_all() {
    return repo.get_all();
}

void Service::update_elem(int cod, ProdusRetur neew) {
    ProdusRetur* v = this->get_all();
    int n= this->get_size();
    bool ok = false;
    for(int i=0;i<n;i++)
        if(v[i].get_id() == cod){
            this->validator.validate(neew);
            this->repo.update_elem(cod, neew), ok = true;
        }
    if(!ok)
        throw MyException("Id-ul nu exista!");

}

void Service::delete_elem(int cod) {
    ProdusRetur* v = this->get_all();
    int n= this->get_size();
    bool ok = false;
    for(int i=0;i<n;i++)
        if(v[i].get_id() == cod)
            this->repo.delete_elem(cod), ok=true;
    if(!ok)
        throw MyException("Id-ul nu exista");


}

int Service::get_size() {
    return repo.get_size();
}

ProdusRetur* Service::sortare_by_pret(ProdusRetur* &produse) {
    produse=get_all();
    for(int i=0; i<get_size()-1; i++){
        for(int j=i+1; j<get_size(); j++){
            if(produse[i].get_pret() > produse[j].get_pret()){
                ProdusRetur aux = produse[i];
                produse[i] = produse[j];
                produse[j]=aux;
            }
        }
    }
    return produse;
}

ProdusRetur *Service::filtreaza_defectiuni(const char* defect, int& len) {
    int n,m=0;
    ProdusRetur* array = new ProdusRetur[1* sizeof(ProdusRetur)];
    ProdusRetur* result;
    array = repo.get_all();
    n=repo.get_size();
    for(int i=0;i<n;i++){
        if(strcmp(array[i].get_defect(),defect)== 0){
            m++;
        }
    }
    result = new ProdusRetur[m];
    m=0;
    for (int i = 0; i < n; i++){
        if(strcmp(array[i].get_defect(), defect)==0){
            result[m] = array[i];
            m++;
        }
    }
    len = m;
    return result;
}

ProdusRetur Service::find_by_id(int id) {
    ProdusRetur* v = this->get_all();
    int n= this->get_size();
    for(int i = 0; i<n; i++){
        if(v[i].get_id() == id)
            return v[i]; // returneaza produsul cu id-ul cautat
    }
    throw MyException("ID invalid!");

}

int Service::get_by_id(int id) {
    ProdusRetur* v = this->get_all();
    int n= this->get_size();
    for(int i = 0; i<n; i++){
        if(v[i].get_id() == id) // daca gaseste in lista noastra un produs cu id-ul dat
            return 1; // returneaza 1
    }
    return 0; // daca nu gaseste, returneaza 0
}












