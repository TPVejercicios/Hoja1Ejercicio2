#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;
using numeros = vector <int>;
/*Dado un array de N caracteres v1, en el que no hay elementos repetidos, y otro array de M
caracteres v2, donde N ≤ M, se quiere comprobar si todos los elementos del array v1 están
también en el array v2. Por ejemplo, si:
v1 = ‘a’ ‘h’ ‘i’ ‘m’
v2 = ‘h’ ‘a’ ‘x’ ‘x’ ‘m’ ‘i’
El resultado sería cierto, ya que todos los elementos de v1 están en v2.*/
const int arrayLenght = 10;



void ImprimeArray(char currArray[])
{
	for (int i = 0; i < arrayLenght; i++)
	{
		cout << "[" << currArray[i] << "]";
	}
	cout << endl;
}

void GeneraArrayAleatorio(char currArray[])
{
	for (int i = 0; i < arrayLenght; i++)
	{
		//limite_inferior + rand() % (limite_superior +1 - limite_inferior)
		currArray[i] = 97 + rand() % (26);
	}
}

void GeneraArrayManual(char currArray[])
{
	char valor = 0;
	for (int i = 0; i < arrayLenght; i++)
	{
		cout << "Ingrese el valor " << i << " del array " << " de " << to_string(arrayLenght) << endl;
		cin >> valor;
		currArray[i] = valor;
		cout << currArray[i] << endl;
		system("cls");
	}
}

bool RevisaArray(char v1 [],char v2 [])
{
	bool existen = false, next = false;
	int a = 0, b = 0, aux = 0;
	for (int i = 0; i < arrayLenght; i++)
	{
		while (!next && b < arrayLenght)
		{
			if (v1[a] == v2[b])
			{
				next = true;
				aux++;
			}
			b++;
		}
		a++;
		b = 0;
		next = false;
	}
	if (aux == arrayLenght)
		return true;
	else
		return false;

}

int main()
{
	modifica :
	char v1[arrayLenght], v2[arrayLenght];
	
	cout << "Ingrese un 0 para generar manualmente el array v1 o 1 para generarlo aleatoriamente" << endl;
	char choiceV1 = _getch();
	if (choiceV1 == '0')
		GeneraArrayManual(v1);
	else
		GeneraArrayAleatorio(v1);

	//char trash = _getch();

	cout << "Ingrese un 0 para generar manualmente el array v2 o 1 para generarlo aleatoriamente" << endl;
	char choiceV2 = _getch();
	if (choiceV2 == '0')
		GeneraArrayManual(v2);
	else
		GeneraArrayAleatorio(v2);


	ImprimeArray(v1);
	ImprimeArray(v2);


	bool runing = true;
	string mensaje = "Bienvenido";
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (runing)
	{
		cout << mensaje << endl;
		cout << "1.- Para comprobar vectores" << endl;
		cout << "2.- Para modificar vectores" << endl;
		cout << "3.- Salir" << endl;
		char tecla = _getch();
		switch (tecla)
		{
		case '1':
			ImprimeArray(v1);
			ImprimeArray(v2);
			if (RevisaArray(v1, v2))
				mensaje = "v1 esta contenido en v2";
			else
				mensaje = "v2 no esta contenido en v2";
				
			break;
		case '2':
			system("cls");
			goto modifica;
			break;
		case '3':
			runing = false;
			break;
		default:
			
			break;
		}
		system("cls");
	}


	return 0;
}