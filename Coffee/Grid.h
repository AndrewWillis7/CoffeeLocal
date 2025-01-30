#pragma once
class Grid
{
public:
	Grid(int size, float spacing) : size(size), spacing(spacing) {}

	void Render();

private:
	int size;
	float spacing;
};

