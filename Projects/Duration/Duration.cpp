//Duration.cpp         //Author: Emily Tsui
//Provides user with task options, user choses desired option, inputs necessary requirements for function, sees if user wants to repeat

#include <iostream>
using namespace std; //Namespace to search in
#include <sstream> //Has ostringstream, easy string conversion
#include <stdlib.h> //Has rand, used in randomize mehod

class Duration{ //Class that contains accessor and mutator methods
  private: //Private attributes
    int hours, minutes, seconds; //Represents user inputs
    string durationFormatted; //String variable to store formatted Duration
  
  public:
    Duration(){ //Constructor
      hours = 0; //Sets hours to default value of 0
      minutes = 0; //Sets minutes to default value of 0
      seconds = 0; //Sets seconds to default value of 0
    }

    Duration(int hrs, int mins, int secs){ //Constructor that takes hours, minutes, seconds
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

    Duration operator + (Duration other){ //Adds two Duration objects together returns the sum
      int addedSecs = 0; //Variable for storage
      //Changes both Duration objects into seconds, adds them
      addedSecs = hours * 3600 + minutes * 60 + seconds + other.hours * 3600 + other.minutes * 60 + other.seconds;
      Duration sum(0, 0, addedSecs); //Creates Duration object
      return sum; //Returns Duration object
    }

    Duration operator - (Duration other){ //Subtracts two Duration objects together returns the difference
      int difference = 0; //Variable for storage
      //Changes both Duration objects into seconds, subtracts them
      difference = hours * 3600 + minutes * 60 + seconds - other.hours * 3600 - other.minutes * 60 - other.seconds;
      if(difference < 0){
        difference = 0;
      }
      Duration diff(0, 0, difference); //Creates Duration object
      return diff; //Returns Duration object
    }
    
    Duration operator * (double other){ //Multiplies a Duration by another constant returns the product
      int product = 0; //Variable for storage
      //Changes Duration object into seconds, multiplies it by inputted other value
      product = (hours * 3600 + minutes * 60 + seconds) * other;
      Duration mult(0, 0, product); //Creates Duration object
      return mult; //Returns Duration object
    }

    Duration operator / (double other){
      int quotient = 0; //Variable for storage
      //Changes Duration object into seconds, dividies it by inputted other value
      quotient = (hours * 3600 + minutes * 60 + seconds) / other;
      Duration quo(0, 0, quotient); //Creates Duration object
      return quo; //Returns Duration object
    }

    double operator / (Duration other){
      double quotient = 0; //Variable for storage
      //Changes both Duration objects into seconds, divides them
      quotient = double(hours * 3600 + minutes * 60 + seconds) / double(other.hours * 3600 + other.minutes * 60 + other.seconds);
      return quotient;
    }

    operator const char * (){  //conversion
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

    void randomize(){ //Randomly generates Duration object less than a day
      srand(time(NULL)); //To randomize new numbers everytime, creates a new seed
      hours = rand() % 23; //Sets private attribute, hours to any random value between 0-23
      minutes = rand() % 59; //Sets private attribute, minutes to any random value between 0-59
      seconds = rand() % 59; //Sets private attribute, seconds to any random value between 0-59
    }
};

int main() { //Used for testing and displaying

  char rerun = 'y'; //Varaible used to detect when the loop should run

  while(rerun == 'y'){ //Loop to repeat process if user wants
  
    int task = 0; //Variable to store which task the user wants
    
    //Displays task options
    cout << "Task options: " << endl << "   1. Add two Duration objects\n";
    cout << "   2. Subtract two Duration objects\n";
    cout << "   3. Multiply a Duration object by a constant\n";
    cout << "   4. Divide a Duration object by a constant\n";
    cout << "   5. Divide two Duration objects\n";
    cout << "   6. Create a randomized Duration object\n";

    //Asks user for desired task
    cout << "\nPlease enter the number corresponding to the desired task (1, 2, 3, 4, 5, or 6). ";
    cin >> task; //Gets user's inputs

    if(task == 1){ //add
      cout << "\n*****Enter 1st Duration Details*****" << endl; //Displays prompt
      int h, m, s; //Variables for storage
      cout << "   Enter the number of hours: "; //Asks user for input
      cin >> h; //Gets user input
      cout << "   Enter the number of minutes: "; //Asks user for input
      cin >> m; //Gets user input
      cout << "   Enter the number of seconds: "; //Asks user for input
      cin >> s; //Gets user input
      Duration d1(h, m, s); //Creates Duration object

      cout << "\n*****Enter 2nd Duration Details*****" << endl; //Displays prompt
      int hr, min, sec; //Variables for storage
      cout << "   Enter the number of hours: "; //Asks user for input
      cin >> hr; //Gets user input
      cout << "   Enter the number of minutes: "; //Asks user for input
      cin >> min; //Gets user input
      cout << "   Enter the number of seconds: "; //Asks user for input
      cin >> sec; //Gets user input
      Duration d2(hr, min, sec); //Creates Duration object

      cout << "\n1st Duration Entered: " << d1; //Displays prompt

      cout << "\n2nd Duration Entered: " << d2; //Displays prompt

      cout << "\nSum of the two Duration objects entered: " << d1 + d2; //Displays prompt
  
    }else if(task == 2){ //subtract
      cout << "\n*****Enter 1st Duration Details*****" << endl; //Displays prompt
      int h, m, s; //Variables for storage
      cout << "   Enter the number of hours: "; //Asks user for input
      cin >> h; //Gets user input
      cout << "   Enter the number of minutes: "; //Asks user for input
      cin >> m; //Gets user input
      cout << "   Enter the number of seconds: "; //Asks user for input
      cin >> s; //Gets user input
      Duration d1(h, m, s); //Creates Duration object

      cout << "\n*****Enter 2nd Duration Details*****" << endl; //Displays prompt
      int hr, min, sec; //Variables for storage
      cout << "   Enter the number of hours: "; //Asks user for input
      cin >> hr; //Gets user input
      cout << "   Enter the number of minutes: "; //Asks user for input
      cin >> min; //Gets user input
      cout << "   Enter the number of seconds: "; //Asks user for input
      cin >> sec; //Gets user input
      Duration d2(hr, min, sec); //Creates Duration object

      cout << "\n1st Duration Entered: " << d1; //Displays prompt

      cout << "\n2nd Duration Entered: " << d2; //Displays prompt

      cout << "\nDifference of the two Duration objects entered: " << d1 - d2; //Displays prompt
  
    }else if(task == 3){ //multiply
      cout << "\n*****Enter Duration Details*****" << endl; //Displays prompt
      int h, m, s; //Variables for storage
      cout << "   Enter the number of hours: "; //Asks user for input
      cin >> h; //Gets user input
      cout << "   Enter the number of minutes: "; //Asks user for input
      cin >> m; //Gets user input
      cout << "   Enter the number of seconds: "; //Asks user for input
      cin >> s; //Gets user input
      Duration d1(h, m, s); //Creates Duration object

      double c; //Variable for storage
      cout << "\n*****Enter A Constant*****" << endl; //Displays prompt
      cin >> c; //Gets user input

      cout << "\n1st Duration Entered: " << d1; //Displays prompt

      cout << "\nConstant Entered: " << c; //Displays prompt

      cout << "\nProduct of the Duration and constant entered: " << d1 * c; //Displays prompt

    }else if(task == 4){ //divide by constant
      cout << "\n*****Enter Duration Details*****" << endl; //Displays prompt
      int h, m, s; //Variables for storage
      cout << "   Enter the number of hours: "; //Asks user for input
      cin >> h; //Gets user input
      cout << "   Enter the number of minutes: "; //Asks user for input
      cin >> m; //Gets user input
      cout << "   Enter the number of seconds: "; //Asks user for input
      cin >> s; //Gets user input
      Duration d1(h, m, s); //Creates Duration object

      double c; //Variable for storage
      cout << "\n*****Enter A Constant*****" << endl; //Displays prompt
      cin >> c; //Gets user input

      cout << "\n1st Duration Entered: " << d1; //Displays prompt

      cout << "\nConstant Entered: " << c; //Displays prompt

      cout << "\nQuotient of the Duration and constant entered: " << d1 / c; //Displays prompt
  
    }else if(task == 5){ //divide 2 Durations
      cout << "\n*****Enter 1st Duration Details*****" << endl; //Displays prompt
      int h, m, s; //Variables for storage
      cout << "   Enter the number of hours: "; //Asks user for input
      cin >> h; //Gets user input
      cout << "   Enter the number of minutes: "; //Asks user for input
      cin >> m; //Gets user input
      cout << "   Enter the number of seconds: "; //Asks user for input
      cin >> s; //Gets user input
      Duration d1(h, m, s); //Creates Duration object

      cout << "\n*****Enter 2nd Duration Details*****" << endl; //Displays prompt
      int hr, min, sec; //Variables for storage
      cout << "   Enter the number of hours: "; //Asks user for input
      cin >> hr; //Gets user input
      cout << "   Enter the number of minutes: "; //Asks user for input
      cin >> min; //Gets user input
      cout << "   Enter the number of seconds: "; //Asks user for input
      cin >> sec; //Gets user input
      Duration d2(hr, min, sec); //Creates Duration object

      cout << "\n1st Duration Entered: " << d1; //Displays prompt

      cout << "\n2nd Duration Entered: " << d2; //Displays prompt

      cout << "\nQuotient of the two Duration objects entered: " << d1 / d2; //Displays prompt

    }else if(task == 6){
      Duration d1;
      d1.randomize();
      cout << "Randomized Duration object (less than a day): " << d1;

    }else{ //Incase user inputs wrong number
      cout << "\nIncorrect input." << endl; //Tells user input was incorrect
    }

    //Asks user if they want to rerun the testing program
    cout << "\n\nWould you like to rerun? Enter 'n' for no, 'y' for yes. "; 
    cin >> rerun; //Gets user's input
    cout << endl; //Enters another line for nice formatting

  }
  return 0;
}