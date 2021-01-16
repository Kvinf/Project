#include "Mainmenu.h"

int main(){
    inserthash("0kepin");
    inserthash("1bryan");
    inserthash("2satya");
    inserthash("3carrick");
    inserthash("4najwa");
    inserthash("5shihab");
    inserthash("6mampus");;
    inserthash("0carrick");//temen kepin ada carrick dan bryan
    inserthash("0bryan");
    viewhash();
    removefriend(0,"0bryan");//masih fail ini
    viewhash();
    return 0;
}