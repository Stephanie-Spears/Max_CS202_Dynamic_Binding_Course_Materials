#include "materials.h"
#include "list.h"


using namespace std;

void getUserInput(Materials & materials);
void modifyList(Materials & materials);

int main()
{
	Materials materials;
	getUserInput(materials);
	modifyList(materials);


	materials.display();
	cout << "Thank you for using my list manager!\n\n";
return 0;
}


void modifyList(Materials & materials)
{
	char chinput = 'x';
	int input = -1;

	while (input != 0)
	{
		cout << "\nWould you like to add more material, or modify?\n";
		cout << "M: Modify.\n";
		cout << "A: Add.\n";
		cout << "Q: Quit. \n";
		cin >> chinput;
		cin.ignore(100, '\n');
		cout << "\n\n";
		chinput = static_cast<char>(toupper(chinput));
		switch(chinput)
		{
			case 'Q':
				input = 0;
				break;
			case 'A':
				getUserInput(materials);
				break;
			case 'M':
			{
				while(chinput != 'Q')
				{
					cout << "Which material would you like to modify? (enter '0' to quit)  ";
					cin >> input;
					cin.ignore(100, '\n');
			
					while(input <= 0 || input > materials.getSize())
					{
						if(input == 0)
						{
							break;;
						}
						cout << "\nINVALID INPUT, TRY AGAIN!   ";
						cin >> input;
						cin.ignore(100, '\n');					
					}
					if(input == 0)
					{
						break;
					}
		
					cout << "\n\nOkay, element #" << input << ", what would you like to do?\n";
					cout << "E: EDIT\n";
					cout << "R: REMOVE\n";
					cout << "C: COMPLETE\n";
					cout << "Q: QUIT\n";
					cout << "CHOICE: ";
					cin >> chinput;
					cin.ignore(100, '\n');
					cout << "\n\n";

					chinput = static_cast<char>(toupper(chinput));
	
					switch(chinput)
					{
						case 'Q':
							cout << "Done modifying. \n\n";
							break;
						case 'R':
							materials.remove(input);
							break;
						case 'E':
							materials.edit(input);
							break;
						case 'C':
							materials.complete(input);
							break;
						default:break;
					}
				materials.display();
				input = -1;
				}
			}
			default:break;
		}
	}
}

void getUserInput(Materials & materials)
{
	int arrlength = 256;
	char input = 'e';

	while(input != 'Q')
	{
		cout << "\nAdding a material. Which type of material to add?\n";
		cout << "R: Reading.\n";
		cout << "E: Excercise set.\n";
		cout << "L: Lecture.\n";
		cout << "Q: Quit adding.\n";
		cout << "CHOICE: ";
		cin >> input;
		cin.ignore(100, '\n');
		cout << "\n";
	
		input = static_cast<char>(toupper(input));

		switch(input)
		{
			case 'Q':
				cout << "Done adding. \n\n";
				break;
			case 'R':
			{
				auto * name = new char[arrlength];
				auto * author = new char[arrlength];
				int chapter, page;
				cout << "Adding reading.\n";
				cout << "What is the name of the reading material?  ";
				cin.getline(name, arrlength);
				cout << "\nWhat is the name of the author?  ";
				cin.getline(author, arrlength);
				cout << "\nWhat is the chapter number?  ";
				cin >> chapter;
				cin.ignore(100, '\n');
				cout << "\nWhat is the page number?  ";
				cin >> page;
				cin.ignore(100, '\n');

				auto * r = new Reading(name, author, chapter, page);
	
				materials.add(*r);

				delete[] name;
				delete[] author;

				break;
			}	
			case 'E':
			{
				auto * setname = new char[arrlength];
				int length;
				cout << "Adding an exercise set.\n";
				cout << "What is the name of the set?  ";
				cin.getline(setname, arrlength);
				cout << "\nWhat is the length of the set?  ";
				cin >> length;
				cin.ignore(100, '\n');
				cout << "\n\n";
				auto * ex = new Exercise_Set(setname);
				for(int i = 1; i <= length; ++i)
				{
					auto * exname = new char[arrlength];
					cout << "What is question #" << i << "?  ";
					cin.getline(exname, arrlength);
					auto * e = new Exercise(exname);
					ex->add(e);
					delete[] exname;
				}
				
				materials.add(*ex);
				
				delete[] setname;

				break;	
			}
			case 'L':
			{
				auto * name = new char[arrlength];
				auto * presenter = new char[arrlength];
				const char * medium;
				int numSlides;
				char ch = 'x';

				cout << "Adding lecture.\n";
				cout << "What is the title of the lecture?  ";
				cin.getline(name, arrlength);
				cout << "\nWho will be presenting the lecture?  ";
				cin.getline(presenter, arrlength);
				cout << "\nWill the lecture be presented";
				cout << "\n(O)nline, or in (C)lass?     ";
				cin >> ch;
				cin.ignore(100, '\n');
				ch = static_cast<char>(toupper(ch));
				switch(ch)
				{
					case 'O':
						medium = "online";
						break;
					case 'C':
						medium = "class";
						break;
					default:
						medium = "unspecified";
						break;
				}
				cout << "\nHow many slides in the lecture?  ";
				cin >> numSlides;
				cin.ignore(100, '\n');

				auto * l = new Lecture(name, presenter, medium, numSlides);

				materials.add(*l);
			
				delete[] name;
				delete[] presenter;
			}
			default:break;
		}
	}
	materials.display();
}
