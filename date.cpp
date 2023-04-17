//
// Created by Munir Bshara on 4/4/23.
//

#include "date.h"

Date::Date() {}

Date::~Date() {}

Date::Date(string date):date(date){
    int counter=0;
    string temp;
    int slashCounter=0;
    while(date[counter]){
        if(date[counter]=='/'){
            if(slashCounter==0){
                month = stoi(temp);
                slashCounter++;
                temp="";
            } else if(slashCounter==1){

                day = stoi(temp);
                temp="";
                slashCounter++;
            }
        } else{
            temp=temp + date[counter];
        }
        counter++;
    }
        year = stoi(temp);
}

bool Date::operator==(const Date& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    return (year==rhs.year) && (day==rhs.day) && (month==rhs.month);
}

string Date::getMonth(){
    switch (month) {
        case 1:
            return "January";
            break;
        case 2:
            return"February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
        default:
            return "INVALID MONTH";
            break;
    }
}

string Date::getDate() {
    return date;
}

void Date::print_date(string format) {
    if(format == "Month D, YYYY"){
        cout << getMonth() << " ";
        cout << day << ", ";
        cout << year << endl;
    }
    else{
        cout << date << endl;
    }
}


