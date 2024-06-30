#include<iostream>
#include<string>
#include<cstring>
#include <sstream>
#include <algorithm>

using namespace std;

class Ezra
{
private:
    string adminpass = "123";

public:
    int i;

    Ezra()
    {
        i = 0;
    }

    bool isNumber(const string& str) const {
        std::istringstream iss(str);
        double d;
        char c;

        if (!(iss >> d) || iss.get(c)) {
            return false;
        }
        return true;
    }

    void Quest(int i)
    {
        string str = to_string(i);
        if ((!isNumber(str)) && (i > 5)) 
        {
            std::cout << "The input is not a valid number." << std::endl;
        }
        else 
        {
            cout << "The Question:" << std::endl;
        }

        switch (i)
        {
        case 1:
            cout << "What is the capital of France?\n a) London\n b) Berlin\n c) Paris\n d) Madrid" << endl;
            break;
        case 2:
            cout << "What is the largest planet in our solar system?\n a) Earth\n b) Jupiter\n c) Mars\n d) Venus" << endl;
            break;
        case 3:
            cout << "Who wrote \"Romeo and Juliet\"?\n a) William Shakespeare\n b) Mark Twain\n c) Charles Dickens\n d) Jane Austen" << endl;
            break;
        case 4:
            cout << "What is the chemical symbol for gold?\n a) Au\n b) Ag\n c) Fe\n d) Pb" << endl;
            break;
        case 5:
            cout << "Which element has the atomic number 1?\n a) Helium\n b) Oxygen\n c) Hydrogen\n d) Carbon" << endl;
            break;
        default:
            cout << "Quiz over!" << endl;
            break;
        }
    }

    void validate(string& pass)
    {
        if (pass == adminpass)
        {
            cout << "NO ACCESS" << endl;
        }
    }
};

class David : public Ezra
{
public:
    string m;
    int i;
    int score=0;

    David(string answ, int num) : Ezra()
    {
        m = answ;
        i = num;
    }

    void Answer(char m)
    {
        char lowerM = tolower(m);

        switch (i)
        {
        case 1:
            if (lowerM == 'c')
            {
                cout << "Answer is: Paris" << endl;
                score++;
            }
            else
            {
                cout << "Incorrect!" << endl;
            }
            break;
        case 2:
            if (lowerM == 'b')
            {
                cout << "Answer is: Jupiter" << endl;
                 score++;
            }
            else
            {
                cout << "Incorrect!" << endl;
            }
            break;
        case 3:
            if (lowerM == 'a')
            {
                cout << "Answer is: William Shakespeare" << endl;
                 score++;
            }
            else
            {
                cout << "Incorrect!" << endl;
            }
            break;
        case 4:
            if (lowerM == 'a')
            {
                cout << "Answer is: Au" << endl;
                 score++;
            }
            else
            {
                cout << "Incorrect!" << endl;
            }
            break;
        case 5:
            if (lowerM == 'c')
            {
                cout << "Answer is: Hydrogen" << endl;
                 score++;
            }
            else
            {
                cout << "Incorrect!" << endl;
            }
            break;
        default:
            cout << "Invalid question number!" << endl;
            break;
        }
    }
    
    int calculateScore()
    {
        return score;
    }
};

int main()
{
    Ezra instance;
    int que;
    char an;

    cout << "Welcome to the Quiz App" << endl;

    for (int j = 1; j < 6; j++) {
        cout << "Question " << j << ":" << endl;
        instance.Quest(j);
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    }

    cout << "Enter the question number you want to answer: ";
    cin >> que;
    cin.ignore(); 

    instance.Quest(que);

    David instance1("placeholder", que); 

    cout << "Enter your Answer (a, b, c, d): ";
    cin >> an;
    cin.ignore(); 

    instance1.Answer(an);
    
    int finalScore = instance1.calculateScore();
    cout << "Your final score is: " << finalScore << " out of 5." << endl;

    return 0;
}
