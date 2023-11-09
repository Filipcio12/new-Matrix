#include "Matrix.h"

struct Matrix::rcMatrix {
	double** arr;
	size_t rows;
	size_t cols;
	size_t rc;
	
	rcMatrix()
	{
		rows = 0;
		cols = 0;
		arr = NULL;
	};
	
	rcMatrix(size_t rows, size_t cols)
	{
		this->rows = rows;
		this->cols = cols;
		arr = new double*[rows];
		
		for (size_t i = 0; i < rows; ++i) {
			arr[i] = new double[cols];
		}

		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < cols; ++j) {
				arr[i][j] = 0;
			}
		}
	};
	
	~rcMatrix()
	{
		for (unsigned int i = 0; i < rows; ++i) {
			delete[] arr[i];
		}
		delete[] arr;
	};
	
	rcMatrix* detach()
	{
		if (rc == 1) {
			return this;
		}
		rcMatrix* m = new rcMatrix(rows, cols);
		rc--;
		return m;
	};
	
	private:
		rcMatrix(const rcMatrix&) = delete;
		rcMatrix& operator=(const rcMatrix&) = delete;
};

Matrix::Matrix()
{
	data = new rcMatrix();
}

Matrix::Matrix(size_t rows, size_t cols)
{
	data = new rcMatrix(rows, cols);
}

Matrix::Matrix(const Matrix& m)
{
	data->rows = m.data->rows;
	data->cols = m.data->cols;
	data->arr = new double*[rows];
	
	for (size_t i = 0; i < rows; ++i) {
        arr[i] = new double[cols];
    }
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            arr[i][j] = m.data->arr[i][j];
        }
    }
}

Matrix::~Matrix()
{
	if (--data->rc == 0) {
		delete data;
	}
}

double Matrix::operator()(size_t row, size_t col)
{
	if (data
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	size_t rows = m.data->rows;
	size_t cols = m.data->cols;
	
	
}






