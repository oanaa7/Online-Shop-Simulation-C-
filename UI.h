#include "Service.h"

class UI{
private:
    Service service;
    void show_menu();
    void ui_add_elem();
    void ui_get_all();
    void ui_delete_elem();
    void ui_update_elem();
    void ui_filtreaza();
    void ui_sorteaza();
    void ui_find_by_tip();
public:
    UI();
    UI(Service& service);
    ~UI();
    void runMenu();
};