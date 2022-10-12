
#include "Repo.h"


Repo::Repo() {
    this->vector = nullptr;
    this->dim=0;
}

Repo::~Repo() {
    if (this->dim > 0)
    {
        delete[] this->vector;
        this->vector = nullptr;
    }


}

Repo::Repo(const Repo &other) {
    if(other.vector != NULL){
        this->vector = new ProdusRetur[other.dim + 1];
        for(int i=0; i<other.dim;i++)
            this->vector[i] = other.vector[i];
    }
    else this->vector=NULL;
    this->dim = other.dim;

}

void Repo::add_elem(ProdusRetur c) {
    ++dim;
    this->realocMemorie(dim);
    vector[dim - 1] = c;

}

void Repo::delete_elem(int id) {
    for (int i = 0; i < this->dim; i++) {
        if (vector[i].get_id() == id) {
            i++;
            while (i < this->dim) {
                vector[i - 1] = vector[i];
                i++;
            }
            dim--;
        }
    }

}

void Repo::update_elem(int id, ProdusRetur new_t) {
    for(int i=0; i< get_size(); i++){
        if(this->vector[i].get_id() == id){
            this->vector[i] = new_t;
        }
    }

}

int Repo::get_size() {
    return this-> dim;;
}

ProdusRetur *Repo::get_all() {
    return this->vector;
}

void Repo::realocMemorie(int n) {
    ProdusRetur* v = this->vector;
    this->vector = new ProdusRetur[n * sizeof(ProdusRetur)];
    for (int i = 0; i < n - 1; i++) {
        vector[i] = v[i];
    }

}

