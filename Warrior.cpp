#include "Warrior.h"



Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength)
 { // no need to include type because already know it's a warrior
     this->allegiance = allegiance;
 }
 
void Warrior::attack(Character &opp)
 {
     if(opp.getHealth() == 0)
     {
        cout <<"Hero ";
        cout << this->getName() << " cannot attack someone that is already dead " << opp.getName() << "." << endl;
        return;
     }
  double damage = 0.0;
   if(opp.getType() == WARRIOR){
     Warrior &opponent = dynamic_cast<Warrior &>(opp);
      if(opponent.allegiance == this->allegiance)
      {
          cout <<"Hero ";
          cout << this->getName() << " does not attack Warrior " << opp.getName() << "." << endl;
          cout << "They share an allegiance with " << allegiance << "." << endl;
          return;
      }
   }
    damage = (health/MAX_HEALTH) * attackStrength;
    double newHealth = opp.getHealth() - damage;
    if(newHealth <= 0)
    {
        opp.setHealth(0);
    }
    else
    {
        opp.setHealth(opp.getHealth() - damage);
    }
    cout <<"Hero ";
    cout << this->getName() << " attacks " << opp.getName() << " --- SLASH!!" << endl;
    cout << opp.getName() << " takes " << damage << " damage." << endl;
     
 }