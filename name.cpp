#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

void send_value(std::string random_name) {
	std::ofstream output_file;
	output_file.open("message.txt", std::ofstream::trunc);
	std::cout << "Generated a random name: " << random_name << std::endl;
	output_file << random_name;
	output_file.close();
}

std::string* parse_name_file(int &size) {
	std::ifstream name_file;
	name_file.open("name.txt");

	std::string input;

	name_file >> input;

	size = std::stoi(input);

	std::string* name_array = new std::string[size];

	int i = 0;

	for (int i = 0; i < size; i++) {
		name_file >> input;
		name_array[i] = input; 
	}

	name_file.close();

	return name_array;
}

std::string* parse_item_file(int &size) {
	std::ifstream item_file;
	item_file.open("item.txt");

	std::string input;

	item_file >> input;

	size = std::stoi(input);

	std::string* item_array = new std::string[size];

	int i = 0;

	for (int i = 0; i < size; i++) {
		item_file >> input;
		item_array[i] = input; 
	}

	item_file.close();

	return item_array;
}

int main() {
	srand(time(nullptr));
	
	int name_size = 0;
	int item_size = 0;
	std::string* name_array = parse_name_file(name_size);
	std::string* item_array = parse_item_file(item_size);

	std::cout << name_size << " " << item_size << std::endl;


	std::ifstream message_file;

	while (true) {
		std::string input; 

		message_file.open("message.txt");
	
		if (!message_file.eof()) {
			message_file >> input;
		}

		message_file.close();

		if (input == "RANDOMNAME") {
			int random_num = rand() % name_size; 
			std::cout << "NAME" << std::endl;
			send_value(name_array[random_num]);

		} else if (input == "RANDOMITEM") {
			int random_num = rand() % item_size;
			std::cout << "ITEM" << std::endl;
			send_value(item_array[random_num]);
		}
	}


}
