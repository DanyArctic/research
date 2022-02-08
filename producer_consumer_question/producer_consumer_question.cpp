#include <thread>
#include <iostream>
#include <mutex>
#include <deque>
#include <chrono>

using namespace std;
std::mutex m;

void incr(int& a)
{
	for (int i = 0; i < 100000; ++i)
	{
		std::lock_guard<std::mutex> lock(m);
		++a;
	}
}

std::mutex m_2;
std::condition_variable cv;
std::deque<int> q;

bool wrote = false;
bool produced()
{
	return wrote;
}


void consumer()
{
	while (true)
	{
		std::unique_lock<std::mutex> locker(m_2);
		cv.wait(locker, []() { return !q.empty(); });
		std::cout << "Consumed: " << q.back() << '\n';
		q.pop_back();
		locker.unlock();
		cv.notify_one();
	}
}

void producer()
{
	for (int i = 0; i < 100; ++i)
	{
		std::this_thread::sleep_for(100ms);
		std::unique_lock<std::mutex> locker(m_2);
		cv.wait(locker, []() { return q.size() < 100; });
		q.push_front(i);
		std::cout << "Produced: " << i << '\n';
		locker.unlock();
		cv.notify_one();
	}
}

int main()
{
	/*int result = 0;
	std::thread t(incr, std::ref(result));
	std::thread t_1(incr, std::ref(result));

	t.join();
	t_1.join();

	std::cout << result << std::endl;
	*/
	std::thread t_1(consumer);
	std::thread t_2(producer);
	std::thread t_3(consumer);

	t_1.join();
	t_2.join();
	t_3.join();

	return 0;
}
