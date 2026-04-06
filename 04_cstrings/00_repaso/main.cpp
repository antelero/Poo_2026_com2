#include <iostream>
using namespace std;

int largo(char *str){
    int cant = 0;
    while(str[cant] != '\0'){
        cant++;
    }
    return cant;
};

char* addChar(char *str, char ch)
{
    int len = largo(str);
    char* newStr = new char[len + 2]; // +1 para el nuevo carácter y +1 para el terminador nulo
    for (int i = 0; i < len; i++) {
        newStr[i] = str[i];
    }
    newStr[len] = ch; // Agregar el nuevo carácter
    newStr[len + 1] = '\0'; // Agregar el terminador nulo
    return newStr;
}

int main()
{
    int n = 5;
    int* v = new int[n];  // reserva dinámica
    for(int i = 0; i < n; i++) {
        v[i] = i * 2;
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    delete[] v;  // liberar memoria
    cout << endl;
    char* str = new char[6];  // 5 letras + '\0'
    //char* str = new char[6]{'H','o','l','a','!','\0'};
    str[0] = 'H';
    str[1] = 'o';
    str[2] = 'l';
    str[3] = 'a';
    str[4] = '!';
    str[5] = '\0';  // IMPORTANTE

    cout << str << " L:" << largo(str) << endl;
    str = addChar(str, '!');
    cout << str << " L:" << largo(str) << endl;
    delete[] str;  // liberar memoria
    return 0;
}

