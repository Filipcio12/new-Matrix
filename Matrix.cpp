#include "Matrix.h"

struct Matrix::rcMatrix {
	double** arr;
	size_t rows;
	size_t cols;
	size_t rc;
	
	rcMatrix()
	{
		rc = 1;
		rows = 0;
		cols = 0;
		arr = NULL;
	};
	
	rcMatrix(size_t rows, size_t cols)
	{
		rc = 1;
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
		for (size_t i = 0; i < rows; ++i) {
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
		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < cols; ++j) {
				m->arr[i][j] = arr[i][j];
			}
		}
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
	m.data->rc++;
	data = m.data;
}

Matrix::~Matrix()
{
	if (--data->rc == 0) {
		delete data;
	}
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (--data->rc == 0) {
		delete data;
	}
	m.data->rc++;
	data = m.data;
	return *this;
}

double Matrix::operator()(size_t row, size_t col) const // read only
{
	if (data->rows > row && data->cols > col) {
		return data->arr[row][col];
	}
	else {
		throw InvalidRange();
	}
}

double& Matrix::operator()(size_t row, size_t col) // write only
{
	if (data->rows > row && data->cols > col) {
		data = data->detach();
		return data->arr[row][col];
	}
	else {
		throw InvalidRange();
	}
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	size_t rows = m.data->rows;
	size_t cols = m.data->cols;
	
	for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            os << m(i, j) << "\t";
        }
        os << "\n";
    }
    return os;
}