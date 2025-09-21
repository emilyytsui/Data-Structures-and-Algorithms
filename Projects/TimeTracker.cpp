//TimeTracker.cpp         //Author: Emily Tsui
//Provides user with task options, user choses desired option, inputs necessary requirements for function, sees if user wants to repeat

#include <iostream>
using namespace std; //Namespace to search in

class Time{ //Class that contains accessor and mutator methods
  private: //Private attributes
    int hours, minutes, seconds; //Represents user inputs
  
  public:
    Time(int sec){ //Constructor that takes seconds only
      int secsLeft = sec; //Sets the variable equal to the the user's seconds input
      hours = secsLeft / 3600; //Sets the private variable equal to the quotient of the user's seconds input divided by 3600
      secsLeft = secsLeft - hours * 3600; //Sets the variable equal to the difference of secsLeft minus hours represented as seconds
      minutes = secsLeft / 60; //Sets the variable equal to the quotient of the calculated value of secsLeft divided by 60
      seconds = secsLeft - minutes * 60; //Sets the private variable equal to the difference of secsLeft minus the product of minutes times 60
    }

    Time(int hrs, int mins, int secs){ //Constructor that takes hours, minutes, seconds
      int totalSecs = hrs * 3600 + mins * 60 + secs; //Sets the variable equal to the total number of seconds, calculated by changing hours and minutes into seconds, then adding them with secs
      hours = totalSecs / 3600; //Sets the private variable equal to the quotient of totalSecs divided by 3600
      totalSecs = totalSecs - hours * 3600; //Sets the variable equal to the difference of totalSecs minus hours represented as seconds
      minutes = totalSecs / 60; //Sets the variable equal to the quotient of the calculated value of totalSecs divided by 60
      seconds = totalSecs - minutes * 60; //Sets the private variable equal to the difference of totalSecs minus the product of minutes times 60
    }

    void DisplayTime(){ //Used to print out the Time variables
      
      if(hours * 3600 + minutes * 60 + seconds < 0){ //Checks to see if hours are negative (result from the subtract method)
        cout << "-"; //Prints out negative sign
      }

      if(abs(hours) < 10 ){ //Checks to see if hours are less than 10
        cout << "0"; //Prints 0 out first for the "HH" format
      }
      cout << abs(hours) << ":"; //Prints out hours followed by colon for format

      if(abs(minutes) < 10){ //Checks to see if minutes are less than 10
        cout << "0"; //Prints 0 out first for the "MM" format
      }
      cout << abs(minutes) << ":"; //Prints out minutes followed by colon for format

      if(abs(seconds) < 10){ //Checks to see if seconds are less than 10
        cout << "0"; //Prints 0 out first for the "SS" format
      }
      cout << abs(seconds); //Prints out seconds

    }

    Time add(Time other){ //Adds two Time objects and returns a new object
      int addedSecs = 0; //Variable for storage
      //Sets the variable equal to the sum of seconds for both time objects calculated by changing hours and minutes into seconds, then adding them with the two seconds inputs
      addedSecs = hours * 3600 + minutes * 60 + seconds + other.hours * 3600 + other.minutes * 60 + other.seconds;
      return Time(addedSecs); //Returns the Time object
    }

    Time subtract(Time other){ //Subtracts two Time objects and returns a new object
      int difference = 0; //Variable for storage
      //Sets the variable equal to the difference of seconds for both time objects calculated by changing hours and minutes into seconds, then adding them with the seconds and subtracting Time other
      difference = hours * 3600 + minutes * 60 + seconds - other.hours * 3600 - other.minutes * 60 - other.seconds;
      return Time(difference); //Returns Time object
    }
    
    Time increaseBy(int h, int m, int s){ //Increases the Time object by the given arguments and returns a new object
      return Time(hours * 3600 + minutes * 60 + seconds + h * 3600 + m * 60 + s); //Returns Time object, converts all hours and minutes into seconds and adds them with seconds and s
    }
    
    Time increaseBy(int s){ //Increases the Time object by the given argument and returns a new object
      return Time(hours * 3600 + minutes * 60 + seconds + s); //Returns Time object, converts hours and minutes into seconds and adds them with seconds and s
    }
};

  int main() { //Used for testing and displaying
 
    char rerun = 'y'; //Varaible used to detect when the loop should run

    while(rerun == 'y'){ //Loop to repeat process if user wants
    
      int task = 0; //Variable to store which task the user wants
      
      cout << "Task options: " << endl << "   1. Add two Time objects\n"; //Displays task options
      cout << "   2. Subtract two Time objects\n"; //Displays task options
      cout << "   3. Increases Time object by given arguments (hour, minute, second)\n"; //Displays task options
      cout << "   4. Increases Time object by given argument (second)\n"; //Displays task options
      cout << "\nPlease enter the number corresponding to the desired task (1, 2, 3, or 4). "; //Asks user for desired task
      cin >> task; //Gets user's inputs

      if(task == 1){ //add

        char object = 'c'; //Variable to store which option the user wants
        cout << "\nOptions for creating a Time object: " << "\n   a. Enter number of seconds only" << endl; //Displays input options
        cout << "   b. Enter number of hours, minutes, seconds" << endl; //Displays input options
        cout << "\nPlease enter the letter corresponding to the desired option (a or b). "; //Asks user to input desired
        cin >> object; //Gets user input
        
        if(object == 'a'){ //If user wants to input seconds only
          
          cout << "\n*****Enter Time Detail*****" << endl; //Displays prompt
          int s; //Variable for storage
          cout << "   Enter the number of seconds: "; //Asks user for input
          cin >> s; //Gets user input
          Time t1(s); //Creates Time object

          char object = 'c'; //Variable to store which option the user wants
          cout << "\nOptions for creating a Time object: " << "\n   a. Enter number of seconds only" << endl; //Displays input options
          cout << "   b. Enter number of hours, minutes, seconds" << endl; //Displays input options
          cout << "\nPlease enter the letter corresponding to the desired option (a or b). "; //Asks user to input desired
          cin >> object; //Gets user input

          if(object == 'a'){ //If user wants to input seconds only
          
            cout << "\n*****Enter Time Detail*****" << endl; //Displays prompt
            int s; //Variable for storage
            cout << "   Enter the number of seconds: "; //Asks user for input
            cin >> s; //Gets user input
            Time t2(s); //Creates Time object

            Time result = t1.add(t2); //Creates new Time object, stores method result in it
          
            cout << "\n1st Time Entered: "; //Asks user for input
            t1.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\n2nd Time Entered: "; //Asks user for input
            t2.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\nSum of the two times entered: "; //Displays prompt
       
            result.DisplayTime(); //Calls DisplayTime() to print out Time object

          }else if(object == 'b'){ //If user wants to input hours, minutes, seconds
            
            cout << "\n*****Enter Time Details*****" << endl; //Displays prompt
            int h, m, s; //Variables for storage
            cout << "   Enter the number of hours: "; //Asks user for input
            cin >> h; //Gets user input
            cout << "   Enter the number of minutes: "; //Asks user for input
            cin >> m; //Gets user input
            cout << "   Enter the number of seconds: "; //Asks user for input
            cin >> s; //Gets user input
            Time t2(h, m, s); //Creates Time object

            Time result = t1.add(t2); //Creates new Time object, stores method result in it
          
            cout << "\n1st Time Entered: "; //Asks user for input
            t1.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\n2nd Time Entered: "; //Asks user for input
            t2.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\nSum of the two times entered: "; //Displays prompt
       
            result.DisplayTime(); //Calls DisplayTime() to print out Time object
          }

        }else if(object == 'b'){ //If user wants to input hours, minutes, seconds
          cout << "\n*****Enter Time Details*****" << endl; //Displays prompt
          int h, m, s; //Variables for storage
          cout << "   Enter the number of hours: "; //Asks user for input
          cin >> h; //Gets user input
          cout << "   Enter the number of minutes: "; //Asks user for input
          cin >> m; //Gets user input
          cout << "   Enter the number of seconds: "; //Asks user for input
          cin >> s; //Gets user input
          Time t1(h, m, s); //Creates Time object

          char object = 'c'; //Variable to store which option the user wants
          cout << "\nOptions for creating a Time object: " << "\n   a. Enter number of seconds only" << endl; //Displays input options
          cout << "   b. Enter number of hours, minutes, seconds" << endl; //Displays input options
          cout << "\nPlease enter the letter corresponding to the desired option (a or b). "; //Asks user to input desired
          cin >> object; //Gets user input

          if(object == 'a'){ //If user wants to input seconds only
          
            cout << "\n*****Enter Time Detail*****" << endl; //Displays prompt
            int s; //Variable for storage
            cout << "   Enter the number of seconds: "; //Asks user for input
            cin >> s; //Gets user input
            Time t2(s); //Creates Time object

            Time result = t1.add(t2); //Creates new Time object, stores method result in it
          
            cout << "\n1st Time Entered: "; //Asks user for input
            t1.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\n2nd Time Entered: "; //Asks user for input
            t2.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\nSum of the two times entered: "; //Displays prompt
       
            result.DisplayTime(); //Calls DisplayTime() to print out Time object

          }else if(object == 'b'){ //If user wants to input hours, minutes, seconds
            
            cout << "\n*****Enter Time Details*****" << endl; //Displays prompt
            int h, m, s; //Variables for storage
            cout << "   Enter the number of hours: "; //Asks user for input
            cin >> h; //Gets user input
            cout << "   Enter the number of minutes: "; //Asks user for input
            cin >> m; //Gets user input
            cout << "   Enter the number of seconds: "; //Asks user for input
            cin >> s; //Gets user input
            Time t2(h, m, s); //Creates Time object

            Time result = t1.add(t2); //Creates new Time object, stores method result in it
          
            cout << "\n1st Time Entered: "; //Asks user for input
            t1.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\n2nd Time Entered: "; //Asks user for input
            t2.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\nSum of the two times entered: "; //Displays prompt
       
            result.DisplayTime(); //Calls DisplayTime() to print out Time object
          }
      
        }else{
          cout << "\nIncorrect input." << endl; //Tells user input was incorrect
        }

      }else if(task == 2){ //subtract
        
        char object = 'c'; //Variable to store which option the user wants
        cout << "\nOptions for creating a Time object: " << "\n   a. Enter number of seconds only" << endl; //Displays input options
        cout << "   b. Enter number of hours, minutes, seconds" << endl; //Displays input options
        cout << "\nPlease enter the letter corresponding to the desired option (a or b). "; //Asks user to input desired
        cin >> object; //Gets user input
        
        if(object == 'a'){ //If user wants to input seconds only
          
          cout << "\n*****Enter Time Detail*****" << endl; //Displays prompt
          int s; //Variable for storage
          cout << "   Enter the number of seconds: "; //Asks user for input
          cin >> s; //Gets user input
          Time t1(s); //Creates Time object

          char object = 'c'; //Variable to store which option the user wants
          cout << "\nOptions for creating a Time object: " << "\n   a. Enter number of seconds only" << endl; //Displays input options
          cout << "   b. Enter number of hours, minutes, seconds" << endl; //Displays input options
          cout << "\nPlease enter the letter corresponding to the desired option (a or b). "; //Asks user to input desired
          cin >> object; //Gets user input

          if(object == 'a'){ //If user wants to input seconds only
          
            cout << "\n*****Enter Time Detail*****" << endl; //Displays prompt
            int s; //Variable for storage
            cout << "   Enter the number of seconds: "; //Asks user for input
            cin >> s; //Gets user input
            Time t2(s); //Creates Time object

            Time result = t1.subtract(t2); //Creates new Time object, stores method result in it
          
            cout << "\n1st Time Entered: "; //Asks user for input
            t1.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\n2nd Time Entered: "; //Asks user for input
            t2.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\nDifference of the two times entered: "; //Displays prompt
       
            result.DisplayTime(); //Calls DisplayTime() to print out Time object

          }else if(object == 'b'){ //If user wants to input hours, minutes, seconds
            
            cout << "\n*****Enter Time Details*****" << endl; //Displays prompt
            int h, m, s; //Variables for storage
            cout << "   Enter the number of hours: "; //Asks user for input
            cin >> h; //Gets user input
            cout << "   Enter the number of minutes: "; //Asks user for input
            cin >> m; //Gets user input
            cout << "   Enter the number of seconds: "; //Asks user for input
            cin >> s; //Gets user input
            Time t2(h, m, s); //Creates Time object

            Time result = t1.subtract(t2); //Creates new Time object, stores method result in it
          
            cout << "\n1st Time Entered: "; //Asks user for input
            t1.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\n2nd Time Entered: "; //Asks user for input
            t2.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\nDifference of the two times entered: "; //Displays prompt
       
            result.DisplayTime(); //Calls DisplayTime() to print out Time object
          }
          
        }else if(object == 'b'){ //If user wants to input hours, minutes, seconds
          cout << "\n*****Enter Time Details*****" << endl; //Displays prompt
          int h, m, s; //Variables for storage
          cout << "   Enter the number of hours: "; //Asks user for input
          cin >> h; //Gets user input
          cout << "   Enter the number of minutes: "; //Asks user for input
          cin >> m; //Gets user input
          cout << "   Enter the number of seconds: "; //Asks user for input
          cin >> s; //Gets user input
          Time t1(h, m, s); //Creates Time object

          char object = 'c'; //Variable to store which option the user wants
          cout << "\nOptions for creating a Time object: " << "\n   a. Enter number of seconds only" << endl; //Displays input options
          cout << "   b. Enter number of hours, minutes, seconds" << endl; //Displays input options
          cout << "\nPlease enter the letter corresponding to the desired option (a or b). "; //Asks user to input desired
          cin >> object; //Gets user input

          if(object == 'a'){ //If user wants to input seconds only
          
            cout << "\n*****Enter Time Detail*****" << endl; //Displays prompt
            int s; //Variable for storage
            cout << "   Enter the number of seconds: "; //Asks user for input
            cin >> s; //Gets user input
            Time t2(s); //Creates Time object

            Time result = t1.subtract(t2); //Creates new Time object, stores method result in it
          
            cout << "\n1st Time Entered: "; //Asks user for input
            t1.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\n2nd Time Entered: "; //Asks user for input
            t2.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\nDifference of the two times entered: "; //Displays prompt
       
            result.DisplayTime(); //Calls DisplayTime() to print out Time object

          }else if(object == 'b'){ //If user wants to input hours, minutes, seconds
            
            cout << "\n*****Enter Time Details*****" << endl; //Displays prompt
            int h, m, s; //Variables for storage
            cout << "   Enter the number of hours: "; //Asks user for input
            cin >> h; //Gets user input
            cout << "   Enter the number of minutes: "; //Asks user for input
            cin >> m; //Gets user input
            cout << "   Enter the number of seconds: "; //Asks user for input
            cin >> s; //Gets user input
            Time t2(h, m, s); //Creates Time object

            Time result = t1.subtract(t2); //Creates new Time object, stores method result in it
          
            cout << "\n1st Time Entered: "; //Asks user for input
            t1.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\n2nd Time Entered: "; //Asks user for input
            t2.DisplayTime(); //Calls DisplayTime() to print out Time object

            cout << "\nDifference of the two times entered: "; //Displays prompt
       
            result.DisplayTime(); //Calls DisplayTime() to print out Time object
          }
      
        }else{
          cout << "\nIncorrect input." << endl; //Tells user input was incorrect
        }

      }else if(task == 3){ //increaseBy
        
        char object = 'c'; //Variable to store which option the user wants
        cout << "\nOptions for creating a Time object: " << "\n   a. Enter number of seconds only" << endl; //Displays input options
        cout << "   b. Enter number of hours, minutes, seconds" << endl; //Displays input options
        cout << "\nPlease enter the letter corresponding to the desired option (a or b). "; //Asks user to input desired
        cin >> object; //Gets user input

        if(object == 'a'){ //If user wants to input seconds only
          cout << "\n*****Enter Time Detail*****" << endl; //Displays prompt
          int s; //Variable for storage
          cout << "   Enter the number of seconds: "; //Asks user for input
          cin >> s; //Gets user input
          Time t1(s); //Creates Time object
        
          cout << "\n***Increasing Arguments***" << endl; //Displays prompt
          int hr, min, sec; //Variables for storage
          cout << "   By how many hours do you want to increase? "; //Asks user for input
          cin >> hr; //Gets user input
          cout << "   By how many minutes do you want to increase? "; //Asks user for input
          cin >> min; //Gets user input
          cout << "   By how many seconds do you want to increase? "; //Asks user for input
          cin >> sec; //Gets user input

          cout << "\nTime Entered: "; //Displays prompt
          t1.DisplayTime(); //Calls DisplayTime() to print out Time object
          
          cout << "\nIncreased Time result: "; //Displays prompt
          Time result = t1.increaseBy(hr, min, sec); //Creates new Time object, stores method result in it
        
          result.DisplayTime(); //Calls DisplayTime() to print out Time object

        }else if(object == 'b'){ //If user wants to input hours, minutes, and seconds

          cout << "\n*****Enter Time Details*****" << endl; //Displays prompt
          int h, m, s; //Variables for storage
          cout << "   Enter the number of hours: "; //Asks user for input
          cin >> h; //Gets user input
          cout << "   Enter the number of minutes: "; //Asks user for input
          cin >> m; //Gets user input
          cout << "   Enter the number of seconds: "; //Asks user for input
          cin >> s; //Gets user input
          Time t1(h, m, s); //Creates Time object

          cout << "\n***Increasing Arguments***" << endl; //Displays prompt
          int hr, min, sec; //Variables for storage
          cout << "   By how many hours do you want to increase? "; //Asks user for input
          cin >> hr; //Gets user input
          cout << "   By how many minutes do you want to increase? "; //Asks user for input
          cin >> min; //Gets user input
          cout << "   By how many seconds do you want to increase? "; //Asks user for input
          cin >> sec; //Gets user input

          cout << "\nTime Entered: "; //Displays prompt
     
          t1.DisplayTime(); //Calls DisplayTime() to print out Time object
          
          cout << "\nIncreased Time result: "; //Displays prompt
          Time result = t1.increaseBy(hr, min, sec); //Creates new Time object, stores method result in it
     
          result.DisplayTime(); //Calls DisplayTime() to print out Time object
        }

      }else if(task == 4){ //increaseBy
        
        char object = 'c'; //Variable to store which option the user wants
        cout << "\nOptions for creating a Time object: " << "\n   a. Enter number of seconds only" << endl; //Displays input options
        cout << "   b. Enter number of hours, minutes, seconds" << endl; //Displays input options
        cout << "\nPlease enter the letter corresponding to the desired option (a or b). "; //Asks user to input desired
        cin >> object; //Gets user input

        if(object == 'a'){ //If user wants to input seconds only
          
          cout << "\n*****Enter Time Detail*****" << endl; //Displays prompt
          int s; //Variable for storage
          cout << "   Enter the number of seconds: "; //Asks user for input
          cin >> s; //Gets user input
          Time t1(s); //Creates Time object
       
          cout << "\n***Increasing Argument***" << endl; //Displays prompt
          int sec; //Variable for storage
          cout << "   By how many seconds do you want to increase? "; //Asks user for input
          cin >> sec; //Gets user input

          cout << "\nTime Entered: "; //Displays prompt
          t1.DisplayTime(); //Calls DisplayTime() to print out Time object
          
          cout << "\nIncreased Time result: "; //Displays prompt
          Time result = t1.increaseBy(sec); //Creates new Time object, stores method result in it
         
          result.DisplayTime(); //Calls DisplayTime() to print out Time object

        }else if(object == 'b'){ //If user wants to input hours, minutes, and seconds

          cout << "\n*****Enter Time Details*****" << endl; //Displays prompt
          int h, m, s; //Variables for storage
          cout << "   Enter the number of hours: "; //Asks user for input
          cin >> h; //Gets user input
          cout << "   Enter the number of minutes: "; //Asks user for input
          cin >> m; //Gets user input
          cout << "   Enter the number of seconds: "; //Asks user for input
          cin >> s; //Gets user input
          Time t1(h, m, s); //Creates Time object

          cout << "\n***Increasing Argument***" << endl; //Displays prompt
          int sec; //Variable for storage
          cout << "   By how many seconds do you want to increase? "; //Asks user for input
          cin >> sec; //Gets user input

          cout << "\nTime Entered: "; //Displays prompt
        
          t1.DisplayTime(); //Calls DisplayTime() to print out Time object
          
          cout << "\nIncreased Time result: "; //Displays prompt
          Time result = t1.increaseBy(sec); //Creates new Time object, stores method result in it
         
          result.DisplayTime(); //Calls DisplayTime() to print out Time object
        }

      }else{ //Incase user inputs wrong number
        cout << "\nIncorrect input." << endl; //Tells user input was incorrect
      }

      cout << "\n\nWould you like to rerun? Enter 'n' for no, 'y' for yes. "; //Asks user if they want to rerun the testing program
      cin >> rerun; //Gets user's input
      cout << endl; //Enters another line for nice formatting

    }
    return 0;
  }