#ifndef ACTIONLIST_H
#define ACTIONLIST_H

class action{
    public:
        int fromRow;
        int fromCol;
        int toRow;
        int toCol;
};

class actionList{

    private:
        action stateActions[300];
        int actionCount;

    public:
        actionList();
        void showAction(int actionIndex);
        void showActions();
        bool validAction(action Action);
        bool addAction(action Move);
        bool resetActions();
        getActionCount();
        void getAction(int actionIndex, action* Action);
};


#endif // ACTIONLIST_H
