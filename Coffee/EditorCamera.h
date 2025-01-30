#include <glew.h>
#include <glm.hpp>
#include <glfw3.h>

class EditorCamera {

public:
	EditorCamera() : position(0.0f, 0.0f, 5.0f), front(0.0f, 0.0f, -1.0f), up(0.0f, 1.0f, 0.0f) {}

	void update(float deltaTime);
	void setWindow(GLFWwindow* win) { window = win; }
	glm::vec3 getPosition() const { return position; }
	glm::vec3 getFront() const { return front; }
	glm::vec3 getUp() const { return up; }
private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	GLFWwindow* window;
};