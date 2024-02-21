#include <iostream>
#include <cassert>
#include "coord.cpp"

using namespace std;

void testEgalCoord(){
assert(egalCoord({2,1}, {2,1}));
assert(!egalCoord({1,2}, {2,1}));
}

void testDirection(){
    for(int d=0; d<8; d++){
        assert(agauche(adroite(Direction(d)))==Direction(d));
        assert(agauche(adroite(Direction(d)))==Direction(d));
    }
}

void testDevantCoord(){
    assert(egalCoord(devantCoord({10,10}, NO)=={9,9}));
    assert(egalCoord(devantCoord({0,0}, N)=={0,0}));
}

int main()
{
testEgalCoord();
testDirection();
testDevantCoord();
}
