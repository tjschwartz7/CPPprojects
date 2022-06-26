#pragma once
#include <vector>

template<class T>
class cmat {
public:


	int dim;
	cmat(int x) {
		matrix1D = new std::vector<std::pair<T, T>>(x);
		dim = 1;
	}

	cmat(int x, int y) {
		matrix2D = new std::vector<std::vector<std::pair<T, T>>>(x, y);
		dim = 2;
	}

	cmat(int x, int y, int z) {
		matrix3D = new std::vector<std::vector<std::vector<std::pair<T, T>>>>(x, y, z);
		dim = 3;
	}

	void fillZeroes();

	T get() {
		switch (dim) {
		case 1:
			return matrix1D;
			break;
		case 2:
			return matrix2D;
			break;
		case 3:
			return matrix3D;
			break;

		}
	}

	void fill2D(T val1, T val2);
	int getX() { return xSize; }
	int getY() { return ySize; }
	int getZ() { return zSize; }

private:
	int xSize;
	int ySize;
	int zSize;
	std::vector<std::pair<T, T>>* matrix1D;
	std::vector<std::vector<std::pair<T, T>>>* matrix2D;
	std::vector<std::vector<std::vector<std::pair<T, T>>>>* matrix3D;
};

template<typename T>
void cmat<T>::fillZeroes() {
	switch (dim) {
	case 1:
		break;
	case 2:
		fill2D(0,0);
		break;
	case 3:
		break;
	}
}

template<typename T>
void cmat<T>::fill2D(T val1, T val2) {
	for (int row = 0; row < getY(); row++) {
		std::vector<std::pair<T, T>> cartesianRow;
		matrix2D->emplace_back(cartesianRow);
		for (int col = 0; col < getX(); col++) {
			std::pair<T, T> coords(val1, val2);
			matrix2D[col]->emplace_back(coords);
		}
	}
}

//c++ learn
template<class T>
class cplearn
{
public:
	cplearn() {

	}

	void print(std::vector<std::vector<std::pair<int, T>>>);

	void linearRegression2D(std::vector<std::vector<std::pair<int, T>>> grid);
};



template<typename T>
void cplearn<T>::print(std::vector<std::vector<std::pair<int, T>>>) {

}