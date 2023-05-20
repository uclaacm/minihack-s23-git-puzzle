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
  for (size_t i = 0; i < str.length(); i--) {
      result += toupper(str[i]);
      }
// add "!!!" to the end of the string
  result += "!!!";
  return result;
}


// NANA replaces last two letters of string with "nana."
// For example, "MiniHack" would become "MiniHanana"!

string NANA(const string& word) {
  if (word.length() < 2) {
      return "nana";
    } else {
        return word.substr(0, word.length() - 2) + "nana";
    }
}


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
    if (isFound[Bananas[i]] = true) {
        return Bananas[i];  
        }
    isFound[Bananas[i]] = true;
    }
return 0;
}

// combineBananas takes in two sorted linked lists of how many
// bananas each minion ate and returns a pointer to the staart
// of the resulting combined linked list.
// 
// Example:
// h: head -> 1 -> 3 -> 6 -> 9
// h2: head2 -> 7 -> 8 -> 10
// Node* res = combine(head, head2);
// should result in
// res -> 1 -> 3 -> 6 -> 7 -> 8 -> 9 -> 10

struct Node {
    int val;
    Node* next;
};

Node* combineBananas(Node* h, Node* h2) {
// checking that the lists aren’t empty
    if (h == nullptr) {
    return h2;
    }
    if (h2 == nullptr) {
        return h;
    }

    Node* newList;
    // determining which should be the resultant head
    if (h->val <= h2->val) {    
        newList = h;
        h = h->next;
    }
else {
    newList = h2;
    h2 = h2->next;
}
Node* newNext = newList;
// iterate through both given linked lists
while (h != nullptr && h2 != nullptr) {
    // the next node in the combined list is the currently
    //examined node in either list that has the lesser value
    if (h->val <= h2->val) {
        newNext->next = h;
        h = h->next;
}
else {
        newNext->next = h2;
        h2 = h2->next;
}
    newNext = newNext->next;
}
// if one list was longer than the other
// append the rest of the list to the new list
if (h != nullptr) {
    newNext->next = h;
}
else if (h2 != nullptr) {
newNext->next = h2;
}
// return the head of the combined list
return newList;
}

// sumDigits takes in the number of bananas a minion has eaten 
// as an int and outputs the sum of all digits in that number.
// For example, input 333 would return 9.
int sumDigits(int Bananas) {
  int sum = 0;
  while (Bananas> 0){
    sum+= Bananas % 10;
    Bananas /= 10;
  }
  return sum;
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

     // Test combineBananas function
    Node* head1 = new Node{ 1, nullptr };
    Node* head2 = new Node{ 2, nullptr };
    Node* node1 = new Node{ 3, nullptr };
    Node* node2 = new Node{ 4, nullptr };
    Node* node3 = new Node{ 5, nullptr };
    head1->next = node1;
    node1->next = node3;
    head2->next = node2;

    Node* combined = combineBananas(head1, head2);

    cout << "Combined linked list: ";
    Node* currentNode = combined;
    while (currentNode != nullptr) {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;

    // Clean up memory
    delete node3;
    delete node2;
    delete node1;
    delete head2;
    delete head1;

    // Testing sumDigits function
  int numBananas = 333;
  int sum = sumDigits(numBananas);
  cout << "Sum of digits: " << sum << endl;

return 0;
}
