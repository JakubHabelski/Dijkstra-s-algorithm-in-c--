#include <iostream>
//#include <windows.h> 
#include <math.h>
//#include <unistd.h>
//#include <bits/stdc++.h>
using namespace std;

int literacyfra(char a);
char liczbalitera(int a);

int main()
{
	//tab[wiersz][kolumna]
	int tab[5][2];
	  for(int i=0; i<5; i++){
	     for(int j=0; j<2; j++){
	         if(j==0) cout<<"Podaj x punktu "<<liczbalitera(i) << endl;
	         if(j==1) cout<<"Podaj y punktu "<<liczbalitera(i) <<endl;
	         cin>>tab[i][j];
	     }
	  }
	cout << endl;
	cout << tab[0][0] << " " << tab[0][1] << endl;
	cout << tab[1][0] << " " << tab[1][1] << endl;
	cout << tab[2][0] << " " << tab[2][1] << endl;
	cout << tab[3][0] << " " << tab[3][1] << endl;
	cout << tab[4][0] << " " << tab[4][1] << endl;
	cout << endl;

	int kolejka = 4;
	float odleglosc[6]; //tablica przechowująca odległości miedzy punktami
	odleglosc[0] = 100;  //przypisuje wartośc do 0 indexu żeby wykorzystać to przy szukaniu najmnijeszej odleglości
	int ps;//punkt startowy
	char psp;//punkt startowy
	float min;			// najniejsza odleglsc miedzy punktami
	cout << "Podaj punkt startowy: " << endl;
	cin >> psp;

	ps = literacyfra(psp);
	int first = ps;  // zmienna która będzie mi slużyc do liczenia odległości od ostatniego po początkowego punktu
	int index = 0;		// index najbliE<szego punktu w tablicy
	bool odwiedzone[5];		// tablica odwiedzonych punktC3w

	float suma = 0;
	float lasttofirst;

	for ( int i = 0; i < 5; i++)
	{
		odwiedzone[i] = false;
	}

	odwiedzone[ps] = true;
	int kolejnosc[6];		//kolejnoED  odowiedzenia
	kolejnosc[0] = ps ;
	kolejnosc[5] = ps ;

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i == ps)
			{
				odleglosc[i] = 100;	//na ten moment nie wiem jak inaczej pominDD  porC3wanie punktktu statr
			}
			else if (odwiedzone[i] == true)
			{
				odleglosc[i] = 100;	//na ten moment nie wiem jak inaczej pominDD  porC3wanie punktktu statr
			}
			else
			{
				odleglosc[i] =
					sqrt(pow(tab[ps][0] - tab[i][0], 2) + pow((tab[ps][1] - tab[i][1]), 2));
					cout << "Odleglosc miedzy punktem: " << liczbalitera(ps) << " a: " << liczbalitera(i) << "  wynosi: " << odleglosc[i] << endl;
			}

		}

		min = odleglosc[0];
		for (int i = 0; i < 5; i++) // szukanie indexu najbliższego punktu
		{
			if (min >= odleglosc[i])
			{
				min = odleglosc[i];
				index = i;
			}
		}

		cout << endl;
		odwiedzone[index] = true;

		for (int j = 0; j < 5; j++)
		{
			if (odwiedzone[j] == true)
			{
				cout << "Punkt : " << j + 1 << " odwiedzone" << endl;
			}
			else
			{
				cout << "Punkt : " << j + 1 << " nieodwiedzone" << endl;
			}
		}

		
		kolejnosc[k + 1] = index ;
		cout << "Najblizej punktu: "<<liczbalitera(ps)<<" jest: " << liczbalitera(index) << endl;
		cout << "Odleglosc: " << min << endl;
		cout << "Rozmiar kolejki: " << kolejka << endl;

		suma = suma + min;
		kolejka--;
		lasttofirst = sqrt(pow(tab[first][0] - tab[index][0], 2) + pow((tab[first][1] - tab[index][1]), 2));
	}

	suma = suma + lasttofirst;
	cout << endl;
	cout << "\nKolejnosc punktow: ";
	for (int i = 0; i < 6; i++)
	{			
		cout << liczbalitera(kolejnosc[i]) << " ";
	}
	cout << "\nSuma: " << suma;

}

int literacyfra(char a) {
	switch (a) {
	case 'a':  return 0;
	case 'A':  return 0;
	case 'b':  return 1;
	case 'B':  return 1;
	case 'c':  return 2;
	case 'C':  return 2;
	case 'd':  return 3;
	case 'D':  return 3;
	case 'e':  return 4;
	case 'E':  return 4;
	}

}
char liczbalitera(int a) {
	switch (a) {
	case 0: return 'A';
	case 1: return 'B';
	case 2: return 'C';
	case 3: return 'D';
	case 4: return 'E';
	}
}