#ifndef ABONAT_SKYPE_ROMANIA_H_INCLUDED
#define ABONAT_SKYPE_ROMANIA_H_INCLUDED

#include "abonat_skype.h"

using namespace std;

class Abonat_Skype_Romania: public Abonat_Skype
{
private:
    static int nr_abonati;
    string adresa_mail;
public:
    Abonat_Skype_Romania(): Abonat_Skype(), adresa_mail("") {nr_abonati++;}
    Abonat_Skype_Romania(int id, string nume, string nr_telefon, string id_skype, string adresa_mail): Abonat_Skype(id, nume, nr_telefon, id_skype), adresa_mail(adresa_mail) {nr_abonati++;}
    Abonat_Skype_Romania(const Abonat_Skype_Romania& subscriber)
    {
        this->id = subscriber.id;
        this->nume = subscriber.nume;
        this->nr_telefon = subscriber.nr_telefon;
        this->id_skype = subscriber.id_skype;
        this->adresa_mail = subscriber.adresa_mail;
    }
    ~Abonat_Skype_Romania() {nr_abonati--;}
    void setAdresaMail(string adresa_mail) {this->adresa_mail = adresa_mail;}
    string getAdresaMail() {return adresa_mail;}
    friend istream& operator>> (istream&, Abonat_Skype_Romania&);
    friend ostream& operator<< (ostream&, const Abonat_Skype_Romania&);

    Abonat_Skype_Romania& operator=(const Abonat_Skype_Romania &subscriber)
    {
        this->id=subscriber.id;
        this->nume=subscriber.nume;
        this->nr_telefon=subscriber.nr_telefon;
        this->id_skype=subscriber.id_skype;
        this->adresa_mail=subscriber.adresa_mail;
        return *this;
    }
    static int getNrAbonatiRomania() {return nr_abonati;}
};

int Abonat_Skype_Romania::nr_abonati=0;

istream& operator>> (istream& in, Abonat_Skype_Romania& abonat)
{
    in >> abonat.id >> abonat.nume >> abonat.nr_telefon >> abonat.id_skype >> abonat.adresa_mail;
    return in;
}

ostream& operator<< (ostream& out, const Abonat_Skype_Romania& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.nr_telefon << ' ' << abonat.id_skype << ' ' << abonat.adresa_mail;
    return out;
}


#endif // ABONAT_SKYPE_ROMANIA_H_INCLUDED