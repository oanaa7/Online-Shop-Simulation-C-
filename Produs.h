#pragma once
#include <ostream>

using namespace std;
class Produs{
protected:
    int id;    // unic
    int pret;   // int >0
    int stoc;   // int >0
    char* tip;   // bluza/pantaloni/rochie
public:
    Produs();       //constructor implicit
    Produs(int id, const char* tip, int pret, int stoc);  // constructor explicit
    Produs(const Produs& produs);
    ~Produs();       // destructor

    int get_id();      // getteri
    int get_pret();
    int get_stoc();
    char* get_tip();

    void set_id(int);    //setteri
    void set_stoc(int);
    void set_pret(int);
    void set_tip(const char*);

    Produs& operator=(const Produs& produs);   // operator atribuire
    bool operator==(const Produs& produs);     // operator egalitate

    friend istream& operator >> (istream&, Produs&);

    friend ostream& operator << (ostream&, const Produs&);




};