#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define BLOCK_SIZE 4

class Reader {	
	char *_buffer;
	int _bufferSize;
	int _offset;

	void buildBuffer(string s) {
		_bufferSize = s.size();
		_buffer = new char[_bufferSize];
		memcpy(_buffer, s.c_str(), s.size());
		_buffer += s.size();
		_buffer -= _bufferSize;
	}
public:
	//given function that reads next 4kb into buffer
	void read4(char *buffer) {
		memcpy(buffer, _buffer + _offset, BLOCK_SIZE);
		_offset += BLOCK_SIZE;
	}

	Reader() : _offset(0) {
		buildBuffer("testabcfatfemenistmonkeythrowssmalleypoop");
	}

	virtual ~Reader() {
		delete[] _buffer;
	}
};

class BlockReader : protected Reader {
	char *_tmpBuffer;
	int _offset;

	int min(int a, int b) {
		return a < b ? a : b;
	}
public:
	void readBlock(char *buffer, int length) {
		while (length) {
			if (_offset < BLOCK_SIZE) {
				int size = min(length, BLOCK_SIZE - _offset);
				memcpy(buffer, _tmpBuffer + _offset, size);
				buffer += size;
				_offset += size;
				length -= size;
			}
			else if (length >= BLOCK_SIZE) {
				read4(buffer);
				buffer += BLOCK_SIZE;
				length -= BLOCK_SIZE;
			}
			else {
				read4(_tmpBuffer);
				_offset = 0;
			}
		}
	}

	BlockReader() : Reader(), _offset(BLOCK_SIZE), _tmpBuffer(new char[BLOCK_SIZE]) { }

	virtual ~BlockReader() {
		delete[] _tmpBuffer;
	}
};

class Solution {
public:

	void test() {
		vector<int> blockSizes = { 3, 7, 1, 2, 10 };
		vector<char*> datas;
		BlockReader reader;

		for (int size : blockSizes) {
			char *data = new char[size + 1];
			reader.readBlock(data, size);
			data[size] = '\0';
			datas.push_back(data);
			cout << data << endl;
		}

		for (char *data : datas)
			delete[] data;
	}
};