// macolours.h - Said - MAC-OLLERS
//      COLOURS FOR THE MAC, what a WIN!!
//      Colours on MAC and WINDOWS are done through ANSI therefore each colour has it's own code to have the text colour change.
//      Background colour is also able to change through the ANSI code. Background and Foreground can be changed individually 
//      and we do not need to restate if we are not changing one or the other. 

//------ DOCUMENTATION ------//
//  To call a colour change use a cout statement and state the colour change you want
//    Example: cout << GREEN; 
//      That will change the colour from there forward; background colours can also be changed the same way 
//          However background colours require 'B_' before the colour you want to change to so that it is clear you want the background to change 


//REQUIREMENT (Mac)
// If on MAC you should use VSCode with coderunner as an extension which should be set to run within the terminal
//  Colours will not work the same on XCode

//RECOMENDATION (Win)
//  If on WINDOWS use Visual Studio with the terminal window text changed to support ASCII to have the best experience.


// RESET // -- RESET CLEARS BOTH (Foreground and Background)
// To revert back to standard colours, since it is the users responsibilty to change the colour back to normal,
//      as it would have been much more work for the user if it reverted back to the standard colours after each line.
#define RESET "\033[0m" /* RESET */


// FOREGROUND COLOUR CHANGE //
//Defining the colour code to match its name beginning
//Code contains \033 indicating we want to change the string
//The last number repersent the colour
#define BLACK     "\033[30m"      /* Black */
#define RED       "\033[31m"      /* Red */
#define GREEN     "\033[32m"      /* Green */
#define YELLOW    "\033[33m"      /* Yellow */
#define BLUE      "\033[34m"      /* Blue */
#define MAGENTA   "\033[35m"      /* Magenta */
#define CYAN      "\033[36m"      /* Cyan */
//LIGHT/BRIGHT Foreground Colours //
//Defining the colour code to match its name beginning LI for LIGHT
#define LIRED     "\033[91m"      /* Light Red */
#define LIGREEN   "\033[92m"      /* Light Green */
#define LIYELLOW  "\033[93m"      /* Light Yellow */
#define LIBLUE    "\033[94m"      /* Light Blue */
#define LIMAGENTA "\033[95m"      /* Light Magenta */
#define LICYAN    "\033[96m"      /* Light Cyan */
#define WHITE     "\033[97m"      /* White */


// BOLD FOREGROUND COLOUR CHANGE // **BOLDED IS MAC USERS ONLY!!** **WINDOWS = LIGHTER!!**
//HOWEVER, A side effect is the colour becomes even lighter from the original in windows
//Defining the colour code to match its name beginning with BOLD to show its BOLDED
//Code contains \033 indicating we want to change the string
//1m is to BOLD the text
//The last number repersent the colour
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
//LIGHT/BRIGHT Colours //
//Defining the colour code to match its name beginning BOLDLI for BOLD LIGHT
#define BOLDLIRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDLIGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDLIYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDLIBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDLIMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDLICYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE     "\033[1m\033[97m"      /* Bold White */

// BACKGROUND COLOUR CHANGE //
//Defining the colour code to match its name beging with B_ to show its background
//Code contains \033 indicating we want to change the string
//The last number repersent the colour of the background
#define B_BLACK     "\033[40m"      /* Black Background */
#define B_RED       "\033[41m"      /* Red Background */
#define B_GREEN     "\033[42m"      /* Green Background */
#define B_YELLOW    "\033[43m"      /* Yellow Background */
#define B_BLUE      "\033[44m"      /* Blue Background */
#define B_MAGENTA   "\033[45m"      /* Magenta Background */
#define B_CYAN      "\033[46m"      /* Cyan Background */
#define B_GRAY      "\033[100m"     /* Gray Background */
//LIGHT/BRIGHT Colours //
//Defining the colour code to match its name beginning B_LI for BACKGROUND LIGHT
#define B_LIRED     "\033[101m"      /* Red Background */
#define B_LIGREEN   "\033[102m"      /* Green Background */
#define B_LIYELLOW  "\033[103m"      /* Yellow Background */
#define B_LIBLUE    "\033[104m"      /* Blue Background */
#define B_LIMAGENTA "\033[105m"      /* Magenta Background */
#define B_LICYAN    "\033[106m"      /* Cyan Background */
#define B_WHITE     "\033[107m"     /* White Background */

//Each colour can be modified slightly or be replaced by another colour through the ANSI escape codes
//      codes for each colour are available @ https://en.wikipedia.org/wiki/ANSI_escape_codea
//          The code that effects the colour itself is "\033[40m" the last number before the m which in this case is 40
//              To get a new colour that value can be swapped/changed.


//Original MISSION
//  Bringing colours to the MAC since,
//      Mac users did not have colours before this point

//------ CREDITS ------//
// TEAM: 4 Cubed - All have 4 letter names
//      Jace Marien - Catalyst
//      Jade Lee - Enhancer
//      Uday Shekhawat - Pioneer
// Created FEBRUARY, 2021 (Senior YEAR BABY!!!)

//----TEAM MESSAGE FOR FUTURE GENERATIONS----//
// #FOODANDCOMSCIGOTOGETHER 
//  #Justlikemyhair
//   #Trending
