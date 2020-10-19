// Королев ДА 417 группа

/*
Записать в файл оценки (в баллах), полученные некото­рым студентом на экзаменах в течение всех сессий, и определить средний балл.
*/

#include <iostream>
#include <fstream>
#include <limits.h>
#include <math.h>

void resetInput() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "\nВведите корректные данные \n\n";
}

void isFileOpen(std::string path, std::ofstream & fout) {
	if(!fout.is_open()) {
		std::cout << "\nОшибка открытия файла\n\n";
		std::cout << path << "\n \n";
	}
	else
		std::cout << "\nФайл открыт\n\n";
}

int gradeAmountInput(float gradeAmount) {
	bool flag;
	flag = true;
	while(flag) {
		std::cout << "\nВведите количество оценок - ";
		std::cin >> gradeAmount;
		if(std::cin.fail() || gradeAmount <= 0)
			resetInput();
		else {
			std::cin.ignore(INT_MAX, '\n');
			flag = false;
		}
	}
	return gradeAmount;
}

int gradeInput(float gradeAmount, float scoreCounter, std::ofstream & fout) {
	bool flag;
	int temp;
	for(; gradeAmount != 0; gradeAmount--) {
		temp = 0;
		flag = true;
		while(flag) {
			std::cout << "\nВведите оценку по пятибальной шкале\n\n";
			std::cin >> temp;
			if(std::cin.fail() || temp <= 0 || temp > 5)
				resetInput();
			else {
				scoreCounter += temp;
				if(gradeAmount != 1)
					fout << temp << ", ";
				else 
					fout << temp << ".";
				flag = false;
			}
		}
	}
	return scoreCounter;
}

void averageScore(float scoreCounter, float gradeAmount, std::ofstream & fout) {
	fout << "\nСредний балл - ";
	fout << round(scoreCounter / gradeAmount);
}

int main() {
	std::ofstream fout;
	std::string path;
	float gradeAmount;
	float scoreCounter;
	path = "grades.txt";
	fout.open(path);
	isFileOpen(path, fout);
	gradeAmount = gradeAmountInput(gradeAmount);
	fout << "Оценки:\n";
	scoreCounter = gradeInput(gradeAmount, scoreCounter, fout);
	averageScore(scoreCounter, gradeAmount, fout);
	std::cout << "\nПрограмма завершила работу\n";
	fout.close();
}