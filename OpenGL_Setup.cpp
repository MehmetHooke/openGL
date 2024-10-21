#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "OpenGL_Setup.h"

float angle = 0.0f; // K�p�n d�n�� a��s�

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Renk ve derinlik tamponlar�n� temizle
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f); // K�p� biraz uza�a ta��
    glRotatef(angle, 1.0f, 1.0f, 0.0f); // K�p� d�nd�r

    // K�p i�in �izim ba�lat
    glBegin(GL_QUADS);

    // �n y�z (k�rm�z�)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // Arka y�z (ye�il)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // Sol y�z (mavi)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // Sa� y�z (sar�)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    // �st y�z (camg�be�i)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // Alt y�z (mor)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glEnd(); // �izimi bitir

    glutSwapBuffers(); // Tamponlar� de�i�tir
}

void update(int value) {
    angle += 2.0f; // K�p�n d�n�� a��s�n� art�r
    if (angle > 360) {
        angle -= 360;
    }

    glutPostRedisplay(); // Ekran� g�ncelle
    glutTimerFunc(16, update, 0); // Her 16 ms'de bir g�ncelle
}
