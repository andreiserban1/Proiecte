#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <string.h>


using namespace std;

class Persoana {     // CLASA "Persoana"

public:

    int idUnic;
    char* nume;
    char* initiala;
    char* prenume;
    int varsta;
    int cifraVerificareCNP;
    unsigned int* initialaCNP;
    string* dataNasteriiCNP;
    unsigned int* codUnicCNP;
    const int nrConstructor;


public:

    Persoana() : nrConstructor(1) {                                    // constructorul implicit (fara parametrii)
        this->idUnic = 1;
        this->nume = new char[strlen("Popescu") + 1];
        strcpy_s(this->nume, strlen("Popescu") + 1, "Popescu");
        this->initiala = new char[strlen("V") + 1];
        strcpy_s(this->initiala, strlen("V") + 1, "V");
        this->prenume = new char[strlen("Ion") + 1];
        strcpy_s(this->prenume, strlen("Ion") + 1, "Ion");
        this->varsta = 25;
        this->cifraVerificareCNP = 1;
        this->initialaCNP = new unsigned int[cifraVerificareCNP];
        this->dataNasteriiCNP = new string[cifraVerificareCNP];
        this->codUnicCNP = new unsigned int[cifraVerificareCNP];
        initialaCNP[0] = 5;
        dataNasteriiCNP[0] = "950808";
        codUnicCNP[0] = 987654;
    }

    Persoana(int varsta, int cifraVerificareCNP, unsigned int* initialaCNP,             // alt constructor
        string* dataNsteriiCNP, unsigned int* codUnicCNP) : nrConstructor(2) {
        this->idUnic = 1;
        this->nume = new char[strlen("") + 1];
        strcpy_s(this->nume, strlen("") + 1, "");
        this->initiala = new char[strlen("") + 1];
        strcpy_s(this->initiala, strlen("") + 1, "");
        this->prenume = new char[strlen("") + 1];
        strcpy_s(this->nume, strlen("") + 1, "");
        this->varsta = varsta;
        this->cifraVerificareCNP = 1;

        this->initialaCNP = new unsigned int[cifraVerificareCNP];
        this->dataNasteriiCNP = new string[cifraVerificareCNP];
        this->codUnicCNP = new unsigned int[cifraVerificareCNP];

        for (int i = 0; i < this->cifraVerificareCNP; i++) {
            this->initialaCNP[i] = initialaCNP[i];
            this->dataNasteriiCNP[i] = dataNasteriiCNP[i];
            this->codUnicCNP[i] = codUnicCNP[i];
        }

    }

    Persoana(int idUnic, const char* nume, const char* initiala, const char* prenume) : nrConstructor(3) {   // alt constructor
        this->idUnic = idUnic;
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
        this->initiala = new char[strlen(initiala) + 1];
        strcpy_s(this->initiala, strlen(initiala) + 1, initiala);
        this->prenume = new char[strlen(initiala) + 1];
        strcpy_s(this->prenume, strlen(prenume), prenume);
        this->varsta = 22;
        this->cifraVerificareCNP = 1;
        this->initialaCNP = new unsigned int[cifraVerificareCNP];
        this->dataNasteriiCNP = new string[cifraVerificareCNP];
        this->initialaCNP = new unsigned int[cifraVerificareCNP];
        initialaCNP[0] = 1;
        dataNasteriiCNP[0] = "771010";
        codUnicCNP[0] = 012120;

    }

    Persoana(int idUnic, const char* nume, const char* initiala,         // constructorul cu parametrii
                      const char* prenume, int varsta, int cifraVerificareCNP, unsigned int* initialaCNP,
                      string* dataNasteriiCNP, unsigned int* codUnicCNP) : nrConstructor(4) { 

        this->idUnic = idUnic;
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
        this->initiala = new char[strlen(initiala) + 1];
        strcpy_s(this->initiala, strlen(initiala) + 1, initiala);
        this->prenume = new char[strlen(prenume) + 1];
        strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
        this->varsta = varsta;
        this->cifraVerificareCNP = cifraVerificareCNP;

        this->initialaCNP = new unsigned int[cifraVerificareCNP];
        this->dataNasteriiCNP = new string[cifraVerificareCNP];
        this->codUnicCNP = new unsigned int[cifraVerificareCNP];

        for (int i = 0; i < this->cifraVerificareCNP; i++) {
            this->initialaCNP[i] = initialaCNP[i];
            this->dataNasteriiCNP[i] = dataNasteriiCNP[i];
            this->codUnicCNP[i] = codUnicCNP[i];
        }

    }
    Persoana(const Persoana& p) : nrConstructor (p.nrConstructor) {                   // constructor de copiere
        this->idUnic = p.idUnic;
        this->nume = new char[strlen(p.nume) + 1];
        strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
        this->initiala = new char[strlen(p.initiala) + 1];
        strcpy_s(this->initiala, strlen(p.initiala) + 1, p.initiala);
        this->prenume = new char[strlen(p.prenume) + 1];
        strcpy_s(this->prenume, strlen(p.prenume) + 1, p.prenume);
        this->varsta = p.varsta;
        this->cifraVerificareCNP = p.cifraVerificareCNP;

        if (this->initialaCNP != NULL)
            delete[] this->initialaCNP;
        if (this->dataNasteriiCNP != NULL)
            delete[] this->dataNasteriiCNP;
        if (this->codUnicCNP != NULL)
            delete[] this->codUnicCNP;

        this->initialaCNP = new unsigned int[cifraVerificareCNP];
        this->dataNasteriiCNP = new string[cifraVerificareCNP];
        this->codUnicCNP = new unsigned int[cifraVerificareCNP];

        for (int i = 0; i < p.cifraVerificareCNP; i++) {
            this->initialaCNP[i] = p.initialaCNP[i];
            this->dataNasteriiCNP[i] = p.dataNasteriiCNP[i];
            this->codUnicCNP[i] = p.codUnicCNP[i];
        }
    }
    Persoana operator=(const Persoana& p) {                 // supraincarcare operator =
        if (this != &p) {
            this->idUnic = p.idUnic;
            this->nume = new char[strlen(p.nume) + 1];
            strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
            this->initiala = new char[strlen(p.initiala) + 1];
            strcpy_s(this->initiala, strlen(p.initiala) + 1, p.initiala);
            this->prenume = new char[strlen(p.prenume) + 1];
            strcpy_s(this->prenume, strlen(p.prenume) + 1, p.prenume);
            this->varsta = p.varsta;
            this->cifraVerificareCNP = p.cifraVerificareCNP;

            if (this->initialaCNP != NULL)
                delete[] this->initialaCNP;
            if (this->dataNasteriiCNP != NULL)
                delete[] this->dataNasteriiCNP;
            if (this->codUnicCNP != NULL)
                delete[] this->codUnicCNP;

            this->initialaCNP = new unsigned int[cifraVerificareCNP];
            this->dataNasteriiCNP = new string[cifraVerificareCNP];
            this->codUnicCNP = new unsigned int[cifraVerificareCNP];

            for (int i = 0; i < p.cifraVerificareCNP; i++) {
                this->initialaCNP[i] = p.initialaCNP[i];
                this->dataNasteriiCNP[i] = p.dataNasteriiCNP[i];
                this->codUnicCNP[i] = p.codUnicCNP[i];
            }
        }
        return *this;
    }
    void afisarePersoana() {
        cout << " ___________________________________" << endl;
        cout << "| > ID: " << this->idUnic << endl;
        cout << "| > Nume: " << this->nume << endl;
        cout << "| > Initiala: " << this->initiala << endl;
        cout << "| > Prenume: " << this->prenume << endl;
        cout << "| > Varsta: " << this->varsta << endl;
        for (int i = 0; i < this->cifraVerificareCNP; i++) {
            cout << "| > CNP: ";
            cout << initialaCNP[i];
            cout << dataNasteriiCNP[i];
            cout << codUnicCNP[i];
        }
        cout << endl;
        cout << "|___________________________________" << endl;
       
    
    }
    friend ofstream& operator<<(ofstream& scrie, Persoana& p) {  // scriere in fisier

        scrie << p.idUnic
              << p.nume
              << p.initiala
              << p.prenume
              << p.varsta
              << p.cifraVerificareCNP;

        for (int i = 0; i < p.cifraVerificareCNP; i++) {
            scrie << p.initialaCNP[i];
            scrie << p.dataNasteriiCNP[i];
            scrie << p.codUnicCNP[i];
        }
        return scrie;

    }

    friend ifstream& operator>>(ifstream& citeste, Persoana& p) {  // citire din fisier
       
        citeste >> p.idUnic;
       
        citeste >> p.nume;
       
        citeste >> p.initiala;
       
        citeste >> p.prenume;
      
        citeste >> p.varsta;

        return citeste;
    }
    int getIDUnic() { // getter pentru id-ul utilizatorului 
        return idUnic;
    }
    void setIDUnic(int idUnic) {  // setter pentru id-ul utilizatorului 
        if (idUnic != NULL) {
            this->idUnic = idUnic;
        }
    }
    const char* getNume() { // getter pentru numele utilizatorului
        strcpy_s(nume, strlen(nume) + 1, this->nume);
        return nume;
    }
    void setNume(const char* nume) {  // setter pentru numele utilizatorului
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);

    }
    const char* getInitiala() {  // getter pentru initiala utilizatorului
        strcpy_s(initiala, strlen(initiala) + 1, this->initiala);
        return initiala;
    }
    void setInitiala(const char* initiala) {  // setter pentru initiala utilizatorului
        this->initiala = new char[strlen(initiala) + 1];
        strcpy_s(this->initiala, strlen(initiala) + 1, initiala);
    }
    const char* getPrenume() {  // getter pentru prenumele utilizatorului
        strcpy_s(prenume, strlen(prenume) + 1, this->prenume);
        return prenume;
    
    }
    void setPrenume(const char* prenume) { // setter pentru prenumele utilizatorului
        this->prenume = new char[strlen(prenume) + 1];
        strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
    }
    int getVarsta() {  // getter pentru varsta 
        return varsta;
    }
    void setVarsta(int varsta) { // setter pentru varsta
        if (varsta != NULL) {
            this->varsta = varsta;
        }
    }
    int getCNP() { // getter pentru CNP
        return cifraVerificareCNP;
    }
    void setCNP(int cifraVerificareCNP, unsigned int* initialaCNP, string* dataNasteriiCNP, unsigned int* codUnicCNP) { // setter pentru CNP
        if (cifraVerificareCNP == 1) {
            this->cifraVerificareCNP = cifraVerificareCNP;

            if (this->initialaCNP != NULL)
                delete[] this->initialaCNP;
            if (this->dataNasteriiCNP != NULL)
                delete[] this->dataNasteriiCNP;
            if (this->codUnicCNP != NULL)
                delete[] this->codUnicCNP;

            this->initialaCNP = new unsigned int[cifraVerificareCNP];
            this->dataNasteriiCNP = new string[cifraVerificareCNP];
            this->codUnicCNP = new unsigned int[cifraVerificareCNP];

            for (int i = 0; i < this->cifraVerificareCNP; i++) {
                this->initialaCNP[i] = initialaCNP[i];
                this->dataNasteriiCNP[i] = dataNasteriiCNP[i];
                this->codUnicCNP[i] = codUnicCNP[i];
            }
        }
    }
 
    friend ostream& operator<<(ostream& oStream, Persoana& p) {  // supraincare operator <<
        oStream << " ___________________________________" << endl;
        oStream << "| > ID: " << p.idUnic << endl;
        oStream << "| > Nume: " << p.nume << endl;
        oStream << "| > Initiala: " << p.initiala << endl;
        oStream << "| > Prenume: " << p.prenume << endl;
        oStream << "| > Varsta: " << p.varsta << endl;

        if (p.cifraVerificareCNP == 1) {
            for (int i = 0; i < p.cifraVerificareCNP; i++) {
                oStream << "| > CNP-ul: ";
                
                oStream << p.initialaCNP[i] << ".";
                oStream << p.dataNasteriiCNP[i] << ".";
                oStream << p.codUnicCNP[i];
                oStream << endl;

            }
            
        }
      
        return oStream;
    }
    friend istream& operator>>(istream& iStream, Persoana& p) {  // supraincarcare operator >>

        cout << "Introduceti id-ul: \n";
        cout << " > ";
        iStream >> p.idUnic;
        cout << "Introduceti numele: \n";
        cout << " > ";
        iStream >> p.nume;
        cout << "Introduceti initiala: \n";
        cout << " > ";
        iStream >> p.initiala;
        cout << "Introduceti prenumele: \n";
        cout << " > ";
        iStream >> p.prenume;
        cout << "Introduceti varsta: \n";
        cout << " > ";
        iStream >> p.varsta;
        cout << "Introduceti cifra '1' pentru verificare: \n";
        cout << " > ";
        iStream >> p.cifraVerificareCNP;

        if (p.initialaCNP != NULL) {
            delete[] p.initialaCNP;
        }
        if (p.dataNasteriiCNP != NULL) {
            delete[] p.dataNasteriiCNP;
        }
        if (p.codUnicCNP != NULL) {
            delete[] p.codUnicCNP;
        }

        p.initialaCNP = new unsigned int[p.cifraVerificareCNP];
        p.dataNasteriiCNP = new string[p.cifraVerificareCNP];
        p.codUnicCNP = new unsigned int[p.cifraVerificareCNP];

        for (int i = 0; i < p.cifraVerificareCNP; i++) {
            cout << "Introduceti prima cifra din CNP: \n";
            cout << " > ";
            iStream >> p.initialaCNP[i];
            cout << "Introduceti urmatoarele 6 cifre din CNP (data de nastere in format 'yymmdd'): \n";
            cout << " > ";
            iStream >> p.dataNasteriiCNP[i];
            cout << "Introduceti ultimele 6 cifre din CNP (codul unic): \n";
            cout << " > ";
            iStream >> p.codUnicCNP[i];
        }
       
        return iStream;
    }


    ~Persoana() {                                // destructor
        if (this->initialaCNP != NULL) {
            delete[] this->initialaCNP;
        }
        if (this->dataNasteriiCNP != NULL) {
            delete[] this->dataNasteriiCNP;
        }
        if (this->codUnicCNP != NULL) {
            delete[] this->codUnicCNP;
        }
    }

    unsigned int operator[](unsigned int element) {  // supraincarcare operator index -> extragerea indicelui din CNP
        if (element >= 0 && element <= 1) {
            return initialaCNP[element];
            
        }       
    }
    Persoana& operator++() {  // operator prefixat pentru incrementarea varstei utilizatorului
        this->varsta++;
        return *this;
    }
    Persoana operator++(int) { // operator postfixat pentru incrementare id-ului utilizatorului
        Persoana aux = *this;
        this->idUnic++;
        return aux;
    }
    Persoana& operator--() { // operator prefixat pentru decrementarea varstei utilizatorului
        this->varsta--;
        return *this;
    }
    Persoana operator--(int) { // operator postfixat pentru decrementarea id-ului utilizatorului
        Persoana aux = *this;
        this->idUnic--;
        return aux;
    }
    
};

class Utilizator : public Persoana {     // CLASA "Utilizator" (este intr-o relatie de "is a" cu clasa "Persoana")
private:

    int idLogare;
    char* parola;
    bool raspunsCaptcha;
 


public:
    char* numeUtilizator;

    Utilizator() : Persoana() {                     // constructor implicit (fara parametrii)
        this->idLogare = 66;
        this->numeUtilizator = new char[strlen("popescu.ion77") + 100];
        strcpy_s(this->numeUtilizator, strlen("popescu.ion77") + 100, "popescu.ion77");
        this->parola = new char[strlen("admin") + 100];
        strcpy_s(this->parola, strlen("admin") + 100, "admin");
        this->raspunsCaptcha = true;
    }

    Utilizator(int idLogare, const char* numeUtilizator, const char* parola, bool raspunsCaptcha, int idUnic, const char* nume, const char* initiala,
        const char* prenume, int varsta, int cifraVerificareCNP, unsigned int* initialaCNP,
        string* dataNasteriiCNP, unsigned int* codUnicCNP) : Persoana(idUnic, nume, initiala, prenume, varsta, cifraVerificareCNP,
            initialaCNP, dataNasteriiCNP, codUnicCNP) {                  // constructor cu parametrii
        this->idLogare = idLogare;
        this->numeUtilizator = new char[strlen(numeUtilizator) + 100];
        strcpy_s(this->numeUtilizator, strlen(numeUtilizator) + 100, numeUtilizator);
        this->parola = new char[strlen(parola) + 100];
        strcpy_s(this->parola, strlen(parola) + 100, parola);
        this->raspunsCaptcha = raspunsCaptcha;
    }
    void afisareUtilizator() {                    // afisare
        cout << "| > ID logare: " << this->idLogare << endl;
        cout << "| > Username: " << this->numeUtilizator << endl;
        cout << "| > Parola: " << this->parola << endl;
        cout << "| > Captcha:";
        if (this->raspunsCaptcha == true) {
            cout << " identitate verificata!\n";
        }
        else if (this->raspunsCaptcha == false) {
            cout << " robot detectat! ";
        }
        cout << "|___________________________________" << endl;

    }
    ~Utilizator() {                         // destructor
        if (this->numeUtilizator != NULL) {
            delete[] this->numeUtilizator;
        }
        if (this->parola != NULL) {
            delete[] this->parola;
        }
    }
    Utilizator(const Utilizator& u) : Persoana(u) {     // constructor de copiere
        this->idLogare = u.idLogare;
        this->numeUtilizator = new char[strlen(u.numeUtilizator) + 100];
        strcpy_s(this->numeUtilizator, strlen(u.numeUtilizator) + 100, u.numeUtilizator);
        this->parola = new char[strlen(u.parola) + 100];
        strcpy_s(this->parola, strlen(u.parola) + 100, u.parola);
        this->raspunsCaptcha = u.raspunsCaptcha;
    }

    Utilizator operator=(const Utilizator& u) {          // operator =
        Persoana::operator=(u);
        if (this != &u) {

            this->idLogare = u.idLogare;
            this->numeUtilizator = new char[strlen(u.numeUtilizator) + 100];
            strcpy_s(this->numeUtilizator, strlen(u.numeUtilizator) + 100, u.numeUtilizator);
            this->parola = new char[strlen(u.parola) + 100];
            strcpy_s(this->parola, strlen(u.parola) + 100, u.parola);
            this->raspunsCaptcha = u.raspunsCaptcha;
        }
        return *this;
    }

    const char* getNumeUtilizator() {   // getter pentru numele utilizatorului
        strcpy_s(numeUtilizator, strlen(numeUtilizator) + 100, this->numeUtilizator);
        return numeUtilizator;
    }

    void setNumeUtilizator(const char* numeUtilizator) {  // setter pentru numele utilizatorului
        this->numeUtilizator = new char[strlen(numeUtilizator) + 100];
        strcpy_s(this->numeUtilizator, strlen(numeUtilizator) + 100, numeUtilizator);
    }

    const char* getParola() {    // getter pentru parola
        strcpy_s(parola, strlen(parola) + 100, this->parola);
        return parola;
    }

    void setParola(const char* parola) {  // setter pentru parola
        this->parola = new char[strlen(parola) + 100];
        strcpy_s(this->parola, strlen(parola) + 100, parola);
    }

    int getIDLogare() {
        return idLogare;
    }

    void setIDLogare(int idLogare) {
        if (idLogare != NULL) {
            this->idLogare = idLogare;
        }
    }

    bool getRaspunsCaptcha() {    // getter pentru raspunsul captcha
        return raspunsCaptcha;
    }

    void setRaspunsCaptcha(bool raspunsCaptcha) {  // setter pentru raspunsul captcha
        if (raspunsCaptcha != NULL) {
            this->raspunsCaptcha = raspunsCaptcha;
        }
    }

    friend ostream& operator<<(ostream& oStream, const Utilizator& u) {       // supraincarcare operator <<
        oStream << "|___________________________________" << endl;
        oStream << "| > Username: ";
        oStream << u.numeUtilizator << endl;
        oStream << "| > Parola: ";
        oStream << u.parola << endl;
        oStream << "| > Captcha: ";

        if (u.raspunsCaptcha == true) {
            oStream << " identitate verificata! ";
        }
        else {
            oStream << " robot identificat! ";
        }
        oStream << endl;
        oStream << "|___________________________________" << endl;
        return oStream;

    }
    friend istream& operator>>(istream& iStream, Utilizator& u) {       // supraincarcare operator >>
        cout << "Introduceti username-ul: \n";
        cout << " > ";
        iStream >> u.numeUtilizator;
        cout << "Introduceti parola: \n";
        cout << " > ";
        iStream >> u.parola;
        cout << "\n";

        return iStream;
    }

    friend ofstream& operator<<(ofstream& scrie, Utilizator& u) {     // scriere in fisier

        scrie << u.numeUtilizator;
        scrie << u.parola;
        scrie << u.raspunsCaptcha;
    }

    friend ifstream& operator>>(ifstream& citeste, Utilizator& u) {       // citire din fisier
        citeste >> u.numeUtilizator;
        citeste >> u.parola;
        citeste >> u.raspunsCaptcha;
    }

    Utilizator operator! () {               // supraincarcare operator ! pentru captcha
        Utilizator aux = *this;
        aux.raspunsCaptcha = !aux.raspunsCaptcha;
        return aux;
    }

    Utilizator operator+(int idLogare) {   // supraincarcare operator +
        Utilizator aux = *this;
        aux.idLogare += idLogare;
        return aux;
    }

    Utilizator operator-(int idLogare) {   // supraincarcare operator -
        Utilizator aux = *this;
        aux.idLogare -= idLogare;
        return aux;
    }

    Utilizator operator/(int idLogare) {   // supraincarcare operator /
        Utilizator aux = *this;
        aux.idLogare /= idLogare;
        return aux;
    }

    Utilizator operator*(int idLogare) {   // supraincarcare operator *
        Utilizator aux = *this;
        aux.idLogare *= idLogare;
        return aux;
    }
    
};


template <class T>

class Email   {
public:
    string domeniuEmail;
    T vechimeEmail;
   
    Email(T vechimeEmail, string domeniuEmail) {
        this->domeniuEmail = domeniuEmail;
        this->vechimeEmail = vechimeEmail;
    }

    friend ostream& operator<<(ostream& oStream, const Email& e) {
        oStream << "Domeniul email-ului: " << e.domeniuEmail << endl;
        oStream << "Vechimea email-ului: " << e.vechimeEmail << endl;
        return oStream;
    }

    friend istream& operator>>(istream& iStream, Email& e) {
        cout << "Introduceti domeniul email-ului: ";
        iStream >> e.domeniuEmail;
        cout << endl;
        cout << "Introduceti vechimea email-ului: ";
        iStream >> e.vechimeEmail;
        cout << endl;
        return iStream;
    }

    T getVechimeEmail() {
        return vechimeEmail;
    }

    void setVechimeEmail(T vechimeEmail) {
        this->vechimeEmail = vechimeEmail;
    }

    void afisare() {
        cout << this->domeniuEmail << endl;
        cout << this->vechimeEmail << endl;
    }

};

enum ModStergere { Delete, Backspace, Meniu_Contextual_Stergere };
enum ModCopiere { CTRL_C, CTRL_X, Meniu_Contextual_Copiere };

class Indicatori {   // CLASA "Indicatori" -> folosita pentru masurarea diferitelor activitati facute de utilizator in aplicatie

public:
    int nrClickStanga;
    int nrClickDreapta;
    double zonaCursorX;
    double zonaCursorY;
    double vitezaRulare;
    double vitezaTastare;
    ModStergere* modStergere;
    ModCopiere* modCopiere;

    static string getModStergere(ModStergere modStergere) {
        if (modStergere == Delete) {
            return "Delete";
        }
        if (modStergere == Backspace) {
            return "Backspace";
        }
        if (modStergere == Meniu_Contextual_Stergere) {
            return "Meniul contextual de stergere";
        }
    }
    static string getModCopiere(ModCopiere modCopiere) {
        if (modCopiere == CTRL_C) {
            return "CTRL+C";
        }
        if (modCopiere == CTRL_X) {
            return "CTRL+X";
        }
        if (modCopiere == Meniu_Contextual_Copiere) {
            return "Meniul contextual de copiere";
        }
    }


    Indicatori() {                      // constructor impplicit
        this->nrClickStanga = 12;
        this->nrClickDreapta = 15;
        this->zonaCursorX = 7.88;
        this->zonaCursorY = 3.23;
        this->vitezaRulare = 215;
        this->vitezaTastare = 5;
        this->modStergere = new ModStergere[3];
        this->modCopiere = new ModCopiere[3];

        modStergere[0] = Delete;
        modStergere[1] = Backspace;
        modStergere[2] = Meniu_Contextual_Stergere;

        modCopiere[0] = CTRL_C;
        modCopiere[1] = CTRL_X;
        modCopiere[2] = Meniu_Contextual_Copiere;
    }

    Indicatori(int nrClickStanga, int nrClickDreapta, double zonaCursorX, double zonaCursorY, double vitezaRulare, double vitezaTastare,
        ModStergere* modStergere, ModCopiere* modCopiere) {   // constructor cu parametrii
        this->nrClickStanga = nrClickStanga;
        this->nrClickDreapta = nrClickDreapta;
        this->zonaCursorX = zonaCursorX;
        this->zonaCursorY = zonaCursorY;
        this->vitezaRulare = vitezaRulare;
        this->vitezaTastare = vitezaTastare;
        for (int i = 0; i < 3; i++) {
            this->modStergere[i] = modStergere[i];
            this->modCopiere[i] = modCopiere[i];
        }
    }

    ~Indicatori() {               // destructor
        if (this->modStergere != NULL) {
            delete[] this->modStergere;
        }
        if (this->modCopiere != NULL) {
            delete[] this->modCopiere;
        }
    }
    void afisareIndicatori() {
        cout << this->nrClickStanga;
    }

    Indicatori(const Indicatori& ind) {
        this->nrClickStanga = ind.nrClickStanga;
        this->nrClickDreapta = ind.nrClickDreapta;
        this->zonaCursorX = ind.zonaCursorX;
        this->zonaCursorY = ind.zonaCursorY;
        this->vitezaRulare = ind.vitezaRulare;
        this->vitezaTastare = ind.vitezaTastare;
        if (this->modStergere != NULL) {
            delete[] this->modStergere;
        }
        if (this->modCopiere != NULL) {
            delete[] this->modCopiere;
        }
        this->modStergere = new ModStergere[3];
        this->modCopiere = new ModCopiere[3];
        for (int i = 0; i < 3; i++) {
            this->modStergere[i] = ind.modStergere[i];
            this->modCopiere[i] = ind.modCopiere[i];
        }
    }

    Indicatori operator=(const Indicatori& ind) {
        if (this != &ind) {
            this->nrClickStanga = ind.nrClickStanga;
            this->nrClickDreapta = ind.nrClickDreapta;
            this->zonaCursorX = ind.zonaCursorX;
            this->zonaCursorY = ind.zonaCursorY;
            this->vitezaRulare = ind.vitezaRulare;
            this->vitezaTastare = ind.vitezaTastare;

            for (int i = 0; i < 3; i++) {
                this->modStergere[i] = modStergere[i];
                this->modCopiere[i] = modCopiere[i];
            }

        }
        return *this;
    }

    friend ostream& operator<<(ostream& oStream, const Indicatori& ind) {
        oStream << "Numarul de click-uri stanga: " << ind.nrClickStanga << endl;
        oStream << "Numarul de click-uri dreapta: " << ind.nrClickDreapta << endl;
        oStream << "Zona in care tine cursorul pe axa X: " << ind.zonaCursorX << endl;
        oStream << "Zona in care tine cursorul pe axa Y: " << ind.zonaCursorY << endl;
        oStream << "Viteza de rulare: " << ind.vitezaRulare << endl;
        oStream << "Viteza de tastare: " << ind.vitezaTastare << endl;
        for (int i = 0; i < 1; i++) {
            oStream << "Modul de stergere: " << getModStergere(ind.modStergere[i]) << endl;
            oStream << "Modul de copiere: " << getModCopiere(ind.modCopiere[i]) << endl;
            break;
        }


        return oStream;
    }

    friend istream& operator>>(istream& iStream, Indicatori& ind) {
        cout << "Introduceti numarul de click-uri stanga: ";
        iStream >> ind.nrClickStanga;
        cout << endl;
        cout << "Introduceti numarul de click-uri dreapta ";
        iStream >> ind.nrClickDreapta;
        cout << endl;
        cout << "Introduceti zona in care se tine cursorul pe axa X: ";
        iStream >> ind.zonaCursorX;
        cout << endl;
        cout << "Introduceti zona in care se tine cursorul pe axa Y: ";
        iStream >> ind.zonaCursorY;
        cout << endl;
        cout << "Introduceti viteza de rulare: ";
        iStream >> ind.vitezaRulare;
        cout << endl;
        cout << "Introduceti viteza de tastare: ";
        iStream >> ind.vitezaTastare;
        cout << endl;

        int a;
        cout << "Introduceti o valoare pentru modul de stergere (0 = Delete, 1 = Backspace, 2 = Meniu_Contextual_Stergere): ";
        iStream >> a;
        if (a == 0) {
            ind.modStergere[0] = Delete;
        }
        if (a == 1) {
            ind.modStergere[1] = Backspace;
        }
        if (a == 2) {
            ind.modStergere[2] = Meniu_Contextual_Stergere;
        }
        int b;
        cout << "Introduceti o valoare pentru modul de copiere (0 = CTRL+C, 1 = CTRL+X, 2 = Meniu_Contextual_Copiere): ";
        iStream >> b;
        if (a == 0) {
            ind.modCopiere[0] = CTRL_C;
        }
        if (a == 1) {
            ind.modCopiere[1] = CTRL_X;
        }
        if (a == 2) {
            ind.modCopiere[2] = Meniu_Contextual_Copiere;
        }
        return iStream;
    }

    int getNrClickStanga() {
        return nrClickStanga;
    }

    int getNrClickDreapta() {
        return nrClickDreapta;
    }

    double getZonaCursorX() {
        return zonaCursorX;
    }

    double getZonaCursorY() {
        return zonaCursorY;
    }

    double getVitezaRulare() {
        return vitezaRulare;
    }

    double getVitezaTastare() {
        return vitezaTastare;
    }

    ModStergere* getModStergere() {
        return modStergere;
    }

    ModCopiere* getModCopiere() {
        return modCopiere;
    }

    void setNrClickStanga(int nrClickStanga) {
        if (this->nrClickStanga != NULL) {
            this->nrClickStanga = nrClickStanga;
        }
    }

    void setNrClickDreapta(int nrClickDreapta) {
        if (this->nrClickDreapta != NULL) {
            this->nrClickDreapta = nrClickDreapta;
        }
    }

    void setZonaCursorX(double zonaCursorX) {
        if (this->zonaCursorX != NULL) {
            this->zonaCursorX = zonaCursorX;
        }
    }

    void setZonaCursorY(double zonaCursorY) {
        if (this->zonaCursorY != NULL) {
            this->zonaCursorY = zonaCursorY;
        }
    }

    void setVitezaRulare(double vitezaRulare) {
        if (this->vitezaRulare != NULL) {
            this->vitezaRulare = vitezaRulare;
        }
    }

    void setVitezaTastare(double vitezaTastare) {
        if (this->vitezaTastare != NULL) {
            this->vitezaTastare = vitezaTastare;
        }
    }

    Indicatori operator++() {   // supraincarcare operator ++ prefixat pentru incrementarea numarului de click-uri stanga
        this->nrClickStanga++;
        return *this;
    }

    Indicatori operator++(int) {  // supraincarcare operator ++ postfixat pentru incrementarea numarului de click-uri dreapta
        Indicatori aux;
        aux.nrClickDreapta++;
        return aux;
    }

    Indicatori operator--() {    // supraincarcare operator -- prefixat pentru decrementarea axei longitudinale X, ce masoara zona in care este mouse-ul
        this->zonaCursorX--;
        return *this;
    }

    Indicatori operator--(int) {    // supraincarcare operator -- postfixat pentru decrementarea axei latitudinale Y, ce masoara zona in care este mouse-ul
        Indicatori aux;
        aux.zonaCursorY--;
        return aux;
    }

    int operator[](int index) {    // supraincarcare operator index pentru extragerea unei metode de stergere la alegere
        if (index >= 0 && index <= 3) {
            return modStergere[index];
        }

    }

};


int main() {

    Persoana p1;
    Persoana p2(2, "Stefan", "P", "Vlad", 18, 1,
        new unsigned int[1] {1}, new string[1]{ "040309" }, new unsigned int[1] {354669});
    Utilizator u1;
    Utilizator u2(33, "stefan.vlad01", "parola1234", true, 1, "Stefan", "P", "Vlad", 18, 1,
        new unsigned int[1] {1}, new string[1]{ "040309" }, new unsigned int[1] {354669});
    Indicatori i1;


    int nrClickuri;
    float zonaCursor;
    double vitezaRulareSauTastare;
    int modDeStergere = i1.modStergere[0];
    int modDeCopiere = i1.modCopiere[1];

    string introducereUtilizator;

    fstream dateUtilizator;
    dateUtilizator.open("date_sesiuni.txt", ios::out);
    dateUtilizator << p1 << u1 << endl;
    dateUtilizator << p2 << u2 << endl;
    dateUtilizator.close();

    dateUtilizator.open("date_sesiuni.txt.", ios::in);
    string afisare;
    while (getline(dateUtilizator, afisare)) {
        cout << afisare << endl;
    }
    cout << " Introduceti username-ul ('popescu.ion77' sau 'stefan.vlad01'): ";
    cin >> introducereUtilizator;

    if (introducereUtilizator == "popescu.ion77") {
        cout << endl;
        cout << "Utilizatorul " << u1.getNumeUtilizator() << ":" << endl;
        cout << "- a dat click stanga in aplicatie de (valoare maxima asteptata -> 12 click-uri): ";
        cin >> nrClickuri;
        if (nrClickuri <= i1.nrClickStanga) {
            cout << "- a dat click dreapta in aplicatie de (valoare maxima asteptata -> 15 click-uri): ";
            cin >> nrClickuri;
            if (nrClickuri <= i1.nrClickDreapta) {
                cout << "- are cursorul plasat din punct de vedere longitudinal pe pozitia (valoare minima asteptata -> 7.88 grade): ";
                cin >> zonaCursor;
                if (zonaCursor >= i1.zonaCursorX) {
                    cout << "- are cursorul plasat din punct de vedere latitudinal  pe pozitia (valoare minima asteptata -> 3.23 grade): ";
                    cin >> zonaCursor;
                    if (zonaCursor >= i1.zonaCursorY) {
                        cout << "- are o viteza de rulare de (valoare asteptata cuprinsa intre 170 si 215 px/s): ";
                        cin >> vitezaRulareSauTastare;
                        if (vitezaRulareSauTastare >= 170 && vitezaRulareSauTastare <= i1.vitezaRulare) {
                            cout << "- are o viteza de tastare de (valoare minima asteptata -> 5 taste/s): ";
                            cin >> vitezaRulareSauTastare;
                            if (vitezaRulareSauTastare >= i1.vitezaTastare) {
                                cout << "- foloseste o metoda de stergere (Delete = '0' / Backspace = '1' / Meniul contextual = '2'. Valoare asteptata -> Delete = '0'): ";
                                cin >> modDeStergere;
                                if (modDeStergere == i1.modStergere[0]) {
                                    cout << "- foloseste o metoda de copiere ( CTRL+C = '0' / CTRL+X = '1' / Meniul contextual = '2'. Valoare asteptata -> CTRL+X = '1'): ";
                                    cin >> modDeCopiere;
                                    if (modDeCopiere == i1.modStergere[1]) {
                                        fstream Scriere;
                                        Scriere.open("sesiuni.txt", ios::out | ios::app);
                                        Scriere << "Utilizatorul '" << u1.getNumeUtilizator() << "' s-a autentificat cu succes! \n";
                                        Scriere.close();
                                        cout << "Utilizatorul '" << u1.getNumeUtilizator() << "' s-a autentificat cu succes! \n";

                                    }
                                    else {
                                        fstream Scriere;
                                        Scriere.open("sesiuni.txt", ios::out | ios::app);
                                        Scriere << "Autentificare invalida din partea utilizatorului " << u1.getNumeUtilizator() << "\n";
                                        Scriere.close();
                                        cout << "Autentificare invalida din partea utilizatorului '" << u1.getNumeUtilizator() << "' \n";
                                    }
                                }
                                else {
                                    fstream Scriere;
                                    Scriere.open("sesiuni.txt", ios::out | ios::app);
                                    Scriere << "Autentificare invalida din partea utilizatorului " << u1.getNumeUtilizator() << "\n";
                                    Scriere.close();
                                    cout << "Autentificare invalida din partea utilizatorului '" << u1.getNumeUtilizator() << "' \n";
                                }
                            }
                            else {
                                fstream Scriere;
                                Scriere.open("sesiuni.txt", ios::out | ios::app);
                                Scriere << "Autentificare invalida din partea utilizatorului " << u1.getNumeUtilizator() << "\n";
                                Scriere.close();
                                cout << "Autentificare invalida din partea utilizatorului '" << u1.getNumeUtilizator() << "' \n";
                            }
                        }

                        else {
                            fstream Scriere;
                            Scriere.open("sesiuni.txt", ios::out | ios::app);
                            Scriere << "Autentificare invalida din partea utilizatorului " << u1.getNumeUtilizator() << "\n";
                            Scriere.close();
                            cout << "Autentificare invalida din partea utilizatorului '" << u1.getNumeUtilizator() << "' \n";
                        }
                    }
                    else {
                        fstream Scriere;
                        Scriere.open("sesiuni.txt", ios::out | ios::app);
                        Scriere << "Autentificare invalida din partea utilizatorului " << u1.getNumeUtilizator() << "\n";
                        Scriere.close();
                        cout << "Autentificare invalida din partea utilizatorului '" << u1.getNumeUtilizator() << "' \n";
                    }
                }
                else {
                    fstream Scriere;
                    Scriere.open("sesiuni.txt", ios::out | ios::app);
                    Scriere << "Autentificare invalida din partea utilizatorului " << u1.getNumeUtilizator() << "\n";
                    Scriere.close();
                    cout << "Autentificare invalida din partea utilizatorului '" << u1.getNumeUtilizator() << "' \n";
                }
            }
            else {
                fstream Scriere;
                Scriere.open("sesiuni.txt", ios::out | ios::app);
                Scriere << "Autentificare invalida din partea utilizatorului " << u1.getNumeUtilizator() << "\n";
                Scriere.close();
                cout << "Autentificare invalida din partea utilizatorului '" << u1.getNumeUtilizator() << "' \n";
            }
        }
        else {
            fstream Scriere;
            Scriere.open("sesiuni.txt", ios::out | ios::app);
            Scriere << "Autentificare invalida din partea utilizatorului " << u1.getNumeUtilizator() << "\n";
            Scriere.close();
            cout << "Autentificare invalida din partea utilizatorului '" << u1.getNumeUtilizator() << "' \n";
        }
    }
    else if (introducereUtilizator != "popescu.ion77" && introducereUtilizator != "stefan.vlad01") {
        cout << "Utilizator nerecunoscut! ";
    }
    else {
        if (introducereUtilizator == "stefan.vlad01") {
            cout << endl;
            cout << "Utilizatorul " << u2.getNumeUtilizator() << ":" << endl;
            cout << "- a dat click stanga in aplicatie de (valoare maxima asteptata -> 12 click-uri): ";
            cin >> nrClickuri;
            if (nrClickuri <= i1.nrClickStanga) {
                cout << "- a dat click dreapta in aplicatie de (valoare maxima asteptata -> 15 click-uri): ";
                cin >> nrClickuri;
                if (nrClickuri <= i1.nrClickDreapta) {
                    cout << "- are cursorul plasat din punct de vedere longitudinal pe pozitia (valoare minima asteptata -> 7.88 grade): ";
                    cin >> zonaCursor;
                    if (zonaCursor >= i1.zonaCursorX) {
                        cout << "- are cursorul plasat din punct de vedere latitudinal  pe pozitia (valoare minima asteptata -> 3.23 grade): ";
                        cin >> zonaCursor;
                        if (zonaCursor >= i1.zonaCursorY) {
                            cout << "- are o viteza de rulare de (valoare asteptata cuprinsa intre 170 si 215 px/s): ";
                            cin >> vitezaRulareSauTastare;
                            if (vitezaRulareSauTastare >= 170 && vitezaRulareSauTastare <= i1.vitezaRulare) {
                                cout << "- are o viteza de tastare de (valoare minima asteptata -> 5 taste/s): ";
                                cin >> vitezaRulareSauTastare;
                                if (vitezaRulareSauTastare >= i1.vitezaTastare) {
                                    cout << "- foloseste o metoda de stergere (Delete = '0' / Backspace = '1' / Meniul contextual = '2'. Valoare asteptata -> Delete = '0'): ";
                                    cin >> modDeStergere;
                                    if (modDeStergere == i1.modStergere[0]) {
                                        cout << "- foloseste o metoda de copiere ( CTRL+C = '0' / CTRL+X = '1' / Meniul contextual = '2'. Valoare asteptata -> CTRL+X = '1'): ";
                                        cin >> modDeCopiere;
                                        if (modDeCopiere == i1.modStergere[1]) {
                                            fstream Scriere;
                                            Scriere.open("sesiuni.txt", ios::out | ios::app);
                                            Scriere << "Utilizatorul '" << u2.getNumeUtilizator() << "' s-a autentificat cu succes! \n";
                                            Scriere.close();
                                            cout << "Utilizatorul '" << u2.getNumeUtilizator() << "' s-a autentificat cu succes! \n";

                                        }
                                        else {
                                            fstream Scriere;
                                            Scriere.open("sesiuni.txt", ios::out | ios::app);
                                            Scriere << "Autentificare invalida din partea utilizatorului " << u2.getNumeUtilizator() << "\n";
                                            Scriere.close();
                                            cout << "Autentificare invalida din partea utilizatorului '" << u2.getNumeUtilizator() << "' \n";
                                        }
                                    }
                                    else {
                                        fstream Scriere;
                                        Scriere.open("sesiuni.txt", ios::out | ios::app);
                                        Scriere << "Autentificare invalida din partea utilizatorului " << u2.getNumeUtilizator() << "\n";
                                        Scriere.close();
                                        cout << "Autentificare invalida din partea utilizatorului '" << u2.getNumeUtilizator() << "' \n";
                                    }
                                }
                                else {
                                    fstream Scriere;
                                    Scriere.open("sesiuni.txt", ios::out | ios::app);
                                    Scriere << "Autentificare invalida din partea utilizatorului " << u2.getNumeUtilizator() << "\n";
                                    Scriere.close();
                                    cout << "Autentificare invalida din partea utilizatorului '" << u2.getNumeUtilizator() << "' \n";
                                }
                            }

                            else {
                                fstream Scriere;
                                Scriere.open("sesiuni.txt", ios::out | ios::app);
                                Scriere << "Autentificare invalida din partea utilizatorului " << u2.getNumeUtilizator() << "\n";
                                Scriere.close();
                                cout << "Autentificare invalida din partea utilizatorului '" << u2.getNumeUtilizator() << "' \n";
                            }
                        }
                        else {
                            fstream Scriere;
                            Scriere.open("sesiuni.txt", ios::out | ios::app);
                            Scriere << "Autentificare invalida din partea utilizatorului " << u2.getNumeUtilizator() << "\n";
                            Scriere.close();
                            cout << "Autentificare invalida din partea utilizatorului '" << u2.getNumeUtilizator() << "' \n";
                        }
                    }
                    else {
                        fstream Scriere;
                        Scriere.open("sesiuni.txt", ios::out | ios::app);
                        Scriere << "Autentificare invalida din partea utilizatorului " << u2.getNumeUtilizator() << "\n";
                        Scriere.close();
                        cout << "Autentificare invalida din partea utilizatorului '" << u2.getNumeUtilizator() << "' \n";
                    }
                }
                else {
                    fstream Scriere;
                    Scriere.open("sesiuni.txt", ios::out | ios::app);
                    Scriere << "Autentificare invalida din partea utilizatorului " << u2.getNumeUtilizator() << "\n";
                    Scriere.close();
                    cout << "Autentificare invalida din partea utilizatorului '" << u2.getNumeUtilizator() << "' \n";
                }
            }
            else {
                fstream Scriere;
                Scriere.open("sesiuni.txt", ios::out | ios::app);
                Scriere << "Autentificare invalida din partea utilizatorului " << u2.getNumeUtilizator() << "\n";
                Scriere.close();
                cout << "Autentificare invalida din partea utilizatorului '" << u2.getNumeUtilizator() << "' \n";
            }
        }

    }

}