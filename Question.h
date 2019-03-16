#ifndef QUESTION_H
#define QUESTION_H


#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Question
{
private:
    int id;
    string text;
    string correct_answer;
    int score;
public:
    Question() {}

    Question(int i, string t, string a, int s) : id(i), text(t), correct_answer(a), score(s) {}

    int getId() const { return this->id; }
    string getText() const {return this->text; }
    string getCorrectAnswer() const { return this->correct_answer; }
    int getScore() const {return this->score; }


    friend istream& operator>>(istream &is, Question& q)
    {
        string line;
        getline(is, line);
        stringstream ss(line);
        string token;
        vector<string> temp;
        while(getline(ss, token, ','))
            temp.push_back(token);

        if(temp.size() != 4)
            return is;

        q.id = stoi(temp[0]);
        q.text = temp[1];
        q.correct_answer = temp[2];
        q.score = stoi(temp[3]);

        return is;

    }

    friend ostream& operator<<(ostream &os, Question& q)
    {
        os << q.getId() <<","<< q.getText() <<","<< q.getCorrectAnswer() <<","<< q.getScore()<<'\n';
        return os;
    }

    ~Question() {}
};

#endif // QUESTION_H
