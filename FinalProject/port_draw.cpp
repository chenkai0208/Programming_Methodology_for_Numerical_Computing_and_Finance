//============================================================================
// Name        : port_draw.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 12/11/2017
// Description : Support File, draw a plot of total portfolio using OpenGL
//============================================================================

#include <GLUT/glut.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

vector <double> port;

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.

    glMatrixMode (GL_PROJECTION);       // Set projection parameters.
    gluOrtho2D(1.0, port.size()-1, *min_element(port.begin(), port.end())-10, *max_element(port.begin(), port.end())+10);
}

void lineSegment (void)
{
    glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.

    glColor3f (0.0, 0.4, 0.2);      // Set line segment color to green.


    glBegin (GL_LINE_STRIP);

        for (int i = 1; i <= port.size(); i++)
        {
            double j = i*1;
            glVertex2i (j, port[i]);
        }
    glEnd ( );
    glFlush ( );     // Process all OpenGL routines as quickly as possible.
}

int main (int argc, char** argv)
{
    /* read current portfolio from txt files */
    string line;
    ifstream portFile ("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/portfolio_history.txt");
    if (portFile.is_open())
    {
        while ( getline (portFile,line) )
        {
            port.push_back(stod(line));
        }
    portFile.close();
    }

    glutInit (&argc, argv);                         // Initialize GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
    glutInitWindowPosition (50, 100);   // Set top-left display-window position.
    glutInitWindowSize (400, 300);      // Set display-window width and height.
    glutCreateWindow ("Portfolio Value"); // Create display window.
    init ( );                            // Execute initialization procedure.
    glutDisplayFunc (lineSegment);       // Send graphics to display window.
    glutMainLoop ( );                    // Display everything and wait.
}
