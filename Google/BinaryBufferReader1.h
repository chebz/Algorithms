#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
	static const int INT_SIZE = 4;

	char *_buffer;
	int _bufferSize;

	//*** given function, I imagine it looks something like this
	int read(char *buffer, int length) {
		int count = 0;

		while (_bufferSize && length--) {
			*buffer++ = *_buffer++;
			count++;
			_bufferSize--;
		}
		return count;
	}
	
	//convert integer to 4 byte number and write it to buffer
	void intToBytes(char *buffer, int n) {
		*buffer++ = n >> 24;
		*buffer++ = (n >> 16) & 0xFF;
		*buffer++ = (n >> 8) & 0xFF;
		*buffer++ = n & 0xFF;
	}

	//convert 4 bytes in buffer to integer number
	int bytesToInt(char *buffer) {
		int n = 0;
		n += *buffer++ << 24;
		n += *buffer++ << 16;
		n += *buffer++ << 8;
		n += *buffer;
		return n;
	}

	//find minimum of a & b
	int min(int a, int b) {
		return a < b ? a : b;
	}

	//read a string from SINGLE chunk, length must equal chunk size
	bool readString(string &s, int length) {
		char *buffer = new char[length + 1];
		if (read(buffer, length) < length) {
			delete[] buffer;
			return false;
		}
		buffer[length] = '\0';
		s = string(buffer);
		delete[] buffer;
		return true;
	}

	//read integer (4 bytes)
	bool readInt(int &n) {
		char *buffer = new char[INT_SIZE];
		if (read(buffer, INT_SIZE) < INT_SIZE) {
			delete[] buffer;
			return false;
		}
		n = bytesToInt(buffer);
		delete[] buffer;
		return true;
	}

	//build char buffer out of collection of strings
	int buildBuffer(vector<string> &v) {
		int size = 0;
		for (string s : v) {
			size += 4 + s.size();
		}
		_buffer = new char[size];
		for (string s : v) {
			intToBytes(_buffer, s.size());
			_buffer += 4;
			memcpy(_buffer, s.c_str(), s.size());
			_buffer += s.size();
		}
		_buffer -= size;
		return size;
	}
public:
	
	//main function which reads chunks in sequence and appends them to chunk
	string readContiguousString(int length) {
		string fullString = "";
		int size = 0;
		while (length && readInt(size)) {
			size = min(size, length);
			string data = "";
			readString(data, size);
			fullString += data;
			length -= size;
		}
		return fullString;
	}	

	//test function that reads entire buffer
	void test1() {
		int size = 0;
		while (readInt(size)) {
			string data = "";
			readString(data, size);
			cout << size << " " << data << "\n";
		}
	}

	//tests main function
	void test2() {
		int n = 3;
		string data = readContiguousString(100);
		cout << data <<"\n";
	}

	Solution() {
		vector<string> data = { "test", "a", "abcd", "monkey programs better than me" };
		_bufferSize = buildBuffer(data);
	}

	~Solution() {
		delete[] _buffer;
	}
};