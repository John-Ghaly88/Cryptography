#include <iostream>
using namespace std;


string encryption(string m, int a, int b) {
	
   string c = "";
   
   for (int i = 0; i < m.length(); i++) {
      
      if(m[i]!=' ')
         c = c + (char) ((((a * (m[i]-'A') ) + b) % 26) + 'A');
      else
         c += m[i];
   }
   return c;
}


int main(void) {
	int a = 7;
	int b = 3;
	string m = "KPF KPF";
	string c = encryption(m,a,b);
	cout << "Encrypted: " << c <<endl;
	
	return 0;
}

