#include "contact.h"
// TODO: Add needed libraries! PHONE NUMBER? DEFUALT ARGUMENT?

Email::Email(string type, string email_addr): email_addr(email_addr){
    // TODO: Complete me!
    Contact::type=type;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!

    cout << "Enter the type of email address: ";
    std::getline(std::cin,Contact::type);
    cout << "Enter email address: ";
    std::getline(std::cin,email_addr);
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
        return "(" + type + ") " + email_addr;
    else if(style=="colon")
        return "(" + type + "): " + email_addr;
    else
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
    cout << get_contact("colon") << endl;
}


Phone::Phone(string type, string num): phone_num(num){ //CHECK PHONE NUMBER
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    Contact::type=type;
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
    cout <<"Enter the type of phone number: ";
    std::getline(std::cin,Contact::type);
    cout << "Enter the phone number: ";
    std::getline(std::cin,phone_num);
}


string Phone::get_contact(string style){ // TODO: fix up substring thingy, by adding condition in print
    // TODO: Complete this method, get hint from Email
    if (style=="full")
        return "(" + type + ") " + phone_num;
    else if(style=="colon")
        return "(" + type + "): " + phone_num.substr(0,3) + "-" + phone_num.substr(3,3) + "-" + phone_num.substr(6,4);

    else
        return "(" + type + "): " + phone_num;; // FIX ME
}


void Phone::print(){
    // Note: get_contact is called with default argument
    if(phone_num.size()==10){
        cout << get_contact("colon") << endl;
    }
    else{
        cout << get_contact("NULL") << endl;
    }

}
