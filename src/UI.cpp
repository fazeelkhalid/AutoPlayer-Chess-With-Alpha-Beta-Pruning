#include "..\\include\\UI.h"
#include <iostream>
#include<iomanip>
using namespace std;

void UI::showPiece(int pieceCode){
    if (pieceCode > 0)
        cout<<setw(4)<<"W";
    else if(pieceCode < 0)
        cout<<setw(4)<<"B";

    switch(pieceCode){
        case 4:
        case -4:
            cout<<"R";
        break;

        case 2:
        case -2:
            cout<<"KN";
        break;

        case 3:
        case -3:
            cout<<"B";
        break;
        case 5:
        case -5:
            cout<<"Q";
        break;
        case 6:
        case -6:
            cout<<"K";
        break;
        case 1:
        case -1:
            cout<<"P";
        break;
        case 0:
            cout<<setw(5)<<"::";
        break;
    }
    cout<<"\t";
}

void UI::updateView(string whitePlayerName, string blackPlayerName){

    for(int i=0; i<80;i++)
        cout<<"_";
    cout<<endl<<setw(50)<<" Game State"<<endl<<endl;
    for(int i=0; i<80;i++)
        cout<<"_";
    cout<<endl<<endl;

    if(state->Board.whiteHome == 0){
        cout<<setw(50)<<"WHITE HOME"<<endl<<endl;
        cout<<setw(55)<<whitePlayerName <<endl<<endl;
    }
    else{
        cout<<setw(50)<<"BLACK HOME"<<endl<<endl;
        cout<<setw(55)<<blackPlayerName  <<endl<<endl;
    }

    cout<<setw(10)<<"Row/Col     0";
    for(int r=49; r<56; r++){
        cout<<setw(8)<< (char) r;
    }
    cout<<endl<<endl<<"\t";
    for(int r=0; r<8; r++){
        cout<<"--------";
    }
    cout<<endl;

    for(int r=0; r<8; r++){
        cout<<setw(5)<<r<<setw(3)<<"|";
        for(int c=0; c<8; c++)
            showPiece(state->Board.board[r][c]);
        cout<<"|"<<endl<<setw(8)<<"|"<<setw(65)<<"|"<<endl<<setw(8)<<"|"<<setw(65)<<"|"<<endl;
    }
    cout<<"\t";
    for(int r=0; r<8; r++){
        cout<<"--------";
    }
    cout<<endl;

    if(state->Board.whiteHome == 7){
        cout<<setw(50)<<"WHITE HOME"<<endl;
        cout<<setw(55)<<whitePlayerName<<endl<<endl;
    }
    else{
        cout<<setw(50)<<"BLACK HOME"<<endl;
        cout<<setw(55)<<blackPlayerName<<endl<<endl;
    }

    if (state->getPlayer() == White)
        cout<<endl<<"White To Turn"<<endl;
    else
        cout<<endl<<"Black To Turn"<<endl;
//    state->Actions.showActions();
}
