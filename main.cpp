#include "classes.h"

int main()
{
    ResArray array;
    Reservoir r1("Oceanic", "ocean", 5000, 3000);
    Reservoir r2("Lagoon", "sea", 1500, 800);
    Reservoir r3("Swamp1", "swamp", 2000, 1000);
    Reservoir r4("Swamp2", "swamp", 1500, 750);
    Reservoir r5;
    r5.setName("Sea");
    r5.setType("sea");
    r5.setV(2500);
    r5.setArea(1000);
    bool check = r3.checkFunc(r4);
    bool comp = r3.compFunc(r4);
    cout << endl;
    cout << boolalpha;
    cout << "It's " << check << " that r3 and r4 are the same types" << endl;
    cout << endl;
    cout << boolalpha;
    cout << "It's " << comp << " that r3 is bigger than r4" << endl;
    cout << noboolalpha;
    string type = r3.getType();
    cout << endl;
    cout << "R3 type: " << type << endl;
    array.addFunc(r1);
    array.addFunc(r2);
    array.addFunc(r3);
    array.addFunc(r4);
    cout << "All reservoirs:" << endl;
    array.printResFunc();
    array.deleteFunc(0);
    cout << "After deleting :" << endl;
    array.printResFunc();
	return 0;
}