#define _WIN32_WINNT 0x0501
#include <iostream>
#include "mingw.thread.h"
#include "mingw.mutex.h"
#include <chrono>

using namespace std;
mutex mtx;

//first thread method
int thread1Function() {
	mtx.lock();
	for(int i=0;i<=20;++i){
		cout<<"First thread count: "<<i<<endl;
	}
	mtx.unlock();
	return 0;
}

//second thread method
int thread2Function() {
	mtx.lock();
	for(int i=20;i>=0;--i){
		cout<<"Second thread count: "<<i<<endl;
	}
	mtx.unlock();
	return 0;
}

int main() {

	auto start = std::chrono::high_resolution_clock::now();

	//run first thread and wait for completion
	thread thread1(thread1Function);
	thread1.join();
	cout<<"First thread complete"<<endl;
	cout<<"\n";

	//run second thread at wait for completion
	thread thread2(thread2Function);
	thread2.join();
	cout<<"Second thread complete"<<endl;
	cout<<"\n";

	auto finish = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();

	return 0;
}
