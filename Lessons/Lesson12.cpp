//Lesson12.cpp              //Author: Emily Tsui
//Date class is able to increment properly, conversion operator to convert the date to int

#include <iostream>
using namespace std;

class Date
{
private:
   int day, month, year;

public:
   Date (int inMonth, int inDay, int inYear)
        : month (inMonth), day(inDay), year (inYear) {};

   Date& operator ++ () // prefix increment
   {
      ++day;

      if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
        if(day > 31){
          day = 1;
          month++;
        }
      }else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
          day = 1;
          month++;
        }
      }else if(month == 12){
        if(day > 31){
          day = 1;
          month = 1;
          year++;
        }
      }else{ //month == 2
        if(leapYear(year)){
          if(day > 29){
            day = 1;
            month++;
          }
        }else{
          if(day > 28){
            day = 1;
            month++;
          }
        }
      }
      return *this;
   }

   Date& operator -- () // prefix decrement
   {
      if(day == 1){
        if(month == 1){
          month = 12;
          day = 31;
          year--;
        }else{
          if(month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            month--;
            day = 30;
          }else{ //(month == 4 || month == 6 || month == 9 || month == 11)
            month--;
            day = 31;
          }
          if(month == 2){
            if(leapYear(year)){
              day = 29;
            }else{
              day = 28;
            }
          }
        }
      }else{
        --day;
      }
      return *this;
   }

   Date operator ++ (int) // postfix increment
   {
      Date copy(month, day, year);
      ++day;
      return copy;
   }

   Date operator -- (int) // postfix decrement
   {
      Date copy(month, day, year);
      --day;
      return copy;
   }

   void DisplayDate()
   {
      cout << month << " / " << day << " / " << year << endl;
   }
  
   bool leapYear(int year){
    if (year % 4 == 0){
      if (year % 100 == 0){
        if (year % 400 == 0){
          return true;
        }
      }
    }
    return false;
   }

   operator int(){
     int daysPassed = 0;
     if(month == 1){
       daysPassed = day;
     }if(month == 2){
       daysPassed = 31 + day;
     }if(month == 3){
       if(leapYear(year)){
         daysPassed = 31 + 29 + day;
       }else{
         daysPassed = 31 + 28 + day;
       }
     }if(month == 4){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + day;
       }else{
         daysPassed = 31 + 28 + 31 + day;
       }
     }if(month == 5){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + 30 + day;
       }else{
         daysPassed = 31 + 28 + 31 + 30 + day;
       }
     }if(month == 6){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + 30 + 31 + day;
       }else{
         daysPassed = 31 + 28 + 31 + 30 + 31 + day;
       }
     }if(month == 7){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + 30 + 31 + 30 + day;
       }else{
         daysPassed = 31 + 28 + 31 + 30 + 31 + 30 + day;
       }
     }if(month == 8){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + 30 + 31 + 30 + 31 + day;
       }else{
         daysPassed = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
       }
     }if(month == 9){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day;
       }else{
         daysPassed = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
       }
     }if(month == 10){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
       }else{
         daysPassed = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
       }
     }if(month == 11){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
       }else{
         daysPassed = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
       }
     }if(month == 12){
       if(leapYear(year)){
         daysPassed = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
       }else{
          daysPassed = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
       }
     }
     return daysPassed;
   }
};

int main ()
{
   Date holiday (12, 31, 2000);

   cout << "The date object is initialized to: ";
   holiday.DisplayDate ();

   ++holiday; // move date ahead by a day
   cout << "Date after prefix-increment is: ";
   holiday.DisplayDate ();

   --holiday; // move date backwards by a day
   cout << "Date after a prefix-decrement is: ";
   holiday.DisplayDate ();
   
   cout << "Days passed since January 1st: " << holiday;

  return 0;
}
