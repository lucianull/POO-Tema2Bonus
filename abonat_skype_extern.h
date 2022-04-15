#ifndef ABONAT_SKYPE_EXTERN_H_INCLUDED
#define ABONAT_SKYPE_EXTERN_H_INCLUDED

#include "abonat_skype.h"

using namespace std;

class Abonat_Skype_Extern: public Abonat_Skype
{
private:
    string tara;
    static int nr_abonati;
public:
    Abonat_Skype_Extern(): Abonat_Skype(), tara("") {nr_abonati++;}
    Abonat_Skype_Extern(int id, string nume, string nr_telefon, string id_skype, string tara): Abonat_Skype(id, nume, nr_telefon, id_skype), tara(tara) {nr_abonati++;}
    Abonat_Skype_Extern(const Abonat_Skype_Extern& abonat)
    {
        this->id = abonat.id;
        this->nume = abonat.nume;
        this->nr_telefon = abonat.nr_telefon;
        this->id_skype = abonat.id_skype;
        this->tara = abonat.tara;
    }
    ~Abonat_Skype_Extern() {nr_abonati--;}
    void setTara(string tara) {this->tara = tara;}
    string getTara() {return tara;}
    friend istream& operator>> (istream&, Abonat_Skype_Extern&);
    friend ostream& operator<< (ostream&, const Abonat_Skype_Extern&);
    static int getNrAbonatiExtern() {return nr_abonati;}
    Abonat_Skype_Extern& operator=(const Abonat_Skype_Extern &subscriber)
    {
        this->id = subscriber.id;
        this->nume = subscriber.nume;
        this->nr_telefon = subscriber.nr_telefon;
        this->id_skype = subscriber.id_skype;
        this->tara = subscriber.tara;
        return *this;
    }
};

int Abonat_Skype_Extern::nr_abonati=0;
istream& operator>> (istream& in, Abonat_Skype_Extern& abonat)
{
    in >> abonat.id >> abonat.nume >> abonat.nr_telefon >> abonat.id_skype >> abonat.tara;
    return in;
}

ostream& operator<< (ostream& out, const Abonat_Skype_Extern& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.nr_telefon << ' ' << abonat.id_skype << ' ' << abonat.tara;
    return out;
}


#endif // ABONAT_SKYPE_EXTERN_H_INCLUDED