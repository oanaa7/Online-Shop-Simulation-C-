#include <iostream>
#include "UI.h"
#include "RepoFile.h"
#include "Teste.h"


using namespace std;

int main() {
    teste();
    RepoFile repofile("sofia.txt");
    repofile.load_from_file();
    Service service(repofile);

    UI ui(service);
    ui.runMenu();
}
