//ADS - SS 2013        Ruben Terry Zavaleta (Matr.Nr. 187139)   Gruppe 1
//Datum 18.04.2013
// Praktikum 2 Augabe 4.


#include "RBtree.h"
#include <iostream>
#include <conio.h>
using namespace std;




int typ_menu()
{
	int opt = 0;
	cout << "\n1: Eingabe integer Zahlen\n"
		<< "2: Eingabe Character\n";
	while (opt<1 || opt >2) opt = (_getche() - '0');
	cout << endl;
	return opt;
}

int opt_menu()
{
	int opt = 0;
	cout << "\n1: Ausgabe des Baumes in Level order\n"
		<< "2: Ausgabe des Baumes in Preorder\n"
		<< "3: Ausgabe des Baumes in Postorder\n"
		<< "4: Ausgabe des Baumes in Inorder\n"
		<< "5: Element suchen\n"
		<< "6: Element loeschen\n"
		<< "7: Element insert\n"
		<< "8: Element eines Niveaus ausgeben\n"
		<< "9: Beenden \n";
	while (opt<1 || opt >9) opt = _getche() - '0';
	cout << endl;
	return opt;
}

int main()
{
	int opt = typ_menu();
	if (opt>1){
		//#define LINUX void
	}
//#ifdef LINUX 
//#define uint char 
//	char ende = '0';
//	RBtree baum;
//	// anderer Code 
//#else		
//#define uint int
	int ende = 0;
	RBtree baum;
//	// wieder anderer Code 
//#endif 
//
	//#define uint(a)  (a==1 ? int : char)

	int wert;


	cout << "\n\n    4. Aufgabe \n\n Geben Sie die Werte ein ( Ende = 0 )\n";
	do
	{
		cin >> wert;
		if (wert != ende) baum.insert(wert);
	} while (wert != ende);	// Daten lesen bis 0 eingegeben wurde
	while (1)
	{
		opt = opt_menu();
		switch (opt)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			baum.baum_malen();
			break;
		//case 5:
		//	cout << "\n Knoten suchen: ";
		//	cin >> wert;
		//	cout << " Zahl " << wert << (baum.suchen(wert) ? "" : " nicht") << " gefunden\n";
		//	break;
		//case 6:
		//	cout << "\n Knoten loeschen: ";
		//	cin >> wert;
		//	if (!baum.entfernen(wert))
		//		cout << " loeschen nicht moeglich Wert nicht gefunden\n";
		//	break;
		//case 7:
		//	cout << "\n Element insert: ";
		//	cin >> wert;
		//	baum.insert(wert);
		//	break;
		//case 8:
		//	cout << "\n Element eines Niveaus ausgeben: ";
		//	cin >> wert;
		//	baum.levelorder(wert);
		//	break;
		case 9:
			return 0;
		}
	}
}
