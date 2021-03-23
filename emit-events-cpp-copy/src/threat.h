#include <iostream>
class Threat {
   public:
	std::string name;
	std::string type;
	std::string status;

public:
    // Parameterized Constructor
    Threat(std::string n, std::string t, std::string s)
    {
        name = n;
        type = t;
        status = s;
    }
    
    Threat() {
    }
};
