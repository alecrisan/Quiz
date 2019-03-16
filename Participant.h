#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Participant
{
private:
    string name;
    int score;
public:
    Participant() {}

    Participant(string n) : name(n), score(0) {}

    string getName() const {return this->name; }
    int getScore() const {return this->score;}

    friend istream& operator>>(istream &is, Participant& p)
    {
        string line;
        getline(is, line);
        stringstream ss(line);
        string token;
        vector<string> temp;
        while(getline(ss, token, ','))
            temp.push_back(token);

        if(temp.size() != 2)
            return is;

        p.name = temp[0];
        p.score = stoi(temp[1]);

        return is;

    }

    friend ostream& operator<<(ostream &os, Participant& p)
    {
        os << p.getName() <<","<< p.getScore() <<'\n';
        return os;
    }

    ~Participant() {}
};

#endif // PARTICIPANT_H
