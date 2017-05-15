#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <string>
int tab[1000001] ,t[1000001],sort_up[1000001],sort_down[1000001];

using namespace std;

void kopiowanie(int tab1[],int tab2[],int n);

//funkcje sortowania
void wybor(int tab[],int n);
void babelkowe(int tab[],int n);
void wstawianie(int tab[],int n);
void quicksort(int tab[], int left, int right);
void quicksort_opt(int tab[], int left, int right);

//scalanie
void scalanie(int tab[], int start, int srodek, int koniec);
void scalanie_sort(int tab[], int start, int koniec);

//sortowanie przez zliczanie
void zliczanie_sort(int A[], int B[], int k, int rozmiar);
int max_liczba(int tablica[], int rozmiar);
void zliczanie_main(int tab[],int n);
main()
{
    int i,n;
    clock_t p;
    p=0;
    p=clock();
    srand( time( NULL ) );
    for(i=0;i<=1000001;i++)
        {
            tab[i]=rand();//losowanie
        }
    for(i=0;i<10;i++)
    {
       // cout<<tab[i]<<" ";
    }
    //cout<<"\n_____________________kopiowanie\n";
    kopiowanie(tab,t,1000001);
    kopiowanie(tab,sort_up,1000001);
    zliczanie_main(sort_up,1000001);
    int j=100000;
    while(i<1000001)
    {
        sort_down[i]=sort_up[j];
        //cout<<sort_down[i]<<endl;
        j--;
        i++;
    }

    //string const Log("log.txt");
    string const Losowe("losowe.txt");
    string const optymistyczne("optymistyczne.txt");
    string const pesymistyczne("pesymistyczne.txt");
    string const tablica("tablica.txt");
    ofstream mojStrumien(Losowe.c_str());
    ofstream mojStrumien1(optymistyczne.c_str());
    ofstream mojStrumien2(pesymistyczne.c_str());
    ofstream mojStrumien3(tablica.c_str());
    //ofstream mojStrumien4(Log.c_str());




   if(mojStrumien)
    {
        for(n=0;n<1000001;n++)
        {
            mojStrumien3<<n<<"|";
            mojStrumien3<<sort_up[n]<<"|"<<endl;
        }
        mojStrumien1 << "n|wybor|wstawianie|bablekowe|quicksort|scalanie|zliczanie" << endl;
        for(n=0;n<10000001;n=n+1000)
        {
            cout<<"\n"<<(n/10000)*5<<"%"<<endl;
            /*mojStrumien1<<n<<"|";
            kopiowanie(tab,t,n);
            p=clock();
            wybor(t,n);
            p=clock()-p;
            mojStrumien <<p<< "|";
            kopiowanie(tab,t,n);
            p=clock();
            wstawianie(t,n);
            p=clock()-p;
            mojStrumien <<p<< "|";
            kopiowanie(tab,t,n);
            p=clock();
            babelkowe(t,n);
            p=clock()-p;
            mojStrumien <<p<< "|";*/
            kopiowanie(tab,t,n);
            p=clock();
            //quicksort(t,0,n);
            p=clock()-p;
            mojStrumien <<p<< "|";
            kopiowanie(tab,t,n);
            p=clock();
            //scalanie_sort(t,0,n);
            p=clock()-p;
            mojStrumien<<p<< "|";
            kopiowanie(tab,t,n);
            p=clock();
            zliczanie_main(t,n);
            p=clock()-p;
            mojStrumien<<p<< "|"<<endl;
        }
n=0;
        cout<<"optymistyczne"<<endl;
        mojStrumien1<< "n|wybor|wstawianie|bablekowe|scalanie|zliczanie" << endl;
        for(n=0;n<=100000001;n=n+10000)
        {
            /*mojStrumien1<<n<<"|";
            cout<<"\n"<<(n/10000)*5<<"%"<<endl;
            kopiowanie(sort_up,t,n);
            p=clock();
            wybor(t,n);
            p=clock()-p;
            mojStrumien1 <<p<< "|";
            kopiowanie(sort_up,t,n);
            p=clock();
            wstawianie(t,n);
            p=clock()-p;
            mojStrumien1 <<p<< "|";
            kopiowanie(sort_up,t,n);
            p=clock();
            babelkowe(t,n);
            p=clock()-p;
            mojStrumien1 <<p<< "|";*/
            kopiowanie(sort_up,t,n);
            p=clock();
            //quicksort_opt(t,0,n);
            p=clock()-p;
            mojStrumien1<<p<< "|";
            kopiowanie(sort_up,t,n);
            p=clock();
            //scalanie_sort(t,0,n);
            p=clock()-p;
            mojStrumien1 <<p<< "|";
            kopiowanie(sort_up,t,n);
            p=clock();
            zliczanie_main(t,n);
            p=clock()-p;
            mojStrumien1 <<p<< "|"<<endl;
        }

        cout <<"pesymistyczne"<<endl;
        mojStrumien << "n|wybor|wstawianie|bablekowe|scalanie|zliczanie" << endl;
        for(n=0;n<=100000001;n=n+10000)
        {

            cout<<"\n"<<(n/10000)*5<<"%"<<endl;
            /*mojStrumien2<<n<<"|";
            kopiowanie(sort_down,t,n);
            p=clock();
            wybor(t,n);
            p=clock()-p;
            mojStrumien2 <<p<< "|";
            kopiowanie(sort_down,t,n);
            p=clock();
            wstawianie(t,n);
            p=clock()-p;
            mojStrumien2 <<p<< "|";
            kopiowanie(sort_down,t,n);
            p=clock();
            babelkowe(t,n);
            p=clock()-p;
            mojStrumien2 <<p<< "|";*/
            kopiowanie(sort_down,t,n);
            p=clock();
            //quicksort(t,0,n);
            p=clock()-p;
            mojStrumien2 <<p<< "|";
            kopiowanie(sort_down,t,n);
            p=clock();
            //scalanie_sort(t,0,n);
            p=clock()-p;
            mojStrumien2 <<p<< "|";
            kopiowanie(sort_down,t,n);
            p=clock();
            zliczanie_main(t,n);
            p=clock()-p;
            mojStrumien2 <<p<< "|"<<endl;
        }


    }
    else
    {
        cout << "B£¥D: nie mo¿na otworzyæ pliku." << endl;
    }
        for(i=0;i<10;i++)
    {
        cout<<t[i]<<" ";
    }
}


void kopiowanie(int tab1[],int tab2[],int n)
{
    for(int i=0;i<n;i++)
        {
            tab2[i]=tab1[i];
            //cout<<tab2[i];
        }
}
void wybor(int tab[],int n)
{
   int i,j,max;
	for (i = 0; i < n; i++)
	{
		max = i;
		for (j = i+1; j < n; j++)
		{
			if (tab[j] < tab[max])
				max = j;
		}
		swap(tab[i],tab[max]);

	}
}
void wstawianie(int tab[],int n)
{
    int tmp,i,j;
    for (i = 1; i < n; i++)
    {
        tmp = tab[i]; // przechowanie elementu tablicy z zmiennej pomocniczej
        for (j = i-1; j >= 0; j--)
        {
            if (tmp < tab[j]) // zamiana miejsc
                {
                    tab[j+1] = tab[j];

                }
            else
            {

                break;
            }
        }
        tab[j+1] = tmp;

    }
}
void quicksort(int tab[], int left, int right)
{
     int i=left;
     int j=right;
     int x=tab[right];
     do
        {
         while(tab[i]<x) {i++;}
         while(tab[j]>x) {j--;}
         if(i<=j)
         {
             int temp=tab[i];
             tab[i]=tab[j];
             tab[j]=temp;
             i++;
             j--;

         }

        }while(i<=j);
     if(left<j) quicksort(tab,left,j);
     if(right>i) quicksort(tab,i,right);
}
void quicksort_opt(int tab[], int left, int right)
{
     int i=left;
     int j=right;
     int x=tab[(right-left)/2];
     do
        {
         while(tab[i]<x) {i++;}
         while(tab[j]>x) {j--;}
         if(i<=j)
         {
             int temp=tab[i];
             tab[i]=tab[j];
             tab[j]=temp;
             i++;
             j--;

         }

        }while(i<=j);
     if(left<j) quicksort(tab,left,j);
     if(right>i) quicksort(tab,i,right);
}
void scalanie(int tab[], int start, int srodek, int koniec)
{
    int tab_pom [(koniec-start)]; // utworzenie tablicy pomocniczej
    int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

    while (i <= srodek && j <= koniec)
    {
        if (tab[j] < tab[i])
        {
            tab_pom[k] = tab[j];
            j++;

        }
        else
        {
            tab_pom[k] = tab[i];
            i++;

        }
        k++;

    }

    if (i <= srodek)
    {
        while (i <= srodek)
        {
            tab_pom[k] = tab[i];
            i++;
            k++;

        }
    }
    else
    {
        while (j <= koniec)
        {
            tab_pom[k] = tab[j];
            j++;
            k++;

        }
    }

    for (i = 0; i <= koniec-start; i++)
        {
            tab[start+i] = tab_pom[i];


        }
}
void scalanie_sort(int tab[], int start, int koniec)
{
    int srodek;

    if (start != koniec)
    {
        srodek = (start + koniec)/2;
        scalanie_sort(tab, start, srodek);
        scalanie_sort(tab, srodek+1, koniec);
        scalanie(tab, start, srodek, koniec);
    }
}
void babelkowe(int tab[],int n)
{
    clock_t start = clock();
    for(int i=0;i<n;i++)
        for(int j=1;j<n-i;j++)
            if(tab[j-1]>tab[j])
            {
                swap(tab[j-1], tab[j]);//zamiana miejscami

            }

}
void zliczanie_sort(int A[], int B[], int k, int rozmiar)
{
int i;
int *C = new int [k+1]; // utworzenie tablicy na statystyki; wszystkie liczby w tablicy sa nie wieksze od k, a C[i] okresla ile razy wystapila liczb i
for (i = 0; i <= k; i++) // zerowanie tablicy pomocniczej
C[i] = 0;
for (i = 0; i < rozmiar; i++)
C[(A[i])]++;
// C[i] zawiera teraz liczbe wystapien liczby i w ciagu wejsciowym
for (i = 1; i <= k; i++)
C[i] += C[i-1];
// C[i] zawiera teraz liczbe elementow mniejszych lub rownych i
for (i = rozmiar-1; i >= 0; i--)
{
B[(C[(A[i])])-1] = A[i]; // wpisanie do tablicy wynikowej pod określony indeks A[i]
C[(A[i])]--; // zmniejszenie indeksu C[i] - odejmujemy wpisana przed chwila liczbe
}
delete [] C;
}

int max_liczba(int tablica[], int rozmiar)
{
int max = tablica[0];
for (int i = 1; i < rozmiar; i++)
{
if (max < tablica[i])
max = tablica[i];
}
return max;
}

void zliczanie_main(int *tablica_wejsciowa, int ilosc_liczb)
{
// utworzenie dynamicznej dwoch tablic na 'ilosc_liczb' elementow
int i;
int *tablica_wyjsciowa = new int [ilosc_liczb+1]; // tablica zawierajaca posortowany ciag
int k = max_liczba(tablica_wejsciowa, ilosc_liczb); // wyszukanie najwiekszej liczby w ciagu wejsciowym
zliczanie_sort(tablica_wejsciowa,tablica_wyjsciowa, k, ilosc_liczb); // wywolanie funkcji sortujacej
for (i=0;i<ilosc_liczb;i++)
    tablica_wejsciowa[i]=tablica_wyjsciowa[i];
// zwolnienie tablic zaalokowanych dynamicznie
delete [] tablica_wyjsciowa;
}

