#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include "Question.h"
#include "Participant.h"
#include <fstream>
#include "exception.h"
#include "observer.h"

class Repository: public Observable
{
private:
    vector<Question> questions;
    vector<Participant> participants;

public:
    Repository() {}

    vector<Question> getQuestions() const {return this->questions;}
    vector<Participant> getParticipants() const {return this->participants;}

    bool findQuestionById(int id)
    {
        for (auto q: this->questions)
            if (q.getId() == id)
                return true;

        return false;
    }

    void sortQById()
    {
        for(int i = 0; i < this->questions.size(); i++)
            for(int j = 0; j< this->questions.size(); j++)
                if (this->questions.at(i).getId() < this->questions.at(j).getId())
                    swap(this->questions.at(i), this->questions.at(j));
    }

    void sortQByScore()
    {
        for(int i = 0; i < this->questions.size(); i++)
            for(int j = 0; j< this->questions.size(); j++)
                if (this->questions.at(i).getScore() > this->questions.at(j).getScore())
                    swap(this->questions.at(i), this->questions.at(j));
    }

    void addQuestion(int i, string t, string a, int s)
    {
        if(findQuestionById(i) == true)
            throw Exception("Question with the same id already exists!");
        if(t == "")
            throw Exception("Text empty!");

        Question q{i, t, a, s};

        this->questions.push_back(q);
        writeToFileQ();
        this->notify();

    }

    void loadFromFileQ()
    {
        ifstream f("/Users/Ale/Documents/Facultate/An1/Semestrul2/OOP/Tests/Quiz/questions.txt");
        Question q;
        if(!f.is_open())
            throw Exception("Couldn't open the file questions.txt");

        while(f >> q)
            this->questions.push_back(q);

        f.close();
    }

    void writeToFileQ()
    {
        ofstream g("/Users/Ale/Documents/Facultate/An1/Semestrul2/OOP/Tests/Quiz/questions.txt");
        if(!g.is_open())
            throw Exception("Couldn't open the file questions.txt");

        for (auto q: this->questions)
            g << q;
        g.close();

    }

    void loadFromFileP()
    {
        ifstream f("/Users/Ale/Documents/Facultate/An1/Semestrul2/OOP/Tests/Quiz/participants.txt");
        Participant p;
        if(!f.is_open())
            throw Exception("Couldn't open the file participants.txt");

        while(f >> p)
            this->participants.push_back(p);

        f.close();
    }

    void writeToFileP()
    {
        ofstream g("/Users/Ale/Documents/Facultate/An1/Semestrul2/OOP/Tests/Quiz/participants.txt");
        if(! g.is_open())
            throw Exception("Couldn't open the file participants.txt");

        for (auto p: this->participants)
            g << p;
        g.close();

    }


    ~Repository() {}
};

#endif // REPOSITORY_H
