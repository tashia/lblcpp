
//编写一个程序，程序会启动4个线程，向4个文件A，B，C，D里写入数据，每个线程只能写一个值。
//线程A：只写A
//线程B：只写B
//线程C：只写C
//线程D：只写D
//
//4个文件A，B，C，D。
//
//程序运行起来，4个文件的写入结果如下：
//A：ABCDABCD...
//B：BCDABCDA...
//C：CDABCDAB...
//D：DABCDABC...

#include <mutex>
#include <thread>
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <condition_variable>
using namespace std;

mutex mtx;

condition_variable cvs[4];

const int loop_count = 300;

void WriteThread(int content, vector<vector<char>>& pipes,
	             condition_variable& my_cv, condition_variable &next_cv){
	int pipe_index= content - 'A';
	for (int i = 0; i < loop_count; ++i){
		// lock
		unique_lock<mutex> lk(mtx);
		my_cv.wait(lk);
		pipes[pipe_index].push_back(content);
		next_cv.notify_one();
		--pipe_index;
		if (pipe_index < 0){
			pipe_index = 3;
		}
	}
}

int main(){
	const int t_count = 4;
	thread write_threads[t_count];
	vector<vector<char>> pipes(4, vector<char>());
	for (int i = 0; i < t_count; ++i){
		write_threads[i] = thread(WriteThread, int('A')+i, std::ref(pipes), 
			                      std::ref(cvs[i]), std::ref(cvs[(i+1)%4]));
	}
	cvs[0].notify_one();
	for (int i = 0; i < t_count; ++i){
		write_threads[i].join();
	}
	for (auto & v : pipes){
		for (auto e : v){
			cout << e << " ";
		}
		cout << endl;
	}
	cout << "done ... " << endl;
	return 0;
}