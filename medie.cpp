#include <vector>
#include <cmath>
#include <iostream>
#include "messaggi_di_errore.cpp"

using namespace std;

//          CLASSI UTILI PER LE MEDIE

class contenitore_di_dato_pesato
{
public:
    double dato;
    double peso;

public:
    contenitore_di_dato_pesato(double dato_esterno, double peso_esterno)
    {
        dato = dato_esterno;
        peso = peso_esterno;
    }

    double get_dato()
    {
        return dato;
    }

    double get_peso()
    {
        return peso;
    }
};

//          FUNZIONI DELLE MEDIE

double media_ponderata(vector<contenitore_di_dato_pesato> &vettore_di_dati)
{

    // IL NUMERATORE È DELLO STESSO TIPO DEL PRODOTTO TRA UN PESO E UN DATO
    auto numeratore = 0.0;

    // IL DENOMINATORE AVRA' LO STESSO TIPO DEL PESO
    double denominatore = 0.0;

    const long long int &lunghezza_vettore = vettore_di_dati.size();

    // CALCOLA IL DENOMINATORE(SOMMA DEI PESI)
    for (size_t index = 0; index < lunghezza_vettore; index++)
    {
        denominatore += vettore_di_dati[index].get_peso();
    }

    if (denominatore <= 0)
    {
        throw denominatore_nullo;
    }

    // CALCOLA IL NUMERATORE(SOMMA DEI PRODOTTI DATI DA PESO N-ESIMO * DATO N-ESIMO)
    for (size_t index1 = 0; index1 < lunghezza_vettore; index1++)
    {
        if (vettore_di_dati[index1].get_dato() == 0 || vettore_di_dati[index1].get_peso() == 0)
        {
            continue;
        }
        else
        {
            numeratore += vettore_di_dati[index1].get_dato() * vettore_di_dati[index1].get_peso();
        }
    }

    // RITORNA LA MEDIA PONDERATA;
    return numeratore / denominatore;
}

double media_aritmetica(vector<double> &vettore_di_dati)
{
    double numeratore = 0.0;
    long long int denominatore = vettore_di_dati.size();
    long long int &lunghezza_vettore = denominatore;

    if (lunghezza_vettore == 0)
    {
        throw denominatore_nullo;
    }

    for (size_t index = 0; index < lunghezza_vettore; index++)
    {
        numeratore += vettore_di_dati[index];
    }

    return numeratore / denominatore;
}

double media_geometrica(vector<double> &vettore_di_dati)
{

    long long int lunghezza_vettore = vettore_di_dati.size();
    double radicando = 1.0;

    if (lunghezza_vettore == 0)
    {
        throw vettore_nullo;
    }

    for (size_t index = 0; index < lunghezza_vettore; index++)
    {
        radicando *= vettore_di_dati[index];
    }

    if (radicando < 0)
    {
        throw valore_minore_di_zero;
    }
    else
    {
        return pow(radicando, 1 / double(lunghezza_vettore));
    }
}