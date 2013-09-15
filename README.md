# Numbered Task Switcher
A very simple task switcher tool that runs in the background.

## Usage
There are 10 slots for windows. These are stored in the number keys on the keyboard (0-9).

## Assign
To assign the currently focused window to one of these slots, press `Alt+Shift+Slot`, where Slot is a number on your keyboard.

## Show
To show a window that was assigned to a slot, press `Alt+Slot`, where Slot is the assigned number on your keyboard.

## Mouse Centering
If you want the mouse cursor to center on the window you are targeting, You can toggle this behavior by pressing Alt+Shift+M.
To disable this functionality, press Alt+Shift+M again to disable.

## Example
In case the above paragraphs aren't clear enough, try this example:
- Find your browser, make sure it's the active window.
- Press Alt+Shift+0
- Now open up another program.
- Press Alt+Shift+1

Now, when you press Alt+0, the browser will become active, and when you press Alt+1, the other program will become active.

## Building and Running
There is no pre-built executable available, though this may change in the future.

The code is very easy to build with MinGW (I have built with plain gcc and with Code::Blocks) or in Visual Studio.

For MinGW (via gcc, assuming already installed):
- Simply run `gcc.exe NumberedTaskSwitcher.cpp -o NumberedTaskSwitcher.exe`
- If you don't want a console window, add "-mwindows" to the command line

For MinGW (via Code::Blocks or other):
- Open NumberedTaskSwitcher.cpp as a regular file
- Build the file. This should output NumberedTaskSwitcher.exe in the same directory as the source
- Run the executable
- If you don't want a console window, go to Settings -> Compiler -> Linker settings -> Other linker options, and type "-mwindows" into the text box

For Visual Studio 2012: (should work for other versions as well)
- Create a new Win32 Console Application project
- In the Application Wizard under Application type, "Windows application" will hide the console window whereas "Console application" will show it
- Select the Empty project checkbox and click finish
- Under the Project menu, select Add Existing Item (Shift+Alt+A) and open NumberedTaskSwitcher.cpp
- Build the project (F7) and the executable should be in the project's directory.

## License
This code is released in the public domain. For places where this is not possible, the code is released under a Creative Commons CC0 license, which is effectively public domain.
