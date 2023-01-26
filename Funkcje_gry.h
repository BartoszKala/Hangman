#pragma once
#include<iostream>
#include<cstdlib> // aby wykonaæ losowanie
#include<stdlib.h>  // wychodzenie z aplikacji
#include<iomanip>  // mneu ____
#include<windows.h>  // zmina koloru czcionki
#include<time.h>   //aby wykonaæ losowanie
#include<string>    // napisy 
#include<fstream>// odczyt z pliku
#include<vector>  // odczyt z pliku
#include<cctype>   // sprawdzenie poprawnoœci wpisanych znaków 
using namespace std;


void zmiana_znakow(string slowo); // funkcja zmienia litery w '_' i na odwrót
void rysowanie(int szanse);  // funkcja odpowiedzialna za rysowanie wisielca jeœli zdarzy siê pomy³ka

void gra2();    // funkcja odpowiadaj¹ca za pobieranie od urzytkownika s³owa 
bool sprawdz(string slowo);  // funkcja sprawdzaj¹ca poprawnoœæ wpisanych znaków 

string losowanie();  // funkcja odpowiedzialna za losowanie s³owa z pliku tekstowego
void gra1();   // fukcja podaj¹ca s³owo wygenerowane pseudolosowo do odgadniêcia

void zasady();   // funkcja wypisuj¹ca zasady korzystania
void menu();  // funkcja wypisuj¹ca menu 




void zasady()   // funkcja wypisuje zasady ko¿ystania z programu
{
	HANDLE hOut{};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);    // identyfikator odpowiedzialny za kolor czcionki
	SetConsoleTextAttribute(hOut, 3);// zmiana koloru czcionki
	cout << "\n\n\t\tZasday gry w Wisielca";
	SetConsoleTextAttribute(hOut, 14);  //tekst zasad gry
	cout << "\n\nObs\210uga menu\n\nU\276ytkownikowi jest wy\230wietlana lista z dost\251pnymi opcjami do wyboru\n\n1. Zasady gray\n2. Gra z komputerem\n3. Gra ze znajomym\n4. Rezygnacja  z gry\n\nU\276ytkowinik powinien wpisa\206 numer 1 - 4, gdzie wpisany numer oznacza dzai\210anie, kt\242re nastepnie zostanie wykonane\n\n\n\n\n2. Gra z komputerem\n\n\nTwoim zadaniem jest odgani\251cie s\210owa, kt\242re zosta\210o wygenerowane przez komputer.Litery s\210owa s\245 ukryte pod podtaci\245 : _,\n\nMusisz wpisa\206 jeden ze znka\242w z podanego alfabetu :\n\n{ a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, r, s, t, u, w, x, y, z}\n\nJe\230li znak znajduje si\251 w s\210owie, zostanie on ods\210oni\251ty,\nw przeciwym przypadku tracisz 1 z dostepnych 7 szans na pomy\210k\251.\nPrzy kolejnych pomy\210kach zostanie wyswietlony ods\210aniaj\245cy si\251 wizerunek wisielca.\n\nJe\230li stracisz wszystkie szanse i ca\210y wizerunek wisielca zostanie ods\210oni\251ty; przegrywasz.\nJe\230li wszystkie znaki : _  zsotan\245 zastapione liter\245; odgad\210e\230 has\210o; wygrywasz.\n\n\n\n\n3. Gra ze znajomym\n\nNa pocz\245tku u\276ytkownik jest proszony o wpisanie s\210owa, zbudowanego przy urzyciu alfabetu :\n\n{ a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, r, s, t, u, w, x, y, z}\n\nS\210owo nie mo\276e by\206 d\210u\276sze ni\276 20 znak\242w.\n\nJe\230li znak jest niepoprawny, u\276ytkownik bedzie zmuszony poda\206 wyraz jeszcze raz.\nNast\251pnie twoim zadaniem jest odgani\251cie s\210owa.\nLitery s\210owa s\245 ukryte pod podtaci\245 : _,\n\nMusisz wpisa\206 jeden ze znka\242w z podanego alfabetu :\n\n{ a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, r, s, t, u, w, x, y, z}\n\nJe\230li znak znajduje si\251 w s\210owie, zostanie on ods\210oni\251ty,\nw przeciwym przypadku tracisz 1 z dostepnych 7 szans na pomy\210k\251.\nPrzy kolejnych pomy\210kach zostanie wyswietlony ods\210aniaj\245cy si\251 wizerunek wisielca.\n\nJe\230li stracisz wszystkie szanse i ca\210y wizerunek wisielca zostanie ods\210oni\251ty; przegrywasz.\nJe\230li wszystkie znaki : _  zsotan\245 zastapione liter\245; odgad\210e\230 has\210o; wygrywasz.\n\n\n\n4. Rezygnacja z gry\n\nPo zako\344czeniu rozgrywki, zostaniesz poproszony o dokonanie wyboru.\n\nWpisz :	\n\nM - przej\230cie do menu\n\nG - kontynu\210uj aktualn\245 rozgrywk\251\n\nR - reyzgnacja z gry";
	SetConsoleTextAttribute(hOut, 15);

	cout << "\n\nDokonaj wyboru (wpisz jedn\245 z liter M/R/G): ";

	char znak{};   // pobranie znaku w celu dalszych operacji
	cin >> znak;

	switch (znak)
	{
	case 'M':
	{system("cls");
	menu();
	break;
	}
	case 'm':    // jeœli zostanie wpisane m to przejdŸ do funkcji menu
	{system("cls");
	menu();
	break;
	}
	case'r':
	{
		exit(0);
		break;
	}
	case'R':       // jeœli zostanie wpisane r to wy³¹cz program
	{
		exit(0);
		break;
	}
	case'g':
	{  system("cls");
	zasady();
	break;
	}
	case 'G':         // zostanie wpisane g to pozostañ w funkcji zasady
	{system("cls");
	zasady();
	break;
	}
	default:       // jesli u¿ytkownik wpisze znak, który nie zosta³ przewidziany to:
	{
		SetConsoleTextAttribute(hOut, 4);
		cout << "\n\nNie ma takiej opcji do wyboru\n\nSpr\242buj jeszcze raz\n\n";
		SetConsoleTextAttribute(hOut, 15);
		system("pause");
		system("cls");
		zasady();
		break;
	}
	}
}


void menu()   // wysiwetlanie manu
{


	HANDLE hOut{};             // identyfikator odpowiedzialny za zmianê koloru czcionki
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTextAttribute(hOut, 14);
	cout << "\t\t\t\t" << setfill('_') << setw(30); // wypisanie lini rozdzielaj¹cycch napisy
	cout << "\t\t\t\t" << endl;

	cout << endl << "\t\t\t\t" << setfill(' ') << setw(15) << "MENU" << endl;

	cout << "\t\t\t\t" << setfill('_') << setw(30);
	cout << "\t\t\t\t" << endl;

	cout << endl << "\t\t\t\t" << "1. Zasady gry" << endl;

	cout << "\t\t\t\t" << setfill('_') << setw(30);
	cout << "\t\t\t\t" << endl;


	cout << endl << "\t\t\t\t" << "2. Gra z koputerem" << endl;

	cout << "\t\t\t\t" << setfill('_') << setw(30);
	cout << "\t\t\t\t" << endl;

	cout << endl << "\t\t\t\t" << "3. Gra ze znajomym" << endl;

	cout << "\t\t\t\t" << setfill('_') << setw(30);
	cout << "\t\t\t\t" << endl;

	cout << endl << "\t\t\t\t" << "4. Rezygnacja z gry" << endl;

	cout << "\t\t\t\t" << setfill('_') << setw(30);
	cout << "\t\t\t\t" << " " << endl << endl << endl;



	


	SetConsoleTextAttribute(hOut, 15);
	cout << endl << endl << endl << endl << endl << endl << endl;

	char wybor{};
	cout << "Dokonaj wyboru:";    // pobranie znaku oznaczj¹cego dane dzia³anie od u¿ytkownika
	cin >> wybor;

	

	for (; ;)
	{
		if (wybor == '1')      // jeœli u¿ytkownik wpisa³ 1 to przejdŸ do funkcji zasady
		{
			system("cls");
			zasady();
			break;
		}
		else if (wybor == '2')   // jesli wpisa³ 2 to przejdŸ do funkcji gra1 (z komputerem)
		{
			system("cls");
			gra1();
			break;
		}
		else if (wybor == '3') // jesli wpisa³ 3 to przejdŸ do funkcji gra2
		{
			system("cls");
			gra2();
			break;
		}
		else if (wybor == '4')   // jeœli wpisa³ 4 to wy³¹cz program
		{
			exit(0);
			break;
		}
		else   //   jeœli u¿ytkownik wpisa³ coœ innego to:
		{
		
			SetConsoleTextAttribute(hOut, 4);
			cout << "Nie ma takiej opcji do wyboru!\n\n";
			SetConsoleTextAttribute(hOut, 15);
			system("pause");
			system("cls");
			menu();
		}
	}

}


void rysowanie(int szanse)   // czêœæ odpowiedzialna za rysowanie wisielca
{

	HANDLE hOut{};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);  

	SetConsoleTextAttribute(hOut, 12);
	switch (szanse)
	{
	case 0:                                        // jeœli iloœæ pomy³ek u¿ytkownika wynosi 0 to:
	{
		cout << "Masz 7 szans na pomy\210k\251\n\n\n";
		break;
	}
	case 1:
	{	cout << "\n\n\n\n\n\n\n\n\n";                   //jeœli ilosc pomy³ek u¿ytkownika wynosi 1 to wyswietl:
	cout << "\t\t==================\n\n\n";
	cout << "\t\tPozosta\210o ci 6 szans\n\n\n";
	break;
	}
	case 2:
	{	cout << endl;
	cout << "\t\t                ||\n";
	cout << "\t\t                ||\n";
	cout << "\t\t                ||\n";
	cout << "\t\t                ||\n";
	cout << "\t\t                ||\n ";
	cout << "\t\t                ||\n ";
	cout << "\t\t                ||\n ";
	cout << "\t\t                ||\n ";
	cout << "\t\t==================\n\n\n";
	cout << "\t\tPozosta\210o ci 5 szans\n\n\n";
	break;
	}
	case 3:
	{
		cout << "\t\t       ===========\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t==================\n\n\n";
		cout << "\t\tPozosta\210y ci 4 szanse\n\n\n";
		break;
	}
	case 4:
	{
		cout << "\t\t       ===========\n";
		cout << "\t\t       |        ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t==================\n\n\n";
		cout << "\t\tPozosta\210y ci 3 szanse\n\n\n";
		break;

	}case 5:
	{
		cout << "\t\t       ===========\n";
		cout << "\t\t       |        ||\n";
		cout << "\t\t       O        ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t==================\n\n\n";
		cout << "\t\tPozosta\210y ci 2 szanse\n\n\n";
		break;
	}
	case 6:
	{
		cout << "\t\t       ===========\n";
		cout << "\t\t       |        ||\n";
		cout << "\t\t       O        ||\n";
		cout << "\t\t       |        ||\n";
		cout << "\t\t                ||\n";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t==================\n\n\n";
		cout << "\t\tMasz ostatni\245 szans\251!\n\n\n";
		break;
	}
	case 7:
	{
		cout << "\t\t       ===========\n";
		cout << "\t\t       |        ||\n";
		cout << "\t\t       O        ||\n";
		cout << "\t\t      /|\\       ||\n";
		cout << "\t\t      / \\       ||\n";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t                ||\n ";
		cout << "\t\t==================\n\n\n\n\n";
	}

	}
	SetConsoleTextAttribute(hOut, 7);
}


void zmiana_znakow(string slowo)  // funkcj zmienia znaki w przyjêtym s³owie
{
	HANDLE hOut{};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	char znak{};       //inicjalizacja znaku, ktory bêdzie pobierany od uzytkownika
	int dlugosc = size(slowo);
	string slowo2 = slowo; //inicjalizacja s³owa, które jest równe temu, które przyjmuje funkcja, nastepnie zmiana jego liter n '_'



	for (int i = 0; i < dlugosc; i++)        //zamiana liter z wyrazu na "_", oprócz spacji
	{
		if (slowo2[i] != 32)
		{
			slowo2[i] = '_';
		}

	}




	int liczba_zyc = 0;   // odpwiada za liczenie pomy³ek


	char alfabet[26]{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};







	while (slowo2 != slowo)//   pêtlna wykonuje siê dopuki slowo z zamienionymi znakami nie jest równe temu przyjêtemu przezz funkcje
	{


		rysowanie(liczba_zyc);        // rysowanie wisielca 

		

		cout << "Dost\251pne litery: {";   // wypisanie liter alfabetu, które jeszcze nie by³y u¿ywane
		for (int i = 0; i < 26; i++)
		{
			cout << alfabet[i] << " ";
		}
		cout << "}";
		cout << endl << endl;






		cout << "Has\210o: ";                          //wypisuje odgadniête litery, np: _ _ _ a _ _ 
		for (int a = 0; a < dlugosc; a++)
		{
			cout << slowo2[a] << " ";
		}
		cout << endl << endl;


		if (liczba_zyc == 7)         // jeœli gracz wykorzysta³ wszystkie szanse to pêtla siê przerywa
			break;





		cout << "Podaj znak: ";              //pobiera od u¿ytkownika znak
		cin >> znak;


		for (int i = 0; i < 26; i++)   // usuniêcie litery ze zbioru liter, które jeszcze nie by³y u¿yte
		{
			if (znak == alfabet[i])
			{
				alfabet[i] = ' ';   // zamiana litery w "puste pole"
			}
		}


		if (65 <= znak && znak <= 90)                    //zamiana du¿ych liter na ma³e(wpisanych podczas odgadywania)
		{
			znak = tolower(znak);
		}


		for (int i = 0; i < dlugosc; i++)   // prorównanie wpisanego znaku z literami z które s¹ ju¿ odgadniête 
		{
			if (znak == slowo2[i])
			{
				SetConsoleTextAttribute(hOut, 4);                                 //zmiana koloru czcionki 
				cout << "\nJu\276 podawa\210e\230 t\251 liter\251\n\n ";
				SetConsoleTextAttribute(hOut, 15);
				liczba_zyc++;
				break;
			}
		}




		std::size_t brak_litery = slowo.find(znak);
		if (brak_litery == std::string::npos)         //  jeœli w wyrazie nie ma wpisanej litery to powiêksz liczbê pomy³ek o 1
		{
			liczba_zyc++;
			SetConsoleTextAttribute(hOut, 4);
			cout << "\nTego znaku nie ma w ha\230le\n\n";    // komunikat w wypadku braku litery w odgadywanym haœle
			SetConsoleTextAttribute(hOut, 15);

		}
		else
		{
			for (int k = 0; k < dlugosc; k++)            // jeœli lietra znajduje siê w haœle, to zamienia pole  "_"  na odgadniêt¹ literê
			{
				if (slowo[k] == znak)
				{
					slowo2[k] = znak;
				}
			}
		}

		if (liczba_zyc > 7)             // jeœli zostan¹ wykorzystane wszystkie szanse funcja siê przerywa
			break;

		system("pause");    //"zapauzuj" program
		system("cls");           // wyczyœæ konsole


		if (slowo == slowo2)   // jesli poczatkowe s³owo i odgadywane s¹ identyczne to wypisz:
		{
			rysowanie(liczba_zyc);       //ewentualne pomy³ki

			cout << "Has\210o: ";
			for (int a = 0; a < dlugosc; a++)
			{
				cout << slowo2[a] << " ";
			}
			cout << endl << endl;

			SetConsoleTextAttribute(hOut, 10);
			cout << "\n\n\n\t\tWygra\210e\230!\n\n";    // wyswietlenie has³a
			SetConsoleTextAttribute(hOut, 14);
			cout << "Has\210o to: " << slowo << endl << endl;
			SetConsoleTextAttribute(hOut, 15);
		}
	}

	if (slowo != slowo2)  // jeœli pocz¹tkowe s³owo nie jest identyczne z tym odgatywanym to wypisz:
	{
		SetConsoleTextAttribute(hOut, 4);
		cout << "\n\n\n\t\tPrzegra\210e\230!\n\n";
		SetConsoleTextAttribute(hOut, 14);
		cout << "Has\210o to: " << slowo << endl << endl;
		SetConsoleTextAttribute(hOut, 15);


	}


}


bool sprawdz(string slowo)   //program sprawdza czy wpisane s³owo jest poprawne (na pocz¹tku gry w 2)
{

	int len = size(slowo);   //d³ugoœæ wpisanego s³owa
	if (size(slowo) > 20)   // jeœli s³owo ma ponad 20 znaków to funkcja zwraca fa³sz
	{
		return false;
	}

	int i = 0;
	while (i < len)
	{               //pêtla dzia³a dopuki nie sprawdzi ka¿dego znaku ze s³owa
	
		for (int j = 0; j < len; j++)
		{
			if ((65 <= slowo[j] && slowo[j] <= 90) || (97 <= slowo[j] && slowo[j] <= 122))
			{
				return true;
			}
		}
		
		 if (isalpha(slowo[i]) || slowo[i] == 32)    // jeœli wpisany znak  jest liter¹ lub spacj¹ to program sprawdza nastêpny znak
		{
			i++;
		}
		else if (isalpha(slowo[i]) == 0)  // funkcja isalpha sprawdza czy zank jest liter¹ 
		{
			return false;   //jeœli nie jest liter¹ zwraca fa³sz
			break;
		}
	
	}
	return true;
}





void gra2()         // uzytkownik podaje s³owo, a nastepnie odgaduje
{
	HANDLE hOut{};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);       //identyfikator odpowiadaj¹cy za zmianê koloru czcionki


	system("cls");

	string slowo;                // s³owo wpisane przez urzytkownika

	cout << endl << "Podaj s\210owo (maksymalnie 20 znak\242w): ";
	cin.ignore();       // zapobiega omijaniu linijki poni¿ej
	getline(cin, slowo);
	system("cls");



	int dlugosc = size(slowo);    // d³ugoœæ wpisanego s³owa

	for (int i = 0; i < dlugosc; i++)
	{
		if (65 <= slowo[i] && slowo[i] <= 90)                    //zamiana du¿ych liter na ma³e
		{
			slowo[i] = tolower(slowo[i]);
		}
	}



	if (sprawdz(slowo) == false)    // jeœli wpisana fraza jest nieprawid³owa funkcja wywo³uje siê na nowo (na np. liczby)
	{
		SetConsoleTextAttribute(hOut, 4);
		cout << endl << "Wpisana fraza jest nieprawid\210owa " << endl << endl;
		cout << "Spr\242buj jeszcze raz\n\n";
		SetConsoleTextAttribute(hOut, 15);
		system("pause");
		system("cls");
		slowo.clear();
		gra2();
	}
	else        //jesli jest poprawna to rozpoczyna gre
	{
		zmiana_znakow(slowo);



		for (; ;)    //po zakoñczeniu rozgrywki, betla wykonuje sie dopuki u¿ytkownik nie wpisze po¿¹danego znaku
		{
			cout << "\n\nDokonaj wyboru (wpisz jedn\245 z liter M/R/G): ";
			char znak{};
			cin >> znak;


			if (znak == 'm' || znak == 'M')   // jesli u¿ytkownik wpisa³ m to przejdŸ do menu
			{
				system("cls");
				menu();
				break;
			}
			else if (znak == 'g' || znak == 'G') // jesli u¿ytkownik wpisa³ g to kontynu³uj  aktualn¹ rozgrywkê (gre w 2 osoby)
			{
				system("cls");
				gra2();
				break;
			}
			else if (znak == 'R' || znak == 'r')  // jeœli uzytkownik wpisa³ r to wy³¹cz program
			{
				exit(0);
				break;
			}
			else
			{
				SetConsoleTextAttribute(hOut, 4);   // jeœliuzytkownik wpisa³ coœ czego nie ma do wyboru to:
				cout << "\n\nNie ma takiej opcji do wyboru\n\nSpr\242buj jeszcze raz\n\n";   // petla znowu zacznie siê od nowa
				SetConsoleTextAttribute(hOut, 15);
			}


		}

	}

}



string losowanie()    // funkcja losuje s³owo z pliku i nastêpnie je zwraca
{
	HANDLE hOut{};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	string slowo{};
	int i = 0;
	vector<string> linia{};

	ifstream plik("slowa.txt");


	if (plik.is_open())
	{
		while (getline(plik, slowo))         // odczyt s³ów z pliku i przekazanie do wektora 
		{
			linia.push_back(slowo);
			i++;
		}
		plik.close();         // zamkniecie pliku

		srand((unsigned)time(NULL));     // pseudolosowanie s³owa
		int los = (rand() % i);    // numer slowa (lini w pliku)
		return linia[los];    // s³owo zwracane przez funkcje
	}
	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, 4);                   // komunikat jeœli nie uda siê otworzyæ pliku
		cout << "\n\n\n\t\tNie mo\253na otworzy\206 pliku!\n\n";
		SetConsoleTextAttribute(hOut, 15);
		system("pause");
		system("cls");
		menu();
	}
	

	
}



void gra1()      // program wykonuje to dzia³anie gdy u¿ytkownik postanowi zagraæ z komputerem       
{

	HANDLE hOut{};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);       //identyfikator odpowiadaj¹cy za zmianê koloru czcionki

	cout << "Odgadnij has\210o:\n\n";

	zmiana_znakow(losowanie());    // rozgrywka; odgadywanie slowa pobraneg z pliku tekstowego


	for (; ;)
	{
		cout << "\n\nDokonaj wyboru (wpisz jedn\245 z liter M/R/G): ";
		char znak{};
		cin >> znak;


		if (znak == 'm' || znak == 'M')   // jesli u¿ytkownik wpisa³ m to przejdŸ do menu
		{
			system("cls");
			menu();
			break;
		}
		else if (znak == 'g' || znak == 'G') // jesli u¿ytkownik wpisa³ g to kontynu³uj  aktualn¹ rozgrywkê (gre z komputerem)
		{
			system("cls");
			gra1();
			break;
		}
		else if (znak == 'R' || znak == 'r')  // jeœli uzytkownik wpisa³ r to wy³¹cz program
		{
			exit(0);
			break;
		}
		else
		{
			SetConsoleTextAttribute(hOut, 4);   // jeœliuzytkownik wpisa³ coœ czego nie ma do wyboru to:
			cout << "\n\nNie ma takiej opcji do wyboru\n\nSpr\242buj jeszcze raz\n\n";
			SetConsoleTextAttribute(hOut, 15);
		}


	}
}





