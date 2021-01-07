

//Tic Tac Toe 

#include <iostream>
#include <stdlib.h>

using namespace std;


char Feld[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //Array für das Spielfeld


int Eingabe;
int Reihe,Spalte;
char Spielzug = 'X';
bool Patt = false;

//Funktionen
//Funktion zur Ausgabe des Spielfeldes


void ausgabe_spielfeld(){


    cout<<"Spieler 1 = [X]  Spieler 2 = [O]"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<Feld[0][0]<<"  | "<<Feld[0][1]<<"   |  "<<Feld[0][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<Feld[1][0]<<"  | "<<Feld[1][1]<<"   |  "<<Feld[1][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<Feld[2][0]<<"  | "<<Feld[2][1]<<"   |  "<<Feld[2][2]<<endl;
    cout<<"     |     |     "<<endl;
}


// Funktion zur Eingabe und erneute Ausgabe des Spielfeldes


void Spielzug_eingabe(){
    
    if(Spielzug == 'X'){
        cout<<"Spieler 1 = [X] ist dran : ";
    }
    else if(Spielzug == 'O'){
        cout<<"Spieler 2 = [O] ist dran : ";
    }
    
    
//Eingabe des Spielers
//Aktualisieren des Spielfeldes und nächste Runde

    cin>> Eingabe;

//Switch case (viele Fälle)

    switch(Eingabe){
        case 1: Reihe=0; Spalte=0; break;
        case 2: Reihe=0; Spalte=1; break;
        case 3: Reihe=0; Spalte=2; break;
        case 4: Reihe=1; Spalte=0; break;
        case 5: Reihe=1; Spalte=1; break;
        case 6: Reihe=1; Spalte=2; break;
        case 7: Reihe=2; Spalte=0; break;
        case 8: Reihe=2; Spalte=1; break;
        case 9: Reihe=2; Spalte=2; break;
        default:
            cout<<"nicht möglich";
    }

    if(Spielzug == 'X' && Feld[Reihe][Spalte] != 'X' && Feld[Reihe][Spalte] != 'O'){
                                                                          //Die Zelle bekommt das Symbol 'X'
        Feld[Reihe][Spalte] = 'X';
        Spielzug = 'O';
    }else if(Spielzug == 'O' && Feld[Reihe][Spalte] != 'X' && Feld[Reihe][Spalte] != 'O'){
                                                                        //Die Zelle bekommt das Symbol 'O'
        Feld[Reihe][Spalte] = 'O';
        Spielzug = 'X';
    }else {
                                                                        //Wenn Zellen schon besetzt sind
        cout<<"Die Zelle ist voll. Bitte andere Zelle auswählen";
        Spielzug_eingabe();
    }
   
   
   
    ausgabe_spielfeld();
}


//Funktion für Gewonnen oder Patt ausgabe

bool gameover(){
    //Gewinnen durch Reihen und Spalten
    
    for(int i=0; i<3; i++)
    if(Feld[i][0] == Feld[i][1] && Feld[i][0] == Feld[i][2] || Feld[0][i] == Feld[1][i] && Feld[0][i] == Feld[2][i])
    return false;

    //Gewinnen durch diagonale

    if(Feld[0][0] == Feld[1][1] && Feld[0][0] == Feld[2][2] || Feld[0][2] == Feld[1][1] && Feld[0][2] == Feld[2][0])
    return false;

    //Überprüfen ob das Spiel noch weitergespielt werden kann
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(Feld[i][j] != 'X' && Feld[i][j] != 'O')
    return true;

    //Überprüfen ob Patt
    Patt = true;
    return false;
}


int main()
{
    cout<<"T I C  -- T A C -- T O E -- "<<endl;
    cout<<"Mehrspieler"<<endl;
    while(gameover()){
        ausgabe_spielfeld();
        Spielzug_eingabe();
        gameover();
    }
    if(Spielzug == 'X' && Patt == false){
        cout<<"Glückwunsch!Spieler 2 ='O' hat Gewonnen";
    }
    else if(Spielzug == 'O' && Patt == false){
        cout<<"Glückwunsch!Spieler 1 ='X' hat Gewonnen";
    }
    else
    cout<<"Patt";
} 
