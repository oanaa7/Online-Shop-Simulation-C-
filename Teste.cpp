#include <cassert>
#include <cstring>
#include "Produs.h"
#include "ProdusRetur.h"
#include "Teste.h"
#include "Repo.h"
#include "RepoFile.h"
#include "Service.h"
#include "ValidatorExceptie.h"

void test_produs(){
    //testare construct implicit
    Produs t1;
    assert(t1.get_id()==0);
    assert(t1.get_stoc()==0);
    assert(t1.get_pret()==0);
    assert(t1.get_tip()==NULL);

    Produs t4;
    t4.set_id(123);
    t4.set_stoc(100);
    t4.set_tip("bluza");
    t4.set_pret(45);
    assert(t4.get_id() == 123);
    assert(t4.get_stoc() == 100);
    assert(t4.get_pret() == 45);
    assert(strcmp(t4.get_tip(), "bluza") == 0);

    //testare constructor explicit
    Produs t2(11, "rochie",100,45);
    assert(t2.get_id() == 11);
    assert(t2.get_pret() == 100);
    assert(strcmp(t2.get_tip(), "rochie") == 0);

    // testare constructor copiere
    Produs t3;
    t3 = t2;
    assert(strcmp(t3.get_tip(), "rochie") == 0);
    assert(t3.get_stoc() == 45);
}
void test_produsretur(){
    //testare construct implicit
    ProdusRetur t1;
    assert(t1.get_id()==0);
    assert(t1.get_stoc()==0);
    assert(t1.get_pret()==0);
    assert(t1.get_tip()==NULL);
    assert(t1.get_defect()==NULL);

    ProdusRetur t4;
    t4.set_id(123);
    t4.set_stoc(100);
    t4.set_tip("bluza");
    t4.set_pret(45);
    t4.set_defect("da");
    assert(t4.get_id() == 123);
    assert(t4.get_stoc() == 100);
    assert(t4.get_pret() == 45);
    assert(strcmp(t4.get_tip(), "bluza") == 0);
    assert(strcmp(t4.get_defect(), "da") == 0);

    //testare constructor explicit
    ProdusRetur t2(11, "rochie",100,45,"nu");
    assert(t2.get_id() == 11);
    assert(t2.get_pret() == 100);
    assert(strcmp(t2.get_tip(), "rochie") == 0);
    assert(strcmp(t2.get_defect(), "nu") == 0);

    // testare constructor copiere
    ProdusRetur t3;
    t3 = t2;
    assert(strcmp(t3.get_tip(), "rochie") == 0);
    assert(t3.get_stoc() == 45);
}
void test_repo(){
    Repo repo;

    ProdusRetur p1 = ProdusRetur(11, "rochie",100,45,"nu");
    ProdusRetur p2 = ProdusRetur(12, "rochie",10,14,"da");
    ProdusRetur p3 =ProdusRetur(12, "bluza",50,16,"da");
    ProdusRetur* vector;

    //Testare add
    assert(repo.get_size()== 0);
    repo.add_elem(p1);
    assert(repo.get_size()== 1);
    repo.add_elem(p2);
    assert(repo.get_size()== 2);

    //Testare get all
    vector = new ProdusRetur[sizeof(ProdusRetur) * repo.get_size()];
    vector = repo.get_all();
    assert(vector[0] == p1); // verific ordinea din vector
    assert(vector[1] == p2);

    // Testare DELETE
    repo.delete_elem(11);
    assert(repo.get_size() == 1); // am sters Cartea "librarie" care avea codul 11

    // Testare UPDATE
    repo.update_elem(12, p3); // am updatat cartea p2(cod 12), cu p3
    assert(repo.get_size()==1);
    assert(vector[0] == p3);

}

void test_repofile(){
    RepoFile repo("repo_test.txt");
    ProdusRetur c1 = ProdusRetur(11, "rochie",100,45,"nu");
    ProdusRetur c2 = ProdusRetur(111, "pantaloni",150,18,"nu");
    ProdusRetur c3 = ProdusRetur(21, "rochie",10,14,"da");
    ProdusRetur c4 =ProdusRetur(21, "bluza",50,16,"da");

    assert(repo.get_size() == 0);

    // verific functia de load (fisierul text are scrisa 1 produs)
    repo.load_from_file();
    assert(repo.get_size() == 1);

    //verific RepoFile ADD
    repo.add_elem(c1);
    assert(repo.get_size() == 2);
    repo.add_elem(c2);
    repo.add_elem(c3);
    assert(repo.get_size() == 4);
    assert(repo.get_all()[3] == c3);
    assert(repo.get_all()[2] == c2);
    assert(repo.get_all()[1] == c1);

    //verific RepoFile Delete
    repo.delete_elem(11);
    assert(repo.get_size() == 3);

    //verific RepoFile Update
    repo.update_elem(21, c4);
    assert(repo.get_size() == 3);
    assert(repo.get_all()[2] == c4);


    repo.delete_elem(111);
    repo.delete_elem(21);

}
void test_service(){
    // testare Creeare service
    RepoFile repo;
    Service service(repo);
    ProdusRetur c1 = ProdusRetur(11, "rochie",100,45,"nu");
    ProdusRetur c2 = ProdusRetur(111, "pantaloni",150,18,"nu");
    ProdusRetur* rezultat = new ProdusRetur[1* sizeof(ProdusRetur)];
    rezultat[0] = c1;
    service.add_element(c1);
    ProdusRetur* lista = service.get_all();
    for(int i=0; i<service.get_size(); i++){
        assert(lista[i] == rezultat[i]);
    }

    // testare ADD service

    service.add_element(c2);
    assert(service.get_size()==2); // am adaugat mai sus si pe c1

    // testare validatori din ADD

    ProdusRetur c9 = ProdusRetur(11, "rochie",10,450,"nu");
    try{
        service.add_element(c9); // produsul nu are cod unic
        assert(false);
    }
    catch (MyException& exc)
    {
        assert(true);
    }
    ProdusRetur c10 = ProdusRetur(101, "rochie",10,-450,"nu");
    try{
        service.add_element(c10); // stocul e negativ
        assert(false);
    }
    catch (MyException& exc)
    {
        assert(true);
    }
    ProdusRetur c11 = ProdusRetur(101, "ghds",10,450,"nu");
    try{
        service.add_element(c10); // tipul nu e din lista:pantaloni, rochie, bluza
        assert(false);
    }
    catch (MyException& exc)
    {
        assert(true);
    }

    // testare Delete service
    service.delete_elem(11); // stergem pe c1
    assert(service.get_size()==1); // ramane doar c2

    // testare validatori din Delete service
    try{
        service.delete_elem(18); // nu exista produs cu acest id
        assert(false);
    }
    catch (MyException& exc)
    {
        assert(true);
    }

    //testare Update service
    ProdusRetur c4 =ProdusRetur(111, "bluza",50,16,"da");
    service.update_elem(111, c4); // am updatat pe c3(id 111) cu c4
    assert(service.get_size() == 1);
    assert(service.get_all()[0] == c4); // entitatea din vectorul nostru e chiar c4


    //testare validatori din update service
    ProdusRetur c17 = ProdusRetur(111, "ghds", 10, 450, "nu");
    ProdusRetur c18 = ProdusRetur(101, "bluza", 10, 450, "nu");
    try {
        service.update_elem(111, c17); // tipul nu e din lista:pantaloni, rochie, bluza
        assert(false);
    }
    catch (MyException &exc) {
        assert(true);
    }
    try{
        service.update_elem(156,c18); // nu exista produs cu codul 156 de updatat
        assert(false);
    }
    catch (MyException &exc) {
        assert(true);
    }
}

void test_functionalitati(){
    RepoFile repo;
    Service service(repo);
    ProdusRetur c1 = ProdusRetur(11, "rochie",100,45,"nu");
    ProdusRetur c2 = ProdusRetur(12, "pantaloni",180,18,"da");
    ProdusRetur c3 = ProdusRetur(13, "pantaloni",170,19,"nu");
    ProdusRetur c4 = ProdusRetur(14, "pantaloni",10,18,"da");
    service.add_element(c1);
    service.add_element(c2);
    service.add_element(c3);
    service.add_element(c4);
    ProdusRetur* produse = service.get_all();

    // testare Sortare dupa pret
    ProdusRetur* vector = service.sortare_by_pret(produse);
    assert(vector[0] == c4); // pret 10
    assert(vector[1] == c1); // pret 100
    assert(vector[2] == c3); // pret 170
    assert(vector[3] == c2); // pret 180

    // testare filtreaza dupa defectiune
    int len, len2;
    ProdusRetur* v = service.filtreaza_defectiuni("nu", len); // in v vor ramane doar produsele cu defect "nu"
    assert(v[0] == c1);
    assert(v[1] == c3);

    ProdusRetur* v1 = service.filtreaza_defectiuni("da", len2); // in v vor ramane doar produsele cu defect "da"
    assert(v1[0] == c4); // ramane ordinea de la sortarea dupa pret
    assert(v1[1] == c2);

}

void teste(){
    test_produs();
    test_produsretur();
    test_repo();
    test_repofile();
    test_service();
    test_functionalitati();

}
