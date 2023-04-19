Contributors:
  1. Munir Bshara 1870254536
  2. Greg Sarandi 4602542064

This program accomplishes all the tasks outlined in phase 1 of the EE355 project. This project practices essential concepts of OOP, such as building a class,
creating frined classes, inheritance, and composition. 

ASSUMPTIONS MADE DURING CREATION OF THIS PROJECT:
  1. The printDB() method in the Network class is used to print the desired database of people and their respective contact info. 
     This function calls print_person(), defined in the Person class. print_person() prints out the persons last name followed by 
     a comma and their first name on the same line. On the next line, it prints out the person's date of birth. On the next line, it prints out 
     the person's phone number. On the next line, it prints out the person's email address. This order was chosen based on the example shown on 
     the blackboard assignment page. However, the networkDB.txt file (which was said to be used as an example) shows the person's email being listed prior 
     to their phone number being listed. This led to ambiguous instructions regarding what the desired output was. As such, we assumed the desired 
     output was the one specifically written on blackboard i.e. person last name, first name followed bu DOB followed by phone number followed by email. 
     Future code can be written to accomodate both formats, however we are awaiting further guidance before embarking on that.
     
  2. The Date class is used for formatting the person's date of birth. Its constructor takes in a string date, and from there assigns values to its 
     corresponding attributes. In order for this program to properly run, the inputted string date must be of the format MM/DD/YYYY, MM/D/YYYY, 
     M/DD/YYYY, M/DD/YYYY, otherwise referred to in this instance as "numerical" format. If the inputted string was a spelled out date, such 
     as "January 8, 2000" (otherwise referred to as "written" format), there would be errors with the program since the first word in the string 
     is not a number. We assumed the inputted date would always be in numerical format. This is because the provided skeleton code template, "person.cpp", 
     states in the set_person() definition: "date format must be "M/D/YYYY". We are sure user enters info in correct format." Since we are sure the user 
     enters the date info in numerical format, we assumed the case of an incorrectly inputted date (January 8,2000) did not need to be covered. Once again,
     future code can be written to accomodate both numerical and written formatted inputs; however, we are awaiting further guidance before doing so.
     
  3. The print() and get_contact() functions of the Phone class are programmed so that "full" format i.e. dashes included (XXX-XXX-XXXX) in the phone number
     is written out if and only if the number is 10 digits long. In the case that the number is not 10 digits long, dashes will not be included in the output
     formatting.
     
  4. We added a get_contact(colon) option for the Email and Phone classes. This prints out the email address and phone number in the format explicitly written
     on the Blackboard project phase 1 description page, where a colon ":" is shown after "Phone(Home)" and "Email(Work)" (refer to the Class-PERSON descripion
     on blackboard). If the colon is not desired, we also have a get_contact(full) option, which excludes the colon. 

Phase 2:

As this phase was short and sweet, other than the default additions made we made some minor tweeks to ensure that our application was scalable.

1. With the Network function loadDB(), we made some changes in assuming that after the initial info section of an individual, which includes, first name, last name, birthdate, phone, and email, there would be a line by line section of all the connections made with that person. 
   This allows for us to also alter saveDB() and include the connections in the saved file, with each connection being printed out line by line.

2. Due to the changes in part 1, we also included a attribute of type vector<string> to be able to store the friends for an individual in order to later assess(after reading the entire database) whether those friends exist in the database or not. 
   This might seem redudant, since a database should always have only correct possible inputs, but it was never specified with an example file, so we wanted to ensure that regardless of the given database it will work.
\