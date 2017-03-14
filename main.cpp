#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

void printHealth(const vector<Character *> &adventurers)
{
    cout << "-----Health Remaining-----" << endl;
    for (unsigned i = 0; i < adventurers.size(); ++i) 
    {
        cout << adventurers.at(i)->getName() << ": " 
        << adventurers.at(i)->getHealth() << endl;
    }
}

bool partyDead(const vector<Character *> &party)
{
    for(unsigned i = 0; i < party.size(); ++i)
    {
        if(party.at(i)->getHealth() > 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    cout << endl;

    std::time_t result = std::time(0);
    cout << asctime(localtime(&result)) << result << " seconds since the Epoch \n";
    srand(seed);

    vector<Character *> adventurers;
    vector<Character *> villains;
    adventurers.push_back(new Warrior("Jason", MAX_HEALTH, 10, "King George"));
    adventurers.push_back(new Warrior("Heracles", MAX_HEALTH, 10, "King George"));
    adventurers.push_back(new Warrior("Bob", MAX_HEALTH, 10, "Queen Emily"));
    // adventurers.push_back(new Elf("Raegron", MAX_HEALTH, 4, "Sylvarian"));
    // adventurers.push_back(new Elf("Cereasstar", MAX_HEALTH, 3, "Sylvarian"));
    // adventurers.push_back(new Elf("Melimion", MAX_HEALTH, 4, "Valinorian"));
    // adventurers.push_back(new Wizard("Merlin", MAX_HEALTH, 5, 10));
    // adventurers.push_back(new Wizard("Adali", MAX_HEALTH, 5, 8));
    // adventurers.push_back(new Wizard("Vrydore", MAX_HEALTH, 4, 6));
    villains.push_back(new Wizard("Merlin", MAX_HEALTH, 5, 10));
    villains.push_back(new Wizard("Adali", MAX_HEALTH, 5, 8));
    villains.push_back(new Wizard("Vrydore", MAX_HEALTH, 4, 6));


    cout << "WELCOME TO JASON AND THE ARGONAUTS" << endl;
    cout << "----------------------------------" << endl;
    char in = 'R';
    do{
        for(unsigned i = 0; i < adventurers.size(); ++i)
        {
            adventurers.at(i)->setHealth(MAX_HEALTH);
        }
        for(unsigned i = 0; i < villains.size(); ++i)
        {
            villains.at(i)->setHealth(MAX_HEALTH);
        }
        do 
        {

            unsigned numAttacks = 3;
            unsigned attacker, defender;
            for (unsigned i = 0; i < numAttacks; ++i) {
                attacker = rand() % adventurers.size();
            // do {
                
                defender = rand() % villains.size();
                    //cannot attack yourself
                // } while (defender == attacker); 
                adventurers.at(attacker)->attack(*villains.at(defender));

                attacker = rand() % adventurers.size();
                defender = rand() % villains.size();
                villains.at(defender)->attack(*adventurers.at(attacker));
                cout << endl;
            }
            cout << "HEROES: ";
            printHealth(adventurers);
            cout << endl;
            cout << "VILLAIN: ";
            printHealth(villains);

            if(partyDead(adventurers))
            {
                break;
            }
            char END;
            cin >> END;
        } while(!partyDead(adventurers));
        cout << endl;
        if(partyDead(adventurers))
        {
            cout << "GAME OVER! The heroes have fallen!" << endl;
        }
        cout << "Press R to play again(anything else to stop)!" << endl;
        cin >> in;
    } while(in == 'R');
}