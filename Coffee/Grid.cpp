#include "Grid.h"
#include <iostream>
#include <cmath>
#include <glew.h>
#include <glfw3.h>


void Grid::Render() {
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 0.5f);

	for (int i = -size; i <= size; i++) {
		glVertex3f(i * spacing, 0.0f, -size * spacing);
		glVertex3f(i * spacing, 0.0f, size * spacing);
		glVertex3f(-size * spacing, 0.0f, i * spacing);
		glVertex3f(size * spacing, 0.0f, i * spacing);
	}
	glEnd();
}