#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <thread>
#include <vector>
#include <algorithm>
#include <pthread.h>

using namespace std;

int rf1, rf2;
int elevator = 0;

int main () {

   std::cout << "Elevator starts the day on Floor 0.\n";

   std::vector<std::thread> users;
   for (int i = 0; i < 5; i++) {
      users.push_back(std::thread([&i]()
      {
         rf1 = rand() % 5;
         rf2 = rand() % 5;

         //make sure not equal
         while (rf1 == rf2) {
            rf2 = rand() % 5;
         }

         std::cout << "User " << i << " is on Floor " << rf1 << " and wants to go to Floor " << rf2 << ".\n";

         while (elevator != rf1) {
            if(elevator < rf1) {
               elevator++;
               std::cout << "Elevator is going up.\n";
               std::cout << "Elevator is now on floor " << elevator << "\n";
            } else if (elevator > rf1) {
               elevator--;
               std::cout << "Elevator is going down.\n";
               std::cout << "Elevator is now on floor " << elevator << "\n";
            }
         }
         std::cout << "Elevator is now on floor " << rf1 << ", opening doors.\n";
         std::cout << "User " << i << " enters elevator.\n";

         while (elevator != rf2) {
            if(elevator < rf2) {
               elevator++;
               std::cout << "Elevator is going up.\n";
               std::cout << "Elevator is now on floor " << elevator << "\n";
            } else if (elevator > rf2) {
               elevator--;
               std::cout << "Elevator is going down.\n";
               std::cout << "Elevator is now on floor " << elevator << "\n";
            }
         }
         std::cout << "Elevator is now on floor " << rf2 << ", opening doors.\n";
         std::cout << "User " << i << " leaves elevator.\n";

      }));
   }
   //std::for_each(users.begin(), users.end(), [](std::thread &t)
   for (auto& thread : users) {
      thread.join();
   }
   
   return 0;
}
