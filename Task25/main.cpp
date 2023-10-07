#include <iostream>
#include <string>

bool word_palindrome(std::string str) {
	for (int i = 0; i < str.size(); i++)
		str[i] = std::tolower(str[i]);
	for (int i = 0; i < str.size() / 2; i++)
		if (str[i] != str[str.size() - i - 1])
			return false;
	return true;
}

int punctuation(const std::string& str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '!' || str[i] == '?')
			sum++;
	}
	return sum;
}	

std::string find_last_occurrence (std::string str, char sym);

int main() {
	setlocale(LC_ALL, "Russian");

	//Задание 1.
	std::cout << "Задание 1.\n";
	std::string str = "Hello world!";
	std::cout << str << std::endl;
	char sym = 'o';
	std::string new_str;
	for (int i = 0; i < str.length(); i++) 
	{
		if (str[i] == sym)
			new_str += sym;
	}
	std::cout << new_str << std::endl;
	std::cout << std::endl;

	//Задание 2.

	std::cout << "Задание 2.\n";
	std::string word;
	std::cout << "Введи слово -> ";
	std::getline(std::cin, word);
	std::cout << word_palindrome(word) << std::endl;
	std::cout << std::endl;

	//Задание 3.

	std::cout << "Задание 3.\n";
	std::cout << "Введи предложение -> ";
	std::string phrase;
	std::getline(std::cin, phrase);
	std::cin.ignore();
	std::cout << "В твоем выражении " << punctuation(phrase) << " знаков препинания или пробелов." << std::endl;
	std::cout << std::endl;

	//Задание 4.

	std::cout << "Задание 4.\n";
	std::string HW = "Hello world!";
	std::cout << HW << std::endl;
	std::cout << "Введи символ -> ";
	char sym2;
	std::cin >> sym2;
	std::cout << find_last_occurrence(HW, sym2);
	std::cout << std::endl;

	return 0;
}

std::string find_last_occurrence (std::string str, char sym) {
	if (str.rfind(sym) == std::string::npos)
		return " ";
	return str.substr(str.rfind(sym));
}