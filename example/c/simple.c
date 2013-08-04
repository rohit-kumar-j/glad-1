#include <stdio.h>
#include <stdlib.h>
#include <GL/glad.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// This file is a modified version of gl3w's test.c

// gcc -I. test.c GL/glad.c -ldl -lglut -Wall -Werror

static int width = 600, height = 600;

static void display(void)
{
    glClearColor(1.0f, 0.2f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
    glutPostRedisplay();
}

static void reshape(int w, int h)
{
    width = w > 1 ? w : 1;
    height = h > 1 ? h : 1;
    glViewport(0, 0, width, height);
    glClearDepth(1.0);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("cookie");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    if (!gladInit()) {
        fprintf(stderr, "failed to initialize glad\n");
        return -1;
    }

    GLVersion glv = gladLoadGL();
    printf("OpenGL %d.%d\n", glv.major, glv.minor);

    printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
           glGetString(GL_SHADING_LANGUAGE_VERSION));

    glutMainLoop();
    return 0;
}
