#include <iostream>
#include <string>
#include <fstream>
#include <limits.h>

void resetInput() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "\n Введите корректные данные \n \n";
}
 
std::string fileInput(std::string path) {
    bool flag = true;
    while(flag) {
        std::cout << "Введите полный путь к файлу \n \n";;
        std::cin >> path; 
        if(std::cin.fail()) {
            resetInput();
        } else {
            flag = false;
        }
    }
    return path;
}
 
void isFileOpen(std::string path, std::ifstream & fin) {
    bool flag = true;
    while(flag) {
        if(!fin.is_open()) {
            std::cout << "Ошибка открытия файла \n \n";
            std::cout << path << "\n \n";
            fileInput(path);
        } else {
            std::cout << "Файл открыт \n \n";
            flag = false;
        }
    }
}
 
int rowCounter(int row, std::ifstream & fin) {
    std::string temp;
    while(!fin.eof()) {
        getline(fin, temp);
        if (temp[0]) {
            row++;
        }
    }
    std::cout << "Рядов : " << row << " \n \n";
    fin.clear();
    fin.seekg(0);
    return row;
}
 
int columnCounter(int row, int column, std::ifstream & fin) {
    int elem;
    std::string str;
    elem = 0;
    while(!fin.eof()) {
        str = "";
        fin >> str;
        if(str[0])
            elem++;
    }
    column = elem / row;
    std::cout << "Элементов : " << elem << " \n \n";
    std::cout << "Столбцов : " << column << " \n \n";
    fin.clear();
    fin.seekg(0);
    return column;
}

void arrayInputFill(int** arrayInput, int row, int column, std::ifstream & fin) {
    std::string elem;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            fin >> elem;
            arrayInput[i][j] = std::stoi(elem);
        }
    }
    fin.clear();
    fin.seekg(0);
}

void arrayInputOutput(int** arrayInput, int row, int column) { 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << arrayInput[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << "\n \n";
}

void columnSumCounter(int** arrayInput, int* arrayOutput, int row, int column) {
    for(int i = 0; i < column; i++) {
        for(int j = 0; j < row; j++) {
            arrayOutput[i] += arrayInput[j][i];
        }
    }
}

void arrayOutputOutput(int* arrayOutput, int row) {
    for(int i = 0; i < row; i++) {
        std::cout << arrayOutput[i] << " ";
    }
}
 
int main() {
    std::ifstream fin;
    std::string path;
    std::string str;
    path = fileInput(path);
    fin.open(path); 
    isFileOpen(path, fin);
    int row = 0;
    int column = 0;
    int** arrayInput;
    int* arrayOutput;
    row = rowCounter(row, fin);
    column = columnCounter(row, column, fin);
    arrayInput = new int* [row];
    for (int i = 0; i < row; i++) {
        arrayInput[i] = new int[column];
    }
    arrayOutput = new int[column];
    arrayInputFill(arrayInput, row, column, fin);
    fin.close();
    arrayInputOutput(arrayInput, row, column);
    columnSumCounter(arrayInput, arrayOutput, row, column);
    arrayOutputOutput(arrayOutput, column);
}