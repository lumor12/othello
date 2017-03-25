#ifndef OTHELLO_H
#define OTHELLO_H


class Othello
{
    public:
        Othello();
        void buildArray(char othello[][8]);
        void printArray(char othello[][8]);
        void searchChar(char othello[][8], char var);
        ~Othello();


};

#endif // OTHELLO_H
