#include "Wizard.h"


 Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength)
 {
     this->rank = rank;
 }
 
 void Wizard::attack(Character &opp)
 {
    if(opp.getHealth() == 0)
     {
        cout <<"Harpy ";
        cout << this->getName() << " cannot attack someone that is already dead " << opp.getName() << "." << endl;
        return;
     }
  double damage = 0.0;
//the damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.
     if(opp.getType() == this->type)
     {
         Wizard &opponent = dynamic_cast<Wizard &>(opp);
         damage = this->attackStrength * ((static_cast<double>(rank))/opponent.rank);
     }
     else
     {
      damage = this->attackStrength;
     }
     double newHealth = opp.getHealth() - damage;
    if(newHealth <= 0)
    {
        opp.setHealth(0);
    }
    else
    {
        opp.setHealth(opp.getHealth() - damage);
    }
    cout <<"Harpy ";
    cout << this->getName() << " attacks " << opp.getName() << " --- POOF!!" << endl;
    cout << opp.getName() << " takes " << damage << " damage." << endl;
     
     
 }