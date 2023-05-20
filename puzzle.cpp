#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// BELLO adds "BELLO " to the beginning of string, capitalizes string, 
// and adds "!!!"" to end of string. For example, "Bob" would become 
// "BELLO BOB!!!"

string BELLO(const string& str) {
  string result = "BELLO ";
// initialize i to 0, continue as long as index is less than length of string, 
// increment by 1 after each iteration of loop
  for (size_t i = 0; i < str.length(); i++) {
      result +=     toupper(str[i]);}
  result += "!!!";
  return result;
}


// NANA replaces last two letters of string with "nana."
// For example, "MiniHack" would become "MiniHanana"!

string NANA(const string& word) {
  if (word.length() < 2) {
      return "nana";} 
      else {
      return word.substr(0, word.length() - 2) + "nana";
  }}


// findDuplicate takes in an array Bananas of how many bananas each minion
// has eaten, and returns any element of Bananas that is not unique. 
// Number of elements in Bananas cannot exceed 500.
// If every minion has eaten a different number of bananas, aka if each element 
// is unique, function returns 0.

int findDuplicate(const int Bananas[], int n) {
  bool isFound[500];
  for (int i = 0; i < 500; i++) {
      isFound[i] = false; 
    }
  for (int i = 0; i < n; i++) {
    if (isFound[Bananas[i]]) {
        return Bananas[i];  
        }
    isFound[Bananas[i]] = true;
    }
return 0;
}


  int main() {
    // Test BELLO function
    string word = "Bob";
    cout << "Original word: " << word << endl;
    cout << "BELLO version: " << BELLO(word) << endl;
    cout << endl;

    // Test NANA function
    string word2 = "MiniHack";
    cout << "Original word: " << word2 << endl;
    cout << "NANA version: " << NANA(word2) << endl;
    cout << endl;

    // Test findDuplicate function
    int bananas[] = { 1, 2, 3, 4, 3, 5 };
    int size = sizeof(bananas) / sizeof(bananas[0]);
    cout << "Duplicate: " << findDuplicate(bananas, size) << endl;
    cout << endl;

    // Test findDuplicate function with a duplicate
    int bananas2[] = { 1, 2, 3, 4, 4, 5 };
    int size2 = sizeof(bananas2) / sizeof(bananas2[0]);
    cout << "Duplicate: " << findDuplicate(bananas2, size2) << endl;
    cout << endl;

        return 0;
}
