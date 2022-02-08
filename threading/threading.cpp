#include <thread>
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

void console_output_values(int i, double d, const std::string& s)
{
	std::cout << " thr thread id is: " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << i << ", " << d << ", " << s << std::endl;
}

void increment_from_reference(int& a)
{
	std::cout << " thr_two thread id is: " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	a++;
}

int sum(int value_1, int value_2)
{
	return value_1 + value_2;
}

int main()
{
	std::cout << "main thread id is: " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
	std::thread thr(console_output_values, 1, 2.34, "example");
	thr.join();
	
	int val = 7;
	std::thread thr_two(increment_from_reference, std::ref(val));
	//thr_two.detach();
	thr_two.join();
	std::cout << val << std::endl;
	std::string input_path = "C:\\Users\\danik\\source\\repos\\research\\threading\\input.txt";
	std::string output_path = "C:\\Users\\danik\\source\\repos\\research\\threading\\output.txt";
	std::ifstream file;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	try
	{
		file.open(input_path);
		std::cout << "Okay! File opened" << std::endl;
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cerr << ex.what() << '\n';
		std::cerr << ex.code() << '\n';
		std::cerr << "Error: file didn't open! Values can't be read." << '\n';
	}
	int a = 0, b = 0;
	int result = 0;
	file >> a >> b;

	std::thread thr_three([&result, a, b]() {result = sum(a, b); });
	thr_three.join();
	
	std::ofstream out(output_path, std::ios::app); //new line in new file, if it doesn't exist
	try
	{
		if (out.is_open())
		{
			out << result << std::endl;
		}
		else
		{
			throw "File opening failure. Values can't be written.";
		}
	}
	catch (const char* exception_message)
	{
		std::cerr << "Error: " << exception_message << '\n';
	}
	out.close();
	std::cout << "result of summary = " << result << '\n';

	return 0;
}