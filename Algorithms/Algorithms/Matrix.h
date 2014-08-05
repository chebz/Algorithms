#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <vector>
#pragma once

class Matrix
{
	int mRows;
	int mCols;
	int *values;

public:
	Matrix(int rows, int cols) :mRows(rows), mCols(cols)
	{
		int size = rows*cols;
		values = new int[size] { 0 };
	}

	~Matrix() 
	{
		delete[] values;
	}

	void populateRandom()
	{
		srand(0);

		for (int y = 0; y < mCols; ++y)
		{
			for (int x = 0; x < mRows; ++x)
			{
				values[y*mRows + x] = rand() % 100;
			}
		}
	}

	void populateValue(int value)
	{
		for (int y = 0; y < mCols; ++y)
		{
			for (int x = 0; x < mRows; ++x)
			{
				values[y*mRows + x] = value;
			}
		}
	}

	int getValue(int row, int col)
	{
		assert(row < mRows && col < mCols);

		return values[col*mRows + row];
	}

	void setValue(int row, int col, int value)
	{
		assert(row < mRows && col < mCols);

		values[col*mRows + row] = value;
	}

	void rotateSquare()
	{
		assert(mRows == mCols);
		
		int layerCount = mRows / 2;

		for (int i = 0; i < layerCount; ++i)
		{
			rotateLayer(i);
		}
	}

	void zerofy()
	{
		std::vector<int> zeros;

		for (int y = 0; y < mCols; ++y)
		{
			for (int x = 0; x < mRows; ++x)
			{
				if (values[y*mRows + x] == 0)
					zeros.push_back(y*mRows + x);
			}
		}

		for (int index : zeros)
		{
			setZeroes(index);
		}
	}

	void print()
	{
		for (int y = 0; y < mCols; ++y)
		{
			for (int x = 0; x < mRows; ++x)
			{
				std::cout << std::setw(3) << values[y*mRows + x] << " ";
			}
			std::cout << std::endl;
		}
	}

private:

	void rotateLayer(int layer)
	{
		int rows = mRows - layer * 2;

		for (int i = 0; i < rows-1; ++i)
		{
			int x1 = i + layer;
			int y1 = layer;
			int index1 = (y1 * mRows) + x1;
			int index2 = rotateIndex(index1);
			int index3 = rotateIndex(index2);
			int index4 = rotateIndex(index3);

			int tmp = values[index1];
			values[index1] = values[index4];
			values[index4] = values[index3];
			values[index3] = values[index2];
			values[index2] = tmp;
		}
	}

	int rotateIndex(int index)
	{
		int y = index / mRows;
		int x = index - y * mRows;

		int x2 = mRows - y - 1;
		int y2 = x;
		return (y2 * mRows) + x2;
	}

	void setZeroes(int index)
	{
		int col = index / mRows;
		int row = index - col * mRows;

		//zero row
		for (int x = 0; x < mRows; ++x)
		{
			values[col * mRows + x] = 0;
		}

		//zero col
		for (int y = 0; y < mCols; ++y)
		{
			values[y * mRows + row] = 0;
		}
	}
};

