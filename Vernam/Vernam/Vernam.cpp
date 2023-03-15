#include <iostream>
#include <fstream>
#include <locale.h>

using namespace std;

int textLen = 0;

string readFile() 
{
	const char* fileName = "originalText.txt";
	char ch;
	string text = "";
	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Файл не неайден!" << endl;
	}
	else
	{
		while (file.get(ch))
		{
			textLen++;
			text += ch;
		}
	}
	return text;
}

char* writeOriginalText(string text)
{
	char* originalText = new char[textLen];
	for (size_t i = 0; i < textLen; i++)
	{
		originalText[i] = text[i];
	}
	return originalText;
}

char* generateKey()
{
	char* key = new char[textLen];
	for (size_t i = 0; i < textLen; i++)
	{
		key[i] = (char)rand() % 256;
	}
	return key;
}

char* encryptText(char* originalText, char* key)
{
	char* cipherText = new char[textLen];
	for (size_t i = 0; i < textLen; i++)
	{
		cipherText[i] = originalText[i] ^ key[i];
	}
	return cipherText;
}

void writeEncryptedMessageToFile(char* text)
{
	const char* fileName = "cipherText.txt";
	ofstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		for (size_t i = 0; i < textLen; i++)
		{
			file << text[i];
		}
	}
	file.close();
}

char* decipherText(char* cipherText , char* key)
{
	char* decryptText = new char[textLen];
	for (size_t i = 0; i < textLen; i++)
	{
		decryptText[i] = cipherText[i] ^ key[i];
	}
	return decryptText;
}

void printOriginalText(char* originalText)
{
	cout << "Текст: ";
	for (size_t i = 0; i < textLen; i++)
	{
		cout << originalText[i];
	}
	cout << endl;
}

void printCipherText(char* cipherText)
{
	cout << "Зашифрованный текст: ";
	for (size_t i = 0; i < textLen; i++)
	{
		cout << cipherText[i];
	}
	cout << endl;
}

void printDecryptText(char* decryptText)
{
	cout << "Расшифрованный текст: ";
	for (size_t i = 0; i < textLen; i++)
	{
		cout << decryptText[i];
	}
	cout << endl;
}

int main(int args, char* argv[])
{
	setlocale(LC_ALL, "ru");

	string text = readFile();

	char* originalText = writeOriginalText(text);
	char* key = generateKey();
	char* cipherText = encryptText(originalText, key);
	char* decryptText = decipherText(cipherText, key);

	printOriginalText(originalText);
	printCipherText(cipherText);
	writeEncryptedMessageToFile(cipherText);
	printDecryptText(decryptText);

	system("pause");
	return 0;
}
