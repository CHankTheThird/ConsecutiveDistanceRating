#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

int main() {
   int numLines;
   int numInts;
   int** numbers = nullptr;
   std::string line;
   std::ifstream testFile;


   testFile.open("TestFile.txt");
   if (testFile.is_open()) {
      testFile >> numLines;
      testFile >> numInts;
      numbers = new int*[numLines];
      for (int line = 0; line < numLines; line++) {
         numbers[line] = new int[numInts];
         for (int numInLine = 0; numInLine < numInts; numInLine++) {
            testFile >> numbers[line][numInLine];
         }
      }
   }
   testFile.close();
   
   if (numbers != nullptr) {
      int totalDistance = 0;

      for (int line = 0; line < numLines; line++) {
         for (int numToCheck = 0; numToCheck < numInts; numToCheck++) {
            int num = numbers[line][numToCheck];
            for (int numToComp = numToCheck + 1; numToComp < numInts; numToComp++) {
               if (std::abs(num - numbers[line][numToComp]) == 1) {
                  totalDistance += (numToComp - numToCheck);
               }
            }
         }
         std::cout << "Total Distance: " << totalDistance << std::endl;
         totalDistance = 0;
      }
   }

   while (true) {

   }
}