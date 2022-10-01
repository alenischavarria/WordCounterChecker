#include <iostream>
#include <string>
#include <fstream>
#include "bst.hpp"
using namespace std;
int main() {

   ifstream Story;
  
    Story.open("largedictionary.txt");
    string* myArray = new string[202413];
    

    int index = 0;

    while (!Story.eof())
    {
        Story >> myArray[index];
        index++;
    }

    Story.close();

  binarySearchTree Tree;

  Tree.loadFromFile("whale.txt");
 
  doublyLinkedList list;

  Tree.findMisSpell(list, myArray, "topMistakes.txt");

  
  
  return 0;
} 