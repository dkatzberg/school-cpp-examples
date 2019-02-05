#include <iostream>
#include<bits/stdc++.h>

using namespace std;

/*
This program is an example for calculation of a class timetable.
@Author: Daniel Katzberg
February, 2019
*/

//The number of max days in the timetable.
const int maxNumberDays = 5;

//The number of max lessons in the timetable.
const int maxNumberLessonPerDay = 5;

//The max number of different lessons in the timetable.
const int maxNumberOfDifferentLessons = 10;

//2D Array for the timetable representation.
int timetable[maxNumberDays][maxNumberLessonPerDay];

//Timetable Counter. How often is a lesson set in the week?
int timetableCounter[maxNumberOfDifferentLessons];

//All available lessons in an array
const string allLessons[maxNumberOfDifferentLessons] = {"German", "History", "English", "Mathematics", "French", "Information science", "Sport", "Biology", "Physics", "Chemistry"};

/*
Prints only the welcome screen and all lessons.
*/
void welcomeScreen() {
    cout << "Welcome. You can enter all classes.\n";
    cout << "The timetable has five days with 5 hours per day.\n";
    cout << "Check all classes and enter just the classes.\n";

    //Write all lessons with the id to the screen.
    for (int lessonIndex = 0; lessonIndex < maxNumberOfDifferentLessons; lessonIndex++) {
        cout << allLessons[lessonIndex] << ": " << (lessonIndex + 1) << "\n";
    }
}

/*
This method is for manually entering the classes into the
time table
*/
void timeTableManuallyInput() {
    int tempLesson = 0;

    //Read all lesson for all days
    for (int day = 0; day < maxNumberDays; day++) {
        cout << "Day " << (day + 1) << "\n";
        for (int lesson = 0; lesson < maxNumberLessonPerDay; lesson++) {

            //Input until a correct answer is given by the user
            //This method will run minimum one time.
            while (tempLesson < 1 || tempLesson > maxNumberOfDifferentLessons) {
                cout <<"  Lesson " << (lesson + 1) << ": ";
                cin >> tempLesson;
                if (!cin || tempLesson < 1 || tempLesson > maxNumberOfDifferentLessons) {
                    cout << "Incorrect Input. Please renew your input.\n";

                    //Reset Input
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    tempLesson = 0;
                }
            }
            //Set the valid lesson.
            timetable[day][lesson] = tempLesson;

            //increase the lesson by one for the weekly check.
            timetableCounter[(tempLesson - 1)] = timetableCounter[(tempLesson - 1)] + 1;

            //Reset temporary variable
            tempLesson = 0;
        }
    }
}

/*
This method looks for the day and checks for doubled lesson on the same day.
A lesson has to set just once per day.
*/
void checkForDoubleLessonOnADay() {

    for (int day = 0; day < maxNumberDays; day++) {
        for (int lesson = 0; lesson < maxNumberLessonPerDay; lesson++) {
            //Check only the lessons after the actual one. All previous lesson combinations are checked before.
            for (int checkLesson = lesson + 1; checkLesson < maxNumberLessonPerDay; checkLesson++) {
                if (timetable[day][lesson] == timetable[day][checkLesson]) {
                    //IT index starts with 0, so we have to increase the days and lessons by one for readable text.
                    cout << "Doubled entry on Day " << (day + 1) << " in Lesson " << (lesson + 1) << " and " << (checkLesson + 1) << ".\n";
                }
            }
        }
    }
}

/*
This method checks for lesson. Lessons are limited
to three times in a week.
*/
void checkForOnlyThreeTimesInAWeek() {
    for (int lessonNumber = 0; lessonNumber < maxNumberOfDifferentLessons; lessonNumber++) {
        if (timetableCounter[lessonNumber] > 3) {
            cout << "The lesson with the number " << (lessonNumber + 1) << " is set more than three times.\n";
        }
    }
}

/*
This method prints the timetable.
*/
void printTimetable() {
    //Simple output for the timetable
    cout << "| Mon | Tue | Wed | Thu | Fri |\n";
    cout << "-------------------------------\n";
    for (int lesson = 0; lesson < maxNumberLessonPerDay; lesson++) {
        for (int day = 0; day < maxNumberDays; day++) {
            cout << "|  " << timetable[day][lesson] << "  ";
            if (day == 4) {
                cout << "|";
            }
        }
        cout << "\n";
    }
    cout << "-------------------------------\n";
}

/*
The main method for starting the application.
*/
int main()
{
    //Just the welcome screen
    welcomeScreen();

    //Read all lessons
    timeTableManuallyInput();

    //Print time table
    printTimetable();

    //Do all the checks
    checkForDoubleLessonOnADay();
    checkForOnlyThreeTimesInAWeek();

    return 0;
}
