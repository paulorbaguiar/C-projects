#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main () {

    cout << "----------------------------------" << endl;
    cout << "-Bem-vindos ao jogo da advinhacao-" << endl;
    cout << "----------------------------------" << endl;
    
    cout << "-Escolha seu nível de dificulade:-" << endl;
    cout << "-- Facil (F) --" << endl;
    cout << "-- Medio (M) --" << endl;
    cout << "-- Dificil (D) --" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_tentativas;
    
    if(dificuldade == 'F'){
        numero_tentativas = 15;
    }
    else if(dificuldade == 'M'){
        numero_tentativas = 10;
    }
    else{
        numero_tentativas = 5;
    }

    srand(time(0));
    const int NUMERO_SECRETO = rand()%100;

    bool nao_acertou = true;
    int tentativas = 0;
    double pontos = 1000.0; 

    for(tentativas = 1; tentativas <= numero_tentativas; tentativas++){
    
        int chute;
        cout << "tentativas: " << tentativas << endl;
        cout << "Qual o seu chute?";
        cin >> chute;
        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;
        cout << "O seu chute foi " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou) 
        {
            cout << "Parabens, voce acertou o numero secreto" << endl;
            nao_acertou = false;
            break;

        }
        else if (maior) 
        {
            cout << "Seu chute e maior que o numero secreto" << endl;
        }
        else 
        {
            cout << "Seu numero e menor que o numero secreto" << endl;
        }
    }

    cout << "Fim de jogo!" << endl;
    if(nao_acertou){
        cout << "Voce perdeu!! O numero secreto é: "<< NUMERO_SECRETO << endl;
    }
    else {
        cout << "Voce acertou o numero secreto em :" << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
    
}