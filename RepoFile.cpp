#include "RepoFile.h"

RepoFile::RepoFile(string filename) {
    this->filename = filename;
}

RepoFile::~RepoFile() {

}

RepoFile::RepoFile() {
    this->filename = " ";
}

void RepoFile::add_elem(ProdusRetur p) {
    Repo::add_elem(p);
    this->save_to_file();
}

void RepoFile::delete_elem(int id) {
    Repo::delete_elem(id);
    this->save_to_file();
}

void RepoFile::update_elem(int id, ProdusRetur p) {
    Repo::update_elem(id, p);
    this->save_to_file();
}
