// ESEMPIO DI MEDIA PONDERATA
contenitore_di_dato_pesato obj1(5, 10);
contenitore_di_dato_pesato obj2(2, 10);
vector<contenitore_di_dato_pesato> vettore_media_per_media_ponderata;
vettore_media_per_media_ponderata.push_back(obj1);
vettore_media_per_media_ponderata.push_back(obj2);
media_ponderata(vettore_media_per_media_ponderata);

// ESEMPIO DI MEDIA ARITMETICA
vector<double> vettore_media_per_media_aritmetica;
vettore_media_per_media_aritmetica.push_back(5);
vettore_media_per_media_aritmetica.push_back(20);
media_aritmetica(vettore_media_per_media_aritmetica);

// ESEMPIO DI MEDIA GEOMETRICA
vector<double> vettore_media_per_media_geometrica;
vettore_media_per_media_geometrica.push_back(3);
vettore_media_per_media_geometrica.push_back(4);
cout << media_geometrica(vettore_media_per_media_geometrica);