/*Grid.h*/
#ifndef MYGRID_H
#define MYGRID_H

#include <vector>
// #include <windows.h>

template<class T>
class Grid
{
private:
	int m_width;
	int m_height;
	std::vector< std::vector<T> > *m_grid; //pointer to a std::vector of std::vectors, constructor will initialize this
	
public:
	/*Constructor*/
	Grid(int width, int height);
	/*Destructor*/
	~Grid();
	/*Output*/
	void Print();
	
	/*Access*/
	T at(int x, int y);
	void set(int x, int y, T value);
	
};

/*Constructor*/
template<typename T>
Grid<T>::Grid(int width, int height) : 
	m_width(width),
	m_height(height),
	m_grid(new std::vector< std::vector<T> >)	
{
	/*Resize the 2D std::vector to the specified width and height*/
	m_grid->resize(m_height); //We need m_height sub-vectors
	for (int i = 0; i < m_height; ++i)
		(*m_grid)[i].resize(m_width); //each sub-vector has a size of m_width
}
/*Destructor*/
template<typename T>
Grid<T>::~Grid()
{
	//delete dynamically allocated grid
	delete m_grid;
}

// template<typename T>
// void Grid<T>::Print()
// {
// 	/*This function assumes there is a valid output operator for type T*/
// 	for (int i = 0; i < m_height; ++i)
// 	{
// 		for (int j = 0; j < m_width; ++j)
// 			// std::cout << at(j,i);
// 	}
// }

template<typename T>
T Grid<T>::at(int x, int y)
{
	//  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	// COORD CursorPosition;
	// CursorPosition.X = 2+(x*2);
	// CursorPosition.Y = 2+(y*2);
	// SetConsoleCursorPosition(console, CursorPosition);
	return (*m_grid)[y][x];
}

template<typename T>
void Grid<T>::set(int x, int y, T value)
{
	(*m_grid)[y][x] = value;
}
#endif  