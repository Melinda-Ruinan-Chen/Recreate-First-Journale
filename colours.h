// colours.h contains two functions that the entire program is able to access: text_colour - which changes the
//		colour of the text, and change_colour - which changes the physical colour of the logical colour passed.
//		The header also contains two enumerated types - one to represent the foreground colour, and another to
//		represent the background colour.

/* -*-*-*-*-*-*-*-*-*-*-*- NOTES -*-*-*-*-*-*-*-*-*-*-*-
	- Even with change_colour, only 16 colours can be used at once, and if change_colour is used on a colour already
		in use (including black for console background) all previous occurrences will be changed. So, you could
		have all colours set to different shades of red but if you change f_green back to green all previous text
		using that shade of red will be set to green.

	- background colours and foreground colours represent the same physical colour (e.g. if you changed f_red
		to green, both f_red and b_red would output green).

	- Change the false in "#define ENABLE_BOLD false" below to true to make -all- console output bold, but note
		that this affects all previous text too.
*/


/* -*-*-*-*-*-*-*-*-*-*-*- DOCUMENTATION -*-*-*-*-*-*-*-*-*-*-*-
	To change the text colour:
		call text_colour(foreground, background)
			foreground: fore_color, the foreground colour to set
			background: back_color, the background colour to set
			RETURN: void
		NOTE: backwards compatible with previous versions of colours.h

	To change the shade of a colour:
		call change_colour(logical_colour, red, green, blue)
			logical_colour: int, the logical colour to be replaced (e.g. f_red, b_black, etc.)
				 NOTE: b_ and f_ don't matter, so it is int
			red: int, the red RGB value of the colour to replace the logical_colour with
			green: int, the green RGB value of the colour to replace the logical_colour with
			blue: int, the blue RGB value of the colour to replace the logical_colour with
			RETURN: COLORREF, the physical colour that was previously set or logical_colour's default if it failed
		----------OR---------
		call change_colour(logical_colour, colour_value)
			logical_colour: int, the logical colour to be replaced (e.g. f_red, b_black, etc.)
				NOTE: b_ and f_ don't matter, so it is int
			colour_value: COLORREF, the physical colour to put in logical_colour's place - useful for setting the
				(cont.) colour to a previously returned value
			RETURN: COLORREF, the physical colour that was previously set or logical_colour's default if it failed

	To set a logical colour to its default value:
		call reset_color(logical_colour)
			logical_colour: int, the logical colour to reset to the original physical colour
			RETURN: bool, whether or not the function succeeded

	To change whether -all- console text is bolded
		NOTE: "#define ENABLE_BOLD false" must be set to true in order for this to work
		to make bold:
			run coloursheader::bold_successful = coloursheader::make_bold(true)
			NOTE: Done automatically when ENABLE_BOLD is set to true
		to unbold:
			run coloursheader::bold_successful = coloursheader::make_bold(false)
*/




#define ENABLE_BOLD false // Change this to true to make all the console text bold

using namespace std;

#if ENABLE_BOLD // Preprocessor used to help compile time if it is unused
namespace coloursheader { // Create namespace to hold this function and its boolean for whether or not it was
	//		successful, so that it isn't accidentally used by an unknowledgable programmer - You probably will have
	//		to look in the header to know how to access the function, in which case the programmer probably knows
	//		what they are doing and will read what the function does

	bool make_bold(bool); // Create function prototype
	bool bold_successful = make_bold(true); // Variable for whether or not the function to bold text was successful

	bool make_bold(bool set_bold) { // Define the function to bold the text.
		// ********* NOTE: WILL SET ALL TEXT IN CONSOLE TO BOLD *********

		// bool set_bold;							// Boolean for whether or not to make the console bold
		CONSOLE_FONT_INFOEX font;					// Structure to hold information on the font
		font.cbSize = sizeof(CONSOLE_FONT_INFOEX);	// Set the size of the buffer to the correct value

		// Run the function to get font information
		if (GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &font)) { // If successful, continue
			// Set the font weight to bold if set_bold is true, otherwise set the font weight to standard
			(set_bold) ? font.FontWeight = 700 : font.FontWeight = 400;

			// Run the function to set the new font information
			if (SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &font)) {
				return true; // If setting the new font was successful, return true
			} // End if
			else { // If setting the new font information failed, return false
				return false;
			} // End else
		} // End if
		else { // If getting the current font information failed, return false
			return false;
		} // End else
	}
	// End make_bold
}
#endif

// ********** structures and enumerated types **********
enum fore_color
{
	f_black = 0,
	f_white = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	f_gray = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	f_red = FOREGROUND_INTENSITY | FOREGROUND_RED,
	f_dred = FOREGROUND_RED,
	f_green = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	f_dgreen = FOREGROUND_GREEN,
	f_yellow = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	f_dyellow = FOREGROUND_RED | FOREGROUND_GREEN,
	f_blue = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	f_dblue = FOREGROUND_BLUE,
	f_magenta = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	f_dmagenta = FOREGROUND_RED | FOREGROUND_BLUE,
	f_cyan = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	f_dcyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
	f_dgray = FOREGROUND_INTENSITY,
};

// ENUMERATE BACKGROUND COLORS
enum back_color
{
	b_black = 0,
	b_white = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	b_gray = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	b_red = BACKGROUND_INTENSITY | BACKGROUND_RED,
	b_dred = BACKGROUND_RED,
	b_green = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
	b_dgreen = BACKGROUND_GREEN,
	b_yellow = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
	b_dyellow = BACKGROUND_RED | BACKGROUND_GREEN,
	b_blue = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
	b_dblue = BACKGROUND_BLUE,
	b_magenta = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
	b_dmagenta = BACKGROUND_RED | BACKGROUND_BLUE,
	b_cyan = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
	b_dcyan = BACKGROUND_GREEN | BACKGROUND_BLUE,
	b_dgray = BACKGROUND_INTENSITY,
};

const COLORREF d_colors[16] = { // The uneditable list of default physical colour values for each logical colour,
	//		in the order of colortable (numerically ascending logical colours)
	0,
	8388608,
	32768,
	8421376,
	128,
	8388736,
	32896,
	12632256,
	8421504,
	16711680,
	65280,
	16776960,
	255,
	16711935,
	65535,
	16777215,
};

// ********** Functions to be used with the colours **********

//Function to set the text colour
void text_colour(fore_color fg, back_color bg)
{
	/** apply the text color we want **/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg | bg);
}
// End text_colour function

// Function to find the given colour's position in colortable/d_colors
unsigned short int get_color_pos(int colour) {
	// int colour;			// The logical colour (e.g. f_red - logical red) to find the position of. int so that
	//		 both f_ and b_ colours can be passed
	unsigned short int position; // The passed colour's position in colourtable array. unsigned because it can't
	//		be negative. short because the array is 0-15, so it doesn't need to be 32-bit

	// Find old_colour's position in the colour table - whether it is f_ or b_
	switch (colour) {
	case f_black: // Logical black (Note: both f_black and b_black represent 0)
		position = 0; break;
	case f_dblue: // Logical dblue
		position = 1; break;
	case f_dgreen: // Logical dgreen
		position = 2; break;
	case f_dcyan: // Logical dcyan
		position = 3; break;
	case f_dred: // Logical dred
		position = 4; break;
	case f_dmagenta: // Logical dmagenta
		position = 5; break;
	case f_dyellow: // Logical dyellow
		position = 6; break;
	case f_gray: // Logical gray
		position = 7; break;
	case f_dgray: // Logical dgray
		position = 8; break;
	case f_blue: // Logical blue
		position = 9; break;
	case f_green: // Logical green
		position = 10; break;
	case f_cyan: // Logical cyan
		position = 11; break;
	case f_red: // Logical red
		position = 12; break;
	case f_magenta: // Logical magenta
		position = 13; break;
	case f_yellow: // Logical yellow
		position = 14; break;
	case f_white: // Logical white
		position = 15; break;
	case b_dblue: // Logical dblue
		position = 1; break;
	case b_dgreen: // Logical dgreen
		position = 2; break;
	case b_dcyan: // Logical dcyan
		position = 3; break;
	case b_dred: // Logical dred
		position = 4; break;
	case b_dmagenta: // Logical dmagenta
		position = 5; break;
	case b_dyellow: // Logical dyellow
		position = 6; break;
	case b_gray: // Logical gray
		position = 7; break;
	case b_dgray: // Logical dgray
		position = 8; break;
	case b_blue: // Logical blue
		position = 9; break;
	case b_green: // Logical green
		position = 10; break;
	case b_cyan: // Logical cyan
		position = 11; break;
	case b_red: // Logical red
		position = 12; break;
	case b_magenta: // Logical magenta
		position = 13; break;
	case b_yellow: // Logical yellow
		position = 14; break;
	case b_white: // Logical white
		position = 15; break;
	}

	return position; // Return the colour's position in the ordered array
}
// End get_color_pos function

// Function to change the physical colour of the logical colour provided - used for if the COLORREF needs to
//		be calculated from RGB
COLORREF change_colour(int logical_colour, int red, int green, int blue) {
	// int logical_colour;						// The logical colour (e.g. f_red -- logical red) to replace the colour
	//													value of. int so that both f_ and b_ colours can be passed 
	// int red, green, blue;					// The RGB values of the colour to replace old_colour with
	COLORREF new_colour;						// The colour value to replace old_colour's value with
	HANDLE console_handle;						// The handle of the console window
	CONSOLE_SCREEN_BUFFER_INFOEX console_info;	// Various information on the console window (extended)
	COLORREF previous_colour;					// The colour value of old_colour when this function was first called
	unsigned short int position;				// logical_colour's position in the colour table. unsigned because it
	//		can't be negative. Short because the array is 0-15, so it doesn't need to be 32-bit

	console_handle = GetStdHandle(STD_OUTPUT_HANDLE); // Get the handle of the console window

	// Make the size (memory size) of ConsoleInfo the proper size
	console_info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	position = get_color_pos(logical_colour);

	// Call the function to get the information associated with the console
	if (GetConsoleScreenBufferInfoEx(console_handle, &console_info)) { // If the function succeeded, continue
		// Copy the previous colour into the variable to return
		previous_colour = console_info.ColorTable[position];

		// Check if the all of the RGB values are valid, and if not, return the unchanged colour
		if ((red > 256 || green > 256 || blue > 256) || (red < 0 || green < 0 || blue < 0)) {
			return previous_colour;
		}

		// Calculate the new colour
		new_colour = RGB(red, green, blue);

		// Redefine the logical colour passed (e.g. f_red/b_red) to represent the new colour value
		console_info.ColorTable[position] = new_colour;

		// Apply the changes
		SetConsoleScreenBufferInfoEx(console_handle, &console_info);

		// Return the orignal colour
		return previous_colour;
	}
	else { // If the function to get console information failed, then return the default value of the passed colour
		return d_colors[position]; // Thought process: if the function failed, that probably means that if it was
		//		called earlier it also failed, so that colour *probably* hadn't been changed earlier
	}
}
// End change_colour(overload: int, int, int)

// Function to change the physical colour of the logical colour provided - used for if the colour is known
//		in COLORREF type (e.g. setting the physical colour to a colour previously returned from change_colour)
COLORREF change_colour(int logical_colour, COLORREF new_colour) {
	// int logical_colour;						// The logical colour (e.g. f_red -- logical red) to replace the colour
	//													value of. int so that both f_ and b_ colours can be passed 
	// COLORREF new_colour;						// The colour value to replace old_colour's value with
	HANDLE console_handle;						// The handle of the console window
	CONSOLE_SCREEN_BUFFER_INFOEX console_info;	// Various information on the console window (extended)
	COLORREF previous_colour;					// The colour value of old_colour when this function was first called
	unsigned short int position;				// logical_colour's position in the colour table. unsigned because it
	//		can't be negative. Short because the array is 0-15, so it doesn't need to be 32-bit

	console_handle = GetStdHandle(STD_OUTPUT_HANDLE); // Get the handle of the console window

	// Make the size (memory size) of ConsoleInfo the proper size
	console_info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	// Find logical_colour's position in the colour table - whether it is f_ or b_
	position = get_color_pos(logical_colour);

	// Call the function to get the information associated with the console
	if (GetConsoleScreenBufferInfoEx(console_handle, &console_info)) { // If the function succeeded, continue
		// Copy the previous colour into the variable to return
		previous_colour = console_info.ColorTable[position];

		// Redefine the logical colour passed (e.g. f_red/b_red) to represent the new colour value
		console_info.ColorTable[position] = new_colour;

		// Apply the changes
		SetConsoleScreenBufferInfoEx(console_handle, &console_info);

		// Return the orignal colour
		return previous_colour;
	}
	else { // If the function to get console information failed, then return the default value of the passed colour
		return d_colors[position]; // Thought process: if the function failed, that probably means that if it was
		//		called earlier it also failed, so that colour *probably* hadn't been changed earlier
	}
}
// End change_colour function (overload: COLORREF)

// Function to reset the logical colour passed to it's original physical colour
bool reset_color(int colour) {
	// int colour; // The logical colour to reset the physical colour of. Int so that both f_ and b_ colours can be passed
	unsigned short int position;	// colour's position in the colourtable/d_colours array. unsigned because it
	//		can't be negative. Short because the array is 0-15, so it doesn't need to be 32-bit

	// Find old_colour's position in the colour table - whether it is f_ or b_
	position = get_color_pos(colour);

	// Change the logical colour to the default physical value
	if (change_colour(colour, d_colors[position]) == d_colors[position]) {
		return false; // Function either failed, or reset a default value
	}

	// If the program reaches here, then the function succeeded, so return that notion
	return true;
}
// End reset_color function