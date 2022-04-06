# ECE-3220-Project
Final Project for Software Development in C++ at University of Missouri-Columbia.

Many Mizzou students are familiar with Schedule Planner, a tool that lets them see class schedules, compare different schedules, and even place conditions on their schedule (like no class on Friday). This is something similar! This project is a command-line interface. Users will input their schedules into the program, which will then output possible schedules.  Some options are included in the program as well, such as scheduling time constraints and making sure prerequisites are met. 

List of Features/Functionalities:
•	Users will input courses as a .txt file that will be parsed by the program. 
o	Includes course name, number, description, section times, and prerequisites, if applicable.
o	Courses may have multiple sections. In that case, the program will include no more than one section of the course in each schedule. The user will need to include the course multiple times in each input file, once for each section.
•	Users can also include a file of courses they’ve already taken.
•	The program will output possible schedules to .txt files along with detailed error messages to the console where applicable.
o	Where errors occur, program usage should be displayed as well.
•	Options for course scheduling will be provided on the command line as flags.
o	Options include time constraints/breaks (e.g., no schedules with class before 10am or after 3pm, lunch breaks, etc.)
o	Day constraints (e.g., no class on Friday)
o	Prerequisite checking enable/disable
•	Each course may have prerequisites that need to be met. If prerequisites are not met, detailed error messages will be displayed to the user.
