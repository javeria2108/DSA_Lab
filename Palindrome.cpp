#include <iostream>
#include <string>

using namespace std;

int main(){
	string input_string="131";
        string reverse="";
        for(int i=input_string.length()-1;i>0;i--){
        	
            reverse.append(input_string[i]);
    }
    cout<<reverse;
    if(input_string.compare(reverse)==0){
      cout<<("given integer is a palindrome");
    }
}
