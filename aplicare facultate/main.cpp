#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <string>
#include<cstring>
#include <cctype>
#include <algorithm>

#define up_arrow 72
#define down_arrow 80
#define enter_key 13

using namespace std;

class Student;
vector <Student> studen;
int main();

class specializare{
public:
    string nume ;
    int NrStudenti=0;
    specializare(string manevra)
    {
        this->nume=manevra;
    }
};

class facultate{
public:
    string nume;
    vector<specializare> specializari;
    int NrStudenti=0;
    facultate(string manevra)
    {
        this->nume=manevra;
    }
};

class universitate{
public:
    string nume;
    vector<facultate> facultati;
    int NrStudenti=0;
    universitate(string num)
    {
        this->nume=num;
    }

};

char statement[250];
vector<universitate> universitati;

class Student{
private:
    int age;
    float grade;
    string name;
    string highschool;
    string facultate;
    string sp;
    string uni;

public:
    Student() {};
    Student(string na,int ag,string hi, float gr,string un,string fa,string spe)
    {
        this->name=na;
        this->highschool=hi;
        this->age= ag;
        this->grade=gr;
        this->uni=un;
        this->facultate=fa;
        this->sp=spe;


    }
    friend istream & operator >> (istream &in, Student &s)
    {
        string da;
        cout<<"Introdu numele: ";
        getline(in,da);
        s.name=da;
        cout<<"Introdu varsta: ";
        getline(in,da);
        s.age=stoi(da);
        cout<<"Introdu liceul: ";
        getline(in,da);
        s.highschool=da;
        cout<<"Introdu nota de admitere: ";
        getline(in,da);
        s.grade=stof(da);
        cout<<"Introdu universitatea: ";
        getline(in,da);
        s.uni=da;
        cout<<"Introdu facultatea: ";
        getline(in,da);
        s.facultate=da;
        cout<<"Introdu specializarea: ";
        getline(in,da);
        s.sp=da;




        return in;
    }
    friend ostream & operator << (ostream &out, const Student &s)
    {
        out<<"Nume: "<<s.name <<endl;
        out<<"Varsta: " << s.age <<endl;
        out<<"Liceu: " << s.highschool<<endl;
        out<<"Nota Admitere: " << s.grade <<endl;
        out<<"Universitate: "<<s.uni<<"\n";
        out<<"Facultate: "<<s.facultate<<endl;
        out<<"Specializare: "<<s.sp<<endl;
        return out;
    }
    friend ofstream & operator << (ofstream &out, const Student &s)
    {
        out << s.name << "," << s.age << "," << s.highschool << "," << s.grade << "," << s.uni<<"," << s.facultate<<"," << s.sp <<endl;
        return out;
    }
};

void init(){
    ifstream meniu;
    meniu.open("Uni.txt");
    ifstream facul;

    string s ;
    string fa;
    string numefa;

    while(getline(meniu,s))
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);


        universitate aux(s);
        facul.open("Facultate.txt");
        while(getline(facul,fa))
        {
            transform(fa.begin(), fa.end(), fa.begin(), ::tolower);
            stringstream ss(fa);
            vector<string>v;
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }

            for (int i=0; i<v.size(); i++)
            {
                if(i==0)
                {
                    facultate manevra(v[i]);
                    aux.facultati.push_back(manevra);
                }
                else
                {
                    specializare sp(v[i]);
                    aux.facultati.back().specializari.push_back(sp);
                }


            }


        }

        universitati.push_back(aux);
        facul.close();
    }

    ifstream hamster;
    string st;

    hamster.open("Data.txt");
    while(getline(hamster,st))
    {
        transform(st.begin(), st.end(), st.begin(), ::tolower);
        stringstream sa(st);
        vector<string>stud;
        while (sa.good())
        {
            string substr;
            getline(sa, substr, ',');
            stud.push_back(substr);
        }

        Student aux(stud[0],stoi(stud[1]),stud[2],stof(stud[3]),stud[4],stud[5],stud[6]);
        studen.push_back(aux);

        for(int j=0; j<universitati.size(); j++)
        {


            if(stud[4]==universitati[j].nume)
            {
                cout<<universitati[j].nume;
                for(int k=0; k<universitati[j].facultati.size(); k++)
                {
                    if(universitati[j].facultati[k].nume==stud[5])
                    {
                        universitati[j].facultati[k].nume;
                        for(int l=0; l<universitati[j].facultati[k].specializari.size(); l++)
                        {
                            if(universitati[j].facultati[k].specializari[l].nume==stud[6])
                            {
                                universitati[j].facultati[k].specializari[l].nume;
                                universitati[j].facultati[k].specializari[l].NrStudenti++;
                                universitati[j].facultati[k].NrStudenti++;
                                universitati[j].NrStudenti++;
                            }
                        }

                    }

                }
            }






        }
    }
}

void Inscrie_te(int x){
    Student st;
    ofstream manevra;


    cout<<endl;
    cout << "Introduceti datele dv. (Nume Prenume, varsta,liceul absolvit, media de admitere):" << endl;
    cin >> st;
    manevra.open("Data.txt",std::ofstream::app);
    manevra<<st;


}

void print_option(int key_press, int main_menu_key){
    switch(key_press)
    {

    case 1:
        system("cls");
        cout << "Meniu";
        cout << "\n\n->Inscrie-te!\n  Vezi formulare\n  Vezi posibilitati\n  Statistici\n  Shut Down\n";
        break;
    case 2:
        system("cls");
        cout << "Meniu";
        cout << "\n\n  Inscrie-te!\n->Vezi formulare\n  Vezi posibilitati\n  Statistici\n  Shut Down\n";
        break;
    case 3:
        system("cls");
        cout << "Meniu";
        cout << "\n\n  Inscrie-te!\n  Vezi formulare\n->Vezi posibilitati\n  Statistici\n  Shut Down\n";
        break;
    case 4:
        system("cls");
        cout << "Meniu";
        cout << "\n\n  Inscrie-te!\n  Vezi formulare\n  Vezi posibilitati\n->Statistici\n  Shut Down\n";
        break;
    case 5:
        system("cls");
        cout << "Meniu";
        cout << "\n\n  Inscrie-te!\n  Vezi formulare\n  Vezi posibilitati\n  Statistici\n->Shut Down\n";
        break;

    }
}

void AfisForm(){
    char chr;
    for(int i=0; i<studen.size(); i++)
    {
        cout<<studen[i]<<endl;
    }
    do {}
    while((chr=getch())!=0x0D);
    main();
}

void AfisPosib(){
    char chr;
    cout<<endl;
    for(int i=0; i<universitati.size(); i++)
    {
        cout<<universitati[i].nume<<"\n";
        for(int j=0; j<universitati[i].facultati.size(); j++)
        {
            cout<<"   "<< universitati[i].facultati[j].nume<<"\n";
            for(int k=0; k<universitati[i].facultati[j].specializari.size(); k++)
            {
                cout<<"      "<< universitati[i].facultati[j].specializari[k].nume<<"\n";
            }
        }
    }
    do {}
    while((chr=getch())!=0x0D);
    main();
}

void AfisStat(){
    char chr;
    cout<<endl;
    for(int i=0; i<universitati.size(); i++)
    {
        cout<<universitati[i].nume<<": "<<universitati[i].NrStudenti<<" Inscrisi\n";
        for(int j=0; j<universitati[i].facultati.size(); j++)
        {
            cout<<"   "<< universitati[i].facultati[j].nume<<": "<<universitati[i].facultati[j].NrStudenti<<" Inscrisi\n";
            for(int k=0; k<universitati[i].facultati[j].specializari.size(); k++)
            {
                cout<<"      "<< universitati[i].facultati[j].specializari[k].nume<<": "<<universitati[i].facultati[j].specializari[k].NrStudenti<<" Inscrisi\n";
            }
        }
    }
    do {}
    while((chr=getch())!=0x0D);
    main();
}

int meniu1(int key){
    int stop = 0;
    char q;
    while(1)
    {
        q = getch();
        switch(q)
        {

        case up_arrow:
            if(key > 1)
                key --;
            print_option(key, 0);
            break;

        case down_arrow:
            if(key < 6)
                key ++;
            print_option(key, 0);
            break;

        case enter_key:
            if(key == 1)
            {
                system("cls");
                Inscrie_te(key);
                return main();
            }

            if(key == 2)
            {
                system("cls");
                AfisForm();
            }
            if(key == 3)
            {
                system("cls");
                AfisPosib();
            }
            if(key == 4)
            {
                system("cls");
                AfisStat();
            }
            if(key==5)
            {
                exit(0);
            }
        case '\b':
            stop = 1;
            key = -1;
            break;
        }
        if(stop == 1)
        {
            return key;
        }
    }
}

int main(){
    universitati.clear();
    init();
    char q;
    int key = 1;
    cout << universitati[0].facultati[0].specializari[0].NrStudenti<<" "<<universitati[0].facultati[0].specializari[0].nume;
    system("cls");
    cout << "Meniu";
    cout <<"\n\n->Inscrie-te!\n  Vezi formulare\n  Vezi posibilitati\n  Statistici\n  Shut Down\n";

    while(1)
    {
        key = meniu1(key);
        if(key == -1)
            break;
    }

    Student student[100];
    int n,i;
    cin >> n;
    cin.ignore();

    return 0;
}


