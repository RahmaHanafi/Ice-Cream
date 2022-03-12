#include <Windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

float angle = 0.10;
float d = 0;
float s = 1;
const GLfloat light_position[] = { 1.0f, 5.0f, 5.0f, 0.05f };


void draw(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glRotatef(angle, 0.0, 0.0, 1.0);

	// Mango
	glPushMatrix();
	glColor3f(1.0,0.523,0.0);
	glTranslatef(7.0,4.7,0.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glutSolidTorus(5.0, 0.8, 50.0, 50.0);
	glPopMatrix();

	// Vanilla
    glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0,11.0,0.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glutSolidTorus(5.0, 0.8, 50.0, 50.0);
	glPopMatrix();

    // Blue berry
	glPushMatrix();
	glColor3f(0.556863,0.137255, 0.419608);
	glTranslatef(-7.0,4.5,0.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glutSolidTorus(5.0, 0.8, 50.0, 50.0);
	glPopMatrix();

	// chocolate
    glPushMatrix();
	glColor3f(0.12,0.052,0.0);
	glTranslatef(0.0,4.0,0.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glutSolidTorus(5.0, 0.8, 50.0, 50.0);
	glPopMatrix();

	// Cone
	glPushMatrix();
	glColor3f(0.72,0.45,0.20);
	glTranslatef(0.0,0.0,0.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glutSolidCone(9.5,27.0,50.0,50.0);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch (key){

	case 'e':
	case 'E':
    exit(0);
		break;

    case 't':
	case 'T':
    {
	d=d+0.5;
    glTranslatef(d,0,0);
	}
		break;

    case 's':
	case 'S':
    {
    s=s+0.1;
    glScalef(s,s,s);
	}
		break;

    case 'r':
	case 'R':
    glRotatef(90,1,0,0);
		break;
	}
}

void mouse(int btn, int state, int x, int y){
	if (state == GLUT_DOWN){
		if (btn == GLUT_LEFT_BUTTON)
			angle = angle + 0.01f;
		else
			angle = 0;
	}
}

void Special_Keys(int key, int x, int y){
	switch (key){
	case GLUT_KEY_LEFT:
		angle = angle + 1.0;
		break;
	case GLUT_KEY_RIGHT:
		angle = angle - 1.0;
		break;
	case GLUT_KEY_UP:
		d++;
		glTranslatef(d,0,0); break;
	case GLUT_KEY_DOWN:
		d--;
		glTranslatef(d, 0, 0);
		 break;
	}
}
void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Ice Cream Cone");
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Special_Keys);
	glutDisplayFunc(draw);
	glutIdleFunc(draw);

	init();
    //Lighting and shade

	/*glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);*/

	glutMainLoop();
	return(0);
}
