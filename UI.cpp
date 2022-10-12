#include <cstring>
#include "UI.h"
#include "ValidatorExceptie.h"

UI::UI() {

}

UI::UI(Service& service1) {
    this->service=service1;

}

UI::~UI() {

}
void UI::show_menu() {
    cout << "1. Adauga produs" << endl;
    cout << "2. Modifica produs" << endl;
    cout << "3. Sterge produs" << endl;
    cout << "a. Afiseaza toate produsele"<<endl;
    cout << "4. Filtreaza produsele dupa defectiune"<<endl;
    cout << "5. Ordoneaza crescator produsele dupa pret"<<endl;
    cout << "6. Cautare produse dupa tip"<<endl;
    cout << "x. Iesire" << endl;
}
void UI::ui_add_elem() {
    try{
        int id, pret, stoc;
        char tip[30];
        char defect[10];
        cout<<"Dati id-ul(unic): ";
        cin>>id;
        cout<<"Dati tipul(bluza, rochie, pantaloni): ";
        cin>>tip;
        cout<<"Dati pretul: ";
        cin>>pret;
        cout<<"Dati stocul: ";
        cin>>stoc;
        cout<<"Prezinta defectiuni(da, nu): ";
        cin>>defect;
        ProdusRetur produs(id,tip,pret,stoc,defect);
        service.add_element(produs);
        cout<<"Produsul a fost adaugat!"<<endl;
        cout<<endl;

    }
    catch(MyException& e){
        cout<<e.getMessage()<<endl;
    }
}
void UI::ui_get_all() {
    ProdusRetur* lista = service.get_all();
    int size = service.get_size();
    if(size == 0){
        cout<<"Nu exista produse adaugate in lista!"<<endl;
    }
    else{
        for(int i=0; i<size;i++){
            cout<<lista[i]<<'\n';
        }
    }
}
void UI::ui_delete_elem() {
    try{
        int cod_dat;
        cout<<"Dati id-ul produsului de sters: ";
        cin>>cod_dat;
        service.delete_elem(cod_dat);
        cout<<"Produsul a fost sters!"<<endl;
        cout<<endl;
    }
    catch(MyException& e){
        cout<<e.getMessage()<<endl;
    }

}
void UI::ui_update_elem() {
    try{
        int id_dat;
        int stoc_nou;
        int pret_nou;
        char tip_nou[30];
        char defect_nou[30];
        cout<<"Dati id-ul produsului de updatat: ";
        cin>>id_dat;
        cout<<"Dati tipul(bluza, rochie, pantaloni): ";
        cin>>tip_nou;
        cout<<"Dati pretul: ";
        cin>>pret_nou;
        cout<<"Dati stocul: ";
        cin>>stoc_nou;
        cout<<"Prezinta defectiuni(da/nu): ";
        cin>>defect_nou;
        ProdusRetur c_noua(id_dat, tip_nou, pret_nou, stoc_nou,defect_nou);
        service.update_elem(id_dat, c_noua);
        cout<<"Update realizat!"<<endl;
        cout<<endl;
    }
    catch(MyException& e){
        cout<<e.getMessage()<<endl;
    }
}

void UI::ui_filtreaza() {
    char defect[10];
    cout<<"In lista vor ramane produsele cu defectiunea(da/nu): ";
    cin>>defect;
    cout<<endl;
    int size;
    ProdusRetur* produse = this->service.filtreaza_defectiuni(defect, size);
    if (size == 0)
    {
        cout << "Nu exista produse in lista!"<<endl;
        cout<<endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << produse[i] <<endl;
        }
    }
}

void UI::ui_sorteaza() {
    ProdusRetur* lista;
    int size = service.get_size();
    this->service.sortare_by_pret(lista);
    for(int i=0; i< size; i++){
        cout<<lista[i]<<endl;
    }
}

void UI::ui_find_by_tip() {
    char tip[20];
    cout<<"Tipul produselor cautate(bluza, rochie, pantaloni): ";
    cin>>tip;
    cout<<endl;
    if(strcmp(tip, "bluza")==0 || strcmp(tip, "rochie")==0 ||  strcmp(tip, "pantaloni")==0){
        ProdusRetur* produse = this->service.get_all();
        int size = this->service.get_size();
        if(size == 0){
            cout<<"Nu exista produse cu tipul dat!"<<endl;

        }
        else{
            for(int i = 0; i<size; i++){
                if(strcmp(produse[i].get_tip(),tip)==0){
                    cout<<produse[i]<<endl;
                }
            }
        }
    }
    else{
        cout<<"Tipul trebuie sa fie: bluza, pantaloni sau rochie!"<<endl;
        cout<<endl;
    }
}

void UI::runMenu() {
    char option;
    while (true) {
        this->show_menu();
        cout<<"Alegeti optiunea: ";
        cin >> option;
        switch(option)
        {
            case '1':
                this->ui_add_elem();
                break;
            case '2':
                this->ui_update_elem();
                break;
            case '3':
                this->ui_delete_elem();
                break;
            case '4':
                this->ui_filtreaza();
                break;
            case '5':
                this->ui_sorteaza();
                break;
            case '6':
                this->ui_find_by_tip();
                break;
            case 'a':
                this->ui_get_all();
                break;
            case 'x':
                cout<<"Program incheiat";
                return;
            default:
                cout<<"Optiune invalida";
                break;
        }

    }

}




