
 #include "Character.h"
 
 
 
 Character::Character(CharType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength)
 { }
 
 CharType Character::getType() const
 {
     return type;
 }
 const string & Character::getName() const
 {
     return name;
 }
 /* Returns the whole number of the health value (static_cast to int). */
 int Character::getHealth() const
 {
     return static_cast<int>(health);
 }
 void Character::setHealth(double h)
 {
     health = h;
 }
 /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
 bool Character::isAlive() const
 {
     if(getHealth() > 0)
     {
        return true;
     }
    
    return false;
 }

