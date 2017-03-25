#ifndef OTHELLO_H
#define OTHELLO_H


class Othello
{
    public:
        Othello();
        void buildArray(char othello[][8]);
        void printGameBoard(char othello[][8]);
        void searchChar(char othello[][8], int cords[][2], char var);
        ~Othello();


};

#endif // OTHELLO_H
