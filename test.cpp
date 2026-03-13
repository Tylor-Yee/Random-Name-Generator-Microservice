#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>


int main() {
	std::ifstream input_file;
	std::ofstream output_file;

	std::string random_name_string;

	output_file.open("message.txt", std::ofstream::trunc);

	output_file << "RANDOMNAME";

	output_file.close();

	std::this_thread::sleep_for(std::chrono::seconds(1));

	input_file.open("message.txt");

	input_file >> random_name_string; 

	std::cout << "random name: " << random_name_string << std::endl;

	input_file.close();

	output_file.open("message.txt", std::ofstream::trunc);

	output_file << "RANDOMITEM";

	output_file.close();

	std::this_thread::sleep_for(std::chrono::seconds(1));

	input_file.open("message.txt");

	input_file >> random_name_string;

	std::cout << "Random item name: " << random_name_string << std::endl;

	input_file.close();
}
