//duration.h          //Author: Emily Tsui
//Modifies Duration.cpp file to become a header file

#include <iostream>
using namespace std;
#include <sstream> //Has ostringstream, easy string conversion
#include <stdlib.h> //Has rand, used in randomize mehod

#ifndef DURATION_H
#define DURATION_H

class Duration{ //Class that contains accessor and mutator methods
  private: //Private attributes
    int hours, minutes, seconds; //Represents user inputs
    string durationFormatted; //String variable to store formatted Duration
  
  public:
    Duration();
    Duration(int);
    Duration(int, int);
    Duration(int, int, int);
    Duration operator + (Duration);
    Duration operator - (Duration);
    Duration operator * (double);
    Duration operator / (double);
    double operator / (Duration);
    operator const char * ();
    void randomize();
};

Duration :: Duration(){ //Constructor
  hours = 0; //Sets hours to default value of 0
  minutes = 0; //Sets minutes to default value of 0
  seconds = 0; //Sets seconds to default value of 0
}

Duration :: Duration(int hrs){
  hours = hrs;
  minutes = 0;
  seconds = 0;
}

Duration :: Duration(int hrs, int mins){
  int totalSecs = hrs * 3600 + mins * 60;
   //Sets the private variable equal to the quotient of totalSecs divided by 3600
  hours = totalSecs / 3600;
  //Sets the variable equal to the difference of totalSecs minus hours represented as seconds
  totalSecs = totalSecs - hours * 3600;
  //Sets the variable equal to the quotient of the calculated value of totalSecs divided by 60
  minutes = totalSecs / 60;
  //Sets the private variable equal to the difference of totalSecs minus the product of minutes times 60
  seconds = totalSecs - minutes * 60;
}

Duration :: Duration(int hrs, int mins, int secs){
  //Sets the variable equal to the total number of seconds, calculated by changing hours and minutes into seconds, then adding them with secs
  int totalSecs = hrs * 3600 + mins * 60 + secs;
  //Sets the private variable equal to the quotient of totalSecs divided by 3600
  hours = totalSecs / 3600;
  //Sets the variable equal to the difference of totalSecs minus hours represented as seconds
  totalSecs = totalSecs - hours * 3600;
  //Sets the variable equal to the quotient of the calculated value of totalSecs divided by 60
  minutes = totalSecs / 60;
  //Sets the private variable equal to the difference of totalSecs minus the product of minutes times 60
  seconds = totalSecs - minutes * 60;
}

Duration Duration :: operator + (Duration other){
  int addedSecs = 0; //Variable for storage
  //Changes both Duration objects into seconds, adds them
  addedSecs = hours * 3600 + minutes * 60 + seconds + other.hours * 3600 + other.minutes * 60 + other.seconds;
  Duration sum(0, 0, addedSecs); //Creates Duration object
  return sum; //Returns Duration object
}

Duration Duration :: operator - (Duration other){
  int difference = 0; //Variable for storage
  //Changes both Duration objects into seconds, subtracts them
  difference = hours * 3600 + minutes * 60 + seconds - other.hours * 3600 - other.minutes * 60 - other.seconds;
  if(difference < 0){
    difference = 0;
  }
  Duration diff(0, 0, difference); //Creates Duration object
  return diff; //Returns Duration object
}

Duration Duration :: operator * (double other){
  int product = 0; //Variable for storage
  //Changes Duration object into seconds, multiplies it by inputted other value
  product = (hours * 3600 + minutes * 60 + seconds) * other;
  Duration mult(0, 0, product); //Creates Duration object
  return mult; //Returns Duration object
}

Duration Duration :: operator / (double other){
  int quotient = 0; //Variable for storage
  //Changes Duration object into seconds, dividies it by inputted other value
  quotient = (hours * 3600 + minutes * 60 + seconds) / other;
  Duration quo(0, 0, quotient); //Creates Duration object
  return quo; //Returns Duration object
}

double Duration :: operator / (Duration other){
  double quotient = 0; //Variable for storage
  //Changes both Duration objects into seconds, divides them
  quotient = double(hours * 3600 + minutes * 60 + seconds) / double(other.hours * 3600 + other.minutes * 60 + other.seconds);
  return quotient;
}

Duration :: operator const char * (){  //conversion
  ostringstream format; //Makes it easy to convert to string

  if(hours * 3600 + minutes * 60 + seconds < 0){ //Checks to see if hours are negative
    format << "-"; //Prints out negative sign
  }

  if(abs(hours) < 10 ){ //Checks to see if hours are less than 10
    format << "0"; //Prints 0 out first for the "HH" format
  }
  format << abs(hours) << ":"; //Prints out hours followed by colon for format

  if(abs(minutes) < 10){ //Checks to see if minutes are less than 10
    format << "0"; //Prints 0 out first for the "MM" format
  }
  format << abs(minutes) << ":"; //Prints out minutes followed by colon for format

  if(abs(seconds) < 10){ //Checks to see if seconds are less than 10
    format << "0"; //Prints 0 out first for the "SS" format
  }
  format << abs(seconds); //Prints out seconds

  durationFormatted = format.str(); //Sets string equal to format string
  return durationFormatted.c_str(); //Returns the formatted Complex object
}

void Duration :: randomize(){
  hours = rand() % 24; //Sets private attribute, hours to any random value between 0-23
  minutes = rand() % 60; //Sets private attribute, minutes to any random value between 0-59
  seconds = rand() % 60; //Sets private attribute, seconds to any random value between 0-59
}

#endif