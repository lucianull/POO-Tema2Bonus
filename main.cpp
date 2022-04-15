#include <iostream>
#include <fstream>
#include "agenda.h"

using namespace std;

int main()
{
    Agenda Ag;
    cout<<"Cu ajutorul acestui meniu modificam agenda de abonati."<<'\n';
    cout<<"Optiuni:"<<'\n'<<'\n';
    cout<<"0: Exit\n";
    cout<<"1: Creeaza abonat\n";
    cout<<"2: Sterge abonat cu indexul\n";
    cout<<"3: Afisare angajat cu numele\n";
    cout<<"4: Afisare numar abonati din Romania\n";
    cout<<"5: Afisare numar abonati externi\n";
    int nr;
    while(true)
    {
        cout << "\n\n" << "Introduceti instructiune\n";
        cin >> nr;
        switch (nr)
        {
        case 0:
            exit(0);
        case 1:
        {
            cout<<"Introduceti tipul abonatului (Romania/extern)\n";
            char str[10];
            cin>>str;
            if(str[0]=='R')
            {
                cout<<"Introduceti id-ul, numele, nr de telefon, id skype si adresa de mail:\n";
                int id;
                string nume, nr_tel, id_skype, adresa_mail;
                cin >> id >> nume >> nr_tel >> id_skype >> adresa_mail;
                Ag.Adaugare_element_romania(id, nume, nr_tel, id_skype, adresa_mail);
            }
            if(str[0]=='e')
            {
                cout<<"Introduceti id-ul, numele, nr de telefon, id skype si tara:\n";
                int id;
                string nume, nr_tel, id_skype, tara;
                cin >> id >> nume >> nr_tel >> id_skype >> tara;
                Ag.Adaugare_element_extern(id, nume, nr_tel, id_skype, tara);
            }
            break;
        }
        case 2:
        {
            cout << "Introduceti indexul abonatului spre a fi sters:\n";
            int nr;
            cin >> nr;
            Ag.Eliminare_element(nr);
            break;
        }
        case 3:
        {
            cout<<"Introduceti numele abonatului:\n";
            string nume;
            cin>>nume;
            Abonat_Skype* q= Ag[nume]; // supraincarcarea operatorului [] returneaza un pointer de tip Abonat_Skype, iar pentru a afisa toate datele despre acel abonat trebuie sa fac downcast spre clasa din care apartine
            if(q == NULL) // verific daca exista un abonat cu acest nume
                cout << "Nu exista nici un angajat cu numele " << nume;
            else
            {
                if(Abonat_Skype_Extern* pointer = dynamic_cast < Abonat_Skype_Extern* > (q))
                    cout << *pointer;
                if(Abonat_Skype_Romania* pointer = dynamic_cast < Abonat_Skype_Romania* > (q))
                    cout << *pointer;
            }
            break;
        }

        case 4:
        {
            cout << Ag.getNrAbonatiRomania() << '\n';
            break;
        }
        case 5:
        {
            cout << Ag.getNrAbonatiExtern() << '\n';
            break;
        }
        }
    }
    return 0;
}
