/*
 * Course: COEN 2220 - Programming 2
 * Name: Abner Tavarez Medina A00636549
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Guided example - static members, copies, and operators
 * Due date: 15/02/2026
 */

#include <iostream>
using namespace std;

class StudyTime
{
    private:
        int minutes;               // Each object stores its own duration.
        static int objectCount;    // One counter is shared by the entire class.

    public:
        StudyTime(int m = 0) {
            minutes = m;
            objectCount++;         // Every new object increases the shared count.
        }

        int getMinutes() const { return minutes; }

        static int getObjectCount() {
            return objectCount;    // A static function reads class-level data.
        }

        // --- STEP 2: copy constructor (uncomment the /* ... */ block later) ---
        
        StudyTime(const StudyTime &other) {
            minutes = other.minutes;  // Copy the source object's duration.
            objectCount++;            // The copy is a new object too.
        }
        

        // --- STEP 3: operator+ (uncomment the /* ... */ block later) ---
        
        StudyTime operator+(const StudyTime &other) const {
            // Return a new duration without changing either operand.
            return StudyTime(minutes + other.minutes);
        }
                // ===== Resuelve estos TODO ahora (Parte E) =====

        // TODO (Parte E): Define operator== so two StudyTime objects are equal
        // when they represent the same number of minutes. The function must not
        // modify either object and must return a bool.
        bool operator==(const StudyTime &other) const {
            return minutes == other.minutes;
        }
};

int StudyTime::objectCount = 0;    // Define the single shared variable.

int main() {
    StudyTime reading(45);          // The first StudyTime object.

    cout << "Reading: " << reading.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    // --- STEP 2 main() code goes here later ---
        StudyTime readingCopy = reading;  // Create a new object from reading.
    cout << "Copy: " << readingCopy.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    // --- STEP 3 main() code goes here later ---
        StudyTime practice(30);
    StudyTime total = reading + practice;  // Calls reading.operator+(practice).

    cout << "Total: " << total.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

 StudyTime object1 = reading;
 StudyTime object2;
  object2 = reading;
  cout << "Final  value: " << StudyTime::getObjectCount() << endl;
  cout << "Object 1 minutes: " << object1.getMinutes() << endl;
  cout << "Object 2 minutes: " << object2.getMinutes() << endl;

  //PARTE E:
  StudyTime time1 (60);
 StudyTime time2 (45);
 StudyTime time3 (60);
 cout << "time 1: " << time1.getMinutes() << " minutes " << endl;
 cout << "time 2: " << time2.getMinutes() << " minutes" << endl;
 cout << "time 3: " << time3.getMinutes() << " minutes" << endl;
 cout << boolalpha;  // Display bool values as true/false instead of 1/0.
cout << "time1 == time2: " << (time1 == time2) << endl;  // false
cout << "time1 == time3: " << (time1 == time3) << endl;  // true
    return 0;
}