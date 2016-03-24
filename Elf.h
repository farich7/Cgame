#include "Character.h"

using namespace std;



class Elf : public Character 
{
    private:
        string familyName;
        
    public:
        Elf(const string &name, double health, double attackStrength, string familyName);
        void attack(Character &);
        
    
    
    
    
    
    
};