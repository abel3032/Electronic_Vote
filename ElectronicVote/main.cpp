#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

class Vot{
private:
    string nume;
    string adresa;
    string cnp;
    string serie;
public:
    Vot()
    {
        nume = " ";
        adresa = " ";
        cnp = " ";
        serie= " ";
    }

    Vot(string argnume, string argadresa, string argcnp, string argserie)
    {
        nume = argnume;
        adresa = argadresa;
        cnp = argcnp;
        serie = argserie;
    }


    string getNume()
    {
        return nume;
    }

    string getAdresa()
    {
        return adresa;
    }

    string getCnp()
    {
        return cnp;
    }

    string getSerie()
    {
        return serie;
    }

};


class Candidat{
private: string nume;
    int nr_voturi;
public:
    Candidat()
    {
        nume = "";
        nr_voturi = 0;
    }
    Candidat(string argnume)
    {
        nume = argnume;
        nr_voturi = 1;
    }

    int getVoturi()
    {
        return nr_voturi;
    }

    string getNumec()
    {
        return nume;
    }

    void increment()
    {
        nr_voturi = nr_voturi + 1;
    }
};

bool comparison(Candidat A, Candidat B)
{
    return A.getVoturi()>B.getVoturi();
}

bool checkAge(string cnp)
{
    int ok = 0;
    int an_final = 0;
    char c;
    string an = "";
    if(cnp[0]=='1' || cnp[0]=='2')
    {
        return true;
    }
    if(cnp[0] == '5' || cnp[0] == '6')
    {
        if(cnp[1]=='0')
        {
            for(int i=2; i<5; i++)
            {
                c = cnp[i];
                an= an + c ;
            }
        }
        else
        {
            for(int i=1; i<5; i++)
            {
                c = cnp[i];
                an= an + c ;
            }
        }
        stringstream geek(an);
        geek >> an_final;
    }
    if(an_final >5)
        return false;
    else
        return true;

}

int main()
{
    queue <Candidat> qandidati_sortare;
    vector <Candidat> candidati_sortare;
    string nume_candidat;
    string prenume_candidat;
    char comanda2;
    string CNP_votant;
    string scandidat;
    map <string, int> candidati_voturi;
    int fraude = 0;
    char comanda;
    vector <string> cnp_deja_vot;
    //char comanda;
    //cin>>comanda;
    vector <Vot> votanti;
    ifstream ip("evidenta.csv");
    string nume, adresa, cnp, serie;
    while(ip.good())
    {
        getline(ip, nume, ',');
        getline(ip, adresa, ',');
        getline(ip, cnp, ',');
        getline(ip, serie, '\n');
        votanti.push_back(Vot(nume, adresa, cnp, serie));
    }
    while(cin>>comanda)
    {
        if(comanda =='+')
        {
            cin>>CNP_votant>>nume_candidat>>prenume_candidat;
            scandidat = nume_candidat + " " + prenume_candidat;
        }
        if(comanda == '+')
        {
            Candidat candidat;
            Vot gasit;
            int cok = 0;
            int ok = 0;
            for(int i=0; i<votanti.size(); i++)
            {
                if(votanti[i].getCnp() == CNP_votant)
                {
                    ok++;
                    if(ok==1)
                    {
                        gasit = votanti[i];
                        break;
                    }
                }
            }
            if(ok == 0 )
            {
                cout<<"CNP invalid"<<endl;
                fraude++;
            }
            if(ok == 1)
            {
                if(checkAge(CNP_votant) == true)
                {
                    for(int i=0; i<cnp_deja_vot.size(); i++)
                    {
                        if(gasit.getCnp() == cnp_deja_vot[i])
                        {
                            cok++;
                            fraude++;
                        }
                        if(cok == 1)
                        {
                            break;
                        }
                    }
                    if(cok == 0)
                    {
                        cnp_deja_vot.push_back(gasit.getCnp());
                        candidat = Candidat(scandidat);
                        if(candidati_sortare.size() == 0)
                        {
                            candidati_sortare.push_back(candidat);
                        }
                        else
                            for(int i=0; i<candidati_sortare.size(); i++)
                            {
                                if(candidati_sortare[i].getNumec() == scandidat)
                                {
                                    candidati_sortare[i].increment();
                                    break;
                                }
                                else
                                {
                                    candidati_sortare.push_back(candidat);
                                    break;
                                }
                            }


                    }
                }
                if(checkAge(CNP_votant) == false)
                    cout<<"Persoana minora"<<endl;

            }
            if(cok !=0 && ok!=0)
            {
                cout<<"Vot deja inregistrat"<<endl;
            }
        }
        if(comanda == '?') {
            for(int i=0; i<candidati_sortare.size(); i++)
            {
                qandidati_sortare.push(candidati_sortare[i]);
            }
            double suma = 0;
            cout << "Statistici" << endl;
            cout << "==========" << endl;
            for (int i=0; i<candidati_sortare.size(); i++) {
                suma = suma + candidati_sortare[i].getVoturi();
            }

            if (candidati_voturi.size() == 0) {
                cout << "Statistici" << endl;
                cout << "==========" << endl;
                cout << "Incercari de frauda: 0" << endl;
            }
            if(candidati_sortare.size() != 0 )
            {
                while(!qandidati_sortare.empty())
                {
                    Candidat qandidat;
                    qandidat = qandidati_sortare.front();
                    cout<<qandidat.getNumec()<< ": " << qandidat.getVoturi() << " voturi"
                        << " (";
                    printf("%.2f", (qandidat.getVoturi() / suma) * 100);
                    cout << "%)" << endl;
                    qandidati_sortare.pop();
                }

            }
        }
        if(comanda == '*')
        {
            for(int i=0; i<candidati_sortare.size(); i++)
            {
                qandidati_sortare.push(candidati_sortare[i]);
            }
            double suma = 0;
            cout<<"Statistici"<<endl;
            cout<<"=========="<<endl;
            for (int i=0; i<candidati_sortare.size(); i++) {
                suma = suma + candidati_sortare[i].getVoturi();
            }
            if(candidati_sortare.size() != 0 )
            {
                while(!qandidati_sortare.empty())
                {
                    Candidat qandidat;
                    qandidat = qandidati_sortare.front();
                    cout<<qandidat.getNumec()<< ": " << qandidat.getVoturi() << " voturi"
                        << " (";
                    printf("%.2f", (qandidat.getVoturi() / suma) * 100);
                    cout << "%)" << endl;
                    qandidati_sortare.pop();
                }

            }
            cout<<"Incercari de frauda: "<<fraude<<endl;
        }
    }
    return 0;
}