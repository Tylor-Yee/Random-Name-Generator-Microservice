HOW TO USE RANDOM NAME GENERATOR:

Note: When creating names in your files to store, make sure you add a hyphen (i.e. a '-') inbetween words, so that the program can correctly parse through each name. 
The program will recognize a space delimited name/item as a separate name/item.

1) Add names/items to each item.txt and name.txt file. Make sure you put the total amount of names/items at the top (one good way to do this is to count the number of lines in the txt file before
  you create a new line at the start to properly). If you have nothing for the item/name file, put a 0 on the first line and NOTHING ELSE. This is assuming you are going to not call the microservice
  for names or items (whichever you are not using). 

3) compile and then execute the name.cpp program. To call the microservice, write to a file titled "message.txt" to send a message for the microservice to process and close the file.
  Then, wait a second for the program to return a name (This can be done with a sleep() function for python or using std::this_thread::sleep_for(std::chronos::seconds(1)) in c++)
  and then grab the name from message.txt and use it however you want!
