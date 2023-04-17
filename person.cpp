#include "person.h"

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    delete email;
    delete phone;
    // TODO: complete the method! MAYBE LINKED LIST DEALLOCATION
}


Person::Person(string f_name, string l_name, string b_date, string email, string phone): f_name(f_name), l_name(l_name){
    // TODO: Complete this method!

    //id
    id_code = codeName(f_name, l_name); //set idname, remove all spaces and make lowercase
    //b_date
    birthdate = new Date(b_date); // What does full version mean
    string temp ="";
    string type ="";
    int counter=1;
    while(email[counter]){
        if(email[counter]==')'){
            type = temp;
            temp ="";
            counter++;
        }
        else {
            temp = temp + email[counter];
        }
        counter++;
    }
    Person::email = new Email(type,temp); //What does full version mean

    temp = "";
    type ="";
    counter=1;
    while(phone[counter]){
        if(phone[counter]==')'){
            type = temp;
            temp ="";
            counter++;
        }
        else {
            temp = temp + phone[counter];
        }
        counter++;
    }
    Person::phone = new Phone(type, temp); //What does full version mean
    // phone and email strings are in full version
}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!

    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

    cout << "Last Name: ";
    std::getline(std::cin,l_name);

    this->id_code = codeName(f_name, l_name); //set idname, all lowercase with no spaces

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp);

    cout << "Type of email address: ";
    std::getline(std::cin,type);
    cout << "Email address: ";
    std::getline(std::cin,temp);
    email = new Email(type,temp);

    cout << "Type of phone number: ";
    std::getline(std::cin,type);
    cout << "Phone number: ";
    std::getline(std::cin,temp);
    phone = new Phone(type,temp);
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!

    ifstream myfile;
    myfile.open(filename);

    string temp;
    string line;
    string type;
    int counter=1;
    if(myfile.is_open()){
        std::getline(myfile,f_name);
        std::getline(myfile,l_name);
        this->id_code = codeName(f_name, l_name); //set idname, all lowercase with no spaces
        std::getline(myfile, line);
        birthdate = new Date(line);
        std::getline(myfile, line);
        while(line[counter]){
            if(line[counter]==')'){
                type = temp;
                temp ="";
                counter++;
            }
            else {
                if(line[counter]!='-'){
                    temp = temp + line[counter];
                }
            }
            counter++;
        }
        phone = new Phone(type,temp);
        temp ="";
        type ="";
        counter=1;
        std::getline(myfile, line);
        while(line[counter]){
            if(line[counter]==')'){
                type = temp;
                temp ="";
                counter++;
            }
            else {
                temp = temp + line[counter];
            }
            counter++;
        }
        email = new Email(type,temp);
    }
}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    return ((f_name==rhs.f_name) && (l_name==rhs.l_name)) && (*birthdate==*(rhs.birthdate));
}

bool Person::operator!=(const Person& rhs){
    // TODO: Complete this method!

    return ((f_name!=rhs.f_name) || (l_name!=rhs.l_name) || (!(*birthdate==*(rhs.birthdate))));
}


void Person::print_person(){
    // Already implemented for you! Do not change!
    cout << l_name <<", " << f_name << endl;
    birthdate->print_date("Month D, YYYY");
    cout << "Phone ";
    phone->print();
    cout << "Email ";
    email->print();
    // for (int i =0; i< myfriends.size(); i++){
    //     Person* temp = myfriends.at(i);
    //     string id = temp->id_code;
    //     cout << id << endl;
    // }
    for (int i =0; i< this->usernames.size(); i++){
        string temp = this->usernames.at(i);
        cout << temp << endl;
    }
}

void Person::makeFriend(Person* newFriend){

    myfriends.push_back(newFriend);
    string fname = newFriend->f_name;
    string lname = newFriend->l_name;
    string user = codeName(fname, lname);
    usernames.push_back(user);
}