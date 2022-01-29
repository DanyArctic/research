#include <thread>
#include <iostream>
#include <chrono>
#include <fstream>

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

int summary(int& value_1, int& value_2)
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

	std::ifstream file("C:\\Users\\danik\\source\\repos\\research\\threading\\values.txt");
	if (file.is_open())
	{
		std::cout << "Okay! File opened\n\n" << std::endl;
	}
	else
	{
		std::cout << "File didn't open!\n\n" << std::endl;
		return -1;
	}
	static int a = 0, b = 0;
	int result = 0;
	file >> a >> b;
	std::thread thr_three([&result]() {result = summary(std::ref(a), std::ref(b)); }); //why it works with static variables and how to capture int with lambdas(e.g. typical)?
	thr_three.join();
	std::cout << "result of summary = " << result << '\n';
	//should I close file?
	std::ofstream out("C:\\Users\\danik\\source\\repos\\research\\threading\\values.txt", std::ios::app);

	if (out.is_open())
	{
		out << '\n' << result << std::endl;
	}
	else
	{
		std::cout << "File opening failure. Process terminate." << std::endl;
		return -1;
	}
	out.close();
	return 0;
}