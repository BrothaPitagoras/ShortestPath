#pragma once

#include <includes.h>
#include <model/Mesh.h>
#include <model/Model.h>

class Matrix : public Model
{
	private:
		const unsigned int rows_;
		const unsigned int cols_;

		void generateMesh(const unsigned int rows, const unsigned int cols);

	public:
		Matrix(const unsigned int rows, const unsigned int cols);
		const unsigned int GetRows() const noexcept { return rows_; }
		const unsigned int GetCols() const noexcept { return cols_; }
};