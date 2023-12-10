#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
	int Phy_classes;
	cin>>Phy_classes;
	int math_classes;
	cin>>math_classes;
	int chem_classes;
	cin>>chem_classes;
	int total_classes=Phy_classes+math_classes+chem_classes;
	int percent=150*0.7;
	if(Phy_classes>=25 && math_classes>=25 && chem_classes>=25 && (total_classes>percent)){
		cout<<"true";
	}
}
