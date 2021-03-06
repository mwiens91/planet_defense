#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <string>
#include "structs.h"

enum good_bad {ALLY, ENEMY}; //0 = ALLY, 1 = ENEMY

class projectile {
	public:
		projectile(GLfloat x, GLfloat y, good_bad side);
		//getter functions
		GLfloat get_origin(int coor) { return origin[coor]; }
		GLfloat get_length() { return length; }
		GLfloat get_width() { return width; }
		GLint get_speed() { return speed; }
		GLfloat get_damage() { return damage; }
		GLint get_side() { return side; }
		//setter functions
		void set_origin(GLfloat valx, GLfloat valy, GLfloat valz)
		{ origin[0] = valx; origin[1] = valy; origin[2] = valz; }
		void set_origin(int coor, GLfloat new_val) 
			{ origin[coor] = new_val; }
		void set_length(GLfloat new_length) 
			{ length = new_length; }
		void set_width(GLfloat new_width) 
			{ width = new_width; }
		void set_speed(GLint new_speed) 
			{ speed = new_speed; }
		void set_damage(GLfloat new_damage) 
			{ damage = new_damage; }
		void set_side(good_bad new_side)
			{ side = new_side;}
	private:
		GLfloat origin[3];
		GLfloat length;
		GLfloat width;
		GLint speed; //negative or positive depending on direction
		GLfloat damage;
		good_bad side;
		bool exists = true;
};

class reg_bullet : public projectile {
	public:
		reg_bullet(GLfloat x, GLfloat y, good_bad side);
		void display_bullet(void);
		hit_box get_hit_box();
		void move();
		bool off_screen();
		void bullet_print();
	private:
		GLfloat triangles[2];
		bool exists = true;
		void load_vertices();
		GLfloat quad[12];
};


#endif
