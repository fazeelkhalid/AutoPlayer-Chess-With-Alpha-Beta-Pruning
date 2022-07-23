#include "..\\include\\actionList.h"
#include<iostream>
using namespace std;

actionList::actionList(){
    actionCount = 0;
    stateActions[0].fromRow = -1;
}

void actionList::showAction(int actionIndex){
   cout<<"( "<< stateActions[actionIndex].fromRow<<","<< stateActions[actionIndex].fromCol<<" )--"
     <<"( "<< stateActions[actionIndex].toRow<<","<< stateActions[actionIndex].toCol<<" ) "<<endl;
}

void actionList::showActions(){
    cout<< "\n All Possible Moves \n";
    for(int i =0; i < actionCount; i++){
        showAction(i);
    }
}

bool actionList::validAction(action Action){
    for(int i = 0; i < actionCount ; i++){
        if(Action.fromRow == stateActions[i].fromRow  &&
           Action.fromCol == stateActions[i].fromCol  &&
           Action.toRow   == stateActions[i].toRow    &&
           Action.toCol   == stateActions[i].toCol )
                return true;
    }
    return false;
}

bool actionList::addAction(action Move){
    if( actionCount < 300 ){
        stateActions[actionCount].fromRow = Move.fromRow;
        stateActions[actionCount].fromCol = Move.fromCol;
        stateActions[actionCount].toRow   = Move.toRow;
        stateActions[actionCount].toCol   = Move.toCol;
        actionCount++;
    }
    return true;
}

bool actionList::resetActions(){
    actionCount = 0;
    stateActions[0].fromRow = -1;
    return true;
}

int actionList::getActionCount(){
    return actionCount;
}

void actionList::getAction(int actionIndex, action* Action){
    Action->fromCol= Action->fromRow = Action->toRow = Action->toCol = -1;

    if (actionIndex < this->actionCount){
        Action->fromRow = stateActions[actionIndex].fromRow;
        Action->fromCol = stateActions[actionIndex].fromCol;
        Action->toRow   = stateActions[actionIndex].toRow;
        Action->toCol   = stateActions[actionIndex].toCol;
    }
    return;
}
