        #include<iostream>

        #include <gl.h>

        #include <glut.h>

        #include <math.h>



        #include <cstring>



        #include <windows.h>

        #include <mmsystem.h>



        using namespace std ;





        void Draw_sky ();

        void DrawTrain();

        void Draw_Night_sky ();

        void Draw_car () ;

        void car () ;



        void Draw_wheel () ;



        float sunX = 0;

        float sunY = 0;



        float moonX = 0;

        float moonY = 0;



        int sunStatus = 1;

        int moonStatus = 0;



        float angle = 10.0f ;

        char hospital[] = "HOSPITAL";

        char trainplatform[]="TRAIN PLATFORM";
          char centralcity[]="CENTRAL CITY";

        char bus1[]="BUS";

        int trainStatus = 1 ;



        int busStatus = 0 ;

        float bus_X = 0.0;

        float bus_Y = 0.0;



        int carStatus = 1;



        float car_x = 0.0f ;

        float car_y = 0.0f ;



        int cloudStatus =1 ;



        float cloud_X = 0;



        float cloud_Y = 0;







        float train_X = 0.0 ;







        float train_Y = 0.0 ;





       void Draw_Total_Scene ()



       {



           glColor3f(0.0,0.0,0.0);



           glPushMatrix();

           glBegin(GL_POLYGON);



           glVertex2i(-10,-10);



           glVertex2i(610,-10);



           glVertex2i(610,810);



           glVertex2i(-10,810);



           glEnd();



           glPopMatrix();





       }

       void update ( int value)

       {

           angle += 0.1f ;

           if ( angle > 360 )

           {



               angle -= 360 ;

           }

           glutPostRedisplay(); //Tell GLUT that the display has changed



	//Tell GLUT to call update again in 25 milliseconds

	glutTimerFunc(25, update, 0);



       }



       void draw_Sun(int x);





        void DrawCircle(float cx, float cy, float r, int num_segments)



{



	glBegin(GL_POLYGON);



	for (int ii = 0; ii < num_segments; ii++)



	{



		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);







		float x = r * cosf(theta);



		float y = r * sinf(theta);







		glVertex2f(x + cx, y + cy);







	}



	glEnd();



}



void Draw_car()

{

    glPushMatrix();

//

//     glBegin(GL_QUADS);

//      glColor3ub(55,155,255);

//    glVertex3f(200,25,0.0);

//    glVertex3f(250,25,0.0);///car er main big glass

//    glVertex3f(250,60,0.0);

//    //glColor3f(1.1,0.0,1.0);

//    glVertex3f(200,60,0.0);

//    glEnd();

//    glBegin(GL_QUADS);

//      glColor3ub(55,155,255);

//    glVertex3f(200,60,0.0);

//    glVertex3f(185,45,0.0);///car left corner

//    glVertex3f(185,25,0.0);

//    //glColor3f(1.1,0.0,1.0);

//    glVertex3f(200,25,0.0);

//    glEnd();

//    glBegin(GL_QUADS);

//      glColor3ub(59, 137, 214);

//    glVertex3f(185,45,0.0);

//    glVertex3f(250,45,0.0);///car body shed

//    glVertex3f(250,60,0.0);

//    //glColor3f(1.1,0.0,1.0);

//    glVertex3f(200,60,0.0);

//    glEnd();

//    glBegin(GL_QUADS);

//      glColor3ub(59, 137, 214);

//    glVertex3f(220,60,0.0);

//    glVertex3f(245,60,0.0);///car left corner

//    glVertex3f(243,70,0.0);

//    //glColor3f(1.1,0.0,1.0);

//    glVertex3f(224,70,0.0);

//    glEnd();

      glScalef(0.63,0.63,0.0);

      glTranslatef(500,20,0.0);



    glBegin(GL_POLYGON);

    glColor3ub(173, 15, 126);

///car-body



    glVertex2f(20,100);

    glVertex2f(20,130);

    glVertex2f(50,130);

    glVertex2f(65,160);

    glVertex2f(135,160);

    glVertex2f(150,130);

    glVertex2f(180,130);

    glVertex2f(180,100);

    glEnd();



     glBegin(GL_POLYGON);

    glColor3ub(55,155,255);

///window

    glVertex2f(46,131);

    glVertex2f(66,158);

    glVertex2f(134,158);

    glVertex2f(147.5,131);







    glEnd();

    glLineWidth(7.5);

    glBegin(GL_LINES);

    glColor3ub(173, 15, 126);

///border

    glVertex2f(100,158);

    glVertex2f(100,131);

    glEnd();

    ///upper tire

    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(162,100);

    glVertex2f(157,110);

    glVertex2f(137,110);

    glVertex2f(132,100);

    glEnd();



    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(38,100);

    glVertex2f(43,110);

    glVertex2f(63,110);

    glVertex2f(68,100);

    glEnd();





     float x1=53,x2=147,y1=96.7,y2=96.7,radius=13;

	int i;

	int triangleAmount = 360; //# of triangles used to draw circle



	//GLfloat radius = 0.8f; //radius

	GLfloat twicePi = 2.0f *3.14159;



	glBegin(GL_TRIANGLE_FAN);

	glColor3ub(66, 67, 68);

		glVertex2f(x2, y2); // center of circle

		for(i = 0; i <= triangleAmount;i++) {

			glVertex2f(

		            x2 + (radius * cos(i *  twicePi / triangleAmount)),

			    y2 + (radius * sin(i * twicePi / triangleAmount))

			);

		}

	glEnd();



	glBegin(GL_TRIANGLE_FAN);

	glColor3ub(66, 67, 68);

		glVertex2f(x1, y1); // center of circle

		for(i = 0; i <= triangleAmount;i++) {

			glVertex2f(

		            x1 + (radius * cos(i *  twicePi / triangleAmount)),

			    y1 + (radius * sin(i * twicePi / triangleAmount))

			);

		}

	glEnd();



    glPopMatrix();

}



void car ()

{



	if (carStatus == 1)



	{



		car_x += 0.35;



	}



	if (car_x > 650)



	{



		car_x = -500;



	}



	glPushMatrix();



	glTranslatef(car_x, car_y, 0.0);



	Draw_car();



	glPopMatrix();







}

void Draw_Night_sky() {



    if (sunY <= -270)

    {

        moonStatus = 1 ;



    }



  	 if (sunY <= -270 )

	{

		glColor3f(0.0, 0.0, 0.0); ///

		cout<<"done ";





	}

	 else if ( sunY <= -152 )

    {

        glColor3f(.657 , .712 , .362);

        cout<<" ekta 1 no " ;



    }





    else if (sunY <= -210 )///

	{

		glColor3f(1, .498, .278);

		cout<<"eta run korse "<<endl;

		//glColor3f(1,1,0);

	}









	glBegin(GL_POLYGON); //Sky



	glVertex2i(610, 710);

	glVertex2i(0, 710);

	glColor3f(2.49, 1.87, 1.0);

	glVertex2i(0, 400);

	glVertex2i(610, 400);

	glEnd();





}



void star()

{

    /*Star counts from left to right*/

    /*star_1*/

glPushMatrix();

glTranslatef(2.0, 550.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_2*/

glPushMatrix();

glTranslatef(20.0, 640.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_3*/

glPushMatrix();

glTranslatef(50.0, 590.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_4*/

glPushMatrix();

glTranslatef(90.0, 640.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_5*/

glPushMatrix();

glTranslatef(90.0, 530.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_6*/

glPushMatrix();

glTranslatef(140.0, 590.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_7*/

glPushMatrix();

glTranslatef(200.0, 570.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_8*/

glPushMatrix();

glTranslatef(270.0, 530.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_9*/

glPushMatrix();

glTranslatef(320.0, 500.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_10*/

glPushMatrix();

glTranslatef(350.0, 570.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_11*/

glPushMatrix();

glTranslatef(410.0, 530.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_12*/

glPushMatrix();

glTranslatef(470.0, 550.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_13*/

glPushMatrix();

glTranslatef(530.0, 530.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();



/*star_14*/

glPushMatrix();

glTranslatef(570.0, 500.0, 0.0); //Move to the center of the triangle

glScalef(0.05,0.05,0);

glBegin(GL_POLYGON);

glColor3f(1.0, 1.0, 1.0);



    glVertex3i(250,350, 0);

    glVertex3i(300,500, 0);

    glVertex3i(350,350, 0);

    glVertex3i(450,300, 0);

    glVertex3i(350,250, 0);

    glVertex3i(300,100, 0);

    glVertex3i(250,250, 0);

    glVertex3i(150,300, 0);

glEnd();

glPopMatrix();









}



void Draw_Night_sky1() {

     float sunt = (-1)*sunY ;

    if (sunt >= 270)

    {

        moonStatus = 1 ;



    }



  	 if (sunt >= 270 )

	{

		glColor3f(0.0, 0.0, 0.0); ///







	}

	 else if ( sunt >= 150 && sunt < 210 )

    {

        glColor3f(.657 , .712 , .362);

        //cout<<" ekta 1 no " ;



    }





    else if (sunt >= 210 )///

	{

		glColor3f(1, .498, .278);

		//cout<<"eta run korse "<<endl;

		//glColor3f(1,1,0);

	}









	glBegin(GL_POLYGON); //Sky



	glVertex2i(610, 710);

	glVertex2i(0, 710);

	glColor3f(2.49, 1.87, 1.0);

	glVertex2i(0, 400);

	glVertex2i(610, 400);

	glEnd();





}

void Draw_bus();



void Draw_sky() {



	glBegin(GL_POLYGON); //Sky

	glColor3f(0.34, 0.808, 1.0);

	glVertex2i(0, 710);

	glVertex2i(0, 400);

	glColor3f(2.49, 1.87, 1.0);

	glVertex2i(610,400 );

	glVertex2i(610, 710);

	glEnd();



}



void draw_Moon() {



	glColor3f(0.980, 0.980, 0.824);///moon color

	DrawCircle(560, 400, 15, 1300);

}

void move_Moon()

{

	if (moonStatus == 1)

	{



		if (moonY >= 250)

		{

			moonY = 250;



		}

		else

		{

			moonY += .15;



		}



	}



	glPushMatrix();



	glTranslatef(moonX, moonY, 0);



	draw_Moon();

	glPopMatrix();





}



void bus ()

{

     if ( busStatus == 1)



            {



                bus_X -= 0.35 ;



            }



            if ( bus_X <= -150  )



            {



                bus_X = 650 ;



            }



            glPushMatrix();

            glTranslatef(bus_X, bus_Y ,0.0);

            Draw_bus();

            glPopMatrix();













}



void move_Sun()

{





	if (sunStatus == 1)// {



	{



		if (sunY <= -390)

		{

			sunY = -390;



		}

		else

		{

			sunY -= .15;



		}

	}



	glPushMatrix();



	glTranslatef(sunX, sunY, 0);



	draw_Sun(1);

	glPopMatrix();



}















void draw_Sun(int x)

{



	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 243, (1.0f / 255) * 202);

	DrawCircle(540, 650, 10.5+15, 650);



	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 234, (1.0f / 255) * 162);

	DrawCircle(540, 650, 10+15, 650);



	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 232, (1.0f / 255) * 149);

	DrawCircle(540, 650, 9.5+15, 650);



	glColor3f((1.0f / 255) * 254, (1.0f / 255) * 222, (1.0f / 255) * 112);

	DrawCircle(540, 650, 9+15, 650);



	glColor3f((1.0f / 255) * 254, (1.0f / 255) * 215, (1.0f / 255) * 78);

	DrawCircle(540, 650, 8.5+15, 650);



	glColor3f(1, .953, .792);

	DrawCircle(540, 650, 8+15, 650);



	glColor3f((1.0f / 255) * 253, (1.0f / 255) * 142, (1.0f / 255) * 0);

	DrawCircle(540, 650, 7.5+15, 650);



	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 158, (1.0f / 255) * 2);

	DrawCircle(540, 650, 6.5+15, 650);



	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 180, (1.0f / 255) * 1);

	DrawCircle(540, 650, 6.3+15, 650);



	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 197, (1.0f / 255) * 1);

	DrawCircle(540, 650, 5.8+15, 650);

}











 void drawCloud()



{



	glPushMatrix();







	glColor3f(0.8, 0.8, 0.8);



	DrawCircle(200, 630, 25, 1000); // 1st cloud



	DrawCircle(230, 650, 25, 1000);



	DrawCircle(180, 650, 25, 1000);



	DrawCircle(210, 680, 25, 1000);







	DrawCircle(600, 590, 25, 1000); // 2nd



	DrawCircle(630, 600, 25, 1000);



	DrawCircle(580, 600, 25, 1000);



	DrawCircle(610, 620, 25, 1000);







	glPopMatrix();



}







void cloud()



{



	if (cloudStatus == 1)



	{



		cloud_X += 0.12;



	}



	if (cloud_X > 650)



	{



		cloud_X = -650;



	}











	glPushMatrix();



	glTranslatef(cloud_X, cloud_Y, 0.0);



	drawCloud();







	glPopMatrix();



}











        void keyboard(unsigned char key, int x, int y)



    {







        switch (key) {



        case 'a':		//train start

        case 'A':



            trainStatus = 1;



            break;



        case 's':		//train stop

        case 'S':



            trainStatus = 0;



            break;



        case 'w':		//train start

        case 'W':



             busStatus = 1;



            break;



        case 'Q':		//train stop

        case 'q':



            busStatus = 0;



            break;



        case 'H':

        case'h':

             sndPlaySound("bus.wav",SND_ASYNC);

            break;



        case 27:     // ESC key



         exit(0);



         break;



        default:



            break;



        }



    }



    void Signboard( float x, float y, char *st)



{



    int l,i;











    l=strlen( st ); // see how many characters are in text string.



    ///glColor3f(0.0,1.0,0.7);



    //glDisable(GL_LIGHTING);



    glRasterPos2f( x, y); // location to start printing text



    for( i=0; i < l; i++) // loop until i is greater then l



    {



       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);



    }



}





 void Draw_rail_Line ( int x , int y )



        {



            int X_min = 0 ;



            int X_max = 620 ;



            int i ;



            glColor3ub (255 , 255 , 255 ) ;



          glBegin(GL_POLYGON);



            glVertex2f(X_min , y);



            glVertex2f(X_max, y);



            glVertex2f(X_max , y+3);



            glVertex2f(X_min , y+3);







            glEnd();



             glColor3ub (255 , 255 , 255 ) ;



          glBegin(GL_POLYGON);



            glVertex2f(X_min , y+15);



            glVertex2f(X_max, y+15);



            glVertex2f(X_max , y+3+15);



            glVertex2f(X_min , y+3+15);







            glEnd();





            for ( i = X_min ; i< X_max ; i += 15)



            {



                glColor3ub (255 , 0 , 0 ) ;



          glBegin(GL_POLYGON);



            glVertex2f(x+i, y);



            glVertex2f(x+i, y-7);



            glVertex2f(x+7+i , y-7);



            glVertex2f(x+7+i , y);







            glEnd();





            glColor3ub (255 , 0 , 0 ) ;



          glBegin(GL_POLYGON);



            glVertex2f(x+i, y+3);



            glVertex2f(x+i+7, y+3);



            glVertex2f(x+7+i+1 , y+15);



            glVertex2f(x+i+1 , y+15);







            glEnd();





            }



        }



void Draw_Relling ( int x , int y , int y_length )



        {



            int X_min = 0 ;



            int X_max = 620 ;



            int i ;



            for ( i = X_min ; i< X_max ; i += 20)



            {



            glColor3ub (255 , 255 , 255 ) ;



            glBegin(GL_POLYGON);



            glVertex2i(x+i , y);



            glVertex2i(x+2+i, y);



            glVertex2i(x+2+i , y+y_length);



            glVertex2i(x+i , y+y_length);







            glEnd();



               DrawCircle(x+i+1,y+y_length,3,100 );



            }



            glBegin(GL_POLYGON);



            glVertex2f(X_min , y+y_length-10);



            glVertex2f(X_max, y+y_length-10);



            glVertex2f(X_max , y+y_length-8);



            glVertex2f(X_min , y+y_length-8);







            glEnd();







            glBegin(GL_POLYGON);



            glVertex2f(X_min , y+5);



            glVertex2f(X_max, y+5);



            glVertex2f(X_max , y+7);



            glVertex2f(X_min , y+7);







            glEnd();



















        }

















        void Draw_1st_tree ()



        {



            glPushMatrix();



          //glScalef(0.0,0.0,0);



            glBegin(GL_QUADS);              ///Wood



            glColor3ub(112, 83, 25);



            glVertex3f(297,400,0.0);



            glColor3ub(112, 83, 25);



            glVertex3f(297,320,0.0);



            glColor3ub(168, 121, 28);



            glVertex3f(303,320,0.0);



            glColor3ub(168, 121, 28);



            glVertex3f(303,400,0.0);



            glEnd();







            glBegin(GL_POLYGON);              ///tree



            glColor3ub(35, 55, 30);



            glVertex3f(300,403,0.0);


            glVertex3f(275,378,0.0);


            glVertex3f(325,378,0.0);



            glEnd();







            glBegin(GL_POLYGON);              ///tree



            glColor3ub(32, 51, 27);



            glVertex3f(300,424,0.0);







            glVertex3f(275,399,0.0);







            glVertex3f(325,399,0.0);



            glEnd();







            glBegin(GL_POLYGON);              ///tree



            glColor3ub(69, 135, 54);



            glVertex3f(300,450,0.0);



            glColor3ub(32, 51, 27);



            glVertex3f(280,420,0.0);



            glColor3ub(32, 51, 27);



            glVertex3f(320,420,0.0);



            glEnd();







        glBegin(GL_POLYGON);              ///tree



            glColor3ub(68, 140, 53);



            glVertex3f(300,475,0.0);



            glColor3ub(62, 117, 50);



            glVertex3f(285,445,0.0);



            glColor3ub(62, 117, 50);



            glVertex3f(315,445,0.0);



            glEnd();



            glBegin(GL_POLYGON);              ///tree



            glColor3ub(220, 244, 66);



            glVertex3f(300,500,0.0);



            glColor3ub(66, 132, 53);



            glVertex3f(290,470,0.0);



            glColor3ub(66, 132, 53);



            glVertex3f(310,470,0.0);



            glEnd();



            glPopMatrix();











        }



        void Draw_2nd_tree ()



        {







            glPushMatrix();



          glScalef(1,1.1,0);



          glTranslatef(60,-30,0);



            glBegin(GL_QUADS);              //Wood



            glColor3ub(112, 83, 25);



            glVertex3f(297,400,0.0);



            glColor3ub(112, 83, 25);



            glVertex3f(297,320,0.0);



            glColor3ub(168, 121, 28);



            glVertex3f(303,320,0.0);



            glColor3ub(168, 121, 28);



            glVertex3f(303,400,0.0);



            glEnd();







            glBegin(GL_POLYGON);              //tree



            glColor3ub(35, 55, 30);



            glVertex3f(300,403,0.0);







            glVertex3f(275,378,0.0);







            glVertex3f(325,378,0.0);



            glEnd();







            glBegin(GL_POLYGON);              //tree



            glColor3ub(32, 51, 27);



            glVertex3f(300,424,0.0);







            glVertex3f(275,399,0.0);







            glVertex3f(325,399,0.0);



            glEnd();







            glBegin(GL_POLYGON);              //tree



            glColor3ub(69, 135, 54);



            glVertex3f(300,450,0.0);



            glColor3ub(32, 51, 27);



            glVertex3f(280,420,0.0);



            glColor3ub(32, 51, 27);



            glVertex3f(320,420,0.0);



            glEnd();







        glBegin(GL_POLYGON);              //tree



            glColor3ub(68, 140, 53);



            glVertex3f(300,475,0.0);



            glColor3ub(62, 117, 50);



            glVertex3f(285,445,0.0);



            glColor3ub(62, 117, 50);



            glVertex3f(315,445,0.0);



            glEnd();



            glBegin(GL_POLYGON);              //tree



            glColor3ub(220, 244, 66);



            glVertex3f(300,500,0.0);



            glColor3ub(66, 132, 53);



            glVertex3f(290,470,0.0);



            glColor3ub(66, 132, 53);



            glVertex3f(310,470,0.0);



            glEnd();



            glPopMatrix();



        }



        void Draw_3rd_tree ()



        {







        glPushMatrix();



          glScalef(0.88,0.9,0);



          glTranslatef(170,36,0);



            glBegin(GL_QUADS);              //Wood



            glColor3ub(112, 83, 25);



            glVertex3f(297,400,0.0);



            glColor3ub(112, 83, 25);



            glVertex3f(297,320,0.0);



            glColor3ub(168, 121, 28);



            glVertex3f(303,320,0.0);



            glColor3ub(168, 121, 28);



            glVertex3f(303,400,0.0);



            glEnd();







            glBegin(GL_POLYGON);              //tree



            glColor3ub(35, 55, 30);



            glVertex3f(300,403,0.0);







            glVertex3f(275,378,0.0);







            glVertex3f(325,378,0.0);



            glEnd();







            glBegin(GL_POLYGON);              //tree



            glColor3ub(32, 51, 27);



            glVertex3f(300,424,0.0);







            glVertex3f(275,399,0.0);







            glVertex3f(325,399,0.0);



            glEnd();







            glBegin(GL_POLYGON);              //tree



            glColor3ub(69, 135, 54);



            glVertex3f(300,450,0.0);



            glColor3ub(32, 51, 27);



            glVertex3f(280,420,0.0);



            glColor3ub(32, 51, 27);



            glVertex3f(320,420,0.0);



            glEnd();







        glBegin(GL_POLYGON);              //tree



            glColor3ub(68, 140, 53);



            glVertex3f(300,475,0.0);



            glColor3ub(62, 117, 50);



            glVertex3f(285,445,0.0);



            glColor3ub(62, 117, 50);



            glVertex3f(315,445,0.0);



            glEnd();



            glBegin(GL_POLYGON);              //tree



            glColor3ub(220, 244, 66);



            glVertex3f(300,500,0.0);



            glColor3ub(66, 132, 53);



            glVertex3f(290,470,0.0);



            glColor3ub(66, 132, 53);



            glVertex3f(310,470,0.0);



            glEnd();



            glPopMatrix();







        }



        void Draw_3rd_Building ()



        {



            glPushMatrix() ;







              glBegin(GL_QUADS);              ///back side blue  building



            glColor3ub(80,60,128);



            glVertex3f(440,360,0.0);



              glColor3ub(30,10,50);



            glVertex3f(510,360,0.0);



            glVertex3f(510,500,0.0);



            glVertex3f(440,500,0.0);



            glEnd();







        glBegin(GL_QUADS);              ///back side blue  building er pasher 3d



            glColor3ub(70,100,118);



            glVertex3f(510,360,0.0);



            glVertex3f(519,366,0.0);



            glVertex3f(519,506,0.0);



            glVertex3f(510,502,0.0);



            glEnd();











        glBegin(GL_QUADS);              ///back side blue  building er uporer 3d



            glColor3ub(70,100,118);



              glVertex3f(510,500,0.0);



            glVertex3f(519,506,0.0);



            glVertex3f(442,506,0.0);



            glVertex3f(440,500,0.0);







            glEnd();



















             glBegin(GL_QUADS);              ///back side blue  building er nicher 1st window



           glColor3ub(55,155,255);



            glVertex3f(450,380,0.0);



            glVertex3f(470,380,0.0);



            glVertex3f(470,400,0.0);



            glVertex3f(450,400,0.0);



            glEnd();























             glBegin(GL_QUADS);              ///back side blue  building er nicher 2nd window



               glColor3ub(55,155,255);



            glVertex3f(480,380,0.0);



            glVertex3f(500,380,0.0);



            glVertex3f(500,400,0.0);



            glVertex3f(480,400,0.0);



            glEnd();















             glBegin(GL_QUADS);              ///back side blue  building 2nd line er last  window



              glColor3ub(55,155,255);



            glVertex3f(480,420,0.0);



            glVertex3f(500,420,0.0);



            glVertex3f(500,440,0.0);



            glVertex3f(480,440,0.0);



            glEnd();



















            glBegin(GL_QUADS);              ///back side blue  building er nicher 1st window



              glColor3ub(55,155,255);



            glVertex3f(450,420,0.0);



            glVertex3f(470,420,0.0);



            glVertex3f(470,440,0.0);



            glVertex3f(450,440,0.0);



            glEnd();















             glBegin(GL_QUADS);              ///back side blue  building er uporerlomba window



            glColor3ub(55,155,255);



            glVertex3f(450,460,0.0);



            glVertex3f(500,460,0.0);



            glVertex3f(500,490,0.0);



            glVertex3f(450,490,0.0);



            glEnd();















            glPopMatrix() ;











        }


        void Draw_Road_2nd_dark ()



        {







              glPushMatrix();



              glBegin(GL_QUADS);              ///back side dark ash road

            glColor3ub(63,63,63);

            glVertex3f(255,320,0.0);

            glVertex3f(599,320,0.0);

            glVertex3f(599,400,0.0);

            glVertex3f(255,400,0.0);

            glEnd();


              glBegin(GL_QUADS);              ///back side dark ash road



            glColor3ub(63,63,63);

            glVertex3f(0,320,0.0);

            glVertex3f(30,320,0.0);

            glVertex3f(30,400,0.0);

            glVertex3f(0,400,0.0);

            glEnd();


            glPopMatrix();

        }





        void mountain()

        {

            glPushMatrix();





             glBegin(GL_QUADS);              ///LAST LEFT MOUNTAIN

            glColor3ub(112, 83, 25);

            glVertex3f(-6,400,0.0);

            glColor3ub(90, 83, 35);

            glVertex3f(35,400,0.0);

            glColor3ub(200, 83, 25);

            glVertex3f(20,500,0.0);

            glColor3f(1.1,1.1,0.0);

            glVertex3f(-6,400,0.0);



            glEnd();



            glBegin(GL_TRIANGLES);              ///LAST LEFT MOUNTAIN ER RIGHT SIDE///

            //glColor3ub(112, 83, 25);

            glVertex3f(35,400,0.0);

            glColor3ub(90, 83, 35);

            glVertex3f(60,400,0.0);

            glColor3ub(190, 83, 25);

            glVertex3f(20,500,0.0);

             glEnd();





               glBegin(GL_QUADS);              ///LAST LEFT MOUNTAIN LEFT SIDE///

            //glColor3ub(112, 83, 25);

            glVertex3f(-10,400,0.0);

            glColor3ub(90, 83, 35);

            glVertex3f(-6,400,0.0);

            glColor3ub(190, 83, 25);

            glVertex3f(20,500,0.0);



            glVertex3f(-10,430,0.0);



            glEnd();

















            glBegin(GL_QUADS);              ///1ST MOUNTAIN

            glColor3ub(112, 83, 25);

            glVertex3f(255,400,0.0);

            glColor3ub(90, 83, 35);

            glVertex3f(300,400,0.0);

            glColor3ub(190, 83, 25);

            glVertex3f(280,500,0.0);



            glVertex3f(255,400,0.0);



            glEnd();



            glBegin(GL_TRIANGLES);              ///1ST MOUNTAIN RIGHT///

            //glColor3ub(112, 83, 25);

            glVertex3f(300,400,0.0);

            glColor3ub(90, 83, 35);

            glVertex3f(340,400,0.0);

            glColor3f(1.1,1.1,0.0);

            //glColor3ub(190, 83, 25);

            glVertex3f(280,500,0.0);



            //glVertex3f(255,400,0.0);



            glEnd();

            glBegin(GL_QUADS);

             glColor3ub(150, 83, 25);

            glVertex3f(255,400,0.0);

            glVertex3f(280,500,0.0);///1ST MOUNTAIN LEFT



            glVertex3f(240,420,0.0);



            glVertex3f(255,400,0.0);



            glEnd();





            glBegin(GL_QUADS);

             glColor3ub(190, 83, 25);

            glVertex3f(340,400,0.0);

             glColor3ub(180, 63, 25);///2ND BIG MOUNTAIN

            glVertex3f(430,400,0.0);

              //glColor3ub(10,50,0);

             glColor3ub(90, 83, 25);

            glVertex3f(370,560,0.0);

             glColor3f(1.1,1.1,0.0);

            glVertex3f(340,400,0.0);

            glEnd();





              glBegin(GL_TRIANGLES);              ///2ND MOUNTAIN LEFT///

            //glColor3ub(112, 83, 25);

            glVertex3f(430,400,0.0);

            glColor3ub(90, 83, 35);

            glVertex3f(460,400,0.0);

             //glColor3ub(30,0,0);

            glColor3ub(190, 83, 25);

            glVertex3f(370,560,0.0);

             glEnd();









              glBegin(GL_QUADS);

             glColor3ub(190, 83, 25);

            glVertex3f(340,400,0.0);///2ND BIG MOUNTAIN ER  RIGHT

            glVertex3f(370,560,0.0);

             glColor3ub(90, 83, 25);

            glVertex3f(350,500,0.0);

            glVertex3f(320,400,0.0);

            glEnd();





            glBegin(GL_QUADS);

             glColor3ub(190, 83, 25);

            glVertex3f(460,400,0.0);

             glColor3ub(180, 63, 25);///3RD BIG MOUNTAIN

            glVertex3f(530,400,0.0);

             glColor3ub(90, 83, 25);

            glVertex3f(520,530,0.0);

            glVertex3f(460,420,0.0);

            glEnd();





              glBegin(GL_TRIANGLES);              ///3RD MOUNTAIN LEFT///

            //glColor3ub(112, 83, 25);

            glVertex3f(530,400,0.0);

            glColor3ub(90, 83, 35);

            glVertex3f(540,400,0.0);

            glColor3ub(190, 83, 25);

            glVertex3f(520,530,0.0);



            //glVertex3f(255,400,0.0);



            glEnd();



            glBegin(GL_QUADS);

             glColor3ub(190, 83, 25);

            glVertex3f(533,400,0.0);

             glColor3ub(180, 63, 25);///4RTH BIG MOUNTAIN

            glVertex3f(590,400,0.0);

             glColor3f(1.1,1.1,0.0);

             //glColor3ub(120, 83, 25);

            glVertex3f(595,460,0.0);

              glColor3ub(120, 83, 25);

            glVertex3f(540,420,0.0);

            glEnd();







              glBegin(GL_TRIANGLES);              ///4RTH MOUNTAIN LEFT///

            glColor3ub(112, 83, 25);

            glVertex3f(590,400,0.0);

            glColor3ub(90, 83, 35);

            glVertex3f(620,400,0.0);

            glColor3ub(200, 83, 25);

            glVertex3f(595,460,0.0);



 glEnd();















            glPopMatrix();

        }







        void  Draw_Road_white_light ()



        {



            glPushMatrix();







             glBegin(GL_QUADS);              ///road white



            glColor3ub(128,128,128);



            glVertex3f(0,240,0.0);



            glVertex3f(599,240,0.0);



            glVertex3f(599,290,0.0);



            glVertex3f(0,290,0.0);



            glEnd();















             glBegin(GL_QUADS);              ///road white er samner border



            glColor3ub(128,128,128);



            glVertex3f(0,228,0.0);



              glColor3ub(63,63,63);



            glVertex3f(599,228,0.0);



             glColor3ub(128,128,128);



            glVertex3f(599,240,0.0);



             glColor3ub(63,63,63);



            glVertex3f(0,240,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///road white



            glColor3ub(128,128,128);



            glVertex3f(255,270,0.0);



            glVertex3f(599,270,0.0);



            glVertex3f(599,320,0.0);



            glVertex3f(255,320,0.0);



            glEnd();















            glBegin(GL_TRIANGLES);              ///ROAD white triangle



            glColor3ub(128,128,128);



            glVertex3f(240,290,0.0);



            glVertex3f(300,280,0.0);



            glVertex3f(255,299,0.0);







            glEnd();















            glBegin(GL_QUADS);              ///road white



            glColor3ub(128,128,128);



            glVertex3f(0,290,0.0);



            glVertex3f(30,290,0.0);



            glVertex3f(30,320,0.0);



            glVertex3f(0,320,0.0);



            glEnd();







            glPopMatrix();











        }

        void draw_airland()

{

    glPushMatrix();







     glBegin(GL_QUADS);              ///airland er uporer border

    glColor3ub(128,128,128);

    glVertex3f(10,140,0.0);

      glColor3ub(63,63,63);

    glVertex3f(580,140,0.0);

     glColor3ub(128,128,128);

    glVertex3f(599,135,0.0);

     glColor3ub(63,63,63);

    glVertex3f(-3,135,0.0);

    glEnd();



 glBegin(GL_QUADS);

        glColor3ub(120,128,128);///airland er main

    glVertex3f(0,100,0.0);

      glColor3ub(63,43,63);

    glVertex3f(599,100,0.0);

     glColor3ub(128,128,128);

    glVertex3f(599,130,0.0);

     glColor3ub(63,73,63);

    glVertex3f(0,130,0.0);

    glEnd();

    glPopMatrix();

}





void Draw_bus()

{

    glPushMatrix();



    glBegin(GL_QUADS);







    glColor3f(1.1,0.0,0.0);

    glVertex3f(70,20,0.0);

    glVertex3f(150,20,0.0);///bus middle main

    glVertex3f(150,50,0.0);

    glVertex3f(70,50,0.0);

    glEnd();





             glColor3ub(100,0,200);     /// BUS likha

             Signboard(100,26,bus1);





      glBegin(GL_QUADS);



    glColor3ub(100,64,30);

    glVertex3f(70,20,0.0);

    glVertex3f(150,20,0.0);///bus middle main border

    glVertex3f(150,25,0.0);

    glVertex3f(70,25,0.0);

    glEnd();



     glColor3ub(63,63,63);

                                   /// 1st chaka

        DrawCircle(85,18,8,1000);

        glColor3ub(128,128,128);

        DrawCircle(85,18,3,1000);





          glColor3ub(63,63,63);

                                   /// 2nd chaka

        DrawCircle(140,18,8,1000);

        glColor3ub(128,128,128);

        DrawCircle(140,18,3,1000);



     glBegin(GL_QUADS);



    glColor3ub(100,64,30);

    glVertex3f(70,20,0.0);

    glVertex3f(71,20,0.0);///bus middle main  lomba border

    glVertex3f(71,50,0.0);

    glVertex3f(70,50,0.0);

    glEnd();



     glBegin(GL_QUADS);



    glColor3f(1.1,0.0,0.0);

    glVertex3f(60,27,0.0);

    glVertex3f(70,20,0.0);///bus er samner part

    glVertex3f(70,50,0.0);

    glColor3f(1.1,0.0,1.0);

    glVertex3f(60,57,0.0);

    glEnd();



  glColor3ub(63,63,63);

                                   /// 1st box er 1st wheel

        DrawCircle(67,35,2,1000);

        glColor3f(1.1,1.1,0.0);

        DrawCircle(67,35,2,1000);









  glColor3ub(63,63,63);

                                   /// 1st box er 1st wheel

        DrawCircle(61,38,2,1000);

        glColor3f(1.1,1.1,0.0);

        DrawCircle(61,38,2,1000);



  glBegin(GL_QUADS);

    glColor3f(0.0,0.0,1.1);

    glVertex3f(60,57,0.0);

    glVertex3f(70,50,0.0);///bus er samner glass

    glVertex3f(70,85,0.0);

    glColor3f(1.1,0.0,1.0);

    glVertex3f(62,87,0.0);

    glEnd();



  glBegin(GL_QUADS);

      glColor3ub(55,155,255);

    glVertex3f(70,50,0.0);

    glVertex3f(149,50,0.0);///bus er main big glass

    glVertex3f(149,85,0.0);

    //glColor3f(1.1,0.0,1.0);

    glVertex3f(70,85,0.0);

    glEnd();



     glBegin(GL_QUADS);

    glColor3f(1.1,0.0,0.0);

    glVertex3f(62,87,0.0);

    glVertex3f(74,85,0.0);///bus er uporer red

    glVertex3f(150,85,0.0);

    //glColor3f(1.1,0.0,1.0);

    glVertex3f(150,87,0.0);

    glEnd();



     glBegin(GL_QUADS);

    glColor3f(1.1,0.0,0.0);

    glVertex3f(147,50,0.0);

    glVertex3f(150,50,0.0);///bus er left border red

    glVertex3f(150,87,0.0);

    //glColor3f(1.1,0.0,1.0);

    glVertex3f(147,87,0.0);

    glEnd();







     glBegin(GL_QUADS);

    glColor3f(1.1,0.0,0.0);

    glVertex3f(80,50,0.0);

    glVertex3f(82,50,0.0);///WINDOW 1SR BORDER

    glVertex3f(82,87,0.0);

    //glColor3f(1.1,0.0,1.0);

    glVertex3f(80,87,0.0);

    glEnd();





     glBegin(GL_QUADS);

    glColor3f(1.1,0.0,0.0);

    glVertex3f(97,50,0.0);

    glVertex3f(99,50,0.0);///WINDOW 2ND BORDER

    glVertex3f(99,87,0.0);

    //glColor3f(1.1,0.0,1.0);

    glVertex3f(97,87,0.0);

    glEnd();









      glBegin(GL_QUADS);

    glColor3f(1.1,0.0,0.0);

    glVertex3f(114,50,0.0);

    glVertex3f(116,50,0.0);///WINDOW 3RD BORDER

    glVertex3f(116,87,0.0);

    //glColor3f(1.1,0.0,1.0);

    glVertex3f(114,87,0.0);

    glEnd();







      glBegin(GL_QUADS);

    glColor3f(1.1,0.0,0.0);

    glVertex3f(133,50,0.0);

    glVertex3f(135,50,0.0);///WINDOW 4RTH BORDER

    glVertex3f(135,87,0.0);

    //glColor3f(1.1,0.0,1.0);

    glVertex3f(133,87,0.0);

    glEnd();



    glPopMatrix();

}

void middle_road_line()

{

    glPushMatrix();



    glBegin(GL_QUADS);



    glColor3f(1.1,1.1,0.0);

    glVertex3f(20,60,0.0);

    glVertex3f(55,60,0.0);///1ST LINE

    glVertex3f(60,65,0.0);

    glVertex3f(25,65,0.0);

    glEnd();



        glBegin(GL_QUADS);



    glColor3f(1.1,1.1,0.0);

    glVertex3f(150,60,0.0);

    glVertex3f(190,60,0.0);///2ND LINE

    glVertex3f(195,65,0.0);

    glVertex3f(155,65,0.0);

    glEnd();



        glBegin(GL_QUADS);

 glColor3f(1.1,1.1,0.0);

    glVertex3f(270,60,0.0);

    glVertex3f(310,60,0.0);///3RD LINE

    glVertex3f(315,65,0.0);

    glVertex3f(275,65,0.0);

    glEnd();



     glBegin(GL_QUADS);

   glColor3f(1.1,1.1,0.0);

    glVertex3f(390,60,0.0);

    glVertex3f(430,60,0.0);///4RTH LINE

    glVertex3f(435,65,0.0);

    glVertex3f(395,65,0.0);

    glEnd();





      glBegin(GL_QUADS);

   glColor3f(1.1,1.1,0.0);

    glVertex3f(510,60,0.0);

    glVertex3f(550,60,0.0);///5th LINE

    glVertex3f(555,65,0.0);

    glVertex3f(515,65,0.0);

    glEnd();



    glPopMatrix();

}







        void Draw_wind_machine1()



{



    glPushMatrix();



         glBegin(GL_QUADS);              ///wind machine er stand



      glColor3ub(63,63,63);



    glVertex3f(551,360,0.0);



     glColor3ub(128,128,128);



    glVertex3f(555,360,0.0);



    glVertex3f(555,470,0.0);



    glVertex3f(551,470,0.0);



    glEnd();
glBegin(GL_QUADS);              ///stand er uporer choto board

      glColor3ub(63,63,63);

    glVertex3f(548,465,0.0);

     glColor3ub(128,128,128);

    glVertex3f(558,465,0.0);

    glVertex3f(558,475,0.0);

    glVertex3f(548,475,0.0);

    glEnd();



     glBegin(GL_QUADS);              ///stand er uporer main board

      glColor3ub(63,63,63);

    glVertex3f(522,475,0.0);

     glColor3ub(128,128,128);

    glVertex3f(587,475,0.0);

    glVertex3f(587,502,0.0);

    glVertex3f(522,502,0.0);

    glEnd();


         glColor3f(0.980, 0.980, 0.824);    /// trainplatform likha
             Signboard(525,482,centralcity);





    glPopMatrix();

}








    //glVertex3f(550,470,0.0);



        void Draw_wall()



        {



            glPushMatrix();







             glBegin(GL_QUADS);              ///1st wall



            glColor3ub(50,10,80);



            glVertex3f(0,240,0.0);



            glColor3ub(150,0,60);



            glVertex3f(100,240,0.0);



            glVertex3f(100,307,0.0);



            glVertex3f(0,307,0.0);



            glEnd();







               glBegin(GL_QUADS);              ///1st wall 1st border



            glColor3ub(90,30,80);



            glVertex3f(0,280,0.0);



            //glColor3ub(150,0,60);



            glVertex3f(100,280,0.0);



            glVertex3f(100,282,0.0);



            glVertex3f(0,282,0.0);



            glEnd();







              glBegin(GL_QUADS);              ///1st wall 2nd border



            glColor3ub(90,30,90);



            glVertex3f(0,270,0.0);



            //glColor3ub(150,0,60);



            glVertex3f(100,270,0.0);



            glVertex3f(100,272,0.0);



            glVertex3f(0,272,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///1st wall left gate



            glColor3ub(0,0,80);



            glVertex3f(100,240,0.0);



            glColor3ub(10,0,70);



            glVertex3f(150,240,0.0);



            glColor3ub(10,0,10);



            glVertex3f(150,318,0.0);



            glVertex3f(100,318,0.0);



            glEnd();























              glBegin(GL_QUADS);              ///2nd wall



            glColor3ub(90,0,80);



            glVertex3f(200,240,0.0);



            glColor3ub(110,0,60);



            glVertex3f(400,240,0.0);



            glVertex3f(400,307,0.0);



            glVertex3f(200,307,0.0);



            glEnd();







             glBegin(GL_QUADS);              ///2nd wall 1st border



            glColor3ub(10,30,80);



            glVertex3f(200,280,0.0);



            //glColor3ub(150,0,60);



            glVertex3f(400,280,0.0);



            glVertex3f(400,282,0.0);



            glVertex3f(200,282,0.0);



            glEnd();







              glBegin(GL_QUADS);              ///2nd wall 2nd border



            glColor3ub(10,30,90);



            glVertex3f(200,270,0.0);



            //glColor3ub(150,0,60);



            glVertex3f(400,270,0.0);



            glVertex3f(400,272,0.0);



            glVertex3f(200,272,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///1st wall right gate



            glColor3ub(0,0,80);



            glVertex3f(160,248,0.0);



            glColor3ub(10,0,70);



            glVertex3f(200,240,0.0);



            glColor3ub(10,0,10);



            glVertex3f(200,315,0.0);



            glVertex3f(160,329,0.0);



            glEnd();







            glBegin(GL_QUADS);              ///3rd wall



            glColor3ub(150,0,80);



            glVertex3f(400,240,0.0);



            glColor3ub(255,0,100);



            glVertex3f(410,245,0.0);



            glVertex3f(410,323,0.0);



            glVertex3f(400,307,0.0);



            glEnd();







         glBegin(GL_QUADS);              ///3rd wall er paser light post



            glColor3ub(150,0,80);



            glVertex3f(430,240,0.0);



          glColor3ub(64,0,0);



            glVertex3f(435,240,0.0);



            glVertex3f(435,350,0.0);



            glVertex3f(430,350,0.0);



            glEnd();



         glBegin(GL_QUADS);              ///3rd wall er paser light post er uporer part



            glColor3ub(150,0,80);



            glVertex3f(410,330,0.0);



          glColor3ub(64,0,0);



            glVertex3f(455,330,0.0);



            glVertex3f(455,340,0.0);



            glVertex3f(410,340,0.0);



            glEnd();











             glBegin(GL_TRIANGLES);              ///3rd wall er paser light post er LEFT LIGHT LAMP



            glColor3ub(150,0,80);



            glVertex3f(412,318,0.0);



          glColor3ub(64,0,0);



            glVertex3f(420,318,0.0);



            glVertex3f(416,332,0.0);



            //glVertex3f(416,340,0.0);



            glEnd();







               glBegin(GL_QUADS);              ///3rd wall er paser light post er LEFT LIGHT

            glColor3f(1.0,1.1,1.1);

            glVertex3f(415,313,0.0);

          //glColor3ub(64,0,0);

            glVertex3f(417,313,0.0);

            glVertex3f(417,318,0.0);
            glVertex3f(415,318,0.0);
            glEnd();
if(sunY <= -270){


 glBegin(GL_POLYGON);              ///3rd wall er paser light post er LEFT LIGHT er view

            glColor4f(1.0,1.1,1.1, 0.5);

            glVertex3f(416,313,0.0);

          //glColor3ub(64,0,0);

            glVertex3f(412,245,0.0);

            glVertex3f(420,245,0.0);
            //glVertex3f(415,318,0.0);
            glEnd();




}




             glBegin(GL_TRIANGLES);              ///3rd wall er paser light post er right LIGHT LAMP



            glColor3ub(150,0,80);



            glVertex3f(445,318,0.0);



          glColor3ub(64,0,0);



            glVertex3f(454,318,0.0);



            glVertex3f(450,332,0.0);



            //glVertex3f(416,340,0.0);



            glEnd();


                glBegin(GL_QUADS);              ///3rd wall er paser light post er right LIGHT

            glColor3f(1.0,1.1,1.1);

            glVertex3f(449,313,0.0);

          //glColor3ub(64,0,0);

            glVertex3f(451,313,0.0);

            glVertex3f(451,318,0.0);
            glVertex3f(449,318,0.0);
            glEnd();
if(sunY <= -270){
            glBegin(GL_POLYGON);              ///3rd wall er paser light post er right LIGHT er view

            glColor4f(1.0,1.1,1.1,1.0);

            glVertex3f(450,313,0.0);

          //glColor3ub(64,0,0);

            glVertex3f(446,244,0.0);

            glVertex3f(454,244,0.0);
            //glVertex3f(415,318,0.0);
            glEnd();

}

            glPopMatrix();



    }



        void Draw_train_station()



        {



            glPushMatrix();







            glBegin(GL_QUADS);              ///samner dark brown



            glColor3ub(112, 83, 25);



            glVertex3f(440,270,0.0);



            glVertex3f(580,270,0.0);



            glVertex3f(580,280,0.0);



            glVertex3f(440,280,0.0);



            glEnd();







         glBegin(GL_QUADS);              ///wide light brown



             glColor3ub(168, 121, 28);



            glVertex3f(580,280,0.0);



            glVertex3f(545,300,0.0);



            glVertex3f(470,300,0.0);



            glVertex3f(440,280,0.0);



            glEnd();



         glBegin(GL_QUADS);              ///pichoner dark brown



             glColor3ub(168, 100, 28);



            glVertex3f(545,300,0.0);



             glColor3ub(220, 120, 38);



            glVertex3f(545,360,0.0);



            glVertex3f(470,360,0.0);



            glVertex3f(470,300,0.0);



            glEnd();



         glBegin(GL_QUADS);              ///sitting line



             glColor3ub(140, 20, 28);



            glVertex3f(479,300,0.0);



             glColor3ub(255, 100, 20);



            glVertex3f(540,300,0.0);



            glColor3ub(255, 10, 204);



            glVertex3f(540,310,0.0);



            glVertex3f(479,310,0.0);



            glEnd();



         glBegin(GL_QUADS);              ///sitting line left stick



             glColor3ub(140, 20, 28);



            glVertex3f(485,285,0.0);



             glColor3ub(255, 100, 20);



            glVertex3f(490,285,0.0);



            glColor3ub(255, 10, 204);



            glVertex3f(490,300,0.0);



             glColor3ub(140, 20, 210);



            glVertex3f(485,300,0.0);



            glEnd();







             glBegin(GL_QUADS);              ///sitting line right stick



             glColor3ub(140, 20, 28);



            glVertex3f(530,285,0.0);



             glColor3ub(255, 100, 20);



            glVertex3f(535,285,0.0);



            glColor3ub(255, 10, 204);



            glVertex3f(535,300,0.0);



             glColor3ub(140, 20, 210);



            glVertex3f(530,300,0.0);



            glEnd();























             glBegin(GL_QUADS);              ///uporer border dark brown



            glColor3ub(112, 83, 25);



            glVertex3f(440,360,0.0);



            glVertex3f(580,360,0.0);



            glVertex3f(580,375,0.0);



            glVertex3f(440,375,0.0);



            glEnd();







          glBegin(GL_QUADS);              ///border



            glColor3ub(112, 50, 25);



            glVertex3f(445,365,0.0);



            glVertex3f(575,365,0.0);



            glVertex3f(575,370,0.0);



            glVertex3f(445,370,0.0);



            glEnd();







        glBegin(GL_QUADS);              ///train station board



            glColor3ub(120, 50, 65);



            glVertex3f(445,345,0.0);



            glVertex3f(573,345,0.0);



            glVertex3f(573,360,0.0);



            glVertex3f(445,360,0.0);



            glEnd();





             glColor3f(1.0,1.1,1.1);    /// trainplatform likha

             Signboard(475,345,trainplatform);



            glBegin(GL_QUADS);              ///train station er right side wall



           glColor3ub(112, 50, 25);



            glVertex3f(470,285,0.0);



            glVertex3f(475,285,0.0);



            glVertex3f(475,345,0.0);



            glVertex3f(470,345,0.0);



            glEnd();







            glBegin(GL_QUADS);              ///train station er left side wall



           glColor3ub(112, 50, 25);



            glVertex3f(550,285,0.0);



            glVertex3f(545,285,0.0);



            glVertex3f(545,345,0.0);



            glVertex3f(550,345,0.0);



            glEnd();















            glPopMatrix();



        }











        void Draw_2nd_Building ()



        {



            glPushMatrix() ;







            glBegin(GL_QUADS);              ///left  2ND building



            glColor3ub(55,10,60);



            glVertex3f(134,280,0.0);



            glVertex3f(240,280,0.0);



            glVertex3f(240,550,0.0);



            glVertex3f(134,550,0.0);



            glEnd();







        glBegin(GL_QUADS);              ///left  2ND building er 3d portion



            glColor3ub(55,50,60);



            glVertex3f(240,290,0.0);



            glVertex3f(255,299,0.0);



            glVertex3f(255,555,0.0);



            glVertex3f(240,555,0.0);



            glEnd();













            glBegin(GL_QUADS);              ///left  2ND building er uporer 3d



            glColor3ub(55,50,60);



            glVertex3f(134,550,0.0);



            glVertex3f(240,550,0.0);



            glVertex3f(255,555,0.0);



            glVertex3f(141,555,0.0);



            glEnd();







             glBegin(GL_QUADS);              ///left  2ND building 1ST BORDER



            glColor3ub(55,30,60);

            glVertex3f(134,300,0.0);

            glVertex3f(240,300,0.0);
            glVertex3f(240,350,0.0);
            glVertex3f(134,350,0.0);



            glEnd();















             glBegin(GL_QUADS);              ///left  2ND building 2ND BORDER



            glColor3ub(55,30,60);



            glVertex3f(134,370,0.0);



            glVertex3f(240,370,0.0);



            glVertex3f(240,420,0.0);



            glVertex3f(134,420,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///left  2ND building 3RD BORDER



            glColor3ub(55,30,60);



            glVertex3f(134,440,0.0);



            glVertex3f(240,440,0.0);



            glVertex3f(240,490,0.0);



            glVertex3f(134,490,0.0);



            glEnd();















        glBegin(GL_QUADS);              ///left  2ND building ER LOMBA BORDER



            glColor3ub(55,30,60);



            glVertex3f(165,290,0.0);



            glVertex3f(210,290,0.0);



            glVertex3f(210,530,0.0);



            glVertex3f(165,530,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///left  2ND building ER UPPER LEFT 1ST WINDOW



            glColor3ub(55,155,255);



            glVertex3f(145,480,0.0);



            glVertex3f(230,480,0.0);



            glVertex3f(230,530,0.0);



            glVertex3f(145,530,0.0);



            glEnd();





             glColor3ub(70,0,200);     /// hospital likha

             Signboard(165,495,hospital);

















            glBegin(GL_QUADS);              ///left  2ND building 2nd  2nd line er 1stWINDOW



            glColor3ub(55,155,255);



            glVertex3f(145,410,0.0);



            glVertex3f(165,410,0.0);



            glVertex3f(165,460,0.0);



            glVertex3f(145,460,0.0);



            glEnd();











         glBegin(GL_QUADS);              ///left  2ND building 2nd  2nd line er 2nd WINDOW



            glColor3ub(55,155,255);



            glVertex3f(175,410,0.0);



            glVertex3f(200,410,0.0);



            glVertex3f(200,460,0.0);



            glVertex3f(175,460,0.0);



            glEnd();



















             glBegin(GL_QUADS);              ///left  2ND building 2nd  2nd line er 3rd WINDOW



            glColor3ub(55,155,255);



            glVertex3f(210,410,0.0);



            glVertex3f(230,410,0.0);



            glVertex3f(230,460,0.0);



            glVertex3f(210,460,0.0);



            glEnd();



























             glBegin(GL_QUADS);              ///left  2ND building ER 3rd line er 1ST WINDOW



            glColor3ub(55,155,255);



            glVertex3f(145,330,0.0);



            glVertex3f(165,330,0.0);



            glVertex3f(165,380,0.0);



            glVertex3f(145,380,0.0);



            glEnd();























            glBegin(GL_QUADS);              ///left  2ND building 3rd line er 2nd WINDOW



            glColor3ub(55,155,255);



            glVertex3f(175,330,0.0);



            glVertex3f(200,330,0.0);



            glVertex3f(200,380,0.0);



            glVertex3f(175,380,0.0);



            glEnd();



















             glBegin(GL_QUADS);              ///left  2ND building 3rd line er 3rd WINDOW



            glColor3ub(55,155,255);



            glVertex3f(210,330,0.0);



            glVertex3f(230,330,0.0);



            glVertex3f(230,380,0.0);



            glVertex3f(210,380,0.0);



            glEnd();







            glPopMatrix() ;











        }







        void Draw_First_Building ()



        {



            glPushMatrix();











            glBegin(GL_QUADS);              ///left building 1ST



            glColor3ub(55,100,60);



            glVertex3f(30,290,0.0);



            glColor3ub(69, 135, 54);



            glVertex3f(135,290,0.0);



            glVertex3f(135,500,0.0);



            glVertex3f(30,500,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///left building 1ST ER BORDER DESIGN



            glColor3ub(55,80,60);



            glVertex3f(60,290,0.0);



            glColor3ub(45, 135, 54);



            glVertex3f(100,290,0.0);



            glVertex3f(100,500,0.0);



            glVertex3f(60,500,0.0);



            glEnd();















            glBegin(GL_QUADS);              ///left building 1ST ER UPORER HOUSE



            glColor3ub(55,80,60);



            glVertex3f(39,500,0.0);



            glVertex3f(85,500,0.0);



            glVertex3f(85,520,0.0);



            glVertex3f(39,520,0.0);



            glEnd();



















            glBegin(GL_QUADS); /// LEFT 1ST FLAT ER UPPER LEFT ER 1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(40, 450, 0.0);



        glVertex3i(60, 450, 0.0);



        glVertex3i(60, 470, 0.0);



        glVertex3i(40, 470, 0.0);



        glEnd() ;



















          glBegin(GL_QUADS); /// LEFT 1ST FLAT ER UPPER LEFT ER 2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(70, 450, 0.0);



        glVertex3i(90, 450, 0.0);



        glVertex3i(90, 470, 0.0);



        glVertex3i(70, 470, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER UPPER LEFT ER 3RD WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(100, 450, 0.0);



        glVertex3i(120, 450, 0.0);



        glVertex3i(120, 470, 0.0);



        glVertex3i(100, 470, 0.0);



        glEnd() ;















            glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 2ND UPPER LEFT ER 1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(40, 400, 0.0);



        glVertex3i(60, 400, 0.0);



        glVertex3i(60, 420, 0.0);



        glVertex3i(40, 420, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 2ND UPPER LEFT ER 2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(70, 400, 0.0);



        glVertex3i(90, 400, 0.0);



        glVertex3i(90, 420, 0.0);



        glVertex3i(70, 420, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 2ND UPPER LEFT ER 3RD WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(100, 400, 0.0);



        glVertex3i(120, 400, 0.0);



        glVertex3i(120, 420, 0.0);



        glVertex3i(100, 420, 0.0);



        glEnd() ;



































            glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 3RD UPPER LEFT ER 1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(40, 350, 0.0);



        glVertex3i(60, 350, 0.0);



        glVertex3i(60, 370, 0.0);



        glVertex3i(40, 370, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 3RD UPPER LEFT ER 2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(70, 350, 0.0);



        glVertex3i(90, 350, 0.0);



        glVertex3i(90, 370, 0.0);



        glVertex3i(70, 370, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 2ND UPPER LEFT ER 3RD WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(100, 350, 0.0);



        glVertex3i(120, 350, 0.0);



        glVertex3i(120, 370, 0.0);



        glVertex3i(100, 370, 0.0);



        glEnd() ;







        glPopMatrix();



        }



         void DrawTrain()



        {



         glPushMatrix();







          glPushMatrix(); /// for translating



            glTranslatef(10,110,0);



            glPushMatrix();









             glBegin(GL_QUADS); /// CONNECTOR



        glColor3ub(0,0,255);//(R,G,B)



        glVertex3i(80, 50, 0.0);



        glVertex3i(380, 50, 0.0);



        glVertex3i(380, 55, 0.0);



        glVertex3i(100, 55, 0.0);



        glEnd() ;







            glBegin(GL_QUADS); ///1ST TRAIN ER 1ST BOX



        glColor3ub(0,0,64);//(R,G,B)



        glVertex3i(80, 50, 0.0);



        //glColor3ub(70,60,120);



        glVertex3i(100, 50, 0.0);



        glVertex3i(100, 90, 0.0);



        glVertex3i(80, 90, 0.0);



        glEnd();



      glColor3ub(63,63,63);

                                   /// 1st box er 1st wheel

        DrawCircle(87,50,5,1000);

        glColor3ub(128,128,128);

        DrawCircle(87,50,3,1000);











        glBegin(GL_QUADS); ///1ST TRAIN ER SMOKE TOOL lomba ta



        glColor3ub(64,0,0);//(R,G,B)



        glVertex3i(88, 90, 0.0);



        glVertex3i(93, 90, 0.0);



        glVertex3i(93, 100, 0.0);



        glVertex3i(88, 100, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///1ST TRAIN ER SMOKE TOOL parallel



        glColor3ub(0,0,64);//(R,G,B)



        glVertex3i(84, 98, 0.0);



        glVertex3i(96, 98, 0.0);



        glVertex3i(96, 105, 0.0);



        glVertex3i(84, 105, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); ///1ST TRAIN ER LIGHT

        glColor3ub(64,0,0);//(R,G,B)

        glVertex3i(76, 70, 0.0);

        glVertex3i(80, 70, 0.0);

        glVertex3i(80, 80, 0.0);

        glVertex3i(76, 80, 0.0);

        glEnd() ;

if ( sunY <= -270) {
glBegin(GL_POLYGON); ///1ST TRAIN ER LIGHT

        glColor4f(1.0,1.0,0,0.5);//(R,G,B)

        glVertex3i(76, 74, 0.0);

        glVertex3i(57, 82, 0.0);

        glVertex3i(57, 68, 0.0);

        //glVertex3i(76, 80, 0.0);

        glEnd() ;


}








        glBegin(GL_QUADS); ///1ST TRAIN ER 2ND PORTION



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(100, 50, 0.0);



        glColor3ub(70,60,140);



        glVertex3i(140, 50, 0.0);



        glVertex3i(140, 140, 0.0);



        glVertex3i(100, 140, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); ///1ST TRAIN ER 2ND PORTION er paser 3d



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(140, 50, 0.0);



        //glColor3ub(70,60,140);



        glVertex3i(144, 50, 0.0);



        glVertex3i(144, 142, 0.0);



        glVertex3i(140, 140, 0.0);



        glEnd() ;











          glColor3ub(63,63,63); /// 1st box er 2nd wheel

        DrawCircle(132,53,10,1000);

        glColor3ub(128,128,128);

        DrawCircle(132,53,3,1000);











        glBegin(GL_QUADS); ///1ST TRAIN ER 2ND PORTION er uporer 3d



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(140, 140, 0.0);



        //glColor3ub(70,60,140);



        glVertex3i(144, 142, 0.0);



        glVertex3i(103, 142, 0.0);



        glVertex3i(100, 140, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///1ST TRAIN ER 2ND PORTION ER WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(115, 95, 0.0);



        glVertex3i(125, 95, 0.0);



        glVertex3i(125, 120, 0.0);



        glVertex3i(115, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///2ND TRAIN



        glColor3ub(10,10,145);//(R,G,B)



        glVertex3i(150, 50, 0.0);



        glColor3f(0.0, 1.0, 0.0);



        glColor3ub(70,50,140);

        glVertex3i(200, 50, 0.0);

        glVertex3i(200, 140, 0.0);



        glVertex3i(150, 140, 0.0);



        glEnd() ;



          glColor3ub(63,63,63);    /// 2nd train er 1st wheel

        DrawCircle(158,53,10,1000);

        glColor3ub(128,128,128);

        DrawCircle(158,53,3,1000);







        glBegin(GL_QUADS); ///2ND TRAIN er paser 3d



        glColor3ub(0,20,130);//(R,G,B)



        glVertex3i(200, 50, 0.0);







        glVertex3i(204, 50, 0.0);



        glVertex3i(204, 142, 0.0);



        glVertex3i(200, 140, 0.0);



        glEnd() ;







        glColor3ub(63,63,63);  /// 2nd train er 2nd wheel

        DrawCircle(195,53,10,1000);

        glColor3ub(128,128,128);

        DrawCircle(195,53,3,1000);











        glBegin(GL_QUADS); ///2ND TRAIN er uporer 3d



        glColor3ub(0,20,130);//(R,G,B)



        glVertex3i(204, 142, 0.0);







        glVertex3i(152, 142, 0.0);



        glVertex3i(150, 140, 0.0);



        glVertex3i(200, 140, 0.0);



        glEnd() ;















        glBegin(GL_QUADS); /// 2ND TRAIN ER WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(160, 95, 0.0);



        glVertex3i(170, 95, 0.0);



        glVertex3i(170, 120, 0.0);



        glVertex3i(160, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// 2ND TRAIN ER  2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(180, 95, 0.0);







        glVertex3i(190, 95, 0.0);



        glVertex3i(190, 120, 0.0);



        glVertex3i(180, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///3RD TRAIN



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(210, 50, 0.0);



        glColor3ub(70,60,140);



        glVertex3i(260, 50, 0.0);



        glVertex3i(260, 140, 0.0);



        glVertex3i(210, 140, 0.0);



        glEnd() ;





 glColor3ub(63,63,63);    /// 3rd train er 1st wheel

        DrawCircle(218,53,10,1000);

        glColor3ub(128,128,128);

        DrawCircle(218,53,3,1000);







        glBegin(GL_QUADS); ///3RD TRAIN er paser 3d



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(260, 50, 0.0);



        glColor3ub(0,60,140);



        glVertex3i(264, 50, 0.0);



        glVertex3i(264, 142, 0.0);



        glVertex3i(260, 140, 0.0);



        glEnd() ;





 glColor3ub(63,63,63);   /// 3rd train er 2nd wheel

        DrawCircle(255,53,10,1000);

       glColor3ub(128,128,128);

        DrawCircle(255,53,3,1000);







        glBegin(GL_QUADS); ///3RD TRAIN er uporer 3d



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(260, 140, 0.0);



        glColor3ub(0,60,140);



        glVertex3i(262, 142, 0.0);



        glVertex3i(212, 142, 0.0);



        glVertex3i(210, 140, 0.0);



        glEnd() ;



















        glBegin(GL_QUADS); /// 3RD TRAIN ER  1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(220, 95, 0.0);



        glVertex3i(230, 95, 0.0);



        glVertex3i(230, 120, 0.0);



        glVertex3i(220, 120, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); /// 3RD TRAIN ER  2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(240, 95, 0.0);



        glVertex3i(250, 95, 0.0);



        glVertex3i(250, 120, 0.0);



        glVertex3i(240, 120, 0.0);



        glEnd() ;















        glBegin(GL_QUADS); ///4RTH TRAIN



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(270, 50, 0.0);



        glVertex3i(320, 50, 0.0);



        glVertex3i(320, 140,0.0);



        glVertex3i(270, 140, 0.0);



        glEnd() ;









          glColor3ub(63,63,63);   /// 4rth train er 1st wheel

        DrawCircle(279,53,10,1000);

        glColor3ub(128,128,128);

        DrawCircle(279,53,3,1000);







        glBegin(GL_QUADS); ///4RTH TRAIN er paser 3d



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(320, 50, 0.0);



        glColor3f(0.1, 1.0, 0.0);



        glVertex3i(324, 52, 0.0);



        glColor3ub(80,60,180);



        glVertex3i(324, 142,0.0);



        glVertex3i(320, 140, 0.0);



        glEnd() ;







          glColor3ub(63,63,63);   /// 4th train er 2nd wheel

        DrawCircle(315,53,10,1000);

        glColor3ub(128,128,128);

        DrawCircle(315,53,3,1000);







        glBegin(GL_QUADS); ///4RTH TRAIN er uporer 3d



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(320, 140, 0.0);



        glColor3f(0.1, 1.0, 0.0);



        glVertex3i(324, 142, 0.0);



        glColor3ub(80,60,180);



        glVertex3i(272, 142,0.0);



        glVertex3i(270, 140, 0.0);



        glEnd() ;



        glBegin(GL_QUADS); /// 4RTH TRAIN ER  1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(280, 95, 0.0);



        glVertex3i(290, 95, 0.0);



        glVertex3i(290, 120, 0.0);



        glVertex3i(280, 120, 0.0);



        glEnd() ;





        glBegin(GL_QUADS); /// 4RTH TRAIN ER  2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(300, 95, 0.0);



        glVertex3i(310, 95, 0.0);



        glVertex3i(310, 120, 0.0);



        glVertex3i(300, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///5TH TRAIN



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(330, 50, 0.0);



        glColor3ub(80,60,140);



        glVertex3i(380, 50, 0.0);



        glColor3ub(80,60,180);



        glVertex3i(380, 140,0.0);



        glVertex3i(330, 140, 0.0);



        glEnd() ;









          glColor3ub(63,63,63);   /// 5th train er 1st wheel

        DrawCircle(339,53,10,1000);

        glColor3ub(128,128,128);

        DrawCircle(339,53,3,1000);







        glBegin(GL_QUADS); ///5TH TRAIN er side er 3d



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(380, 50, 0.0);



        //glColor3ub(80,60,140);



        glVertex3i(385, 55, 0.0);



        //glColor3ub(80,60,180);



        glVertex3i(385, 142,0.0);



        glVertex3i(380, 140, 0.0);



        glEnd() ;







          glColor3ub(63,63,63);    /// 5th train er 2nd wheel

        DrawCircle(375,53,10,1000);

        glColor3ub(128,128,128);



        DrawCircle(375,53,3,1000);







        glBegin(GL_QUADS); ///5TH TRAIN er upor er 3d



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(380, 140, 0.0);



        //glColor3ub(80,60,140);



        glVertex3i(385, 142, 0.0);



        //glColor3ub(80,60,180);



        glVertex3i(332, 142,0.0);



        glVertex3i(330, 140, 0.0);



        glEnd() ;



















        glBegin(GL_QUADS); /// 5TH TRAIN ER  1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(340, 95, 0.0);



        glVertex3i(350, 95, 0.0);



        glVertex3i(350, 120, 0.0);



        glVertex3i(340, 120, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); /// 5TH TRAIN ER  2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(360, 95, 0.0);



        glVertex3i(370, 95, 0.0);



        glVertex3i(370, 120, 0.0);



        glVertex3i(360, 120, 0.0);



        glEnd() ;















           glPopMatrix();







            glPopMatrix();///translation er pop







            glPopMatrix();











        }











        void display(void)



        {



        /* clear all pixels */



        glClear(GL_COLOR_BUFFER_BIT);







        glColor3f(1.0, 1.0, 0.0);//(R,G,B)























        glBegin(GL_QUADS); ///1ST TRAIN ER 1ST BOX



        glColor3ub(0,0,64);//(R,G,B)



        glVertex3i(80, 50, 0.0);



        glVertex3i(100, 50, 0.0);



        glVertex3i(100, 90, 0.0);



        glVertex3i(80, 90, 0.0);



        glEnd();







        glBegin(GL_QUADS); ///1ST TRAIN ER SMOKE TOOL



        glColor3ub(64,0,0);//(R,G,B)



        glVertex3i(88, 90, 0.0);



        glVertex3i(93, 90, 0.0);



        glVertex3i(93, 100, 0.0);



        glVertex3i(88, 100, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///1ST TRAIN ER SMOKE TOOL



        glColor3ub(0,0,64);//(R,G,B)



        glVertex3i(84, 98, 0.0);



        glVertex3i(96, 98, 0.0);



        glVertex3i(96, 105, 0.0);



        glVertex3i(84, 105, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///1ST TRAIN ER LIGHT



        glColor3ub(64,0,0);//(R,G,B)



        glVertex3i(76, 70, 0.0);



        glVertex3i(80, 70, 0.0);



        glVertex3i(80, 80, 0.0);



        glVertex3i(76, 80, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///1ST TRAIN ER 2ND PORTION



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(100, 50, 0.0);







        glVertex3i(130, 50, 0.0);







        glVertex3i(130, 140, 0.0);



        glVertex3i(100, 140, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///1ST TRAIN ER 2ND PORTION ER WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(110, 95, 0.0);



        glVertex3i(120, 95, 0.0);



        glVertex3i(120, 120, 0.0);



        glVertex3i(110, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///2ND TRAIN



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(140, 50, 0.0);



        glVertex3i(190, 50, 0.0);



        glVertex3i(190, 140, 0.0);



        glVertex3i(140, 140, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); /// 2ND TRAIN ER WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(150, 95, 0.0);



        glVertex3i(160, 95, 0.0);



        glVertex3i(160, 120, 0.0);



        glVertex3i(150, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// 2ND TRAIN ER  2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(170, 95, 0.0);



        glVertex3i(180, 95, 0.0);



        glVertex3i(180, 120, 0.0);



        glVertex3i(170, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///3RD TRAIN



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(200, 50, 0.0);



        glVertex3i(250, 50, 0.0);



        glVertex3i(250, 140, 0.0);



        glVertex3i(200, 140, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); /// 3RD TRAIN ER  1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(210, 95, 0.0);



        glVertex3i(220, 95, 0.0);



        glVertex3i(220, 120, 0.0);



        glVertex3i(210, 120, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); /// 3RD TRAIN ER  2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(230, 95, 0.0);



        glVertex3i(240, 95, 0.0);



        glVertex3i(240, 120, 0.0);



        glVertex3i(230, 120, 0.0);



        glEnd() ;















        glBegin(GL_QUADS); ///4RTH TRAIN



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(260, 50, 0.0);



        glVertex3i(310, 50, 0.0);



        glVertex3i(310, 140,0.0);



        glVertex3i(260, 140, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// 4RTH TRAIN ER  1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(270, 95, 0.0);



         glColor3ub(55,80,60);



        glVertex3i(280, 95, 0.0);



         glColor3ub(10,80,60);



        glVertex3i(280, 120, 0.0);



        glVertex3i(270, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// 4RTH TRAIN ER  2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(290, 95, 0.0);



        glVertex3i(300, 95, 0.0);



        glVertex3i(300, 120, 0.0);



        glVertex3i(290, 120, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); ///5TH TRAIN



        glColor3ub(0,60,140);//(R,G,B)



        glVertex3i(320, 50, 0.0);



        glVertex3i(370, 50, 0.0);



        glVertex3i(370, 140,0.0);



        glVertex3i(320, 140, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// 5TH TRAIN ER  1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(330, 95, 0.0);



        glVertex3i(340, 95, 0.0);



        glVertex3i(340, 120, 0.0);



        glVertex3i(330, 120, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); /// 5TH TRAIN ER  2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(350, 95, 0.0);



        glVertex3i(360, 95, 0.0);



        glVertex3i(360, 120, 0.0);



        glVertex3i(350, 120, 0.0);



        glEnd() ;







        glBegin(GL_QUADS); /// CONNECTOR



        glColor3ub(0,0,64);//(R,G,B)



        glVertex3i(80, 50, 0.0);



        glVertex3i(370, 50, 0.0);



        glVertex3i(370, 55, 0.0);



        glVertex3i(100, 55, 0.0);



        glEnd() ;















        glBegin(GL_QUADS);              ///left building 1ST



            glColor3ub(55,100,60);



            glVertex3f(30,290,0.0);



            glVertex3f(135,290,0.0);



            glVertex3f(135,500,0.0);



            glVertex3f(30,500,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///left building 1ST ER BORDER DESIGN



            glColor3ub(55,80,60);



            glVertex3f(60,290,0.0);



            glVertex3f(100,290,0.0);



            glVertex3f(100,500,0.0);



            glVertex3f(60,500,0.0);



            glEnd();















            glBegin(GL_QUADS);              ///left building 1ST ER UPORER HOUSE



            glColor3ub(55,80,60);



            glVertex3f(39,500,0.0);



            glVertex3f(85,500,0.0);



            glVertex3f(85,520,0.0);



            glVertex3f(39,520,0.0);



            glEnd();



















            glBegin(GL_QUADS); /// LEFT 1ST FLAT ER UPPER LEFT ER 1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(40, 450, 0.0);



        glVertex3i(60, 450, 0.0);



        glVertex3i(60, 470, 0.0);



        glVertex3i(40, 470, 0.0);



        glEnd() ;



















          glBegin(GL_QUADS); /// LEFT 1ST FLAT ER UPPER LEFT ER 2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(70, 450, 0.0);



        glVertex3i(90, 450, 0.0);



        glVertex3i(90, 470, 0.0);



        glVertex3i(70, 470, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER UPPER LEFT ER 3RD WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(100, 450, 0.0);



        glVertex3i(120, 450, 0.0);



        glVertex3i(120, 470, 0.0);



        glVertex3i(100, 470, 0.0);



        glEnd() ;















            glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 2ND UPPER LEFT ER 1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(40, 400, 0.0);



        glVertex3i(60, 400, 0.0);



        glVertex3i(60, 420, 0.0);



        glVertex3i(40, 420, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 2ND UPPER LEFT ER 2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(70, 400, 0.0);



        glVertex3i(90, 400, 0.0);



        glVertex3i(90, 420, 0.0);



        glVertex3i(70, 420, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 2ND UPPER LEFT ER 3RD WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(100, 400, 0.0);



        glVertex3i(120, 400, 0.0);



        glVertex3i(120, 420, 0.0);



        glVertex3i(100, 420, 0.0);



        glEnd() ;











            glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 3RD UPPER LEFT ER 1ST WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(40, 350, 0.0);



        glVertex3i(60, 350, 0.0);



        glVertex3i(60, 370, 0.0);



        glVertex3i(40, 370, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 3RD UPPER LEFT ER 2ND WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(70, 350, 0.0);



        glVertex3i(90, 350, 0.0);



        glVertex3i(90, 370, 0.0);



        glVertex3i(70, 370, 0.0);



        glEnd() ;











        glBegin(GL_QUADS); /// LEFT 1ST FLAT ER 2ND UPPER LEFT ER 3RD WINDOW



        glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        glVertex3i(100, 350, 0.0);



        glVertex3i(120, 350, 0.0);



        glVertex3i(120, 370, 0.0);



        glVertex3i(100, 370, 0.0);



        glEnd() ;























         glBegin(GL_QUADS);              ///left  2ND building



            glColor3ub(55,10,60);



            glVertex3f(134,280,0.0);



            glVertex3f(240,280,0.0);



            glVertex3f(240,550,0.0);



            glVertex3f(134,550,0.0);



            glEnd();







        glBegin(GL_QUADS);              ///left  2ND building er 3d portion



            glColor3ub(55,50,60);



            glVertex3f(240,290,0.0);



            glVertex3f(255,299,0.0);



            glVertex3f(255,555,0.0);



            glVertex3f(240,555,0.0);



            glEnd();















            glBegin(GL_QUADS);              ///left  2ND building er uporer 3d



            glColor3ub(55,50,60);



            glVertex3f(134,550,0.0);



            glVertex3f(240,550,0.0);



            glVertex3f(255,555,0.0);



            glVertex3f(141,555,0.0);



            glEnd();



































             glBegin(GL_QUADS);              ///left  2ND building 1ST BORDER



            glColor3ub(55,30,60);



            glVertex3f(134,300,0.0);



            glVertex3f(240,300,0.0);



            glVertex3f(240,350,0.0);



            glVertex3f(134,350,0.0);



            glEnd();















             glBegin(GL_QUADS);              ///left  2ND building 2ND BORDER



            glColor3ub(55,30,60);



            glVertex3f(134,370,0.0);



            glVertex3f(240,370,0.0);



            glVertex3f(240,420,0.0);



            glVertex3f(134,420,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///left  2ND building 3RD BORDER



            glColor3ub(55,30,60);



            glVertex3f(134,440,0.0);



            glVertex3f(240,440,0.0);



            glVertex3f(240,490,0.0);



            glVertex3f(134,490,0.0);



            glEnd();















        glBegin(GL_QUADS);              ///left  2ND building ER LOMBA BORDER



            glColor3ub(55,30,60);



            glVertex3f(165,290,0.0);



            glVertex3f(210,290,0.0);



            glVertex3f(210,530,0.0);



            glVertex3f(165,530,0.0);



            glEnd();











            glBegin(GL_QUADS);              ///left  2ND building ER UPPER LEFT 1ST WINDOW



            glColor3ub(55,155,255);



            glVertex3f(145,480,0.0);



            glVertex3f(230,480,0.0);



            glVertex3f(230,530,0.0);



            glVertex3f(145,530,0.0);



            glEnd();



















            glBegin(GL_QUADS);              ///left  2ND building 2nd  2nd line er 1stWINDOW



            glColor3ub(55,155,255);



            glVertex3f(145,410,0.0);



            glVertex3f(165,410,0.0);



            glVertex3f(165,460,0.0);



            glVertex3f(145,460,0.0);



            glEnd();











         glBegin(GL_QUADS);              ///left  2ND building 2nd  2nd line er 2nd WINDOW



            glColor3ub(55,155,255);



            glVertex3f(175,410,0.0);



            glVertex3f(200,410,0.0);



            glVertex3f(200,460,0.0);



            glVertex3f(175,460,0.0);



            glEnd();



















             glBegin(GL_QUADS);              ///left  2ND building 2nd  2nd line er 3rd WINDOW







            glColor3ub(55,155,255);



            glVertex3f(210,410,0.0);



            glVertex3f(230,410,0.0);



            glVertex3f(230,460,0.0);



            glVertex3f(210,460,0.0);



            glEnd();



























             glBegin(GL_QUADS);              ///left  2ND building ER 3rd line er 1ST WINDOW



            glColor3ub(55,155,255);



            glVertex3f(145,330,0.0);



            glVertex3f(165,330,0.0);



            glVertex3f(165,380,0.0);



            glVertex3f(145,380,0.0);



            glEnd();























            glBegin(GL_QUADS);              ///left  2ND building 3rd line er 2nd WINDOW



            glColor3ub(55,155,255);



            glVertex3f(175,330,0.0);



            glVertex3f(200,330,0.0);



            glVertex3f(200,380,0.0);



            glVertex3f(175,380,0.0);



            glEnd();



















             glBegin(GL_QUADS);              ///left  2ND building 3rd line er 3rd WINDOW



            glColor3ub(55,155,255);



            glVertex3f(210,330,0.0);



            glVertex3f(230,330,0.0);



            glVertex3f(230,380,0.0);



            glVertex3f(210,380,0.0);



            glEnd();











             glBegin(GL_QUADS);              ///road white



            glColor3ub(128,128,128);



            glVertex3f(0,240,0.0);



            glVertex3f(599,240,0.0);



            glVertex3f(599,290,0.0);



            glVertex3f(0,290,0.0);



            glEnd();















            glBegin(GL_QUADS);              ///road white



            glColor3ub(128,128,128);



            glVertex3f(255,270,0.0);



            glVertex3f(599,270,0.0);



            glVertex3f(599,320,0.0);



            glVertex3f(255,320,0.0);



            glEnd();















            glBegin(GL_TRIANGLES);              ///ROAD white triangle



            glColor3ub(128,128,128);



            glVertex3f(240,290,0.0);



            glVertex3f(300,280,0.0);



            glVertex3f(255,299,0.0);







            glEnd();















            glBegin(GL_QUADS);              ///road white



            glColor3ub(128,128,128);



            glVertex3f(0,290,0.0);



            glColor3ub(63,63,63);



            glVertex3f(30,290,0.0);



            glVertex3f(30,320,0.0);



            glVertex3f(0,320,0.0);



            glEnd();























              glBegin(GL_QUADS);              ///back side dark ash road



            glColor3ub(63,63,63);



            glVertex3f(255,320,0.0);



            glVertex3f(599,320,0.0);



            glVertex3f(599,400,0.0);



            glVertex3f(255,400,0.0);



            glEnd();























              glBegin(GL_QUADS);              ///back side dark ash road



            glColor3ub(63,63,63);



            glVertex3f(0,320,0.0);



            glVertex3f(30,320,0.0);



            glVertex3f(30,400,0.0);



            glVertex3f(0,400,0.0);



            glEnd();











           glBegin(GL_QUADS);              ///back side blue  building



            glColor3ub(80,60,128);



            glVertex3f(440,360,0.0);



            glVertex3f(510,360,0.0);



            glVertex3f(510,500,0.0);



            glVertex3f(440,500,0.0);



            glEnd();







        glBegin(GL_QUADS);              ///back side blue  building er pasher 3d



            glColor3ub(70,100,118);



            glVertex3f(510,360,0.0);



            glVertex3f(519,366,0.0);



            glVertex3f(519,506,0.0);



            glVertex3f(510,502,0.0);



            glEnd();











        glBegin(GL_QUADS);              ///back side blue  building er uporer 3d



            glColor3ub(70,100,118);



              glVertex3f(510,500,0.0);



            glVertex3f(519,506,0.0);



            glVertex3f(442,506,0.0);



            glVertex3f(440,500,0.0);







            glEnd();



















             glBegin(GL_QUADS);              ///back side blue  building er nicher 1st window



           glColor3ub(55,155,255);



            glVertex3f(450,380,0.0);



            glVertex3f(470,380,0.0);



            glVertex3f(470,400,0.0);



            glVertex3f(450,400,0.0);



            glEnd();























             glBegin(GL_QUADS);              ///back side blue  building er nicher 2nd window



               glColor3ub(55,155,255);



            glVertex3f(480,380,0.0);



            glVertex3f(500,380,0.0);



            glVertex3f(500,400,0.0);



            glVertex3f(480,400,0.0);



            glEnd();















             glBegin(GL_QUADS);              ///back side blue  building 2nd line er last  window



              glColor3ub(55,155,255);



            glVertex3f(480,420,0.0);



            glVertex3f(500,420,0.0);



            glVertex3f(500,440,0.0);



            glVertex3f(480,440,0.0);



            glEnd();



















            glBegin(GL_QUADS);              ///back side blue  building er nicher 1st window



              glColor3ub(55,155,255);



            glVertex3f(450,420,0.0);



            glVertex3f(470,420,0.0);



            glVertex3f(470,440,0.0);



            glVertex3f(450,440,0.0);



            glEnd();















             glBegin(GL_QUADS);              ///back side blue  building er uporerlomba window



            glColor3ub(55,155,255);



            glVertex3f(450,460,0.0);



            glVertex3f(500,460,0.0);



            glVertex3f(500,490,0.0);



            glVertex3f(450,490,0.0);



            glEnd();















        //glBegin(GL_LINE); /// 5TH TRAIN ER  2ND WINDOW



        //glColor3f(0.0, 1.0, 0.0);//(R,G,B)



        //glVertex3i(130, 50, 0.0);



        //glVertex3i(140, 50, 0.0);







        //glEnd() ;







        //glPushMatrix();             //1st train 1st wheel



           // glColor3ub(98,98,255);



            //glutSolidSphere(20);







           // glPopMatrix();















        glFlush();







        }



         void train ()



        {



            if ( trainStatus == 1)



            {



                train_X -= 0.25 ;



            }



            if ( train_X <= -500  )



            {



                train_X = 500 ;



            }



            glPushMatrix();



            if ( train_X == 400)

            {

                sndPlaySound("train.wav",SND_ASYNC);

            }



            glTranslatef(train_X, train_Y ,0.0);



            DrawTrain();







            glPopMatrix();







        }







        void MyDisplay ()



        {







            Draw_Total_Scene();


            middle_road_line();



            Draw_sky();

            if ( sunY <= -150)

            {

                Draw_Night_sky1();



            }

            if ( sunY <= -380)

            {

                star();



            }

            move_Sun();

            move_Moon();

            draw_airland();



            car();

              bus();

            glPushMatrix();

            //glTranslatef(.5,0.0,0.0);

           // glRotatef(  angle ,0.0 ,0.0,1.0);





            glPopMatrix();

            glPopMatrix();

            mountain();



            Draw_First_Building() ; /// 1st buildin



            Draw_2nd_Building() ; /// 2nd building



            Draw_Road_white_light() ;  ///white road draw kora hoise







            Draw_Road_2nd_dark()  ; /// 2nd road drawing







            Draw_3rd_Building();/// 3rd building







            Draw_wind_machine1();





            Draw_1st_tree() ;







            Draw_2nd_tree() ;







            Draw_3rd_tree() ;







            cloud();







            Draw_train_station();







            Draw_wall();



            Draw_Relling(0,180,60);



            Draw_rail_Line(0,150);





             train();











            glFlush();







            glutPostRedisplay();







            glutSwapBuffers();







        }



        void init(void)



        {



        /* select clearing (background) color */



        glClearColor(0.0, 0.0, 0.0, 0.0);



        /* initialize viewing values */



        glColor3f(1.0f, 1.0f, 1.0f);



        glPointSize(0.0f);



        glMatrixMode(GL_MODELVIEW);



        glLoadIdentity();



        //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);



        gluOrtho2D(0.0,600.0,0.0,700.0);



        }







        void myInit(void)







        {







            glClearColor(0.0, 0.0, 1.0, 0.0);







            glColor3f(1.0f, 1.0f, 1.0f);







            glPointSize(0.0);







            glMatrixMode(GL_PROJECTION);







            glLoadIdentity();







            gluOrtho2D(0.0, 1200.0, 0.0, 800.0);







        }



        /*



        * Declare initial window size, position, and display mode



        * (single buffer and RGBA). Open window with “hello”



        * in its title bar. Call initialization routines.



        * Register callback function to display graphics.



        * Enter main loop and process events.



        */



        int main(int argc, char** argv)



        {



        glutInit(&argc, argv);



        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);



        glutInitWindowSize(1000,600 );



        glutInitWindowPosition(0,0);



        glutCreateWindow("CITY NIGHT");



        //glutReshapeFunc(handleResize);



        init();



        glutFullScreen();



        glutDisplayFunc(MyDisplay);



        glutKeyboardFunc(keyboard);



        glutTimerFunc(25, update, 0);



        glutMainLoop();



        return 0; /* ISO C requires main to return int. */



        }











