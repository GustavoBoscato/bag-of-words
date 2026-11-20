#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> lerArquivo(string nomeDocumento){
    ifstream documento(nomeDocumento);
    if(!documento.is_open()){
        cout << "Não foi possível abrir o documento. \n";
        return {};
    }
    vector<string> MAT;
    string linha;
    
    while(getline(documento, linha)){
        string linhaFormatada;
        bool espaco = true;
        for (int c = 0; linha[c] != '\0' ; c++)
        {
            if (linha[c] >= 'A' && linha[c] <= 'Z'  ){
                linhaFormatada.push_back(linha[c] + ' ');
                espaco = false;
            } else if (linha[c] >= 'a' && linha[c] <= 'z' ){
                linhaFormatada.push_back(linha[c]);
                espaco = false;
            } else if (linha[c] == ' ' && espaco == false){
                linhaFormatada.push_back(' ');
                espaco = true;
            }

        }
            MAT.push_back(linhaFormatada);

    }
    return MAT;
}

void imprimirDocumento(vector<string> MAT){
    for (int i = 0; i < (int)MAT.size(); i++){;
        for (int j = 0; j <= (int)MAT[i].size(); j++){
            char letra = MAT[i][j];
            cout << letra;
            }
            cout << '\n';
        }
        
    }

vector<string> puxarVocabulario(vector<string> MAT){

    vector<string> vocabulario; 
    
    for (int i = 0; i < (int)MAT.size(); i++){
        string palavra;
        for (int j = 0; j <= (int)MAT[i].size(); j++){
            char letra = MAT[i][j];
            if (letra != ' ' && letra != '\0'){
                palavra.push_back(letra);
            } else if((int)palavra.size() > 0){
                bool existeVocabulario = false;
                for (int c = 0; c < (int)vocabulario.size(); c++){
                    if (vocabulario[c] == palavra){
                        existeVocabulario = true;
                    }
                }
                if (existeVocabulario == false){
                    vocabulario.push_back(palavra);
                }
                palavra = "";
            }
        }
    }
    return vocabulario;
}
void imprimirVocabulario(vector<string> vocabulario){
 for (int c = 0; c < (int)vocabulario.size(); c++){
        if (c == (int)vocabulario.size() - 1 ){
            cout << vocabulario[c] << ".";
        } else{
            cout << vocabulario[c] << ", ";
        }
        
    }
}

int main(){
    string nomeDocumento = "documentos.txt";
    vector<string> linhas = lerArquivo(nomeDocumento);
    if ((int)linhas.size() == 0){
        cout << "Documento vazio";
    } else{
    vector<string> vocabulario = puxarVocabulario(linhas);
    imprimirDocumento(linhas);
    imprimirVocabulario(vocabulario);
    }
}