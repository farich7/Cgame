#include "Wizard.h"


 Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength)
 {
     this->rank = rank;
 }
 
 void Wizard::attack(Character &opp)
 {
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
     opp.setHealth(opp.getHealth() - damage);
    cout <<"Wizard ";
    cout << this->getName() << " attacks " << opp.getName() << " --- POOF!!" << endl;
    cout << opp.getName() << " takes " << damage << " damage." << endl;
     
     
 }