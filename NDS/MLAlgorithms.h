#pragma once
#include <vector>

//c++ learn
template<class T>
class cplearn
{
public:
	cplearn() {

	}

	void print(std::vector<std::vector<std::pair<int, T>>>);

	std::vector<std::vector<std::pair<int, T>>> getZeroes(int xSize, int ySize);

	void linearRegression2D(std::vector<std::vector<std::pair<int, T>>> grid);
};

	template<typename T>
	std::vector<std::vector<std::pair<int, T>>> cplearn<T>::getZeroes(int xSize, int ySize) {
		std::vector<std::vector<std::pair<int, T>>> cartesianGrid;
		for (int row = 0; row < ySize; row++) {
			std::vector<std::pair<int, T>> cartesianRow;
			cartesianGrid.emplace_back(cartesianRow);
			for (int col = 0; col < xSize; col++) {
				std::pair<int, T> coords(0, 0);
				cartesianGrid[col].emplace_back(coords);
			}
		}
		return cartesianGrid;
	}

	template<typename T>
	void cplearn<T>::print(std::vector<std::vector<std::pair<int, T>>>) {

	}