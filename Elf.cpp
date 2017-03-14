#include "Elf.h"

 
 Elf::Elf(const string &name, double health, double attackStrength, string familyName) : Character(ELF, name, health, attackStrength)
 { 
     this->familyName = familyName;
 }
 
 void Elf::attack(Character &opp)
 {
    if(opp.getHealth() == 0)
     {
        cout <<"Elf ";
        cout << this->getName() << " cannot attack someone that is already dead " << opp.getName() << "." << endl;
        return;
     }
   double damage = 0.0;
     if(opp.getType() == ELF)
     {
         Elf &opponent = dynamic_cast<Elf &>(opp);
         if(opponent.familyName == this->familyName)
         {
          cout <<"Elf ";
          cout << this->getName() << " does not attack Elf " << opp.getName() << "." << endl;
          cout << "They are both members of the " << familyName << " family." << endl;
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
    
    
/*Warrior Bob attacks Arthur --- SLASH!!
Arthur takes 4 damage.*/

    cout <<"Elf ";
    cout << this->getName() << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
    cout << opp.getName() << " takes " << damage << " damage." << endl;
     
 }