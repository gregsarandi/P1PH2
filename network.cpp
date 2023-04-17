#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>


Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    Network::loadDB(fileName);
}

Network::~Network(){
    // Should i delete that stuff
    Person* ptr = head;
    Person* temp = NULL;
    while(ptr != NULL){
        temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
    delete temp;
    delete ptr;
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* ptr = head;
    while(ptr != NULL){
        if(*ptr==*searchEntry){
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL;
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* ptr = head;
    while(ptr != NULL){
        if(ptr->f_name==fname && ptr->l_name==lname){
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL;
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly.
}




void Network::loadDB(string filename){ // FIXME erase all elements of LL
    // TODO: Complete this method
    ifstream myfile;
    myfile.open(filename);
    string line;
    string check;
    int counter = 0;
    string f_name;
    string l_name;
    vector<string> names;
    string date;
    string email;
    string phone;
    Person* ptr = head;
    Person* temp = NULL; //Louis-Dreyfus, Julia Scarlett Elizabeth
    if(count != 0){
        while(ptr != NULL){
            temp= ptr->next;
            remove(ptr->f_name, ptr->l_name);
            ptr=temp;
        }
    }
    if( myfile.is_open() ){
        while(std::getline(myfile,line)){
            if(counter==0){
                l_name = "";
                date = "";
                email = "";
                f_name=line;
                counter++;
            }
            else if(counter==1){
                l_name=line;
                counter++;
            }
            else if(counter==2){
                date=line;
                counter++;
            }
            else if(counter==3){
                email=line;
                counter++;
            }
            else if(counter==4){
                phone = line;
                counter++;
            }
            else if(counter > 4){
                check = line.substr(0,1);
                if(check != "-"){ //not at ----------------, check this
                    names.push_back(line);
                    counter ++;
                }
                else{
                    Person *nP = new Person(f_name,l_name,date, email, phone);
                    nP->usernames = names;
                    push_back(nP);
                    names.clear();
                    counter = 0;
                }
            }
        
        }
    }
    myfile.close();
}

void Network::saveDB(string filename){
    // TODO: Complete this method

    ofstream myfile;
    myfile.open(filename); // FIXME, DOES THIS MEAN THAT I NEED TO PRINT EVERYTHING TO FILENAME

    Person* ptr = head;
    while(ptr != NULL){
        myfile << ptr->f_name << endl;
        myfile << ptr->l_name << endl;
        myfile << ptr->birthdate->getDate() << endl;
        myfile << ptr->email->get_contact() << endl;
        myfile << ptr->phone->get_contact() << endl;
        for (int i =0; i< ptr->usernames.size(); i++){
            string temp = ptr->usernames.at(i);
            myfile << temp << endl;
        }
        myfile << "------------------------------" << endl;
        ptr = ptr->next;
    }
    myfile.close();
}


void Network::printDB(){
    // Leave me alone! I know how to print!
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;

    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method
    newEntry->next = NULL;
    newEntry->prev = tail;

    if (tail != NULL)
        tail->next = newEntry;
    else
        head = newEntry;

    tail = newEntry;
    count++;
}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
    Person *p;
    if((p=search(fname,lname))){
        if(p==head && p==tail){
            head = NULL;
            tail = NULL;
        }
        if(p==tail){
            tail = p->prev;
        }
        if(p==head){
            head = p->next;
        }
        if(p->next != NULL){
            p->next->prev = p->prev;
        }
        if(p->prev != NULL){
            p->prev->next = p->next;
        }

        count--;
        delete p;
        return 1;
    }
    else{
        //delete p;
        return 0;
    }

}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you,
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library
        //printDB();
        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "6. Connect \n"; //maybe change to Connect People
        cout << "\nSelect an option ... ";

        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }

        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            cout << "Network saved in " << fileName << endl;
            saveDB(fileName);
        }
        else if (opt==2){ // sarandi@usc.edu
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // Take a look into sample_files.cpp

            string command(" ls | grep \".txt\"");
            const char* final_command = command.c_str();
            system(final_command);

            cout << "Enter the name of the load file: ";
            // If file with name FILENAME does not exist:
            cin >> fileName;
            ifstream myfile(fileName);
            if(myfile.fail()) {
                cout << "File FILENAME does not exist!" << endl;
            }
            // If file is loaded successfully, also print the count of people in it:
            else{
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
            myfile.close();
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back
            // Add a new Person ONLY if it does not exists!
            Person *p = new Person();

            cout << "Adding a new person \n";
            if(search(p) != NULL){
                cout << "This person already exists \n";
            }
            else{
                push_front(p);
                cout << "Person added \n";
            }
        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            std::getline(std::cin, fname);
            cout << "Last name: ";
            std::getline(std::cin, lname);
            if(remove(fname,lname)){
                cout << "Remove Successful! \n";
            }
            else{
                cout << "Person not found! \n";
            }

        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name \n";
            cout << "Last name: ";
            std::getline(std::cin, lname);
            Person *ptr = head;

            int flag =0;
            while(ptr != NULL){
                if(ptr->l_name == lname){
                    flag=1;
                    ptr->print_person();
                }
                ptr=ptr->next;
            }
            if(flag==0){
                cout << "Person not found! \n";
            }
        }
        else if (opt == 6){
            string fname1;
            string lname1;
            string fname2;
            string lname2;
            Person* person1;
            Person* person2;
            cout << "Make friends" << endl;
            cout << "Person 1 \n";
            cout << "First Name: ";
            std::getline(std::cin, fname1);
            cout << "Last Name: ";
            std::getline(std::cin, lname1);
            person1 = search(fname1, lname1);
            if (person1 == NULL){
                cout << "Person not found" << endl;
            } //return to main menu
            else{
                cout << "Person 2 \n";
                cout << "First Name: ";
                std::getline(std::cin, fname2);
                cout << "Last Name: ";
                std:: getline(std::cin, lname2);
                person2 = search(fname2, lname2);
                if (person2 == NULL){
                    cout << "Person not found" << endl;
                }
                else {
                    cout << "\n\n";
                    person1->print_person();
                    cout << "\n\n";
                    person2->print_person();
                    person1->makeFriend(person2);
                    person2->makeFriend(person1);

                }
            }

        }
        else{
            cout << "Nothing matched!\n";
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
