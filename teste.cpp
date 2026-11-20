#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void lerArquivo(){
    ifstream documento("documentos.txt");
    if(!documento.is_open()){
        cout << "Não foi possível abrir o documento. \n";
    }
    string linha;
    int contLinhas = 0;
    int maior = 0;
    int contLetras = 0;
    while(getline(documento, linha)){
        cout << linha << '\n';
        contLinhas++;
        for (int c = 0; linha[c] != '\0'; c++){
            if (linha[c] >= 'A' && linha[c] <= 'Z' || linha[c] >= 'a' && linha[c] <= 'z' ){
                contLetras = contLetras + 1;
            }
        }
        if (contLetras > maior){
                maior = contLetras;
        }
            contLetras = 0;
    }
    cout << contLinhas << '\n';
    cout << maior << '\n';
    char MAT[contLinhas][maior];

    









    
}

int main(){
    
    lerArquivo();

}