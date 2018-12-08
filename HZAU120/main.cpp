#include<iostream>
#include<GL/glew.h>
#include<GLFW\glfw3.h>
#define GLEW_STATIC
class Point {
private:
	float x, y;
public:
	Point(float x_, float y_) {
		x = x_;
		y = y_;
	}
	float getx() {
		return x;
	}
	float gety() {
		return y;
	}
};

// 绘制直线
void setline(Point p1,Point p2) {
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(15);//设置线段宽度
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	
	glVertex2f(p1.getx(),p1.gety());
	glVertex2f(p2.getx(), p2.gety());
	glEnd();
	glFlush();
	
}

// 绘制贝塞尔曲线
void setBezier(Point p0, Point p1, Point p2, Point p3, double t) {
	glColor3f(1.0, 0.0, 0.0); //设置线条颜色
	glPointSize(15); //设置点的大小

	glBegin(GL_LINE_STRIP);
	for (int i = 1; i <= 200; i++)
	{
		GLfloat t = i / 200.0;
		GLfloat b0 = pow(1 - t, 3.0);
		GLfloat b1 = 3.0 * t*pow(1 - t, 2.0);
		GLfloat b2 = 3.0 * t*t*(1 - t);
		GLfloat b3 = t * t*t;
		//运用三次Bezier曲线
		GLfloat x = p0.getx()*b0 + p1.getx()*b1 + p2.getx()*b2 + p3.getx()*b3;
		GLfloat y = p0.gety()*b0 + p1.gety()*b1 + p2.gety()*b2 + p3.gety()*b3;

		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}


int main(int argc, char *argv[])
{

	GLFWwindow* window;
	if (!glfwInit())
		return -1;
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 800, "OpenGl", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		/*your draw*/
		// drawPoint(); 
		Point p11 = Point(-0.6, 0.75);
		Point p12 = Point(-0.6, 0.5);
		Point p13 = Point(-0.4, 0.375);
		Point p14 = Point(-0.2, 0.375);
		Point p15 = Point(-0.2, 0.75);
		Point p16 = Point(-0.4, 0.125);


		Point p21 = Point(0.6, 0.75);
		Point p22 = Point(0.6, 0.5);
		Point p23 = Point(0.4, 0.375);
		Point p24 = Point(0.2, 0.375);
		Point p25 = Point(0.2, 0.75);
		Point p26 = Point(0.65, 0.125);

		Point p31 = Point(-0.6, 0);
		Point p32 = Point(-0.6, -0.8);
		Point p33 = Point(-0.6, -0.125);
		Point p34 = Point(-0.5, -0.25);
		Point p35 = Point(-0.5, -0.75);
		Point p36 = Point(-0.3, -0.75);
		Point p37 = Point(-0.3, -0.25);
		Point p38 = Point(-0.2, -0.75);
		Point p38u = Point(-0.2, -0.65);

		Point p0 = Point(0, -0.25);
		Point p0r = Point(0.07, -0.25);
		Point p00 = Point(0, -0.5);
		Point p00r = Point(-0.1, -0.5);

		Point p41 = Point(0.65, -0.125);
		Point p42 = Point(0.25, -0.75);
		Point p43 = Point(0.65, -0.25);
		Point p44 = Point(0.65, -0.75);
		Point p45 = Point(0.4575, -0.75);
		Point p46 = Point(0.25, -0.25);
		Point p47 = Point(0.4575, -0.45);
		Point p48 = Point(0.175, -0.5);
		Point p48u = Point(0.175, -0.4);

		Point p1_1 = Point(-0.6, 0.4375);
		Point p1_2 = Point(-0.4625, 0.375);
		setBezier(p12, p1_1, p1_2, p13, 20);

		Point p2_1 = Point(0.6, 0.4375);
		Point p2_2 = Point(0.4625, 0.375);
		setBezier(p22, p2_1, p2_2, p23, 20);

		Point p1_3 = Point(-0.6, 0.0625);
		Point p1_4 = Point(-0.4625, 0.125);
		setBezier(p31, p1_3, p1_4, p16, 20);

		Point p4_1 = Point(0.15, -0.25);
		Point p4_2 = Point(0.175, -0.35);
		setBezier(p0r, p4_1, p4_2, p48u, 20);

		Point p3_1 = Point(-0.175, -0.5);
		Point p3_2 = Point(-0.2, -0.625);
		setBezier(p00r, p3_1, p3_2, p38u, 20);

		setline(p11,p12);
		setline(p13, p14);
		setline(p14, p15);
		setline(p14, p24);
		setline(p21, p22);
		setline(p23, p24);
		setline(p24, p25);
		setline(p16, p26);

		setline(p31, p32);
		setline(p33, p41);
		setline(p34, p35);
		setline(p35, p36);
		setline(p36, p37);
		setline(p37, p0);
		setline(p38, p38u);

		setline(p42, p46);
		setline(p46, p43);
		setline(p43, p44);
		setline(p44, p45);
		setline(p45, p47);
		setline(p48, p48u);
		
		setline(p38, p42);

		setline(p00, p48);
		setline(p0, p0r);
		setline(p00, p00r);
		//drawTriangle();         
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwTerminate();


	return 0;
}
